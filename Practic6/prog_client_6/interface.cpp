#include "interface.h"
#include "common.h"
#include <QInputDialog>
using namespace std;

Interface::Interface(QWidget *parent)
    : QWidget(parent){

    setWindowTitle("Практическая работа № 6");
    setFixedSize(750, 750);
    QString val = QInputDialog::getText(this,"Размерность матрицы", "Введите размерность: ");
    qDebug() << val;
    n = val.toInt() * val.toInt();
    int sqrt_n = val.toInt();

    name_values = new QLabel* [n];
    values_a = new QLineEdit* [n];
    values_b = new QLineEdit* [n];
    QString label;
    int x = 20, y = 0;


    for(int i = 0; i < n; i++){
        if((i%sqrt_n == 0)){
            x = 20;
            y+= 20;
        }
        else x += 125;
        label = QString().setNum(i+1) + ") :=";

        name_values[i] = new QLabel(label, this);
        name_values[i]->setGeometry(x,y,30,25);
        values_a[i] = new QLineEdit("1", this);
        values_a[i]->setGeometry(x+40,y,30,25);
        skobka = new QLabel("", this);
        skobka->setGeometry(x+70,y,10,25);
        values_b[i] = new QLineEdit("1", this);
        values_b[i]->setGeometry(x+80,y,30,25);

    }
    x = 50;
    y += 40;
    Determinant = new QPushButton("Детерминант", this);
    Determinant->setGeometry(x-40,y,120,30);
    TransposedMatrix = new QPushButton("Транспон.", this);
    TransposedMatrix->setGeometry(x+90,y,120,30);
    RankMatrix = new QPushButton("Ранк матрицы", this);
    RankMatrix->setGeometry(x+220,y,120,30);
    OutPutMatr = new QPushButton("Матрица", this);
    OutPutMatr->setGeometry(x+350,y,120,30);

    y+=60;
    d_mode = new QRadioButton("вещественные", this);
    d_mode->setGeometry(x-40,y,120,30);
    r_mode = new QRadioButton("рациональные", this);
    r_mode->setGeometry(x+80,y,120,30);
    c_mode = new QRadioButton("комплексные", this);
    c_mode->setGeometry(x+200,y,120,30);

    d_mode->setChecked(true);

    y+=50;
    Output = new QLabel(this);
    Output->setGeometry(x-40,y,300,150);

    connect(Determinant,SIGNAL(pressed()),this,SLOT(formRequest()));
    connect(TransposedMatrix,SIGNAL(pressed()),this,SLOT(formRequest()));
    connect(RankMatrix,SIGNAL(pressed()),this,SLOT(formRequest()));
    connect(OutPutMatr,SIGNAL(pressed()),this,SLOT(formRequest()));

}


void Interface::formRequest()
{
    QString msg;
    if(d_mode->isChecked()){
        msg += QString().setNum(D_MODE) + ";";
        msg += QString().setNum(n) + ";";
        for(int i = 0; i < n; i++){
            msg<<values_a[i]->text();
        }
    }
    else if(r_mode->isChecked()){
        msg += QString().setNum(R_MODE) + ";";
        msg += QString().setNum(n) + ";";
        for(int i = 0; i < n; i++){
            msg<<values_a[i]->text()<<values_b[i]->text();
        }
    }
    else if(c_mode->isChecked()){
        msg += QString().setNum(C_MODE) + ";";
        msg += QString().setNum(n) + ";";
        for(int i = 0; i < n; i++){
            msg<<values_a[i]->text()<<values_b[i]->text();
        }
    }

    QPushButton *btn = (QPushButton*)sender();
    if(btn == Determinant)
        msg << QString().setNum(DETERMINANT);

    if (btn == TransposedMatrix)
        msg << QString().setNum(TRANSPOSEDMATRIX);

    if (btn == RankMatrix)
        msg << QString().setNum(RANKOFMATRIX);

    if (btn == OutPutMatr)
        msg << QString().setNum(SHOWMATRIX);

    emit request(msg);
}

void Interface::answer(QString msg)
{
    QString text;
    int p = msg.indexOf(";");
    int t = msg.left(p).toInt();
    msg = msg.mid(p+1,msg.length()-p-2);

    switch (t)
    {
    case SHOWMATRIX:
        text = "The Matrix:\n";
        p = msg.indexOf(separator);
        text += msg.left(p);
        Output->setText(text);
        break;
    case TRANSPOSEDMATRIX:
        text = "The Transposed Matrix:\n";
        p = msg.indexOf(separator);
        text += msg.left(p);
        Output->setText(text);
        break;
    case RANKOFMATRIX:
        text = "The rank = ";
        text += msg;
        Output->setText(text);
        break;
    case DETERMINANT:
        text = "The Determinant = ";
        text += msg;
        Output->setText(text);
        break;
    default: break;
    }
}

Interface::~Interface()
{
    delete ValueMatr;
    delete Matr;

    delete[] name_values;
    delete skobka;
    delete[] values_a;
    delete[] values_b;

    delete d_mode;
    delete r_mode;
    delete c_mode;
}
