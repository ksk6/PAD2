#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


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

private:
    Ui::MainWindow *ui;

    enum Zeilen
    {
        Buchungsnummer, Preis, Kunde, Reisenummer
    };
};

#endif // MAINWINDOW_H
