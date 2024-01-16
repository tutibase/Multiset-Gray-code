#include <iostream>
#include "universum.h"
#include <locale.h>
#include "multiset.h"
#include<windows.h>
using namespace std;

int main() {
    setlocale(0, "");
    srand(time(0));
    SetConsoleOutputCP(CP_UTF8);

    universum Universum;
    Universum.Out();

    multiset A(&Universum);
    multiset B(&Universum);
    multiset C(&Universum, 1);
    cout << "\nA ";
    A.Out();
    cout << "\nB ";
    B.Out();

    int i = 1;
    bool flag = 1;
    while (flag)
    {
        
        switch (i) {
        case 0:
            flag = 0;
            break;

        case 1:
            help();
            break;

        case 2:
            Universum.Out();
            break;

        case 3:
            cout << "\nA ";
            A.Out();
            break;

        case 4:
            cout << "\nB ";
            B.Out();
            break;

        case 5:
            cout << "\n¬A ";
            C.addition(A);
            C.Out();
            break;

        case 6:
            cout << "\n¬B ";
            C.addition(B);
            C.Out();
            break;

        case 7:
            cout << "\nобъединение A и B ";
            C.unionS(A, B);
            C.Out();
            break;

        case 8:
            cout << "\nпересечение A и B ";
            C.intersection(A, B);
            C.Out();
            break;

        case 9:
            cout << "\nA\\B ";
            C.difference(A, B);
            C.Out();
            break;

        case 10:
            cout << "\nB\\A ";
            C.difference(B, A);
            C.Out();
            break;

        case 11:
            cout << "\nсимметрическая разность A и B ";
            C.simDifference(A, B);
            C.Out();
            break;

        case 12:
            cout << "\nсимметрическая разность B и A ";
            C.simDifference(B, A);
            C.Out();
            break;

        case 13:
            cout << "\nA-B ";
            C.arifDifference(A, B);
            C.Out();
            break;

        case 14:
            cout << "\nB-A ";
            C.arifDifference(B, A);
            C.Out();
            break;

        case 15:
            cout << "\nA*B ";
            C.arifMultiplication(A, B);
            C.Out();
            break;

        default:
            break;
        }

        if (flag) i = intInput("\nВведите цифру [0; 15]\n", 15);
    }
}