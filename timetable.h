#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <QList>
#include <QStringList>
#include <QTime>
#include <QSet>
#include <QDebug>
//#include <algorithm>

#include <QSet>

#include <QStandardItemModel>
#include "transport.h"

class TimeTable
{
public:
    TimeTable();

    TimeTable(const QList<QStringList> &);

    QStandardItemModel * getModelTransport(const QList<Transport> &);
    QList<Transport> getAllTransport();

    QList<QList<Transport>> reduceByCompany();
    QList<QList<Transport>> reduceByCompanyAll();

private:
    QList<Transport> listTransport;

private:
    void removeInefficient(QList<Transport> &);       //Удаление из списка транспорта согласно условию
    void removeIdentical(const QList<Transport> & listToCompare, QList<Transport> & listToRemove); //Удаление совпадений из второго списка
};

#endif // TIMETABLE_H
