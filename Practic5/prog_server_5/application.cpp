#include "application.h"
#include "square_matrix.h"
#include "common.h"
#include "math.h"
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
    int pos = msg.indexOf(";");
    int n = msg.left(pos).toInt();
    msg = msg.right(msg.length()-pos-1);
    int sqrt_n = sqrt(n);
    number** Arr = new number* [sqrt_n];
    for(int i = 0; i < pow(n,0.5); i++){
        Arr[i] = new number[sqrt_n];
    }
    for(int i = 0; i < sqrt(n); i++){
        for(int j = 0; j < sqrt(n); j++){
            msg >> Arr[i][j];
        }
    }
    int t = msg.left(pos).toInt();
    square_matrix Obj(sqrt_n);
    Obj.input(Arr, sqrt_n);
    switch (t)
    {
    case SHOWMATRIX:
        msg = msg.right(msg.length()-pos-1);
        Obj.show(s, n);
        answer<<QString().setNum(SHOWMATRIX);
        answer += s;
        break;
    case DETERMINANT:
        s<<Obj.MatrDeterminant(sqrt_n);
        answer<<QString().setNum(DETERMINANT)<<s;
        break;
    case RANKOFMATRIX:
        s<< QString().setNum(Obj.findMatrixRank(sqrt_n));
        s = s.left(msg.length()-1);
        answer<<QString().setNum(RANKOFMATRIX)<<s;
        break;
    case TRANSPOSEDMATRIX:
        Obj.transposition(sqrt_n);
        Obj.show(s, n);
        answer<<QString().setNum(TRANSPOSEDMATRIX)<<s;
        break;
    default: return;
    }
    comm->send(QByteArray().append(answer.toStdString()));
}
