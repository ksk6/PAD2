#ifndef CHECKDIALOG_H
#define CHECKDIALOG_H



#include <QDialog>

#include "travelagency.h"



namespace Ui {
class CheckDialog;
}



class CheckDialog : public QDialog
{
    Q_OBJECT

public:

    explicit CheckDialog(QWidget *parent = nullptr);
    ~CheckDialog(); 

    void setTravelAgency(TravelAgency *ta);

    void checkTravelsAndFillTable();


private slots:
    void on_btnClose_clicked();

private:

    Ui::CheckDialog *ui;

    TravelAgency *ta;

    void generateTableHeader();

};



#endif // CHECKDIALOG_H
