#ifndef TEST_H
#define TEST_H

#include <QtTest/QTest>

class Test : public QObject
{
    Q_OBJECT
private slots:
    void testAvis();
    void testUnitedAirlines();
    void testValue();
public:
};

#endif // TEST_H
