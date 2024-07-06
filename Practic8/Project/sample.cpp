#include "sample.h"
#include <math.h>

using namespace std;

Sample::Sample(Graph* obj)
{
    string NameFile = obj->selectFile();
    obj->InputFileValues(NameFile);
    graph = obj;
}
void Sample::getGraph(Graph* obj)
{
    graph = obj;
    count = obj->count;
}
bool Sample::empty() {
    return graph->empty();
}

void Sample::draw(QPainter* painter, QRect& rect)
{
    if (empty()) return;


    int radius = 150;
    int vertR = 15;
    vector<Node*> Nodes = graph->getNodes();
    std::map<Node*, QPoint> NodesPos;
    int step = 360 / graph->size();
    for (int i = 0, angle = 0; i < graph->size(); ++i, angle += step) {

        double rad = qDegreesToRadians(static_cast<double>(angle));
        int dx = static_cast<int>(radius * qCos(rad));
        int dy = static_cast<int>(radius * qSin(rad));


        QPoint circlePoint = rect.center() + QPoint(dx, dy);
        NodesPos[Nodes[i]] = circlePoint;
        painter->setBrush(Qt::green);
        painter->drawEllipse(circlePoint, vertR, vertR);


        painter->setPen(Qt::black);
        painter->setFont(QFont("Arial", 10, QFont::Bold));
        QRect textRect(circlePoint.x() - vertR, circlePoint.y() - vertR, 2*vertR, 2*vertR);
        painter->drawText(textRect, QChar(Nodes[i]->name), QTextOption(Qt::AlignCenter));
    }


    painter->setPen(QPen(Qt::black, 3));
    for (int i = 0; i < graph->size(); ++i) {
        std::vector<Node*> neighbors = Nodes[i]->neighbors;
        for (int j = 0; j < neighbors.size(); ++j) {

            QPointF p1 = NodesPos[Nodes[i]];
            QPointF p2 = NodesPos[neighbors[j]];
            QPointF v = p2 - p1;
            double length = sqrt(v.x() * v.x() + v.y() * v.y());
            QPointF offset = QPoint(v.x() / length * vertR, v.y() / length * vertR);
            painter->drawLine(p1 + offset, p2 - offset);

            // Draw arrow
            double size = 5;
            QPointF arrowTop = p2 - offset;
            QPointF arrowDir = (v / length) * size;
            QPointF arrowL = arrowTop - arrowDir + QPointF(arrowDir.y(), -arrowDir.x());
            QPointF arrowR = arrowTop - arrowDir + QPointF(-arrowDir.y(), arrowDir.x());
            painter->drawPolygon(QPolygonF() << arrowTop << arrowL << arrowR);
        }
    }
}
