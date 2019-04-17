#include "transport.h"

Transport::Transport()
{

}

Transport::Transport(const QStringList &listData)
{
    this->transportName = listData.at(0);
    this->departureTime = QTime::fromString(listData.at(1), "hh:mm");
    this->arrivalTime = QTime::fromString(listData.at(2), "hh:mm");
}

QList<QStandardItem *> Transport::getListStandartItemData() const
{
    QList<QStandardItem *> stdItemList;
    stdItemList.append(new QStandardItem(transportName));
    stdItemList.append(new QStandardItem(departureTime.toString()));
    stdItemList.append(new QStandardItem(arrivalTime.toString()));

    return stdItemList;
}

QString Transport::getTransportName() const
{
    return transportName;
}

QTime Transport::getDepartureTime() const
{
    return departureTime;
}

QTime Transport::getArrivalTime() const
{
    return arrivalTime;
}

bool Transport::compareLessTime(const Transport & t1, const Transport & t2)
{
    if(t1.departureTime == t2.departureTime)
        return t1.arrivalTime < t2.arrivalTime;
    return t1.departureTime < t2.departureTime;
}

QStringList Transport::toStringList() const
{
    QStringList strList;
    strList.append(transportName);
    strList.append(departureTime.toString("hh:mm"));
    strList.append(arrivalTime.toString("hh:mm"));
    return strList;
}

int Transport::getRouteDuration() const
{
    return getDepartureTime().msecsTo(getArrivalTime());
}

bool operator==(const Transport &left, const Transport &right)
{
    return (left.departureTime == right.departureTime) &&
            (left.arrivalTime == right.arrivalTime) &&
            (left.transportName == right.transportName);
}
