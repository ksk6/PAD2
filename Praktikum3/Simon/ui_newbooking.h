/********************************************************************************
** Form generated from reading UI file 'newbooking.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWBOOKING_H
#define UI_NEWBOOKING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_NewBooking
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *lblPreis;
    QLabel *lblReiseID;
    QLabel *lblStart;
    QLabel *lblEnde;
    QLabel *lblBuchungstyp;
    QLabel *lblBookingDetail1;
    QLabel *lblBookingDetail2;
    QLabel *lblBookingDetail3;
    QDoubleSpinBox *SBPreis;
    QSpinBox *SBReiseID;
    QDateEdit *DEStart;
    QDateEdit *DEEnde;
    QComboBox *cBBuchungstyp;
    QLineEdit *lEBookingDetail1;
    QLineEdit *lEBookingDetail2;
    QLineEdit *lEBookingDetail3;
    QLabel *lblBookingDetail4;
    QLineEdit *lEBookingDetail4;
    QCheckBox *cBBookingDetail5;
    QComboBox *cBSeat;

    void setupUi(QDialog *NewBooking)
    {
        if (NewBooking->objectName().isEmpty())
            NewBooking->setObjectName(QStringLiteral("NewBooking"));
        NewBooking->resize(270, 354);
        buttonBox = new QDialogButtonBox(NewBooking);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-90, 290, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lblPreis = new QLabel(NewBooking);
        lblPreis->setObjectName(QStringLiteral("lblPreis"));
        lblPreis->setGeometry(QRect(10, 20, 47, 13));
        lblReiseID = new QLabel(NewBooking);
        lblReiseID->setObjectName(QStringLiteral("lblReiseID"));
        lblReiseID->setGeometry(QRect(10, 50, 47, 13));
        lblStart = new QLabel(NewBooking);
        lblStart->setObjectName(QStringLiteral("lblStart"));
        lblStart->setGeometry(QRect(10, 70, 61, 16));
        lblEnde = new QLabel(NewBooking);
        lblEnde->setObjectName(QStringLiteral("lblEnde"));
        lblEnde->setGeometry(QRect(10, 100, 47, 13));
        lblBuchungstyp = new QLabel(NewBooking);
        lblBuchungstyp->setObjectName(QStringLiteral("lblBuchungstyp"));
        lblBuchungstyp->setGeometry(QRect(10, 130, 71, 16));
        lblBookingDetail1 = new QLabel(NewBooking);
        lblBookingDetail1->setObjectName(QStringLiteral("lblBookingDetail1"));
        lblBookingDetail1->setGeometry(QRect(10, 160, 81, 16));
        lblBookingDetail2 = new QLabel(NewBooking);
        lblBookingDetail2->setObjectName(QStringLiteral("lblBookingDetail2"));
        lblBookingDetail2->setGeometry(QRect(10, 190, 71, 16));
        lblBookingDetail3 = new QLabel(NewBooking);
        lblBookingDetail3->setObjectName(QStringLiteral("lblBookingDetail3"));
        lblBookingDetail3->setGeometry(QRect(10, 220, 91, 16));
        SBPreis = new QDoubleSpinBox(NewBooking);
        SBPreis->setObjectName(QStringLiteral("SBPreis"));
        SBPreis->setGeometry(QRect(90, 10, 161, 22));
        SBReiseID = new QSpinBox(NewBooking);
        SBReiseID->setObjectName(QStringLiteral("SBReiseID"));
        SBReiseID->setGeometry(QRect(90, 40, 161, 22));
        DEStart = new QDateEdit(NewBooking);
        DEStart->setObjectName(QStringLiteral("DEStart"));
        DEStart->setGeometry(QRect(90, 70, 161, 22));
        DEEnde = new QDateEdit(NewBooking);
        DEEnde->setObjectName(QStringLiteral("DEEnde"));
        DEEnde->setGeometry(QRect(90, 100, 161, 22));
        cBBuchungstyp = new QComboBox(NewBooking);
        cBBuchungstyp->addItem(QString());
        cBBuchungstyp->addItem(QString());
        cBBuchungstyp->addItem(QString());
        cBBuchungstyp->setObjectName(QStringLiteral("cBBuchungstyp"));
        cBBuchungstyp->setGeometry(QRect(90, 130, 161, 22));
        lEBookingDetail1 = new QLineEdit(NewBooking);
        lEBookingDetail1->setObjectName(QStringLiteral("lEBookingDetail1"));
        lEBookingDetail1->setGeometry(QRect(90, 160, 161, 20));
        lEBookingDetail2 = new QLineEdit(NewBooking);
        lEBookingDetail2->setObjectName(QStringLiteral("lEBookingDetail2"));
        lEBookingDetail2->setGeometry(QRect(90, 190, 161, 20));
        lEBookingDetail3 = new QLineEdit(NewBooking);
        lEBookingDetail3->setObjectName(QStringLiteral("lEBookingDetail3"));
        lEBookingDetail3->setGeometry(QRect(90, 220, 161, 20));
        lblBookingDetail4 = new QLabel(NewBooking);
        lblBookingDetail4->setObjectName(QStringLiteral("lblBookingDetail4"));
        lblBookingDetail4->setGeometry(QRect(10, 250, 47, 13));
        lEBookingDetail4 = new QLineEdit(NewBooking);
        lEBookingDetail4->setObjectName(QStringLiteral("lEBookingDetail4"));
        lEBookingDetail4->setGeometry(QRect(90, 250, 161, 20));
        cBBookingDetail5 = new QCheckBox(NewBooking);
        cBBookingDetail5->setObjectName(QStringLiteral("cBBookingDetail5"));
        cBBookingDetail5->setGeometry(QRect(90, 220, 70, 17));
        cBSeat = new QComboBox(NewBooking);
        cBSeat->addItem(QString());
        cBSeat->addItem(QString());
        cBSeat->addItem(QString());
        cBSeat->addItem(QString());
        cBSeat->addItem(QString());
        cBSeat->addItem(QString());
        cBSeat->setObjectName(QStringLiteral("cBSeat"));
        cBSeat->setGeometry(QRect(90, 250, 161, 22));

        retranslateUi(NewBooking);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewBooking, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewBooking, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewBooking);
    } // setupUi

    void retranslateUi(QDialog *NewBooking)
    {
        NewBooking->setWindowTitle(QApplication::translate("NewBooking", "Dialog", nullptr));
        lblPreis->setText(QApplication::translate("NewBooking", "Preis", nullptr));
        lblReiseID->setText(QApplication::translate("NewBooking", "Reise-ID", nullptr));
        lblStart->setText(QApplication::translate("NewBooking", "Stardatum", nullptr));
        lblEnde->setText(QApplication::translate("NewBooking", "Enddatum", nullptr));
        lblBuchungstyp->setText(QApplication::translate("NewBooking", "Buchungstyp", nullptr));
        lblBookingDetail1->setText(QApplication::translate("NewBooking", "Startflughafen", nullptr));
        lblBookingDetail2->setText(QApplication::translate("NewBooking", "Zielflughafen", nullptr));
        lblBookingDetail3->setText(QApplication::translate("NewBooking", "Airline", nullptr));
        cBBuchungstyp->setItemText(0, QApplication::translate("NewBooking", "Flugbuchung", nullptr));
        cBBuchungstyp->setItemText(1, QApplication::translate("NewBooking", "Hotelbuchung", nullptr));
        cBBuchungstyp->setItemText(2, QApplication::translate("NewBooking", "Mietwagenbuchung", nullptr));

        lblBookingDetail4->setText(QApplication::translate("NewBooking", "Sitzplatz", nullptr));
        cBBookingDetail5->setText(QString());
        cBSeat->setItemText(0, QApplication::translate("NewBooking", "A", nullptr));
        cBSeat->setItemText(1, QApplication::translate("NewBooking", "B", nullptr));
        cBSeat->setItemText(2, QApplication::translate("NewBooking", "C", nullptr));
        cBSeat->setItemText(3, QApplication::translate("NewBooking", "D", nullptr));
        cBSeat->setItemText(4, QApplication::translate("NewBooking", "E", nullptr));
        cBSeat->setItemText(5, QApplication::translate("NewBooking", "F", nullptr));

    } // retranslateUi

};

namespace Ui {
    class NewBooking: public Ui_NewBooking {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWBOOKING_H
