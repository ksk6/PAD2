#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "travelagency.h"
#include <qmessagebox.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionProgramm_beenden_triggered()
{
    this->~MainWindow();
}

void MainWindow::on_actionDatei_einlesen_triggered()
{
    TravelAgency ta;
    ta.readFile();

    QMessageBox msgBox;
    QString result = "Es wurden " + QString::number(ta.getAllBooking().size()) + " Buchungen, " + QString::number(ta.getAllCustomers().size()) +
            " Kunden und "  + QString::number(ta.getAllTravels().size()) + " Reisen im Gesamtwert von " + QString::number(ta.getTotalPrice()) +
            " eingelesen";
    msgBox.setText(result);
    msgBox.exec();
    QTableWidgetItem data ("hi");
    //Spalten
    int columnCount = 4;
    ui->tWOverview->setColumnCount(columnCount);
    //Zeilen
    int rowCount = int(ta.getAllBooking().size());
    ui->tWOverview->setRowCount(rowCount);
    //Erste Spalte mit Buchungsnummern füllen
    for(int y = 0; y < rowCount; y++)
    {
        for(int x = 0; x < columnCount; x++){
            string buchungsnr = to_string(ta.getAllBooking().at(y)->getId());
            ui->tWOverview->setItem(y, Buchungsnummer, new QTableWidgetItem(buchungsnr.c_str()));
            string price = to_string(ta.getAllBooking().at(y)->getPrice());
            ui->tWOverview->setItem(y, Preis, new QTableWidgetItem(price.c_str()));
            //Kundenname herausfinden
            for(Customer *c : ta.getAllCustomers())
            {
                if(c->getId() == ta.getAllBooking().at(y)->getTravelId())
                {
                    string name = c->getName();
                    ui->tWOverview->setItem(y, Kunde, new QTableWidgetItem(name.c_str()));
                }
            }

            string travelid = to_string(ta.getAllBooking().at(y)->getTravelId());
            ui->tWOverview->setItem(y, Reisenummer, new QTableWidgetItem(travelid.c_str()));


        }

    }

}

void MainWindow::on_tWOverview_cellDoubleClicked(int row, int column)
{
    //ui->tWOverview->s
}
