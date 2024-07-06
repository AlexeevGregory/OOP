#ifndef DERIVESAMPLE_H
#define DERIVESAMPLE_H

#include "sample.h"

class Derivesample : public Sample
{
    int active;
public:
    explicit Derivesample(Graph*);
    void draw(QPainter*,QRect);
    void newEvent(bool);
};

#endif // DERIVESAMPLE_H
