#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <travelagency.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionProgramm_beenden_triggered();

    void on_actionDatei_einlesen_triggered();

    void on_tWOverview_cellDoubleClicked(int row, int column);

    void on_actionNeue_Buchung_anlegen_triggered();

    void on_actionDatei_speichern_triggered();

private:
    Ui::MainWindow *ui;
    void ReloadData();
    TravelAgency* ta;
    enum Zeilen
    {
        Buchungsnummer, Preis, Kunde, Reisenummer
    };
};

#endif // MAINWINDOW_H
