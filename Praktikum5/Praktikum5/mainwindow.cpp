#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <addbookingdialog.h>
#include <sstream>
#include <iostream>
#include "checkdialog.h"



// ==================================================== CONSTRUCTOR ====================================================



    MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow)
    {
        ui->setupUi(this);

        this->showMaximized(); // Maximiert startem
        this->setWindowTitle("TravelAgency - Verwaltung"); // Fenstertitel

        // Initialeinstellungen der Tabelle
        QTableWidget* table = ui->tableWidget;
        table->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded); // Vertical Scrollbar as needed
        table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Horizontal Scrollbar off
        table->setSelectionBehavior(QAbstractItemView::SelectRows); // Selektieren ganzer Zeilen
        table->verticalHeader()->setVisible(false); // Ausblenden des vertikalen Headers
        table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // Spaltenbreite automatisch anpassen
        table->setSortingEnabled(false); // Sortieren verbieten (wird nach dem Füllen der Tabelle aktiviert. Grund: Vermeiden von Fehlern beim Füllen)!

        // Instanziieren einer TravelAgency
        ta = new TravelAgency("TravenAgency");

        // Verstecken der Buchungsspezifischen Details
        ui->stackedDetailsWidget->hide();
    }



// ==================================================== DESTRUCTOR ====================================================



    MainWindow::~MainWindow()
    {
        delete ui; // Delete UI from Heap
        delete ta; // Delete TravelAgency from Heap
    }



// ==================================================== MENU TRIGGERS ====================================================



// DATEI -> NEU...




// DATEI -> SPEICHERN




// DATEI -> SPEICHERN ALS...

    void MainWindow::on_actionSpeichern_als_triggered()
    {
        QString filename = QFileDialog::getSaveFileName(
            this, "Speichern als...", QDir::currentPath(), ("Textdatei (.txt)")
        );

        QFile file(filename);

        if (file.open(QFile::WriteOnly | QFile::Truncate)) {
            QTextStream out(&file);

            for(unsigned long long i = 0; i < ta->allBookings.size(); i++) {
                out << ta->getConcatenatedData(ta->allBookings[i]) << endl;
            }

        } else {
            cout << "[ERROR] Datei konnte zum beschreiben nicht geöffnet werden!" << endl;
            QMessageBox::critical(this, "Fehler beim Speichern", "Datei konnte zum beschreiben nicht geöffnet werden!");
            return;
        }

        if(file.isOpen())
            file.close();
    }



// DATEI -> IMPORT

    void MainWindow::on_actionImport_triggered()
    {
        // Auswählen einer Datei über Dateiexplorer
        QString path = QFileDialog::getOpenFileName(
            this, ("Öffnen"), "./", ("Textdateien (*.txt)")
        );

        // Import beenden, wenn Dateipfad leer
        if(path.isNull()) return;

        // Einlesen der ausgewählen Datei
        ta->readFile( path.toStdString() );

        // Popupfenster mit Informationen anzeigen
        ostringstream oss;
        if(ta->getLastImportBookingCount() == 0) {
            oss << "Es wurden keine neuen Buchungen hinzugefügt.";
        } else {
            oss << "Es wurden " <<
                   ta->getLastImportBookingCount() << " Buchungen " <<
                   ta->getLastImportCustomerCount() << " Kunden " <<
                   ta->getLastImportTravelCount() << " Reisen im Gesamtwert von " <<
                   ta->getLastImportPriceTotal() << " EURO eingelesen.";
        }

        QString text = QString::fromStdString(oss.str());
        QMessageBox::information(this, "Import Information", text);

        // Tabelle füllen
        reloadTable();

//        for(Booking* b : ta->allBookings) {
//            cout << b->showDetails() << endl;
//        }

    }



// DATEI -> EXPORT

    void MainWindow::on_actionExport_triggered()
    {

    }



// DATEI -> BEENDEN

    void MainWindow::on_actionClose_triggered()
    {
        close();
    }



// BEARBEITEN -> BUCHUNG HINZUFUEGEN

    void MainWindow::on_actionAddBooking_triggered()
    {
        // Initialisieren des Dialogs
        AddBookingDialog* addBookingDialog = new AddBookingDialog();

        // Verbinden die Signale von AddBookingDialog mit den Slots dieser Klasse (MainWindow)
        connect(
            addBookingDialog,
            SIGNAL(send_DataFB(double, long, QDate, QDate, QString, QString, QString, char, vector<string>)),
            this,
            SLOT(receive_DataFB(double, long, QDate, QDate, QString, QString, QString, char, vector<string>))
        );

        connect(
            addBookingDialog,
            SIGNAL(send_DataHB(double, long, QDate, QDate, QString, QString, bool, vector<string>)),
            this,
            SLOT(receive_DataHB(double, long, QDate, QDate, QString, QString, bool, vector<string>))
        );

        connect(
            addBookingDialog,
            SIGNAL(send_DataRCR(double, long, QDate, QDate, QString, QString, QString, QString, vector<string>)),
            this,
            SLOT(receive_DataRCR(double, long, QDate, QDate, QString, QString, QString, QString, vector<string>))
        );

        // Anzeigen des Dialogs
        addBookingDialog->show();
    }



