#include "addbookingdialog.h"
#include "ui_addbookingdialog.h"
#include <QPushButton>

#include <iostream>



using namespace std;



AddBookingDialog::AddBookingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBookingDialog)
{
    ui->setupUi(this);
}

AddBookingDialog::~AddBookingDialog()
{
    delete ui;
}

void AddBookingDialog::on_buttonOK_clicked()
{
    QString arc1, arc2;
    vector<string> arcs;

    if((arc1 = ui->inputArc1->text()) != "") {
        arcs.push_back(arc1.toStdString());
    }
    if((arc2 = ui->inputArc2->text()) != "") {
        arcs.push_back(arc2.toStdString());
    }

    switch(ui->inputBookingtype->currentIndex()) {
        case 0: { // FLIGHTBOOKING

            char seatPref;
            if(ui->inputSeatPref->currentIndex()) {
                seatPref = 'A';
            } else {
                seatPref = 'W';
            }

            emit send_DataFB(
                ui->inputPrice->value(),
                ui->inputTravelId->value(),
                ui->inputDateFrom->date(),
                ui->inputDateTo->date(),
                ui->inputDeparture->text(),
                ui->inputArrival->text(),
                ui->inputAirline->text(),
                seatPref,
                arcs
            );

            break;
        }
        case 1: { // HOTELBOOKING
            emit send_DataHB(
                ui->inputPrice->value(),
                ui->inputTravelId->value(),
                ui->inputDateFrom->date(),
                ui->inputDateTo->date(),
                ui->inputHotel->text(),
                ui->inputTown->text(),
                ui->inputSmoke->isChecked(),
                arcs
            );

            break;
        }
        case 2: { // RENTALCARRESERVATION
            emit send_DataRCR(
                ui->inputPrice->value(),
                ui->inputTravelId->value(),
                ui->inputDateFrom->date(),
                ui->inputDateTo->date(),
                ui->inputPickupLocation->text(),
                ui->inputReturnLocation->text(),
                ui->inputCompany->text(),
                ui->inputInsuranceType->text(),
                arcs
            );

            break;
        }
    }

    close();
}

void AddBookingDialog::on_buttonReject_clicked()
{
    close();
}

void AddBookingDialog::on_inputBookingtype_currentIndexChanged(int index)
{
    ui->stackedDetailsWidget->setCurrentIndex(index);
}
