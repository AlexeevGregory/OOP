#include "derivesample.h"
#include <math.h>

Derivesample::Derivesample(Graph* obj) : Sample(obj)
{
    active = 0;
}

void Derivesample::draw(QPainter* p, QRect r)
{
    if (empty()) return;

    Sample::draw(p, r);


    int radius = 150;
    int vertR = 15;
    int angle = active * 360 / graph->size();
    double rad = qDegreesToRadians(static_cast<double>(angle));
    int dx = static_cast<int>(radius * qCos(rad));
    int dy = static_cast<int>(radius * qSin(rad));
    QPoint circlePoint = r.center() + QPoint(dx, dy);
    p->setBrush(Qt::blue);
    p->drawEllipse(circlePoint, vertR, vertR);


    std::vector<Node*> Nodes = graph->getNodes();
    p->setPen(Qt::black);
    p->setFont(QFont("Arial", 10, QFont::Bold));
    QRect textRect(circlePoint.x() - vertR, circlePoint.y() - vertR, 2*vertR, 2*vertR);
    p->drawText(textRect, QChar(Nodes[active]->name), QTextOption(Qt::AlignCenter));
}

void Derivesample::newEvent(bool direction)
{
    if (direction) active++;
    else active = (--active) + graph->size();
    active = active % graph->size();
}
