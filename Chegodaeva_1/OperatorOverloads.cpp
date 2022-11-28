#include "OperatorOverloads.h"
using namespace std;


ostream& operator << (ostream& out, const tube& NewTube)
{
    out << "Название трубы: " << NewTube.name << endl
        << "Длина трубы: " << NewTube.length << endl
        << "Диаметр трубы: " << NewTube.diameter << endl
        << "Статус трубы: " << NewTube.status << endl;
    return out;
}

ostream& operator << (ostream& out, const cs& NewCS)
{
    out << "Название компрессорной станции: " << NewCS.name << endl
        << "Количество всех цехов компрессорной станции: " << NewCS.workshops << endl
        << "Количество работающих цехов компрессорной станции: " << NewCS.working_workshops << endl
        << "Эффективность компрессорной станции: " << NewCS.efficiency << endl;
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
    cout << "Введите название Трубы:" << endl;
    in >> ws;
    getline(cin, NewTube.name);

    cout << "Введите длину трубы: " << endl;
    NewTube.length = CheckingValues(1, 100000);

    cout << "Введите диаметр трубы: " << endl;
    NewTube.diameter = CheckingValues(1, 1500);

    cout << "Введитк статус трубы: "
        << "0 - не работает "
        << "1 - работает " << endl;
    NewTube.status = CheckingValues(0, 1);
    return in;
}

istream& operator >> (istream& in, cs& NewCS)
{
    cout << "Введите название компрессорной станции:" << endl;
    in >> ws;
    getline(cin, NewCS.name);

    cout << "Введите количество всех цехов компрессорной станции:" << endl;
    NewCS.workshops = CheckingValues(1, 10000);

    cout << "Введите количество работающих цехов компрессорной станции:" << endl;
    NewCS.working_workshops = CheckingValues(0, NewCS.workshops);

    cout << "Введите эффективность компрессорной станции от 0 до 100:" << endl;
    NewCS.efficiency = CheckingValues(0, 100);

    return in;
}