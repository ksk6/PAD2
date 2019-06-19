/********************************************************************************
** Form generated from reading UI file 'addbookingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOOKINGDIALOG_H
#define UI_ADDBOOKINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddBookingDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelPreis;
    QDoubleSpinBox *inputPrice;
    QLabel *labelTravelId;
    QSpinBox *inputTravelId;
    QLabel *labelDateFrom;
    QDateEdit *inputDateFrom;
    QLabel *labelDateTo;
    QDateEdit *inputDateTo;
    QLabel *labelBookingtype;
    QComboBox *inputBookingtype;
    QStackedWidget *stackedDetailsWidget;
    QWidget *pageFBDetails;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBoxFBDetails;
    QFormLayout *formLayout_2;
    QLabel *labelDeparture;
    QLabel *labelArrival;
    QLabel *labelAirline;
    QLabel *labelSeatPref;
    QComboBox *inputSeatPref;
    QLineEdit *inputAirline;
    QLineEdit *inputArrival;
    QLineEdit *inputDeparture;
    QWidget *pageHBDetails;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBoxHBDetails;
    QFormLayout *formLayout_3;
    QLabel *labelHotel;
    QLabel *labelTown;
    QLabel *labelSmoke;
    QLineEdit *inputHotel;
    QLineEdit *inputTown;
    QCheckBox *inputSmoke;
    QWidget *pageRCRDetails;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBoxRCRDetails;
    QFormLayout *formLayout_4;
    QLabel *labelPickupLoc;
    QLabel *labelReturnLoc;
    QLabel *labelCompany;
    QLabel *labelInsuranceType;
    QLineEdit *inputPickupLocation;
    QLineEdit *inputReturnLocation;
    QLineEdit *inputCompany;
    QLineEdit *inputInsuranceType;
    QLineEdit *inputArc1;
    QLabel *labelArc1;
    QLabel *labelArc2;
    QLineEdit *inputArc2;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonReject;
    QPushButton *buttonOK;

    void setupUi(QDialog *AddBookingDialog)
    {
        if (AddBookingDialog->objectName().isEmpty())
            AddBookingDialog->setObjectName(QString::fromUtf8("AddBookingDialog"));
        AddBookingDialog->resize(400, 424);
        verticalLayout = new QVBoxLayout(AddBookingDialog);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(12, 12, 12, 12);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelPreis = new QLabel(AddBookingDialog);
        labelPreis->setObjectName(QString::fromUtf8("labelPreis"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelPreis);

        inputPrice = new QDoubleSpinBox(AddBookingDialog);
        inputPrice->setObjectName(QString::fromUtf8("inputPrice"));
        inputPrice->setMinimumSize(QSize(0, 25));
        inputPrice->setMaximumSize(QSize(16777215, 25));

        formLayout->setWidget(0, QFormLayout::FieldRole, inputPrice);

        labelTravelId = new QLabel(AddBookingDialog);
        labelTravelId->setObjectName(QString::fromUtf8("labelTravelId"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelTravelId);

        inputTravelId = new QSpinBox(AddBookingDialog);
        inputTravelId->setObjectName(QString::fromUtf8("inputTravelId"));
        inputTravelId->setMinimumSize(QSize(0, 25));
        inputTravelId->setMaximumSize(QSize(16777215, 25));

        formLayout->setWidget(1, QFormLayout::FieldRole, inputTravelId);

        labelDateFrom = new QLabel(AddBookingDialog);
        labelDateFrom->setObjectName(QString::fromUtf8("labelDateFrom"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelDateFrom);

        inputDateFrom = new QDateEdit(AddBookingDialog);
        inputDateFrom->setObjectName(QString::fromUtf8("inputDateFrom"));
        inputDateFrom->setMinimumSize(QSize(0, 25));
        inputDateFrom->setMaximumSize(QSize(16777215, 25));

        formLayout->setWidget(2, QFormLayout::FieldRole, inputDateFrom);

        labelDateTo = new QLabel(AddBookingDialog);
        labelDateTo->setObjectName(QString::fromUtf8("labelDateTo"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelDateTo);

        inputDateTo = new QDateEdit(AddBookingDialog);
        inputDateTo->setObjectName(QString::fromUtf8("inputDateTo"));
        inputDateTo->setMinimumSize(QSize(0, 25));
        inputDateTo->setMaximumSize(QSize(16777215, 25));

        formLayout->setWidget(3, QFormLayout::FieldRole, inputDateTo);

        labelBookingtype = new QLabel(AddBookingDialog);
        labelBookingtype->setObjectName(QString::fromUtf8("labelBookingtype"));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelBookingtype);

        inputBookingtype = new QComboBox(AddBookingDialog);
        inputBookingtype->addItem(QString());
        inputBookingtype->addItem(QString());
        inputBookingtype->addItem(QString());
        inputBookingtype->setObjectName(QString::fromUtf8("inputBookingtype"));
        inputBookingtype->setMinimumSize(QSize(0, 25));
        inputBookingtype->setMaximumSize(QSize(16777215, 25));

        formLayout->setWidget(4, QFormLayout::FieldRole, inputBookingtype);

        stackedDetailsWidget = new QStackedWidget(AddBookingDialog);
        stackedDetailsWidget->setObjectName(QString::fromUtf8("stackedDetailsWidget"));
        pageFBDetails = new QWidget();
        pageFBDetails->setObjectName(QString::fromUtf8("pageFBDetails"));
        verticalLayout_2 = new QVBoxLayout(pageFBDetails);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBoxFBDetails = new QGroupBox(pageFBDetails);
        groupBoxFBDetails->setObjectName(QString::fromUtf8("groupBoxFBDetails"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        groupBoxFBDetails->setFont(font);
        formLayout_2 = new QFormLayout(groupBoxFBDetails);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        labelDeparture = new QLabel(groupBoxFBDetails);
        labelDeparture->setObjectName(QString::fromUtf8("labelDeparture"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelDeparture);

        labelArrival = new QLabel(groupBoxFBDetails);
        labelArrival->setObjectName(QString::fromUtf8("labelArrival"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelArrival);

        labelAirline = new QLabel(groupBoxFBDetails);
        labelAirline->setObjectName(QString::fromUtf8("labelAirline"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, labelAirline);

        labelSeatPref = new QLabel(groupBoxFBDetails);
        labelSeatPref->setObjectName(QString::fromUtf8("labelSeatPref"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, labelSeatPref);

        inputSeatPref = new QComboBox(groupBoxFBDetails);
        inputSeatPref->addItem(QString());
        inputSeatPref->addItem(QString());
        inputSeatPref->setObjectName(QString::fromUtf8("inputSeatPref"));
        inputSeatPref->setMinimumSize(QSize(0, 25));
        inputSeatPref->setMaximumSize(QSize(16777215, 25));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, inputSeatPref);

        inputAirline = new QLineEdit(groupBoxFBDetails);
        inputAirline->setObjectName(QString::fromUtf8("inputAirline"));
        inputAirline->setMinimumSize(QSize(0, 25));
        inputAirline->setMaximumSize(QSize(16777215, 25));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, inputAirline);

        inputArrival = new QLineEdit(groupBoxFBDetails);
        inputArrival->setObjectName(QString::fromUtf8("inputArrival"));
        inputArrival->setMinimumSize(QSize(0, 25));
        inputArrival->setMaximumSize(QSize(16777215, 25));
        inputArrival->setReadOnly(false);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, inputArrival);

        inputDeparture = new QLineEdit(groupBoxFBDetails);
        inputDeparture->setObjectName(QString::fromUtf8("inputDeparture"));
        inputDeparture->setMinimumSize(QSize(0, 25));
        inputDeparture->setMaximumSize(QSize(16777215, 25));
        inputDeparture->setReadOnly(false);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, inputDeparture);


        verticalLayout_2->addWidget(groupBoxFBDetails);

        stackedDetailsWidget->addWidget(pageFBDetails);
        pageHBDetails = new QWidget();
        pageHBDetails->setObjectName(QString::fromUtf8("pageHBDetails"));
        verticalLayout_3 = new QVBoxLayout(pageHBDetails);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBoxHBDetails = new QGroupBox(pageHBDetails);
        groupBoxHBDetails->setObjectName(QString::fromUtf8("groupBoxHBDetails"));
        formLayout_3 = new QFormLayout(groupBoxHBDetails);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        labelHotel = new QLabel(groupBoxHBDetails);
        labelHotel->setObjectName(QString::fromUtf8("labelHotel"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, labelHotel);

        labelTown = new QLabel(groupBoxHBDetails);
        labelTown->setObjectName(QString::fromUtf8("labelTown"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, labelTown);

        labelSmoke = new QLabel(groupBoxHBDetails);
        labelSmoke->setObjectName(QString::fromUtf8("labelSmoke"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, labelSmoke);

        inputHotel = new QLineEdit(groupBoxHBDetails);
        inputHotel->setObjectName(QString::fromUtf8("inputHotel"));
        inputHotel->setMinimumSize(QSize(0, 25));
        inputHotel->setMaximumSize(QSize(16777215, 25));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, inputHotel);

        inputTown = new QLineEdit(groupBoxHBDetails);
        inputTown->setObjectName(QString::fromUtf8("inputTown"));
        inputTown->setMinimumSize(QSize(0, 25));
        inputTown->setMaximumSize(QSize(16777215, 25));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, inputTown);

        inputSmoke = new QCheckBox(groupBoxHBDetails);
        inputSmoke->setObjectName(QString::fromUtf8("inputSmoke"));
        inputSmoke->setMinimumSize(QSize(0, 25));
        inputSmoke->setMaximumSize(QSize(16777215, 25));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, inputSmoke);


        verticalLayout_3->addWidget(groupBoxHBDetails);

        stackedDetailsWidget->addWidget(pageHBDetails);
        pageRCRDetails = new QWidget();
        pageRCRDetails->setObjectName(QString::fromUtf8("pageRCRDetails"));
        verticalLayout_4 = new QVBoxLayout(pageRCRDetails);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBoxRCRDetails = new QGroupBox(pageRCRDetails);
        groupBoxRCRDetails->setObjectName(QString::fromUtf8("groupBoxRCRDetails"));
        formLayout_4 = new QFormLayout(groupBoxRCRDetails);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        labelPickupLoc = new QLabel(groupBoxRCRDetails);
        labelPickupLoc->setObjectName(QString::fromUtf8("labelPickupLoc"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, labelPickupLoc);

        labelReturnLoc = new QLabel(groupBoxRCRDetails);
        labelReturnLoc->setObjectName(QString::fromUtf8("labelReturnLoc"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, labelReturnLoc);

        labelCompany = new QLabel(groupBoxRCRDetails);
        labelCompany->setObjectName(QString::fromUtf8("labelCompany"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, labelCompany);

        labelInsuranceType = new QLabel(groupBoxRCRDetails);
        labelInsuranceType->setObjectName(QString::fromUtf8("labelInsuranceType"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, labelInsuranceType);

        inputPickupLocation = new QLineEdit(groupBoxRCRDetails);
        inputPickupLocation->setObjectName(QString::fromUtf8("inputPickupLocation"));
        inputPickupLocation->setMinimumSize(QSize(0, 25));
        inputPickupLocation->setMaximumSize(QSize(16777215, 25));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, inputPickupLocation);

        inputReturnLocation = new QLineEdit(groupBoxRCRDetails);
        inputReturnLocation->setObjectName(QString::fromUtf8("inputReturnLocation"));
        inputReturnLocation->setMinimumSize(QSize(0, 25));
        inputReturnLocation->setMaximumSize(QSize(16777215, 25));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, inputReturnLocation);

        inputCompany = new QLineEdit(groupBoxRCRDetails);
        inputCompany->setObjectName(QString::fromUtf8("inputCompany"));
        inputCompany->setMinimumSize(QSize(0, 25));
        inputCompany->setMaximumSize(QSize(16777215, 25));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, inputCompany);

        inputInsuranceType = new QLineEdit(groupBoxRCRDetails);
        inputInsuranceType->setObjectName(QString::fromUtf8("inputInsuranceType"));
        inputInsuranceType->setMinimumSize(QSize(0, 25));
        inputInsuranceType->setMaximumSize(QSize(16777215, 25));

        formLayout_4->setWidget(3, QFormLayout::FieldRole, inputInsuranceType);


        verticalLayout_4->addWidget(groupBoxRCRDetails);

        stackedDetailsWidget->addWidget(pageRCRDetails);

        formLayout->setWidget(5, QFormLayout::SpanningRole, stackedDetailsWidget);

        inputArc1 = new QLineEdit(AddBookingDialog);
        inputArc1->setObjectName(QString::fromUtf8("inputArc1"));
        inputArc1->setEnabled(true);
        inputArc1->setMinimumSize(QSize(0, 25));
        inputArc1->setMaximumSize(QSize(16777215, 25));

        formLayout->setWidget(6, QFormLayout::FieldRole, inputArc1);

        labelArc1 = new QLabel(AddBookingDialog);
        labelArc1->setObjectName(QString::fromUtf8("labelArc1"));
        labelArc1->setEnabled(true);

        formLayout->setWidget(6, QFormLayout::LabelRole, labelArc1);

        labelArc2 = new QLabel(AddBookingDialog);
        labelArc2->setObjectName(QString::fromUtf8("labelArc2"));
        labelArc2->setEnabled(true);

        formLayout->setWidget(7, QFormLayout::LabelRole, labelArc2);

        inputArc2 = new QLineEdit(AddBookingDialog);
        inputArc2->setObjectName(QString::fromUtf8("inputArc2"));
        inputArc2->setEnabled(true);
        inputArc2->setMinimumSize(QSize(0, 25));
        inputArc2->setMaximumSize(QSize(16777215, 25));

        formLayout->setWidget(7, QFormLayout::FieldRole, inputArc2);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonReject = new QPushButton(AddBookingDialog);
        buttonReject->setObjectName(QString::fromUtf8("buttonReject"));
        buttonReject->setAutoDefault(false);

        horizontalLayout->addWidget(buttonReject);

        buttonOK = new QPushButton(AddBookingDialog);
        buttonOK->setObjectName(QString::fromUtf8("buttonOK"));

        horizontalLayout->addWidget(buttonOK);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AddBookingDialog);

        buttonOK->setDefault(true);


        QMetaObject::connectSlotsByName(AddBookingDialog);
    } // setupUi

    void retranslateUi(QDialog *AddBookingDialog)
    {
        AddBookingDialog->setWindowTitle(QApplication::translate("AddBookingDialog", "Buchung hinzuf\303\274gen", nullptr));
        labelPreis->setText(QApplication::translate("AddBookingDialog", "Preis", nullptr));
        labelTravelId->setText(QApplication::translate("AddBookingDialog", "Reise ID", nullptr));
        labelDateFrom->setText(QApplication::translate("AddBookingDialog", "Startdatum", nullptr));
        labelDateTo->setText(QApplication::translate("AddBookingDialog", "Enddatum", nullptr));
        labelBookingtype->setText(QApplication::translate("AddBookingDialog", "Buchungstyp", nullptr));
        inputBookingtype->setItemText(0, QApplication::translate("AddBookingDialog", "Flugbuchung", nullptr));
        inputBookingtype->setItemText(1, QApplication::translate("AddBookingDialog", "Hotelbuchung", nullptr));
        inputBookingtype->setItemText(2, QApplication::translate("AddBookingDialog", "Mietwagenreservierung", nullptr));

        groupBoxFBDetails->setTitle(QApplication::translate("AddBookingDialog", "Flugdetails:", nullptr));
        labelDeparture->setText(QApplication::translate("AddBookingDialog", "Startflughafen", nullptr));
        labelArrival->setText(QApplication::translate("AddBookingDialog", "Zielflughafen", nullptr));
        labelAirline->setText(QApplication::translate("AddBookingDialog", "Fluglinie", nullptr));
        labelSeatPref->setText(QApplication::translate("AddBookingDialog", "Sitzplatzpr\303\244ferenz", nullptr));
        inputSeatPref->setItemText(0, QApplication::translate("AddBookingDialog", "Fenster", nullptr));
        inputSeatPref->setItemText(1, QApplication::translate("AddBookingDialog", "Gang", nullptr));

        groupBoxHBDetails->setTitle(QApplication::translate("AddBookingDialog", "Hoteldetails:", nullptr));
        labelHotel->setText(QApplication::translate("AddBookingDialog", "Hotel", nullptr));
        labelTown->setText(QApplication::translate("AddBookingDialog", "Stadt", nullptr));
        labelSmoke->setText(QApplication::translate("AddBookingDialog", "Raucherzimmer", nullptr));
        inputSmoke->setText(QString());
        groupBoxRCRDetails->setTitle(QApplication::translate("AddBookingDialog", "Mietwagendetails:", nullptr));
        labelPickupLoc->setText(QApplication::translate("AddBookingDialog", "Abholstation", nullptr));
        labelReturnLoc->setText(QApplication::translate("AddBookingDialog", "R\303\274ckgabestation", nullptr));
        labelCompany->setText(QApplication::translate("AddBookingDialog", "Autovermietung", nullptr));
        labelInsuranceType->setText(QApplication::translate("AddBookingDialog", "Versicherung", nullptr));
        labelArc1->setText(QApplication::translate("AddBookingDialog", "Abh\303\244ngigkeit 1", nullptr));
        labelArc2->setText(QApplication::translate("AddBookingDialog", "Abh\303\244ngigkeit 2", nullptr));
        buttonReject->setText(QApplication::translate("AddBookingDialog", "Verwerfen", nullptr));
        buttonOK->setText(QApplication::translate("AddBookingDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddBookingDialog: public Ui_AddBookingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOOKINGDIALOG_H
