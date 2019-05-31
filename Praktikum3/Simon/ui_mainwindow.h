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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
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
    QWidget *centralWidget;
    QTableWidget *tWOverview;
    QWidget *wDetailAnsicht;
    QLineEdit *lEBuchungsnummer;
    QLabel *lblBuchungsnummer;
    QLabel *lblVon;
    QLabel *lblBis;
    QCalendarWidget *cWVon;
    QCalendarWidget *cWBis;
    QMenuBar *menuBar;
    QMenu *menuFunktionen;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(870, 566);
        actionDatei_einlesen = new QAction(MainWindow);
        actionDatei_einlesen->setObjectName(QStringLiteral("actionDatei_einlesen"));
        actionProgramm_beenden = new QAction(MainWindow);
        actionProgramm_beenden->setObjectName(QStringLiteral("actionProgramm_beenden"));
        actionNeue_Buchung_anlegen = new QAction(MainWindow);
        actionNeue_Buchung_anlegen->setObjectName(QStringLiteral("actionNeue_Buchung_anlegen"));
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
        tWOverview->setGeometry(QRect(10, 0, 421, 511));
        tWOverview->setEditTriggers(QAbstractItemView::DoubleClicked);
        wDetailAnsicht = new QWidget(centralWidget);
        wDetailAnsicht->setObjectName(QStringLiteral("wDetailAnsicht"));
        wDetailAnsicht->setGeometry(QRect(430, 0, 421, 511));
        lEBuchungsnummer = new QLineEdit(wDetailAnsicht);
        lEBuchungsnummer->setObjectName(QStringLiteral("lEBuchungsnummer"));
        lEBuchungsnummer->setEnabled(false);
        lEBuchungsnummer->setGeometry(QRect(100, 20, 221, 20));
        lblBuchungsnummer = new QLabel(wDetailAnsicht);
        lblBuchungsnummer->setObjectName(QStringLiteral("lblBuchungsnummer"));
        lblBuchungsnummer->setGeometry(QRect(10, 20, 121, 16));
        lblVon = new QLabel(wDetailAnsicht);
        lblVon->setObjectName(QStringLiteral("lblVon"));
        lblVon->setGeometry(QRect(10, 60, 47, 13));
        lblBis = new QLabel(wDetailAnsicht);
        lblBis->setObjectName(QStringLiteral("lblBis"));
        lblBis->setGeometry(QRect(10, 250, 47, 13));
        cWVon = new QCalendarWidget(wDetailAnsicht);
        cWVon->setObjectName(QStringLiteral("cWVon"));
        cWVon->setGeometry(QRect(100, 50, 312, 183));
        cWBis = new QCalendarWidget(wDetailAnsicht);
        cWBis->setObjectName(QStringLiteral("cWBis"));
        cWBis->setGeometry(QRect(100, 250, 312, 183));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 870, 21));
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

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionDatei_einlesen->setText(QApplication::translate("MainWindow", "Datei einlesen", nullptr));
        actionProgramm_beenden->setText(QApplication::translate("MainWindow", "Programm beenden", nullptr));
        actionNeue_Buchung_anlegen->setText(QApplication::translate("MainWindow", "Neue Buchung anlegen", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tWOverview->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Buchungsnr", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tWOverview->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Preis", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tWOverview->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Kunde", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tWOverview->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Reisenummer", nullptr));
        lblBuchungsnummer->setText(QApplication::translate("MainWindow", "Buchungsnummer", nullptr));
        lblVon->setText(QApplication::translate("MainWindow", "von", nullptr));
        lblBis->setText(QApplication::translate("MainWindow", "bis", nullptr));
        menuFunktionen->setTitle(QApplication::translate("MainWindow", "Funktionen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
