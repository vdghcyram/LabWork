#pragma once
#include <iostream>
#include <fstream>
using namespace std;


class tube
{
private:
    string name;
    double length;
    double diameter;
    bool status;
    

public:
    static int MaxID;
    tube()
    {
        name ="";
        length = 0;
        diameter = 0;
        status = 0;
        ++MaxID;
    }
    void EditTube();

    template<typename T>
    friend void ChangingID(T Object);
    friend istream& operator >> (istream& in, tube& NewTube);
    friend ifstream& operator >> (ifstream& fin, tube& NewTube);
    friend ofstream& operator << (ofstream& fout,const tube& NewTube);
    friend ostream& operator << (ostream& out, const tube& NewTube);
};