﻿#include <iostream>
#include <fstream>

using namespace std;

void consol()
{
    cout << "Меню:" << endl
        << "1. Добавить трубу" << endl
        << "2. Добавить КС" << endl
        << "3. Просмотр всех объектов" << endl
        << "4. Редактировать трубу" << endl
        << "5. Редактировать КС" << endl
        << "6. Сохранить" << endl
        << "7. Загрузить" << endl
        << "0. Выход" << endl;
}

struct tube
{
    double length;
    double diameter;
    bool status;
};

void InputTube()
{
    tube NewTube;
    cout << "Введите длину трубы:";
    cin >> NewTube.length;
    cout << "Введите диаметр трубы:";
    cin >> NewTube.diameter;
    cout << "Введите статус трубы: 1 - рабочее; 0 - в ремонте:";
    cin >> NewTube.status;
}

void PrintTube(const tube& NewTube)
{
    cout << "Длина трубы:" << NewTube.length
        << "\tДиаметр трубы:" << NewTube.diameter
        << "\tСтатус трубы:" << NewTube.status <<endl;
}


void EditTube(tube& NewTube)
{
    cout << "Введите обновлённый статус трубы:";
    cin >> NewTube.status;
}

struct cs
{
    string name;
    int workshops;
    int working_workshops;
    double efficiency;
};

void InputCS()
{
    cs NewCS;
    cout << "Введите название компрессорной станции:";
    cin >> NewCS.name;
    cout << "Введите количество всех цехов компрессорной станции:";
    cin >> NewCS.workshops;
    cout << "Введите количество работающих цехов компрессорной станции:";
    cin >> NewCS.working_workshops;
    cout << "Введите эффективность компрессорной станции:";
    cin >> NewCS.efficiency;
}

void PrintCS(const cs& NewCS)
{
    cout << "Название компрессорной станции:" << NewCS.name
        << "\tКоличество всех цехов компрессорной станции" << NewCS.workshops
        << "\tКоличество работающих цехов компрессорной станции:" << NewCS.working_workshops
        << "\tЭффективность компрессорной станции:" << NewCS.efficiency << endl;
}

void EditCS(cs& NewCS)
{
    cout << "Введите обновлённое количество работающих цехов компрессорной станции:";
    cin >> NewCS.working_workshops;
}

void SaveAll(const tube& NewTube, const cs& NewCS)
{
    ofstream fout;
    fout.open("data.txt", 'w');
    fout << NewTube.length << endl << NewTube.diameter << endl << NewTube.status << endl;
    fout << NewCS.name << endl << NewCS.workshops << endl << NewCS.working_workshops << endl << NewCS.efficiency << endl;
    fout.close();
}

void DownloadAll()
{
    ifstream fin;
    fin.open("data.txt", 'r');
    tube NewTube;
    fin >> NewTube.length;
    fin >> NewTube.diameter;
    fin >> NewTube.status;
    cs NewCS;
    fin >> NewCS.name;
    fin >> NewCS.workshops;
    fin >> NewCS.working_workshops;
    fin >> NewCS.efficiency;
}

int main()
{
    setlocale(LC_ALL, "rus");       //Поддержка русского языка
    consol();
    int x;
    switch (cin >> x)
        case 1:
            InputTube();
            break;
        case 2:
            InputCS();
            break;
        case 3:
            PrintTube();
            break;
        case 4:
            edit_tube();
            break;
        case 5:
            edit_ks();
            break;
        case 6:
            SaveAll();
            break;
        case 7:
            DownloadAll();
            break;

}