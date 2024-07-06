#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "matrix.h"

class Interface : public QWidget
{
    Q_OBJECT

    QLabel *name_value1, *skobka1;
    QLineEdit *val1_a, *val1_b;

    QLabel *name_value2, *skobka2;
    QLineEdit *val2_a, *val2_b;

    QLabel *name_value3, *skobka3;
    QLineEdit *val3_a, *val3_b;

    QLabel *name_value4, *skobka4;
    QLineEdit *val4_a, *val4_b;

    QLabel *name_value5, *skobka5;
    QLineEdit *val5_a, *val5_b;

    QLabel *name_value6, *skobka6;
    QLineEdit *val6_a, *val6_b;

    QLabel *name_value7, *skobka7;
    QLineEdit *val7_a, *val7_b;

    QLabel *name_value8, *skobka8;
    QLineEdit *val8_a, *val8_b;

    QLabel *name_value9, *skobka9;
    QLineEdit *val9_a, *val9_b;



    QPushButton *Determinant;
    QPushButton *TransposedMatrix;
    QPushButton *RankMatrix;
    QPushButton *OutPutMatr;


    QLabel *Output;

public:
    Interface(QWidget *parent = nullptr);
    ~Interface();
public slots:
    void determinant();
    void Transpose();
    void rankofmatrix();
    void output();
};
#endif // INTERFACE_H
