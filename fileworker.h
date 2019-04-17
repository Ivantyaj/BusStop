#ifndef FILEWORKER_H
#define FILEWORKER_H

#include <QFile>
#include <QStringList>
#include <QList>
#include <QFileDialog>
#include <QTextStream>
#include <QIODevice>
#include "transport.h"

class FileWorker
{
public:
    FileWorker();

    static QList<QStringList> readData(const QString & fileName);
    static void writeData(const QList<QList<Transport> > & data, const QString & fileName);
};

#endif // FILEWORKER_H