// BEARBEITEN -> BUCHUNG AENDERN

// BEARBEITEN -> BUCHUNG ENTFERNEN


// BEARBEITEN -> REISEN PRÜFEN

    void MainWindow::on_actionPruefen_triggered()
    {
        CheckDialog *checkResults = new CheckDialog();
        checkResults->setTravelAgency(ta);
        checkResults->show();
        checkResults->checkTravelsAndFillTable();
    }



// ==================================================== SIGNAL SLOTS ====================================================

/*
 *
 * Hier werden die ankommenden Daten des AddBookingDialogs in temporäre Variablen geschrieben. Anschließend ruft
 * die Funktion receive_readyToCreate() die Funktion createBooking() aus der TravelAgency auf.
 *
 */

// ADDBOOKINGDIALOG - DATA

    void MainWindow::receive_DataFB(double price, long tid, QDate dateFrom, QDate dateTo, QString departure, QString arrival, QString airline, char seatPref, vector<string> arcs)
    {
        ta->createBooking(price, tid, dateFrom, dateTo, departure, arrival, airline, seatPref, arcs);
        reloadTable();
    }



    void MainWindow::receive_DataHB(double price, long tid, QDate dateFrom, QDate dateTo, QString hotel, QString town, bool smoke, vector<string> arcs)
    {
        ta->createBooking(price, tid, dateFrom, dateTo, hotel, town, smoke, arcs);
        reloadTable();
    }



    void MainWindow::receive_DataRCR(double price, long travelId, QDate start, QDate end, QString pickupLocation, QString returnLocation, QString company, QString insuranceType, vector<string> arcs)
    {
        ta->createBooking(price, travelId, start, end, pickupLocation, returnLocation, company, insuranceType, arcs);
        reloadTable();
    }



// ==================================================== TABLE ====================================================



// FUNCTION: FILL_TABLE

    void MainWindow::reloadTable()
    {
        QTableWidget* table = ui->tableWidget;

        // Table leeren und Sortieren verbieten
        table->clear();
        table->setSortingEnabled(false); // Wird deaktiviert um Fehler zu vermeiden (ist nötig! wird nach dem Füllen aktiviert)

        // Header generieren
        generateTableHeader();

        // Zeilen erstellen
        table->setRowCount(ta->getBookingsCount());

        // Zeiger auf ein TableWidgetItem
        QTableWidgetItem* item;


        // Initialisieren der einzelnen Zellen und Einfügen in die jeweilige Zeile

        int r = 0; // row index

        for(unsigned long long i = 0; i < ta->allBookings.size(); i++) {

            // Spalte 1 (BuchungsNr.)
            item = new QTableWidgetItem();
            item->setData(Qt::EditRole, static_cast<long long>(ta->allBookings[i]->getBid())); // setData() statt setText(), um sortieren zu können!!
            item->setFlags(item->flags() ^ Qt::ItemIsEditable); // Das Edititieren der Zelle verbieten
            table->setItem(r, 0, item); // Setzen der Zelle an die richtige Stelle (Zeile/Spalte)

            // Spalte 2 (Preis)
            item = new QTableWidgetItem();
            item->setData(Qt::EditRole, ta->allBookings[i]->getPrice());
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            table->setItem(r, 1, item);

            // Spalte 3 (Kunde)
            item = new QTableWidgetItem();
            item->setData(Qt::EditRole, QString::fromStdString(ta->getCustomer(ta->allBookings[i])->getName()));
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            table->setItem(r, 2, item);

            // Spalte 4 (ReiseNr.)
            item = new QTableWidgetItem();
            item->setData(Qt::EditRole, static_cast<long long>(ta->allBookings[i]->getTid()));
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            table->setItem(r, 3, item);

            r++; // increment row
        }

        // Nach Buchungsnummer aufsteigend sortieren (default)
        table->sortItems(0, Qt::AscendingOrder); // (<Spalte>, <Verfahren>)

        // Manuelles bzw. nachträgliches Sortieren erlauben (durch Klicken auf entsprechenden Header)
        table->setSortingEnabled(true);

    }



