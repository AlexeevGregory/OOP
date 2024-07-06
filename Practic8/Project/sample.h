#ifndef SAMPLE_H
#define SAMPLE_H

#include "graph.h"
#include <map>
#include <QPainter>


using namespace std;

class Sample
{
protected:
    int count;
    Graph *graph;
public:
    Sample(Graph*);
    bool empty();
    void getGraph(Graph* obj);
    void draw(QPainter*, QRect&);
};

#endif // SAMPLE_H
