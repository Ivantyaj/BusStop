#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <QList>
#include <QStringList>
#include <QTime>
#include <QStandardItem>

class Transport
{
public:
    Transport();

    Transport(const QStringList &);

    QList<QStandardItem *> getListStandartItemData() const;

    QString getTransportName() const;
    QTime getDepartureTime() const;
    QTime getArrivalTime() const;

    static bool compareLessTime(const Transport &, const Transport &); //Компаратор для std::sort

    QStringList toStringList() const;
    int getRouteDuration() const;

    friend bool operator==(const Transport& left, const Transport& right);

private:
    QString transportName;
    QTime departureTime;
    QTime arrivalTime;
};

bool operator==(const Transport& left, const Transport& right);

#endif // TRANSPORT_H
