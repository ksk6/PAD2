#ifndef ADDBOOKINGDIALOG_H
#define ADDBOOKINGDIALOG_H

#include <QDialog>
#include <QDate>
#include <QString>
#include <vector>

using namespace std;

namespace Ui {
class AddBookingDialog;
}

class AddBookingDialog : public QDialog
{
    Q_OBJECT

public:

    explicit AddBookingDialog(QWidget *parent = nullptr);
    ~AddBookingDialog();


signals:

    void send_DataFB(double price, long tid, QDate dateFrom, QDate dateTo,
                     QString departure, QString arrival, QString airline, char seatPref,
                     vector<string> arcs);

    void send_DataHB(double price, long tid, QDate dateFrom, QDate dateTo,
                     QString hotel, QString town, bool smoke,
                     vector<string> arcs);

    void send_DataRCR(double price, long travelId, QDate start, QDate end,
                      QString pickupLocation, QString returnLocation, QString company, QString insuranceType,
                      vector<string> arcs);


private slots:

    void on_buttonOK_clicked();
    void on_buttonReject_clicked();

    void on_inputBookingtype_currentIndexChanged(int index);


private:

    Ui::AddBookingDialog *ui;


};

#endif // ADDBOOKINGDIALOG_H
