#ifndef INTERFACE_H
#define INTERFACE_H


#include "sample.h"

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>>


class Interface : public QWidget {
private:
    Q_OBJECT

    QPushButton *ChangeBtnFile;
    Sample *sample;

public:
    explicit Interface(Sample*, QWidget *parent = nullptr);
    ~Interface() override;

protected:
    void paintEvent(QPaintEvent*) override;

public slots:
    void changeFile();
};


#endif // INTERFACE_H
