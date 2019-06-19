#include "mainwindow.h"

#include <QApplication>

#include "test.h"



int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    // UNIT TESTS
    //Test t;
    //QTest::qExec(&t);


    return a.exec();
}
