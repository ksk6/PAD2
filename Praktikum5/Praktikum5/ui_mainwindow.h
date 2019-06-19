/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionImport;
    QAction *actionExport;
    QAction *actionAddBooking;
    QAction *actionRemoveBooking;
    QAction *actionChangeBooking;
    QAction *actionClose;
    QAction *actionNeu;
    QAction *actionSpeichern;
    QAction *actionSpeichern_als;
    QAction *actionSchlie_en;
    QAction *actionPruefen;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBoxDetails;
    QGridLayout *gridLayout;
    QSpinBox *spinBoxTravel;
    QLabel *labelTo;
    QLabel *labelCustomer;
    QDoubleSpinBox *spinBoxPrice;
    QLabel *labelFrom;
    QLabel *labelTravel;
    QCalendarWidget *calendarTo;
    QLabel *labelBookingId;
    QLabel *labelPrice;
    QCalendarWidget *calendarFrom;
    QStackedWidget *stackedDetailsWidget;
    QWidget *pageFlightBooking;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxFBDetails;
    QFormLayout *formLayout;
    QLineEdit *textAirline;
    QLabel *labelDeparture;
    QLineEdit *textSeatPref;
    QLineEdit *textArrival;
    QLabel *labelSeatPref;
    QLabel *labelArrival;
    QLineEdit *textDeparture;
    QLabel *labelAirline;
    QWidget *pageHotelBooking;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBoxHBDetails;
    QFormLayout *formLayout_2;
    QLabel *labelHotel;
    QLabel *labelCity;
    QLabel *labelSmoke;
    QLineEdit *textHotel;
    QLineEdit *textCity;
    QLineEdit *textSmoke;
    QWidget *pageRentalCarReservation;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBoxRCRDetails;
    QFormLayout *formLayout_3;
    QLabel *labelCompany;
    QLabel *labelPickupLoc;
    QLabel *labelReturnLoc;
    QLabel *labelInsurance;
    QLineEdit *textCompany;
    QLineEdit *textPickupLoc;
    QLineEdit *textReturnLoc;
    QLineEdit *textInsurance;
    QLineEdit *textCustomer;
    QLineEdit *textBookingId;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QMenu *menuDatei;
    QMenu *menuBearbeiten;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1159, 814);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionImport = new QAction(MainWindow);
        actionImport->setObjectName(QString::fromUtf8("actionImport"));
        QFont font;
        font.setPointSize(11);
        actionImport->setFont(font);
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QString::fromUtf8("actionExport"));
        actionExport->setEnabled(false);
        actionExport->setFont(font);
        actionAddBooking = new QAction(MainWindow);
        actionAddBooking->setObjectName(QString::fromUtf8("actionAddBooking"));
        actionAddBooking->setEnabled(true);
        actionAddBooking->setFont(font);
        actionRemoveBooking = new QAction(MainWindow);
        actionRemoveBooking->setObjectName(QString::fromUtf8("actionRemoveBooking"));
        actionRemoveBooking->setEnabled(false);
        actionRemoveBooking->setFont(font);
        actionChangeBooking = new QAction(MainWindow);
        actionChangeBooking->setObjectName(QString::fromUtf8("actionChangeBooking"));
        actionChangeBooking->setEnabled(false);
        actionChangeBooking->setFont(font);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionClose->setFont(font);
        actionNeu = new QAction(MainWindow);
        actionNeu->setObjectName(QString::fromUtf8("actionNeu"));
        actionNeu->setEnabled(false);
        actionSpeichern = new QAction(MainWindow);
        actionSpeichern->setObjectName(QString::fromUtf8("actionSpeichern"));
        actionSpeichern->setEnabled(false);
        actionSpeichern_als = new QAction(MainWindow);
        actionSpeichern_als->setObjectName(QString::fromUtf8("actionSpeichern_als"));
        actionSpeichern_als->setEnabled(true);
        actionSchlie_en = new QAction(MainWindow);
        actionSchlie_en->setObjectName(QString::fromUtf8("actionSchlie_en"));
        actionSchlie_en->setEnabled(false);
        actionPruefen = new QAction(MainWindow);
        actionPruefen->setObjectName(QString::fromUtf8("actionPruefen"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBoxDetails = new QGroupBox(centralWidget);
        groupBoxDetails->setObjectName(QString::fromUtf8("groupBoxDetails"));
        groupBoxDetails->setMinimumSize(QSize(300, 0));
        groupBoxDetails->setMaximumSize(QSize(600, 16777215));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        groupBoxDetails->setFont(font1);
        gridLayout = new QGridLayout(groupBoxDetails);
        gridLayout->setSpacing(12);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 12, 12, 12);
        spinBoxTravel = new QSpinBox(groupBoxDetails);
        spinBoxTravel->setObjectName(QString::fromUtf8("spinBoxTravel"));
        spinBoxTravel->setMinimumSize(QSize(0, 25));
        spinBoxTravel->setMaximumSize(QSize(16777215, 25));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        spinBoxTravel->setFont(font2);
        spinBoxTravel->setReadOnly(true);
        spinBoxTravel->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(spinBoxTravel, 7, 1, 1, 1);

        labelTo = new QLabel(groupBoxDetails);
        labelTo->setObjectName(QString::fromUtf8("labelTo"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelTo->sizePolicy().hasHeightForWidth());
        labelTo->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        labelTo->setFont(font3);
        labelTo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        labelTo->setMargin(5);

        gridLayout->addWidget(labelTo, 5, 0, 1, 1);

        labelCustomer = new QLabel(groupBoxDetails);
        labelCustomer->setObjectName(QString::fromUtf8("labelCustomer"));
        QFont font4;
        font4.setPointSize(10);
        labelCustomer->setFont(font4);

        gridLayout->addWidget(labelCustomer, 8, 0, 1, 1);

        spinBoxPrice = new QDoubleSpinBox(groupBoxDetails);
        spinBoxPrice->setObjectName(QString::fromUtf8("spinBoxPrice"));
        spinBoxPrice->setMinimumSize(QSize(0, 25));
        spinBoxPrice->setMaximumSize(QSize(16777215, 25));
        spinBoxPrice->setFont(font2);
        spinBoxPrice->setReadOnly(true);
        spinBoxPrice->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBoxPrice->setMaximum(1000000.000000000000000);

        gridLayout->addWidget(spinBoxPrice, 6, 1, 1, 1);

        labelFrom = new QLabel(groupBoxDetails);
        labelFrom->setObjectName(QString::fromUtf8("labelFrom"));
        sizePolicy1.setHeightForWidth(labelFrom->sizePolicy().hasHeightForWidth());
        labelFrom->setSizePolicy(sizePolicy1);
        labelFrom->setFont(font3);
        labelFrom->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        labelFrom->setMargin(5);

        gridLayout->addWidget(labelFrom, 2, 0, 1, 1);

        labelTravel = new QLabel(groupBoxDetails);
        labelTravel->setObjectName(QString::fromUtf8("labelTravel"));
        labelTravel->setFont(font4);

        gridLayout->addWidget(labelTravel, 7, 0, 1, 1);

        calendarTo = new QCalendarWidget(groupBoxDetails);
        calendarTo->setObjectName(QString::fromUtf8("calendarTo"));
        calendarTo->setSelectionMode(QCalendarWidget::NoSelection);
        calendarTo->setVerticalHeaderFormat(QCalendarWidget::ISOWeekNumbers);
        calendarTo->setDateEditEnabled(false);

        gridLayout->addWidget(calendarTo, 5, 1, 1, 1);

        labelBookingId = new QLabel(groupBoxDetails);
        labelBookingId->setObjectName(QString::fromUtf8("labelBookingId"));
        labelBookingId->setFont(font3);
        labelBookingId->setMargin(5);

        gridLayout->addWidget(labelBookingId, 0, 0, 1, 1);

        labelPrice = new QLabel(groupBoxDetails);
        labelPrice->setObjectName(QString::fromUtf8("labelPrice"));
        labelPrice->setFont(font4);

        gridLayout->addWidget(labelPrice, 6, 0, 1, 1);

        calendarFrom = new QCalendarWidget(groupBoxDetails);
        calendarFrom->setObjectName(QString::fromUtf8("calendarFrom"));
        calendarFrom->setGridVisible(false);
        calendarFrom->setSelectionMode(QCalendarWidget::NoSelection);
        calendarFrom->setVerticalHeaderFormat(QCalendarWidget::ISOWeekNumbers);
        calendarFrom->setNavigationBarVisible(true);
        calendarFrom->setDateEditEnabled(false);

        gridLayout->addWidget(calendarFrom, 2, 1, 1, 1);

        stackedDetailsWidget = new QStackedWidget(groupBoxDetails);
        stackedDetailsWidget->setObjectName(QString::fromUtf8("stackedDetailsWidget"));
        pageFlightBooking = new QWidget();
        pageFlightBooking->setObjectName(QString::fromUtf8("pageFlightBooking"));
        QFont font5;
        font5.setBold(true);
        font5.setWeight(75);
        pageFlightBooking->setFont(font5);
        verticalLayout = new QVBoxLayout(pageFlightBooking);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBoxFBDetails = new QGroupBox(pageFlightBooking);
        groupBoxFBDetails->setObjectName(QString::fromUtf8("groupBoxFBDetails"));
        groupBoxFBDetails->setFont(font);
        formLayout = new QFormLayout(groupBoxFBDetails);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        textAirline = new QLineEdit(groupBoxFBDetails);
        textAirline->setObjectName(QString::fromUtf8("textAirline"));
        textAirline->setMinimumSize(QSize(0, 25));
        textAirline->setMaximumSize(QSize(16777215, 25));
        textAirline->setFont(font2);
        textAirline->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, textAirline);

        labelDeparture = new QLabel(groupBoxFBDetails);
        labelDeparture->setObjectName(QString::fromUtf8("labelDeparture"));
        labelDeparture->setFont(font4);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelDeparture);

        textSeatPref = new QLineEdit(groupBoxFBDetails);
        textSeatPref->setObjectName(QString::fromUtf8("textSeatPref"));
        textSeatPref->setMinimumSize(QSize(0, 25));
        textSeatPref->setMaximumSize(QSize(16777215, 25));
        textSeatPref->setFont(font2);
        textSeatPref->setReadOnly(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, textSeatPref);

        textArrival = new QLineEdit(groupBoxFBDetails);
        textArrival->setObjectName(QString::fromUtf8("textArrival"));
        textArrival->setMinimumSize(QSize(0, 25));
        textArrival->setMaximumSize(QSize(16777215, 25));
        textArrival->setFont(font2);
        textArrival->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, textArrival);

        labelSeatPref = new QLabel(groupBoxFBDetails);
        labelSeatPref->setObjectName(QString::fromUtf8("labelSeatPref"));
        labelSeatPref->setFont(font4);

        formLayout->setWidget(3, QFormLayout::LabelRole, labelSeatPref);

        labelArrival = new QLabel(groupBoxFBDetails);
        labelArrival->setObjectName(QString::fromUtf8("labelArrival"));
        labelArrival->setFont(font4);

        formLayout->setWidget(2, QFormLayout::LabelRole, labelArrival);

        textDeparture = new QLineEdit(groupBoxFBDetails);
        textDeparture->setObjectName(QString::fromUtf8("textDeparture"));
        textDeparture->setMinimumSize(QSize(0, 25));
        textDeparture->setMaximumSize(QSize(16777215, 25));
        textDeparture->setFont(font2);
        textDeparture->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, textDeparture);

        labelAirline = new QLabel(groupBoxFBDetails);
        labelAirline->setObjectName(QString::fromUtf8("labelAirline"));
        labelAirline->setFont(font4);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelAirline);


        verticalLayout->addWidget(groupBoxFBDetails);

        stackedDetailsWidget->addWidget(pageFlightBooking);
        pageHotelBooking = new QWidget();
        pageHotelBooking->setObjectName(QString::fromUtf8("pageHotelBooking"));
        pageHotelBooking->setFont(font5);
        verticalLayout_2 = new QVBoxLayout(pageHotelBooking);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBoxHBDetails = new QGroupBox(pageHotelBooking);
        groupBoxHBDetails->setObjectName(QString::fromUtf8("groupBoxHBDetails"));
        groupBoxHBDetails->setFont(font);
        formLayout_2 = new QFormLayout(groupBoxHBDetails);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        labelHotel = new QLabel(groupBoxHBDetails);
        labelHotel->setObjectName(QString::fromUtf8("labelHotel"));
        labelHotel->setFont(font4);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelHotel);

        labelCity = new QLabel(groupBoxHBDetails);
        labelCity->setObjectName(QString::fromUtf8("labelCity"));
        labelCity->setFont(font4);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelCity);

        labelSmoke = new QLabel(groupBoxHBDetails);
        labelSmoke->setObjectName(QString::fromUtf8("labelSmoke"));
        labelSmoke->setFont(font4);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, labelSmoke);

        textHotel = new QLineEdit(groupBoxHBDetails);
        textHotel->setObjectName(QString::fromUtf8("textHotel"));
        textHotel->setMinimumSize(QSize(0, 25));
        textHotel->setMaximumSize(QSize(16777215, 25));
        textHotel->setFont(font2);
        textHotel->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, textHotel);

        textCity = new QLineEdit(groupBoxHBDetails);
        textCity->setObjectName(QString::fromUtf8("textCity"));
        textCity->setMinimumSize(QSize(0, 25));
        textCity->setMaximumSize(QSize(16777215, 25));
        textCity->setFont(font2);
        textCity->setReadOnly(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, textCity);

        textSmoke = new QLineEdit(groupBoxHBDetails);
        textSmoke->setObjectName(QString::fromUtf8("textSmoke"));
        textSmoke->setMinimumSize(QSize(0, 25));
        textSmoke->setMaximumSize(QSize(16777215, 25));
        textSmoke->setFont(font2);
        textSmoke->setReadOnly(true);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, textSmoke);


        verticalLayout_2->addWidget(groupBoxHBDetails);

        stackedDetailsWidget->addWidget(pageHotelBooking);
        pageRentalCarReservation = new QWidget();
        pageRentalCarReservation->setObjectName(QString::fromUtf8("pageRentalCarReservation"));
        pageRentalCarReservation->setFont(font5);
        verticalLayout_3 = new QVBoxLayout(pageRentalCarReservation);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBoxRCRDetails = new QGroupBox(pageRentalCarReservation);
        groupBoxRCRDetails->setObjectName(QString::fromUtf8("groupBoxRCRDetails"));
        groupBoxRCRDetails->setFont(font);
        formLayout_3 = new QFormLayout(groupBoxRCRDetails);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        labelCompany = new QLabel(groupBoxRCRDetails);
        labelCompany->setObjectName(QString::fromUtf8("labelCompany"));
        labelCompany->setFont(font3);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, labelCompany);

        labelPickupLoc = new QLabel(groupBoxRCRDetails);
        labelPickupLoc->setObjectName(QString::fromUtf8("labelPickupLoc"));
        labelPickupLoc->setFont(font3);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, labelPickupLoc);

        labelReturnLoc = new QLabel(groupBoxRCRDetails);
        labelReturnLoc->setObjectName(QString::fromUtf8("labelReturnLoc"));
        labelReturnLoc->setFont(font3);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, labelReturnLoc);

        labelInsurance = new QLabel(groupBoxRCRDetails);
        labelInsurance->setObjectName(QString::fromUtf8("labelInsurance"));
        labelInsurance->setFont(font3);

        formLayout_3->setWidget(3, QFormLayout::LabelRole, labelInsurance);

        textCompany = new QLineEdit(groupBoxRCRDetails);
        textCompany->setObjectName(QString::fromUtf8("textCompany"));
        textCompany->setMinimumSize(QSize(0, 25));
        textCompany->setMaximumSize(QSize(16777215, 25));
        textCompany->setFont(font2);
        textCompany->setReadOnly(true);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, textCompany);

        textPickupLoc = new QLineEdit(groupBoxRCRDetails);
        textPickupLoc->setObjectName(QString::fromUtf8("textPickupLoc"));
        textPickupLoc->setMinimumSize(QSize(0, 25));
        textPickupLoc->setMaximumSize(QSize(16777215, 25));
        textPickupLoc->setFont(font2);
        textPickupLoc->setReadOnly(true);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, textPickupLoc);

        textReturnLoc = new QLineEdit(groupBoxRCRDetails);
        textReturnLoc->setObjectName(QString::fromUtf8("textReturnLoc"));
        textReturnLoc->setMinimumSize(QSize(0, 25));
        textReturnLoc->setMaximumSize(QSize(16777215, 25));
        textReturnLoc->setFont(font2);
        textReturnLoc->setReadOnly(true);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, textReturnLoc);

        textInsurance = new QLineEdit(groupBoxRCRDetails);
        textInsurance->setObjectName(QString::fromUtf8("textInsurance"));
        textInsurance->setMinimumSize(QSize(0, 25));
        textInsurance->setMaximumSize(QSize(16777215, 25));
        textInsurance->setFont(font2);
        textInsurance->setReadOnly(true);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, textInsurance);


        verticalLayout_3->addWidget(groupBoxRCRDetails);

        stackedDetailsWidget->addWidget(pageRentalCarReservation);

        gridLayout->addWidget(stackedDetailsWidget, 9, 0, 1, 2);

        textCustomer = new QLineEdit(groupBoxDetails);
        textCustomer->setObjectName(QString::fromUtf8("textCustomer"));
        textCustomer->setMinimumSize(QSize(0, 25));
        textCustomer->setMaximumSize(QSize(16777215, 25));
        textCustomer->setFont(font2);
        textCustomer->setReadOnly(true);

        gridLayout->addWidget(textCustomer, 8, 1, 1, 1);

        textBookingId = new QLineEdit(groupBoxDetails);
        textBookingId->setObjectName(QString::fromUtf8("textBookingId"));
        textBookingId->setMinimumSize(QSize(0, 25));
        textBookingId->setMaximumSize(QSize(16777215, 25));
        textBookingId->setFont(font2);
        textBookingId->setReadOnly(true);

        gridLayout->addWidget(textBookingId, 0, 1, 1, 1);


        gridLayout_2->addWidget(groupBoxDetails, 0, 1, 1, 1);

        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QFont font6;
        font6.setPointSize(9);
        font6.setBold(true);
        font6.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font6);
        __qtablewidgetitem->setBackground(QColor(170, 170, 170));
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font6);
        __qtablewidgetitem1->setBackground(QColor(170, 170, 170));
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font6);
        __qtablewidgetitem2->setBackground(QColor(170, 170, 170));
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font6);
        __qtablewidgetitem3->setBackground(QColor(170, 170, 170));
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1159, 19));
        menuDatei = new QMenu(menuBar);
        menuDatei->setObjectName(QString::fromUtf8("menuDatei"));
        menuDatei->setFont(font);
        menuBearbeiten = new QMenu(menuBar);
        menuBearbeiten->setObjectName(QString::fromUtf8("menuBearbeiten"));
        menuBearbeiten->setFont(font);
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuDatei->menuAction());
        menuBar->addAction(menuBearbeiten->menuAction());
        menuDatei->addAction(actionNeu);
        menuDatei->addAction(actionSpeichern);
        menuDatei->addAction(actionSpeichern_als);
        menuDatei->addAction(actionSchlie_en);
        menuDatei->addSeparator();
        menuDatei->addAction(actionImport);
        menuDatei->addAction(actionExport);
        menuDatei->addSeparator();
        menuDatei->addAction(actionClose);
        menuBearbeiten->addAction(actionAddBooking);
        menuBearbeiten->addAction(actionChangeBooking);
        menuBearbeiten->addAction(actionRemoveBooking);
        menuBearbeiten->addAction(actionPruefen);

        retranslateUi(MainWindow);

        stackedDetailsWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionImport->setText(QApplication::translate("MainWindow", "Importieren", nullptr));
        actionExport->setText(QApplication::translate("MainWindow", "Exportieren", nullptr));
        actionAddBooking->setText(QApplication::translate("MainWindow", "Buchung hinzuf\303\274gen", nullptr));
        actionRemoveBooking->setText(QApplication::translate("MainWindow", "Buchung entfernen", nullptr));
        actionChangeBooking->setText(QApplication::translate("MainWindow", "Buchung \303\244ndern", nullptr));
        actionClose->setText(QApplication::translate("MainWindow", "Beenden", nullptr));
        actionNeu->setText(QApplication::translate("MainWindow", "Neu...", nullptr));
        actionSpeichern->setText(QApplication::translate("MainWindow", "Speichern", nullptr));
        actionSpeichern_als->setText(QApplication::translate("MainWindow", "Speichern als...", nullptr));
        actionSchlie_en->setText(QApplication::translate("MainWindow", "Schlie\303\237en", nullptr));
        actionPruefen->setText(QApplication::translate("MainWindow", "Reisen pr\303\274fen", nullptr));
        groupBoxDetails->setTitle(QApplication::translate("MainWindow", "Details zur Buchung", nullptr));
        labelTo->setText(QApplication::translate("MainWindow", "Bis:", nullptr));
        labelCustomer->setText(QApplication::translate("MainWindow", "Kunde:", nullptr));
        labelFrom->setText(QApplication::translate("MainWindow", "Von:", nullptr));
        labelTravel->setText(QApplication::translate("MainWindow", "Reise:", nullptr));
        labelBookingId->setText(QApplication::translate("MainWindow", "Buchungsnummer:", nullptr));
        labelPrice->setText(QApplication::translate("MainWindow", "Preis:", nullptr));
        groupBoxFBDetails->setTitle(QApplication::translate("MainWindow", "Flugdetails:", nullptr));
        labelDeparture->setText(QApplication::translate("MainWindow", "Startflughafen:", nullptr));
        labelSeatPref->setText(QApplication::translate("MainWindow", "Sitzplatzpr\303\244ferenz:", nullptr));
        labelArrival->setText(QApplication::translate("MainWindow", "Zielflughafen:", nullptr));
        labelAirline->setText(QApplication::translate("MainWindow", "Fluglinie:", nullptr));
        groupBoxHBDetails->setTitle(QApplication::translate("MainWindow", "Hoteldetails:", nullptr));
        labelHotel->setText(QApplication::translate("MainWindow", "Hotel:", nullptr));
        labelCity->setText(QApplication::translate("MainWindow", "Stadt:", nullptr));
        labelSmoke->setText(QApplication::translate("MainWindow", "Raucherzimmer:", nullptr));
        groupBoxRCRDetails->setTitle(QApplication::translate("MainWindow", "Mietwagendetails:", nullptr));
        labelCompany->setText(QApplication::translate("MainWindow", "Autovermietung:", nullptr));
        labelPickupLoc->setText(QApplication::translate("MainWindow", "Abholstation:", nullptr));
        labelReturnLoc->setText(QApplication::translate("MainWindow", "R\303\274ckgabestation:", nullptr));
        labelInsurance->setText(QApplication::translate("MainWindow", "Versicherung:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "BuchungsNr.", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Preis", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Kunde", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "ReiseNr.", nullptr));
        menuDatei->setTitle(QApplication::translate("MainWindow", "Datei", nullptr));
        menuBearbeiten->setTitle(QApplication::translate("MainWindow", "Bearbeiten", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
