#ifndef NEWBOOKING_H
#define NEWBOOKING_H
#include <QDialog>
#include <QAbstractButton>
#include "travelagency.h"

namespace Ui {
class NewBooking;
}

class NewBooking : public QDialog
{
    Q_OBJECT

public:
    explicit NewBooking(QWidget *parent = nullptr, TravelAgency* t = nullptr);
    ~NewBooking();
    //NewBooking(TravelAgency ta);
    vector<QString> ReturnData() const;
    vector<QString>* data;
    TravelAgency* ta;

private slots:
    void on_cBBuchungstyp_currentIndexChanged(const QString &arg1);
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::NewBooking *ui;

};

#endif // NEWBOOKING_H
