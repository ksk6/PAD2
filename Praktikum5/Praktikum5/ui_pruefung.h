/********************************************************************************
** Form generated from reading UI file 'pruefung.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRUEFUNG_H
#define UI_PRUEFUNG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_pruefung
{
public:
    QTableWidget *tablePruefungsergebnisse;

    void setupUi(QDialog *pruefung)
    {
        if (pruefung->objectName().isEmpty())
            pruefung->setObjectName(QString::fromUtf8("pruefung"));
        pruefung->resize(916, 503);
        tablePruefungsergebnisse = new QTableWidget(pruefung);
        if (tablePruefungsergebnisse->columnCount() < 5)
            tablePruefungsergebnisse->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tablePruefungsergebnisse->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tablePruefungsergebnisse->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tablePruefungsergebnisse->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tablePruefungsergebnisse->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tablePruefungsergebnisse->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tablePruefungsergebnisse->setObjectName(QString::fromUtf8("tablePruefungsergebnisse"));
        tablePruefungsergebnisse->setGeometry(QRect(20, 20, 871, 461));

        retranslateUi(pruefung);

        QMetaObject::connectSlotsByName(pruefung);
    } // setupUi

    void retranslateUi(QDialog *pruefung)
    {
        pruefung->setWindowTitle(QApplication::translate("pruefung", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tablePruefungsergebnisse->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("pruefung", "Reise", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tablePruefungsergebnisse->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("pruefung", "Fehlendes Hotel", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tablePruefungsergebnisse->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("pruefung", "\303\234berfl\303\274ssiges Hotel", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tablePruefungsergebnisse->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("pruefung", "\303\234berfl\303\274ssiger Mietwagen", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tablePruefungsergebnisse->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("pruefung", "Roundtrip", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pruefung: public Ui_pruefung {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRUEFUNG_H
