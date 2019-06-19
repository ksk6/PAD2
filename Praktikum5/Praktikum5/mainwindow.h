#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include "travelagency.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"



namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    char getTmpNewBooking_Bookingtype() const;
    void setTmpNewBooking_Bookingtype(char value);
    long getTmpNewBooking_TravelId() const;
    void setTmpNewBooking_TravelId(long value);
    double getTmpNewBooking_Price() const;
    void setTmpNewBooking_Price(double value);
    string getTmpNewBooking_DateFrom() const;
    void setTmpNewBooking_DateFrom(const string &value);
    string getTmpNewBooking_DateTo() const;
    void setTmpNewBooking_DateTo(const string &value);
    string getTmpNewBooking_Var1() const;
    void setTmpNewBooking_Var1(const string &value);
    string getTmpNewBooking_Var2() const;
    void setTmpNewBooking_Var2(const string &value);
    string getTmpNewBooking_Var3() const;
    void setTmpNewBooking_Var3(const string &value);

private slots:
    void on_actionImport_triggered();
    void on_actionClose_triggered();
    void on_tableWidget_cellClicked(int row, int column);
    void on_actionExport_triggered();
    void on_actionAddBooking_triggered();

    // cross window signal slots
    void receive_DataFB(double price, long tid, QDate dateFrom, QDate dateTo,
                        QString departure, QString arrival, QString airline, char seatPref, vector<string> arcs);

    void receive_DataHB(double price, long tid, QDate dateFrom, QDate dateTo,
                        QString hotel, QString town, bool smoke, vector<string> arcs);

    void receive_DataRCR(double price, long travelId, QDate start, QDate end,
                         QString pickupLocation, QString returnLocation, QString company, QString insuranceType, vector<string> arcs);


    void on_actionSpeichern_als_triggered();

    void on_actionPruefen_triggered();

private:
    Ui::MainWindow *ui;
    TravelAgency* ta;

    void reloadTable();
    void generateTableHeader();

    // Temporäre Daten für eine neue Buchung
    char tmpNewBooking_Bookingtype;
    long tmpNewBooking_TravelId;
    double tmpNewBooking_Price;
    string
        tmpNewBooking_DateFrom,
        tmpNewBooking_DateTo,
        tmpNewBooking_Var1,
        tmpNewBooking_Var2,
        tmpNewBooking_Var3;

};

#endif // MAINWINDOW_H
