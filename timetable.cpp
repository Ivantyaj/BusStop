#include "timetable.h"

TimeTable::TimeTable()
{

}

TimeTable::TimeTable(const QList<QStringList> &listData)
{
    for(QStringList stringListData: listData){
        listTransport.append(Transport(stringListData));
    }
}

QList<Transport> TimeTable::getAllTransport()
{
    return listTransport;
}

QStandardItemModel *TimeTable::getModelTransport(const QList<Transport> & transports)
{
    QStandardItemModel * model = new QStandardItemModel();
    model->setColumnCount(3);
    for(Transport transport: transports){
        model->insertRow(model->rowCount(), transport.getListStandartItemData());
    }
    return model;
}

QList<QList<Transport> > TimeTable::reduceByCompany() //Только для двух
{
    QString namePosh = "Posh";
    QString nameGrotty = "Grotty";
    QList<Transport> posh;
    QList<Transport> grotty;
    for(Transport & transport: listTransport){
        if(transport.getTransportName() == namePosh){
            posh.append(transport);
        } else {
            grotty.append(transport);
        }
    }
    QList<QList<Transport>> listReduce;

    std::sort(posh.begin(), posh.end(), Transport::compareLessTime);
    std::sort(grotty.begin(), grotty.end(), Transport::compareLessTime);

    removeInefficient(posh);
    removeInefficient(grotty);

    removeIdentical(posh, grotty);

    listReduce.append(posh);
    listReduce.append(grotty);

    return listReduce;
}

QList<QList<Transport> > TimeTable::reduceByCompanyAll() //Для любого числа компаний
{                                                        //Но без удаления совпадений
    QSet<QString> names;
    for(Transport transport: listTransport){
        names << transport.getTransportName();
    }

    QList<QList<Transport>> listReduce;

    for(QString name: names){
        QList<Transport> transportList;
        for(Transport & transport: listTransport){
            if(transport.getTransportName() == name)
                transportList.append(transport);
        }
        std::sort(transportList.begin(), transportList.end(), Transport::compareLessTime);
        removeInefficient(transportList);
        listReduce.append(transportList);
    }

    return listReduce;


}

void TimeTable::removeInefficient(QList<Transport> & list)
{
    QList<const Transport *> transportToRemove;

    for (int i = 0; i < list.size() - 1; i++) {
        if((list.at(i).getDepartureTime() < list.at(i+1).getDepartureTime() &&
                list.at(i).getArrivalTime() >= list.at(i+1).getArrivalTime()) ||
                list.at(i).getDepartureTime() == list.at(i+1).getDepartureTime() ||
                list.at(i).getRouteDuration() > QTime(1,0).msecsSinceStartOfDay())
            transportToRemove.append(&list.at(i));
    }
    if(list.at(list.size() - 1).getRouteDuration() > QTime(1,0).msecsSinceStartOfDay())
        transportToRemove.append(&list.at(list.size() - 1));

    for(auto & transport : transportToRemove){
        list.removeOne(*transport);
    }
}

void TimeTable::removeIdentical(const QList<Transport> &listToCompare, QList<Transport> &listToRemove)
{
    for(const Transport &transportToCompare : listToCompare){
        for(Transport &transportToRemove : listToRemove){
            if(transportToCompare.getDepartureTime() == transportToRemove.getDepartureTime() &&
                    transportToCompare.getArrivalTime() == transportToRemove.getArrivalTime())
                listToRemove.removeOne(transportToRemove);
        }
    }
}
