#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "tube.h"
#include "cs.h"

ostream& operator << (ostream& out, const tube& NewTube);
ostream& operator << (ostream& out, const cs& NewCS);
ofstream& operator << (ofstream& fout, const tube& NewTube);
ofstream& operator << (ofstream& fout, const cs& NewCS);
ifstream& operator >> (ifstream& fin, tube& NewTube);
ifstream& operator >> (ifstream& fin, cs& NewCS);
istream& operator >> (istream& in, tube& NewTube);
istream& operator >> (istream& in, cs& NewCS);

template <typename T>
T CheckingValues(T beginning = numeric_limits<T>::min(), T end = numeric_limits<T>::max())
{
    T variable;
    cin >> variable;
    while (cin.fail() || cin.peek() != '\n' || variable<beginning || variable>end)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "¬ведите корректные данные от " << beginning << " до " << end << endl;
        cin >> variable;
    }
    return variable;
}