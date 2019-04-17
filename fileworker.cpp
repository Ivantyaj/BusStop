#include "fileworker.h"

FileWorker::FileWorker()
{

}

QList<QStringList> FileWorker::readData(const QString & fileName)
{
    QFile * file = new QFile(fileName);

    file->open(QFile::ReadOnly | QFile::Text);

    QTextStream in(file);

    QList<QStringList> dataList;

    while(!in.atEnd()){
        QString line = in.readLine();

        QStringList stringListData;
        for(QString item : line.split(" ")){
            stringListData << item;
        }
        dataList.append(stringListData);
    }
    file->close();
    return dataList;
}

void FileWorker::writeData(const QList<QList<Transport> > &data, const QString &fileName)
{
    QFile file(fileName);

    if (file.open(QFile::WriteOnly))
    {
        QTextStream stream(&file);

        QString string;
        for(QList<Transport> listTransport : data){
            for(Transport transport : listTransport){
                string += transport.toStringList().join(" ");
                string += "\n";
            }
            string += "\n";
        }
        stream << string.trimmed();

        file.close();
    }
}
