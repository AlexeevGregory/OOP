#include <QApplication>
#include "interface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Graph graph;
    Sample sample(&graph);
    Interface interface(&sample);
    interface.show();

    return a.exec();
}
