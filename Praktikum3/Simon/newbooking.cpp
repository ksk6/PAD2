#include "newbooking.h"
#include "ui_newbooking.h"
#include "qmessagebox.h"
#include <iostream>
#include <string>

NewBooking::NewBooking(QWidget *parent, TravelAgency* t) :
    QDialog(parent),
    ui(new Ui::NewBooking)
{
    ui->setupUi(this);
    this->ta=t;
    this->setWindowTitle("Neue Buchung hinzufügen");
    ui->cBBookingDetail5->setVisible(false);
    ui->lEBookingDetail4->setEnabled(false);
    ui->lEBookingDetail4->setVisible(false);
}

NewBooking::~NewBooking()
{
    delete ui;
}

void NewBooking::on_cBBuchungstyp_currentIndexChanged(const QString &arg1)
{

    if(arg1 == "Hotelbuchung")
    {
        ui->lblBookingDetail1->setText("Hotel");
        ui->lblBookingDetail2->setText("Stadt");
        ui->lblBookingDetail3->setEnabled(true);
        ui->lblBookingDetail3->setText("Raucher?");
        ui->lEBookingDetail3->setEnabled(false);
        ui->lEBookingDetail3->setVisible(false);
        ui->lblBookingDetail3->setVisible(true);
        ui->lEBookingDetail4->setEnabled(false);
        ui->lEBookingDetail4->setVisible(false);
        ui->lblBookingDetail4->setVisible(false);
        ui->cBBookingDetail5->setVisible(true);
        ui->cBBookingDetail5->setEnabled(true);
        ui->cBSeat->setVisible(false);
        ui->cBSeat->setEnabled(false);
    }else if(arg1 == "Flugbuchung")
    {
        ui->lblBookingDetail1->setText("Startflughafen");
        ui->lblBookingDetail2->setText("Zielflughafen");
        ui->lblBookingDetail3->setText("Airline");
        ui->lblBookingDetail4->setText("Sitzplatz");
        ui->lblBookingDetail4->setVisible(true);
        ui->lblBookingDetail3->setEnabled(true);
        ui->lEBookingDetail3->setEnabled(true);
        ui->lEBookingDetail3->setVisible(true);
        ui->lblBookingDetail3->setVisible(true);
        ui->cBBookingDetail5->setVisible(false);
        ui->cBBookingDetail5->setEnabled(false);
        ui->lEBookingDetail4->setEnabled(false);
        ui->lEBookingDetail4->setVisible(false);
        ui->cBSeat->setEnabled(true);
        ui->cBSeat->setVisible(true);
    }else if(arg1 == "Mietwagenbuchung"){
        ui->lblBookingDetail1->setText("Abholstation");
        ui->lblBookingDetail2->setText("Abgabestation");
        ui->lblBookingDetail3->setText("Firma");
        ui->lblBookingDetail3->setEnabled(true);
        ui->lEBookingDetail3->setEnabled(true);
        ui->lEBookingDetail3->setVisible(true);
        ui->lblBookingDetail3->setVisible(true);
        ui->lblBookingDetail4->setText("Versicherung");
        ui->lEBookingDetail4->setEnabled(true);
        ui->lEBookingDetail4->setVisible(true);
        ui->lblBookingDetail4->setVisible(true);
        ui->cBBookingDetail5->setVisible(false);
        ui->cBSeat->setVisible(false);
        ui->cBSeat->setEnabled(false);
    }
}
vector<QString> NewBooking::ReturnData() const
{
    //char type, double price, string start, string end, long travelID, vector<string> bookingDetails
    //vector<QString> data;

    if(ui->cBBuchungstyp->itemData(ui->cBBuchungstyp->currentIndex()) == "Flugbuchung"){
        this->data->push_back("F");
        this->data->push_back(ui->lEBookingDetail1->text());
        this-> data->push_back(ui->lEBookingDetail2->text());
        this->data->push_back(ui->lEBookingDetail3->text());
    }else if(ui->cBBuchungstyp->itemData(ui->cBBuchungstyp->currentIndex()) == "Hotelbuchung"){
        this->data->push_back("H");
        this->data->push_back(ui->lEBookingDetail1->text());
        this->data->push_back(ui->lEBookingDetail2->text());
    }else{
        this->data->push_back("R");
        this->data->push_back(ui->lEBookingDetail1->text());
        this->data->push_back(ui->lEBookingDetail2->text());
        this->data->push_back(ui->lEBookingDetail3->text());
    }
    this->data->push_back(ui->SBPreis->text());
    this->data->push_back(ui->DEStart->text());
    this->data->push_back(ui->DEEnde->text());
    this->data->push_back(ui->SBReiseID->text());

    return *this->data;
}
void NewBooking::on_buttonBox_accepted()
{
    vector<string> bookingData;
    int created = -1;
    if(ui->cBBuchungstyp->itemData(ui->cBBuchungstyp->currentIndex()) == "Flugbuchung"){
        bookingData.push_back(ui->lEBookingDetail1->text().toStdString());
        bookingData.push_back(ui->lEBookingDetail2->text().toStdString());
        bookingData.push_back(ui->lEBookingDetail3->text().toStdString());
        created = ta->createBooking('f', ui->SBPreis->text().toDouble(), ui->DEStart->text().toStdString(), ui->DEEnde->text().toStdString(), ui->SBReiseID->text().toLong(), bookingData);
    }else if(ui->cBBuchungstyp->itemData(ui->cBBuchungstyp->currentIndex()) == "Hotelbuchung"){
        bookingData.push_back(ui->lEBookingDetail1->text().toStdString());
        bookingData.push_back(ui->lEBookingDetail2->text().toStdString());
        created = ta->createBooking('h', ui->SBPreis->text().toDouble(), ui->DEStart->text().toStdString(), ui->DEEnde->text().toStdString(), ui->SBReiseID->text().toLong(), bookingData);
    }else{
        bookingData.push_back(ui->lEBookingDetail1->text().toStdString());
        bookingData.push_back(ui->lEBookingDetail2->text().toStdString());
        bookingData.push_back(ui->lEBookingDetail3->text().toStdString());
        created = ta->createBooking('r', ui->SBPreis->text().toDouble(), ui->DEStart->text().toStdString(), ui->DEEnde->text().toStdString(), ui->SBReiseID->text().toLong(), bookingData);
    }
    if(created != -1){
        //this->hide();
        this->close();
    }else{
        QMessageBox msgBox;
        msgBox.setWindowTitle("Fehler");
        msgBox.setText("Um eine Buchung anzulegen, muss die jeweilige Reise vorher existieren!");
        msgBox.exec();
    }
}

void NewBooking::on_buttonBox_rejected()
{
    this->hide();
}

void NewBooking::on_buttonBox_clicked(QAbstractButton *button)
{}