// SET TABLE HEADER

    void MainWindow::generateTableHeader()
    {
        QTableWidget* table = ui->tableWidget;

        // Spalten
        table->setHorizontalHeaderLabels(
            QStringList() << "BuchungsNr." << "Preis" << "Kunde" << "ReiseNr."
        );

        // Aussehen
        QString headerStyle = "QHeaderView::section {"
                "background-color: #bbbbbb;"
                "color: black;"
                "border-bottom: 2px solid black;"
                "text-align: left;"
                "padding-left: 5px;"
                "font-family: Segoe UI;"
                "font-size: 9pt;"
                "font-weight: bold; }";


        table->horizontalHeader()->setStyleSheet(headerStyle);

    }



    // EVENT: TABLECELL_CLICKED

    void MainWindow::on_tableWidget_cellClicked(int row, int column)
    {
        // Zeiger auf notwendige Elemente des UI's
        QTableWidget* table = ui->tableWidget;
        QLineEdit* textBookingNr = ui->textBookingId;
        QCalendarWidget* calFrom = ui->calendarFrom;
        QCalendarWidget* calTo = ui->calendarTo;
        QDoubleSpinBox* spinBoxPrice = ui->spinBoxPrice;
        QSpinBox* spinBoxTravel = ui->spinBoxTravel;
        QLineEdit* textCustomer = ui->textCustomer;
        QStackedWidget* stackedDetailsWidget = ui->stackedDetailsWidget;

        // Get BookingID
        QString bid = table->item(row, 0)->text();
        long bid_l = bid.toLong();

        // Get Booking Element
        Booking* b = ta->findBooking(bid_l);

        // Show StackedDetailsWidget
        stackedDetailsWidget->show();

        // Show Details
        textBookingNr->setText(bid);
        calFrom->setSelectedDate(b->getQDateFrom());
        calTo->setSelectedDate(b->getQDateTo());
        spinBoxPrice->setValue(b->getPrice());
        spinBoxTravel->setValue(b->getTid());
        textCustomer->setText(ta->getCustomer(b)->getQName());

        // Show specific Details
        if(FlightBooking* fb = dynamic_cast<FlightBooking*>(b)) {
            stackedDetailsWidget->setCurrentIndex(0);
            ui->textAirline->setText(fb->getQAirline());
            ui->textDeparture->setText(fb->getQFromDest());
            ui->textArrival->setText(fb->getQToDest());
            ui->textSeatPref->setText(QString::fromStdString(fb->showDetails()));
        } else if(HotelBooking* hb = dynamic_cast<HotelBooking*>(b)) {
            stackedDetailsWidget->setCurrentIndex(1);
            ui->textHotel->setText(hb->getQHotel());
            ui->textCity->setText(hb->getQTown());
            ui->textSmoke->setText(QString::fromStdString(hb->showDetails()));
        } else if(RentalCarReservation* rcr = dynamic_cast<RentalCarReservation*>(b)) {
            stackedDetailsWidget->setCurrentIndex(2);
            ui->textCompany->setText(rcr->getQCompany());
            ui->textPickupLoc->setText(rcr->getQPickupLocation());
            ui->textReturnLoc->setText(rcr->getQReturnLocation());
            ui->textInsurance->setText(QString::fromStdString(rcr->showDetails()));
        } else {
            stackedDetailsWidget->hide();
        }

    }



// ==================================================== GETTER/SETTER ====================================================



    string MainWindow::getTmpNewBooking_Var3() const
    {
        return tmpNewBooking_Var3;
    }

    void MainWindow::setTmpNewBooking_Var3(const string &value)
    {
        tmpNewBooking_Var3 = value;
    }

    string MainWindow::getTmpNewBooking_Var2() const
    {
        return tmpNewBooking_Var2;
    }

    void MainWindow::setTmpNewBooking_Var2(const string &value)
    {
        tmpNewBooking_Var2 = value;
    }

    string MainWindow::getTmpNewBooking_Var1() const
    {
        return tmpNewBooking_Var1;
    }

    void MainWindow::setTmpNewBooking_Var1(const string &value)
    {
        tmpNewBooking_Var1 = value;
    }

    string MainWindow::getTmpNewBooking_DateTo() const
    {
        return tmpNewBooking_DateTo;
    }

    void MainWindow::setTmpNewBooking_DateTo(const string &value)
    {
        tmpNewBooking_DateTo = value;
    }

    string MainWindow::getTmpNewBooking_DateFrom() const
    {
        return tmpNewBooking_DateFrom;
    }

    void MainWindow::setTmpNewBooking_DateFrom(const string &value)
    {
        tmpNewBooking_DateFrom = value;
    }

    double MainWindow::getTmpNewBooking_Price() const
    {
        return tmpNewBooking_Price;
    }

    void MainWindow::setTmpNewBooking_Price(double value)
    {
        tmpNewBooking_Price = value;
    }

    long MainWindow::getTmpNewBooking_TravelId() const
    {
        return tmpNewBooking_TravelId;
    }

    void MainWindow::setTmpNewBooking_TravelId(long value)
    {
        tmpNewBooking_TravelId = value;
    }

    char MainWindow::getTmpNewBooking_Bookingtype() const
    {
        return tmpNewBooking_Bookingtype;
    }

    void MainWindow::setTmpNewBooking_Bookingtype(char value)
    {
        tmpNewBooking_Bookingtype = value;
    }
