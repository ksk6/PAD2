/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDatei_einlesen;
    QAction *actionProgramm_beenden;
    QAction *actionNeue_Buchung_anlegen;
    QAction *actionDatei_speichern;
    QWidget *centralWidget;
    QTableWidget *tWOverview;
    QWidget *wDetailAnsicht;
    QLineEdit *lEBuchungsnummer;
    QLabel *lblBookingNumber;
    QLabel *lblFrom;
    QLabel *lblTo;
    QCalendarWidget *cWVon;
    QCalendarWidget *cWBis;
    QLabel *lblPrice;
    QLabel *lblTravel;
    QLabel *lblCustomer;
    QDoubleSpinBox *dSBPrice;
    QSpinBox *sBTravel;
    QLineEdit *lECustomer;
    QGroupBox *gBAdditionalInformation;
    QLabel *lblAdditional1;
    QLabel *lblAdditional2;
    QLabel *lblAdditional3;
    QLabel *lblAdditional4;
    QLineEdit *lEAdditional1;
    QLineEdit *lEAdditional2;
    QLineEdit *lEAdditional3;
    QLineEdit *lEAdditional4;
    QMenuBar *menuBar;
    QMenu *menuFunktionen;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(867, 768);
        actionDatei_einlesen = new QAction(MainWindow);
        actionDatei_einlesen->setObjectName(QStringLiteral("actionDatei_einlesen"));
        actionProgramm_beenden = new QAction(MainWindow);
        actionProgramm_beenden->setObjectName(QStringLiteral("actionProgramm_beenden"));
        actionNeue_Buchung_anlegen = new QAction(MainWindow);
        actionNeue_Buchung_anlegen->setObjectName(QStringLiteral("actionNeue_Buchung_anlegen"));
        actionDatei_speichern = new QAction(MainWindow);
        actionDatei_speichern->setObjectName(QStringLiteral("actionDatei_speichern"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tWOverview = new QTableWidget(centralWidget);
        if (tWOverview->columnCount() < 4)
            tWOverview->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tWOverview->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tWOverview->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tWOverview->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tWOverview->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tWOverview->setObjectName(QStringLiteral("tWOverview"));
        tWOverview->setGeometry(QRect(10, 0, 421, 711));
        tWOverview->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tWOverview->setDragDropOverwriteMode(false);
        wDetailAnsicht = new QWidget(centralWidget);
        wDetailAnsicht->setObjectName(QStringLiteral("wDetailAnsicht"));
        wDetailAnsicht->setGeometry(QRect(430, 0, 421, 541));
        lEBuchungsnummer = new QLineEdit(wDetailAnsicht);
        lEBuchungsnummer->setObjectName(QStringLiteral("lEBuchungsnummer"));
        lEBuchungsnummer->setEnabled(false);
        lEBuchungsnummer->setGeometry(QRect(100, 20, 311, 20));
        lblBookingNumber = new QLabel(wDetailAnsicht);
        lblBookingNumber->setObjectName(QStringLiteral("lblBookingNumber"));
        lblBookingNumber->setGeometry(QRect(10, 20, 121, 16));
        lblFrom = new QLabel(wDetailAnsicht);
        lblFrom->setObjectName(QStringLiteral("lblFrom"));
        lblFrom->setGeometry(QRect(10, 60, 47, 13));
        lblTo = new QLabel(wDetailAnsicht);
        lblTo->setObjectName(QStringLiteral("lblTo"));
        lblTo->setGeometry(QRect(10, 250, 47, 13));
        cWVon = new QCalendarWidget(wDetailAnsicht);
        cWVon->setObjectName(QStringLiteral("cWVon"));
        cWVon->setEnabled(false);
        cWVon->setGeometry(QRect(100, 50, 312, 183));
        cWBis = new QCalendarWidget(wDetailAnsicht);
        cWBis->setObjectName(QStringLiteral("cWBis"));
        cWBis->setEnabled(false);
        cWBis->setGeometry(QRect(100, 250, 312, 183));
        lblPrice = new QLabel(wDetailAnsicht);
        lblPrice->setObjectName(QStringLiteral("lblPrice"));
        lblPrice->setGeometry(QRect(10, 450, 47, 13));
        lblTravel = new QLabel(wDetailAnsicht);
        lblTravel->setObjectName(QStringLiteral("lblTravel"));
        lblTravel->setGeometry(QRect(10, 480, 47, 13));
        lblCustomer = new QLabel(wDetailAnsicht);
        lblCustomer->setObjectName(QStringLiteral("lblCustomer"));
        lblCustomer->setGeometry(QRect(10, 510, 47, 13));
        dSBPrice = new QDoubleSpinBox(wDetailAnsicht);
        dSBPrice->setObjectName(QStringLiteral("dSBPrice"));
        dSBPrice->setEnabled(false);
        dSBPrice->setGeometry(QRect(100, 450, 311, 22));
        dSBPrice->setMaximum(9999.99);
        sBTravel = new QSpinBox(wDetailAnsicht);
        sBTravel->setObjectName(QStringLiteral("sBTravel"));
        sBTravel->setEnabled(false);
        sBTravel->setGeometry(QRect(100, 480, 311, 22));
        lECustomer = new QLineEdit(wDetailAnsicht);
        lECustomer->setObjectName(QStringLiteral("lECustomer"));
        lECustomer->setEnabled(false);
        lECustomer->setGeometry(QRect(100, 510, 311, 20));
        gBAdditionalInformation = new QGroupBox(centralWidget);
        gBAdditionalInformation->setObjectName(QStringLiteral("gBAdditionalInformation"));
        gBAdditionalInformation->setGeometry(QRect(430, 550, 421, 161));
        lblAdditional1 = new QLabel(gBAdditionalInformation);
        lblAdditional1->setObjectName(QStringLiteral("lblAdditional1"));
        lblAdditional1->setGeometry(QRect(10, 30, 91, 16));
        lblAdditional2 = new QLabel(gBAdditionalInformation);
        lblAdditional2->setObjectName(QStringLiteral("lblAdditional2"));
        lblAdditional2->setGeometry(QRect(10, 60, 91, 16));
        lblAdditional3 = new QLabel(gBAdditionalInformation);
        lblAdditional3->setObjectName(QStringLiteral("lblAdditional3"));
        lblAdditional3->setGeometry(QRect(10, 90, 91, 16));
        lblAdditional4 = new QLabel(gBAdditionalInformation);
        lblAdditional4->setObjectName(QStringLiteral("lblAdditional4"));
        lblAdditional4->setGeometry(QRect(10, 120, 131, 16));
        lEAdditional1 = new QLineEdit(gBAdditionalInformation);
        lEAdditional1->setObjectName(QStringLiteral("lEAdditional1"));
        lEAdditional1->setEnabled(false);
        lEAdditional1->setGeometry(QRect(100, 30, 311, 20));
        lEAdditional2 = new QLineEdit(gBAdditionalInformation);
        lEAdditional2->setObjectName(QStringLiteral("lEAdditional2"));
        lEAdditional2->setEnabled(false);
        lEAdditional2->setGeometry(QRect(100, 60, 311, 20));
        lEAdditional3 = new QLineEdit(gBAdditionalInformation);
        lEAdditional3->setObjectName(QStringLiteral("lEAdditional3"));
        lEAdditional3->setEnabled(false);
        lEAdditional3->setGeometry(QRect(100, 90, 311, 20));
        lEAdditional4 = new QLineEdit(gBAdditionalInformation);
        lEAdditional4->setObjectName(QStringLiteral("lEAdditional4"));
        lEAdditional4->setEnabled(false);
        lEAdditional4->setGeometry(QRect(100, 120, 311, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 867, 21));
        menuFunktionen = new QMenu(menuBar);
        menuFunktionen->setObjectName(QStringLiteral("menuFunktionen"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFunktionen->menuAction());
        menuFunktionen->addAction(actionDatei_einlesen);
        menuFunktionen->addAction(actionProgramm_beenden);
        menuFunktionen->addAction(actionNeue_Buchung_anlegen);
        menuFunktionen->addAction(actionDatei_speichern);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionDatei_einlesen->setText(QApplication::translate("MainWindow", "Datei einlesen", nullptr));
        actionProgramm_beenden->setText(QApplication::translate("MainWindow", "Programm beenden", nullptr));
        actionNeue_Buchung_anlegen->setText(QApplication::translate("MainWindow", "Neue Buchung anlegen", nullptr));
        actionDatei_speichern->setText(QApplication::translate("MainWindow", "Datei speichern", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tWOverview->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Buchungsnr", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tWOverview->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Preis", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tWOverview->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Kunde", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tWOverview->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Reisenummer", nullptr));
        lblBookingNumber->setText(QApplication::translate("MainWindow", "Buchungsnummer", nullptr));
        lblFrom->setText(QApplication::translate("MainWindow", "von", nullptr));
        lblTo->setText(QApplication::translate("MainWindow", "bis", nullptr));
        lblPrice->setText(QApplication::translate("MainWindow", "Preis", nullptr));
        lblTravel->setText(QApplication::translate("MainWindow", "Reise", nullptr));
        lblCustomer->setText(QApplication::translate("MainWindow", "Kunde", nullptr));
        gBAdditionalInformation->setTitle(QApplication::translate("MainWindow", "GroupBox", nullptr));
        lblAdditional1->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        lblAdditional2->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        lblAdditional3->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        lblAdditional4->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        menuFunktionen->setTitle(QApplication::translate("MainWindow", "Funktionen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
