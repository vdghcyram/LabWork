#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class tube
{
private:
    double length;
    double diameter;
    bool status;
    int id;

public:
    tube()
    {
        length = 0;
        diameter = 0;
        status = 0;
       
    }

    void EditTube();
    friend istream& operator >> (istream& in, tube& NewTube);
    friend ifstream& operator >> (ifstream& fin, tube& NewTube);
    friend ofstream& operator << (ofstream& fout, tube& NewTube);
    friend ostream& operator << (ostream& out, const tube& NewTube);
};

