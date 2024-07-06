#include "application.h"
#include "matrix.h"
#include "common.h"

Application::Application(int argc, char *argv[])
    : QCoreApplication(argc,argv)
{
    CommParams pars = { QHostAddress("127.0.0.1"), 10000,
                        QHostAddress("127.0.0.1"), 10001};
    comm = new Communicator(pars, this);

    connect(comm,SIGNAL(recieved(QByteArray)),this,SLOT(recieve(QByteArray)));
}

void Application::recieve(QByteArray msg)
{
    QString answer, s = "";
    Rational val1,val2,val3,val4,val5,val6,val7,val8,val9;
    msg>>val1>>val2>>val3>>val4>>val5>>val6>>val7>>val8>>val9;
    matrix Obj;
    Obj.input(val1,val2,val3,val4,val5,val6,val7,val8,val9);
    int pos = msg.indexOf(";");
    int t = msg.left(pos).toInt();
    switch (t)
    {
    case SHOWMATRIX:
        msg = msg.right(msg.length()-pos-1);
        Obj.show(s);
        answer<<QString().setNum(SHOWMATRIX);
        answer += s;
        break;
    case DETERMINANT:
        s<<Obj.MatrDeterminant();
        answer<<QString().setNum(DETERMINANT)<<s;
        break;
    case RANKOFMATRIX:
        s<< QString().setNum(Obj.rankOfMatrix3x3());
        answer<<QString().setNum(RANKOFMATRIX)<<s;
        break;
    case TRANSPOSEDMATRIX:
        Obj.transposition();
        Obj.show(s);
        answer<<QString().setNum(TRANSPOSEDMATRIX)<<s;
        break;
    default: return;
    }
    comm->send(QByteArray().append(answer.toStdString()));
}
