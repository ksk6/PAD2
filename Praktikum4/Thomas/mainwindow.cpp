#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>
#include <newbooking.h>
#include <booking.h>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ta = new TravelAgency;
    this->setWindowTitle("Reiseverwaltung");
    ui->gBAdditionalInformation->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ta;
    delete ui;
}

void MainWindow::ReloadData(){
    //Spalten
    int columnCount = 4;
    ui->tWOverview->setColumnCount(columnCount);
    //Zeilen
    int rowCount = int(ta->getAllBooking().size());
    ui->tWOverview->setRowCount(rowCount);

    for(int y = 0; y < rowCount; y++)
    {
        string buchungsnr = to_string(ta->getAllBooking().at(y)->getId());
        ui->tWOverview->setItem(y, Buchungsnummer, new QTableWidgetItem(buchungsnr.c_str()));
        double d_price = ta->getAllBooking().at(y)->getPrice();

        QString q_price = QString::number(d_price);
        ui->tWOverview->setItem(y, Preis, new QTableWidgetItem(q_price));
        string travelid = to_string(ta->getAllBooking().at(y)->getTravelId());
        ui->tWOverview->setItem(y, Reisenummer, new QTableWidgetItem(travelid.c_str()));

        //Kundenname herausfinden
        for(Customer *c : ta->getAllCustomers())
        {
            for(Travel *CusTravel : c->getTravelList())
            {
                if(ta->getAllBooking().at(y)->getTravelId() == CusTravel->getId())
                {
                    string name = c->getName();
                    ui->tWOverview->setItem(y, Kunde, new QTableWidgetItem(name.c_str()));
                }
            }
        }
    }
}

void MainWindow::on_actionProgramm_beenden_triggered()
{
    this->~MainWindow();
}

void MainWindow::on_actionDatei_einlesen_triggered()
{
    delete ta;
    ta = new TravelAgency;
    bool successfull = ta->readFile();
    if(successfull == true){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Einleseergebnis");
        QString result = "Es wurden " + QString::number(ta->getAllBooking().size()) + " Buchungen, " + QString::number(ta->getAllCustomers().size()) +
                " Kunden und "  + QString::number(ta->getAllTravels().size()) + " Reisen im Gesamtwert von " + QString::number(ta->getTotalPrice()) +
                " eingelesen";
        msgBox.setText(result);
        msgBox.exec();
        ReloadData();
    }

}

void MainWindow::on_tWOverview_cellDoubleClicked(int row, int column)
{
    ui->gBAdditionalInformation->setVisible(true);
    Booking *b = ta->getAllBooking().at(unsigned (row));
    ui->lEBuchungsnummer->setText(QString::number(b->getId()));

    //To Date
    QString QStringToDate =  QString::fromStdString(b->getToDate());
    QDate ToDate = QDate::fromString(QStringToDate,"yyyyMMdd");
    ui->cWBis->setSelectedDate(ToDate);

    //From Date
    QString QStringFromDate = QString::fromStdString(b->getFromDate());
    QDate FromDate = QDate::fromString(QStringFromDate,"yyyyMMdd");
    ui->cWVon->setSelectedDate(FromDate);
    ui->sBTravel->setValue(b->getTravelId());

    double price = b->getPrice();

    QString q_price = QString::number(price);
    ui->dSBPrice->setValue(b->getPrice());

    Travel *t = ta->findTravel(b->getTravelId());
    Customer *c = ta->findCustomer(t->getCustomerID());
    ui->lECustomer->setText(QString::fromStdString(c->getName()));

    if(b->getType() == 'F'){
        //GUI Beschriftung anpassen
        ui->gBAdditionalInformation->setTitle("Flugdetails");
        ui->lblAdditional1->setText("Startflughafen");
        ui->lblAdditional2->setText("Zielflughafen");
        ui->lblAdditional3->setText("Airline");
        ui->lblAdditional4->setText("Sitzplatz");
        ui->lblAdditional3->setVisible(true);
        ui->lblAdditional4->setVisible(true);
        ui->lEAdditional3->setVisible(true);
        ui->lEAdditional4->setVisible(true);

        //Conversation from booking to flightbooking
        FlightBooking* f = dynamic_cast<FlightBooking*>(b);

        //Load Data
        ui->lEAdditional1->setText(QString::fromStdString(f->getFromDest()));
        ui->lEAdditional2->setText(QString::fromStdString(f->getToDest()));
        ui->lEAdditional3->setText(QString::fromStdString(f->getAirline()));
        ui->lEAdditional4->setText(QString::fromStdString(f->showDetails()));
        //delete f;
    }else if(b->getType() == 'H'){
        //GUI Beschriftung anpassen
        ui->gBAdditionalInformation->setTitle("Hoteldetails");
        ui->lblAdditional1->setText("Hotel");
        ui->lblAdditional2->setText("Stadt");
        ui->lblAdditional3->setVisible(true);
        ui->lblAdditional4->setVisible(false);
        ui->lEAdditional3->setVisible(false);
        ui->lEAdditional4->setVisible(false);

        //Conversation from booking to hotelbooking
        HotelBooking* h = dynamic_cast<HotelBooking*>(b);

        //Load Data
        ui->lEAdditional1->setText(QString::fromStdString(h->getHotel()));
        ui->lEAdditional2->setText(QString::fromStdString(h->getTown()));
        ui->lblAdditional3->setText(QString::fromStdString(h->showDetails()));
        //h->HotelBooking::~HotelBooking();
        //delete h;
    }else if(b->getType() == 'R'){
        //GUI Beschriftung anpassen
        ui->gBAdditionalInformation->setTitle("Mietwagendetails");
        ui->lblAdditional1->setText("Autovermietung");
        ui->lblAdditional2->setText("Abholstation");
        ui->lblAdditional3->setText("Rueckgabestation");
        ui->lblAdditional4->setText("Versicherung");
        ui->lblAdditional3->setVisible(true);
        ui->lblAdditional4->setVisible(true);
        ui->lEAdditional3->setVisible(true);
        ui->lEAdditional4->setVisible(true);

        //Conversation from booking to rentalcarreservation
        RentalCarReservation* r = dynamic_cast<RentalCarReservation*>(b);

        //Load Data
        ui->lEAdditional1->setText(QString::fromStdString(r->getCompany()));
        ui->lEAdditional2->setText(QString::fromStdString(r->getPickupLocation()));
        ui->lEAdditional3->setText(QString::fromStdString(r->getReturnLocation()));
        ui->lEAdditional4->setText(QString::fromStdString(r->showDetails()));
        //delete r;
    }
}

void MainWindow::on_actionNeue_Buchung_anlegen_triggered()
{
    NewBooking newbooking(this, ta);
    newbooking.setModal(true);
    newbooking.exec();
    ReloadData();
}

void MainWindow::on_actionDatei_speichern_triggered()
{
    QString filename = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("Name der Datei:"), QLineEdit::Normal);
    filename += ".txt";
    ta->writeFile(filename);
}
