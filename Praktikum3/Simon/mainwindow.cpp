#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>
#include <newbooking.h>
#include <booking.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ta = new TravelAgency;
    this->setWindowTitle("Reiseverwaltung");
}
//TravelAgency ta;

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
    //Erste Spalte mit Buchungsnummern füllen

    for(int y = 0; y < rowCount; y++)
    {
        string buchungsnr = to_string(ta->getAllBooking().at(y)->getId());
        ui->tWOverview->setItem(y, Buchungsnummer, new QTableWidgetItem(buchungsnr.c_str()));
        string price = to_string(ta->getAllBooking().at(y)->getPrice());
        ui->tWOverview->setItem(y, Preis, new QTableWidgetItem(price.c_str()));
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
    ta->readFile();
    QMessageBox msgBox;
    msgBox.setWindowTitle("Einleseergebnis");
    QString result = "Es wurden " + QString::number(ta->getAllBooking().size()) + " Buchungen, " + QString::number(ta->getAllCustomers().size()) +
            " Kunden und "  + QString::number(ta->getAllTravels().size()) + " Reisen im Gesamtwert von " + QString::number(ta->getTotalPrice()) +
            " eingelesen";
    msgBox.setText(result);
    msgBox.exec();
    ReloadData();

}

void MainWindow::on_tWOverview_cellDoubleClicked(int row, int column)
{
    Booking *b = ta->getAllBooking().at(unsigned (row));
    //QString id = QString::number(ta.getAllBooking().at(row)->getId());
    ui->lEBuchungsnummer->setText(QString::number(b->getId()));


    //To Date
    QString test = QString::fromStdString("Test");
    //string todate = b->getToDate().c_str();
    QString QStringToDate =  QString::fromStdString(b->getToDate());
    QDate ToDate = QDate::fromString(QStringToDate,"yyyyMMdd");
    ui->cWBis->setSelectedDate(ToDate);

    //From Date
    QString QStringFromDate = QString::fromStdString(b->getFromDate());
    QDate FromDate = QDate::fromString(QStringFromDate,"yyyyMMdd");
    ui->cWVon->setSelectedDate(FromDate);

    delete b;
}

void MainWindow::on_actionNeue_Buchung_anlegen_triggered()
{
    NewBooking newbooking(this, ta);
    newbooking.setModal(true);
    newbooking.exec();
    ReloadData();
}
