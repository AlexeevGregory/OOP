#include "application.h"
#include "number.h"
#include "matrix.h"
#include <iostream>

using namespace std;

Application::Application()
{

}

int Application::menu()
{
    int choice;
    cout << "1 - input new values" << endl;
    cout << "2 - value of the determinant" << endl;
    cout << "3 - transposed matrix" << endl;
    cout << "4 - the rank of the matrix" << endl;
    cout << "5 - output values of the matrix" << endl;
    cout << "0 - exit" << endl;
    cout << "> ";
    cin >> choice;
    return choice;
}
int Application::exec()
{
    int choice;
    number Matrix[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    matrix action;
    while(true)
    {
        choice = menu();
        switch (choice) {
        case 1:
            action.input(Matrix);
            break;
        case 2:
            cout << "The value of determinant is " << action.determinant(Matrix) << endl;
            break;
        case 3:
            action.transposition(Matrix);
            break;
        case 4:
            cout << "The rank of matrix is " << action.rankOfMatrix3x3(Matrix) << endl;
            break;
        case 5:
            action.show(Matrix);
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }
}
