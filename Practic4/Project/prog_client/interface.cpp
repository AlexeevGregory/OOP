#include "interface.h"
#include "common.h"
using namespace std;

Interface::Interface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Практическая работа № 4");
    setFixedSize(600, 500);

    name_value1 = new QLabel("1) :=", this);
    name_value1->setGeometry(50,20,30,25);
    val1_a = new QLineEdit("1", this);
    val1_a->setGeometry(90,20,50,25);
    skobka1 = new QLabel("/", this);
    skobka1->setGeometry(150,20,10,25);
    val1_b = new QLineEdit("1", this);
    val1_b->setGeometry(160,20,50,25);

    name_value2 = new QLabel("2) :=", this);
    name_value2->setGeometry(50,40,30,25);
    val2_a = new QLineEdit("0", this);
    val2_a->setGeometry(90,40,50,25);
    skobka2 = new QLabel("/", this);
    skobka2->setGeometry(150,40,10,25);
    val2_b = new QLineEdit("1", this);
    val2_b->setGeometry(160,40,50,25);

    name_value3 = new QLabel("3) :=", this);
    name_value3->setGeometry(50,60,30,25);
    val3_a = new QLineEdit("0", this);
    val3_a->setGeometry(90,60,50,25);
    skobka3 = new QLabel("/", this);
    skobka3->setGeometry(150,60,10,25);
    val3_b = new QLineEdit("1", this);
    val3_b->setGeometry(160,60,50,25);

    name_value4 = new QLabel("4) :=", this);
    name_value4->setGeometry(50,80,30,25);
    val4_a = new QLineEdit("0", this);
    val4_a->setGeometry(90,80,50,25);
    skobka4 = new QLabel("/", this);
    skobka4->setGeometry(150,80,10,25);
    val4_b = new QLineEdit("1", this);
    val4_b->setGeometry(160,80,50,25);

    name_value5 = new QLabel("5) :=", this);
    name_value5->setGeometry(50,100,30,25);
    val5_a = new QLineEdit("1", this);
    val5_a->setGeometry(90,100,50,25);
    skobka5 = new QLabel("/", this);
    skobka5->setGeometry(150,100,10,25);
    val5_b = new QLineEdit("1", this);
    val5_b->setGeometry(160,100,50,25);

    name_value6 = new QLabel("6) :=", this);
    name_value6->setGeometry(50,120,30,25);
    val6_a = new QLineEdit("0", this);
    val6_a->setGeometry(90,120,50,25);
    skobka6 = new QLabel("/", this);
    skobka6->setGeometry(150,120,10,25);
    val6_b = new QLineEdit("1", this);
    val6_b->setGeometry(160,120,50,25);

    name_value7 = new QLabel("7) :=", this);
    name_value7->setGeometry(50,140,30,25);
    val7_a = new QLineEdit("0", this);
    val7_a->setGeometry(90,140,50,25);
    skobka7 = new QLabel("/", this);
    skobka7->setGeometry(150,140,10,25);
    val7_b = new QLineEdit("1", this);
    val7_b->setGeometry(160,140,50,25);

    name_value8 = new QLabel("8) :=", this);
    name_value8->setGeometry(50,160,30,25);
    val8_a = new QLineEdit("0", this);
    val8_a->setGeometry(90,160,50,25);
    skobka8 = new QLabel("/", this);
    skobka8->setGeometry(150,160,10,25);
    val8_b = new QLineEdit("1", this);
    val8_b->setGeometry(160,160,50,25);

    name_value9 = new QLabel("9) :=", this);
    name_value9->setGeometry(50,180,30,25);
    val9_a = new QLineEdit("1", this);
    val9_a->setGeometry(90,180,50,25);
    skobka9 = new QLabel("/", this);
    skobka9->setGeometry(150,180,10,25);
    val9_b = new QLineEdit("1", this);
    val9_b->setGeometry(160,180,50,25);


    Determinant = new QPushButton("Детерминант", this);
    Determinant->setGeometry(10,220,120,30);
    TransposedMatrix = new QPushButton("Транспон.", this);
    TransposedMatrix->setGeometry(140,220,120,30);
    RankMatrix = new QPushButton("Ранк матрицы", this);
    RankMatrix->setGeometry(270,220,120,30);
    OutPutMatr = new QPushButton("Матрица", this);
    OutPutMatr->setGeometry(400,220,120,30);


    Output = new QLabel(this);
    Output->setGeometry(10,300,300,150);

    connect(Determinant,SIGNAL(pressed()),this,SLOT(formRequest()));
    connect(TransposedMatrix,SIGNAL(pressed()),this,SLOT(formRequest()));
    connect(RankMatrix,SIGNAL(pressed()),this,SLOT(formRequest()));
    connect(OutPutMatr,SIGNAL(pressed()),this,SLOT(formRequest()));
}

void Interface::formRequest()
{
    QString msg;
    msg << val1_a->text() << val1_b->text();
    msg << val2_a->text() << val2_b->text();
    msg << val3_a->text() << val3_b->text();
    msg << val4_a->text() << val4_b->text();
    msg << val5_a->text() << val5_b->text();
    msg << val6_a->text() << val6_b->text();
    msg << val7_a->text() << val7_b->text();
    msg << val8_a->text() << val8_b->text();
    msg << val9_a->text() << val9_b->text();
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
    delete name_value1;
    delete skobka1;
    delete val1_a;
    delete val1_b;

    delete name_value2;
    delete skobka2;
    delete val2_a;
    delete val2_b;

    delete name_value3;
    delete skobka3;
    delete val3_a;
    delete val3_b;

    delete name_value4;
    delete skobka4;
    delete val4_a;
    delete val4_b;

    delete name_value5;
    delete skobka5;
    delete val5_a;
    delete val5_b;

    delete name_value6;
    delete skobka6;
    delete val6_a;
    delete val6_b;

    delete name_value7;
    delete skobka7;
    delete val7_a;
    delete val7_b;

    delete name_value8;
    delete skobka8;
    delete val8_a;
    delete val8_b;

    delete name_value9;
    delete skobka9;
    delete val9_a;
    delete val9_b;
}
