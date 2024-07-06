#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Interface : public QWidget
{
    Q_OBJECT

    QLabel **name_values, *skobka, *Matr;
    QLineEdit **values_a, **values_b, *ValueMatr;
    int n;

//    friend QString& operator<< (QString&,const QString&);

    QPushButton *NewMatrix;
    QPushButton *Determinant;
    QPushButton *TransposedMatrix;
    QPushButton *RankMatrix;
    QPushButton *OutPutMatr;


    QLabel *Output;

public:
    Interface(QWidget *parent = 0);
    ~Interface();

public slots:
    void answer(QString);
private slots:
    void formRequest();

signals:
    void request(QString);

};

#endif // INTERFACE_H
