#ifndef INTERFACE_H
#define INTERFACE_H


#include "sample.h"
#include "derivesample.h"

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QMouseEvent>


class Interface : public QWidget {
private:
    Q_OBJECT

    QPushButton *ChangeBtnFile;
    Sample *sample;
    Derivesample* derivesample;

public:
    explicit Interface(Derivesample*, QWidget *parent = nullptr);
    ~Interface() override;

protected:
    void mousePressEvent(QMouseEvent*);
    void paintEvent(QPaintEvent*) override;

public slots:
    void changeFile();
};


#endif // INTERFACE_H
