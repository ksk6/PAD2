#include "checkdialog.h"
#include "ui_checkdialog.h"



CheckDialog::CheckDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckDialog)
{
    ui->setupUi(this);

    // Einstellungen für die Tabelle
    QTableWidget* table = ui->tableTravelChecks;
    table->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded); // Vertical Scrollbar as needed
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Horizontal Scrollbar off
    table->setSelectionBehavior(QAbstractItemView::SelectRows); // Selektieren ganzer Zeilen
    table->verticalHeader()->setVisible(false); // Ausblenden des vertikalen Headers
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // Spaltenbreite automatisch anpassen
    table->setSortingEnabled(false); // Sortieren verbieten (wird nach dem Füllen der Tabelle aktiviert. Grund: Vermeiden von Fehlern beim Füllen)!
}



CheckDialog::~CheckDialog()
{
    delete ui;
}



void CheckDialog::setTravelAgency(TravelAgency *ta)
{
    this->ta = ta;
}



void CheckDialog::checkTravelsAndFillTable()
{
    QTableWidget* table = ui->tableTravelChecks;

    // Table leeren und Sortieren verbieten
    table->clear();
    table->setSortingEnabled(false); // Wird deaktiviert um Fehler zu vermeiden (ist nötig! wird nach dem Füllen aktiviert)

    // Header generieren
    generateTableHeader();

    // Zeilen erstellen
    table->setRowCount(ta->allTravels.size());

    // Zeiger auf ein TableWidgetItem
    QTableWidgetItem* item;


    // TABELLE FÜLLEN
    // Loop durch alle Travels (sind vorsortiert)
    for(int i = 0; i < ta->allTravels.size(); i++) {
        Travel *t = ta->allTravels[i];

        // Spalte 1 (Reise)
        item = new QTableWidgetItem();
        item->setBackgroundColor("grey");
        item->setData(Qt::EditRole, static_cast<long long>(t->getTid()));
        item->setFlags(item->flags() ^ Qt::ItemIsEditable); // Edititieren der Zelle verbieten
        table->setItem(i, 0, item); // Setzen der Zelle an die richtige Stelle (Zeile/Spalte)

        // Spalte 2 (Fehlendes Hotel)
        item = new QTableWidgetItem();
        if(t->checkMissingHotel()) { item->setBackgroundColor("green"); }
        else { item->setBackgroundColor("red"); }
        item->setData(Qt::EditRole, t->checkMissingHotel());
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        table->setItem(i, 1, item);

        // Spalte 3 (Überflüssiges Hotel)
        item = new QTableWidgetItem();
        if(t->checkNeedlessHotel()) { item->setBackgroundColor("green"); }
        else { item->setBackgroundColor("red"); }
        item->setData(Qt::EditRole, t->checkNeedlessHotel());
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        table->setItem(i, 2, item);

        // Spalte 4 (Überflüssiger Mietwagen)
        item = new QTableWidgetItem();
        if(t->checkNeedlessRentalCar()) { item->setBackgroundColor("green"); }
        else { item->setBackgroundColor("red"); }
        item->setData(Qt::EditRole, t->checkNeedlessRentalCar());
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        table->setItem(i, 3, item);

        // Spalte 5 (Kein Roundtrip)
        item = new QTableWidgetItem();
        if(t->checkRoundtrip()) { item->setBackgroundColor("green"); }
        else { item->setBackgroundColor("red"); }
        item->setData(Qt::EditRole, t->checkRoundtrip());
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        table->setItem(i, 4, item);
    }



    // Nach Buchungsnummer aufsteigend sortieren (default)
    table->sortItems(0, Qt::AscendingOrder); // (<Spalte>, <Verfahren>)

    // Manuelles bzw. nachträgliches Sortieren erlauben (durch Klicken auf entsprechenden Header)
    table->setSortingEnabled(true);
}



void CheckDialog::generateTableHeader()
{
    QTableWidget* table = ui->tableTravelChecks;

    // Spalten
    table->setHorizontalHeaderLabels(
        QStringList() << "Reise" << "Fehlendes Hotel" << "Überflüssiges Hotel" << "Überflüssiger Mietwagen" << "Kein Roundtrip"
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



void CheckDialog::on_btnClose_clicked()
{
    close();
}
