#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QCoreApplication>

#include "communicator.h"

class Application : public QCoreApplication
{
    Q_OBJECT

    Communicator *comm;

public:

    Application(int, char**);

signals:

public slots:

    void recieve(QByteArray);

};

#endif // APPLICATION_H
