/********************************************************************************
** Form generated from reading UI file 'checkdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKDIALOG_H
#define UI_CHECKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CheckDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *btnClose;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableTravelChecks;

    void setupUi(QDialog *CheckDialog)
    {
        if (CheckDialog->objectName().isEmpty())
            CheckDialog->setObjectName(QString::fromUtf8("CheckDialog"));
        CheckDialog->resize(700, 400);
        CheckDialog->setMinimumSize(QSize(700, 400));
        verticalLayout = new QVBoxLayout(CheckDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnClose = new QPushButton(CheckDialog);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        gridLayout->addWidget(btnClose, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        tableTravelChecks = new QTableWidget(CheckDialog);
        if (tableTravelChecks->columnCount() < 5)
            tableTravelChecks->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableTravelChecks->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableTravelChecks->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableTravelChecks->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableTravelChecks->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableTravelChecks->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableTravelChecks->setObjectName(QString::fromUtf8("tableTravelChecks"));

        gridLayout->addWidget(tableTravelChecks, 0, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(CheckDialog);

        QMetaObject::connectSlotsByName(CheckDialog);
    } // setupUi

    void retranslateUi(QDialog *CheckDialog)
    {
        CheckDialog->setWindowTitle(QApplication::translate("CheckDialog", "Dialog", nullptr));
        btnClose->setText(QApplication::translate("CheckDialog", "Schlie\303\237en", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableTravelChecks->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CheckDialog", "Reise", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableTravelChecks->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CheckDialog", "Fehlendes Hotel", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableTravelChecks->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("CheckDialog", "\303\234berfl\303\274ssiges Hotel", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableTravelChecks->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("CheckDialog", "\303\234berfl\303\274ssiger Mietwagen", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableTravelChecks->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("CheckDialog", "Kein Roundtrip", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckDialog: public Ui_CheckDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKDIALOG_H
