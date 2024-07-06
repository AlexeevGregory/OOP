#include <QApplication>
#include "interface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Graph graph;
    Derivesample derivesample(&graph);
    Interface interface(&derivesample);
    interface.show();

    return a.exec();
}
