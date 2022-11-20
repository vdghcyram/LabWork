#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class cs
{
private:
    string name;
    int workshops;
    int working_workshops;
    int efficiency;
    int id;

public:
    cs() 
    {
        name = "";
        workshops = 0;
        working_workshops = 0;
        efficiency = 0; 
        
    }

    void EditCS();
    friend istream& operator >> (istream& in, cs& NewCS);
    friend ostream& operator << (ostream& out, const cs& NewCS);
    friend ifstream& operator >> (ifstream& fin, cs& NewCS);
    friend ofstream& operator << (ofstream& fout, cs& NewCS);
};

