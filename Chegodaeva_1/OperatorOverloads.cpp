#include "OperatorOverloads.h"
using namespace std;


ostream& operator << (ostream& out, const tube& NewTube)
{
    out << "�������� �����: " << NewTube.name << endl
        << "����� �����: " << NewTube.length << endl
        << "������� �����: " << NewTube.diameter << endl
        << "������ �����: " << NewTube.status << endl;
    return out;
}

ostream& operator << (ostream& out, const cs& NewCS)
{
    out << "�������� ������������� �������: " << NewCS.name << endl
        << "���������� ���� ����� ������������� �������: " << NewCS.workshops << endl
        << "���������� ���������� ����� ������������� �������: " << NewCS.working_workshops << endl
        << "������������� ������������� �������: " << NewCS.efficiency << endl;
    return out;
}

ofstream& operator << (ofstream& fout, const tube& NewTube)
{
    fout << NewTube.name << endl << NewTube.length << endl << NewTube.diameter << endl << NewTube.status << endl;
    return fout;
}

ofstream& operator << (ofstream& fout, const cs& NewCS)
{
    fout << NewCS.name << endl << NewCS.workshops << endl << NewCS.working_workshops << endl << NewCS.efficiency << endl;
    return fout;
}

ifstream& operator >> (ifstream& fin, tube& NewTube)
{
    fin >> NewTube.name;
    fin >> NewTube.length;
    fin >> NewTube.diameter;
    fin >> NewTube.status;
    return fin;
}

ifstream& operator >> (ifstream& fin, cs& NewCS)
{
    fin >> NewCS.name;
    fin >> NewCS.workshops;
    fin >> NewCS.working_workshops;
    fin >> NewCS.efficiency;
    return fin;
}

istream& operator >> (istream& in, tube& NewTube)
{
    cout << "������� �������� �����:" << endl;
    in >> ws;
    getline(cin, NewTube.name);

    cout << "������� ����� �����: " << endl;
    NewTube.length = CheckingValues(1, 100000);

    cout << "������� ������� �����: " << endl;
    NewTube.diameter = CheckingValues(1, 1500);

    cout << "������� ������ �����: "
        << "0 - �� �������� "
        << "1 - �������� " << endl;
    NewTube.status = CheckingValues(0, 1);
    return in;
}

istream& operator >> (istream& in, cs& NewCS)
{
    cout << "������� �������� ������������� �������:" << endl;
    in >> ws;
    getline(cin, NewCS.name);

    cout << "������� ���������� ���� ����� ������������� �������:" << endl;
    NewCS.workshops = CheckingValues(1, 10000);

    cout << "������� ���������� ���������� ����� ������������� �������:" << endl;
    NewCS.working_workshops = CheckingValues(0, NewCS.workshops);

    cout << "������� ������������� ������������� ������� �� 0 �� 100:" << endl;
    NewCS.efficiency = CheckingValues(0, 100);

    return in;
}