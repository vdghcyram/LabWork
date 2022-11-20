#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "tube.h"
#include "cs.h"

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
        << "0. Выход" << endl
        << "Введите номер пункта: ";
}

template <typename T>
bool CheckingValues(const T& Variable, T beginning = numeric_limits<T>::min(), T end = numeric_limits<T>::max())
{
    if (cin.fail() || cin.peek() != '\n' || Variable<beginning || Variable>end)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Введите корректные данные от " << beginning << " до " << end << endl;
        return false;
    } return true;
}

bool tube::EditTube()
{
    if (length = 0)
    {
        char check = '0';
        do {
            cout << "Введите обновлённый статус трубы: " << endl;
            cin >> check;
        } while (!CheckingValues(check, '0', '1'));
        if (check == '1')
        {
            status = true;
        }return false;
    }return true;
}

void cs::EditCS()
{
    if (workshops = 0)
    {
        char check = '0';
        do {
            cout << "Введите обновлённое количество работающих цехов компрессорной станции: " << endl;
            cin >> check;
        } while (!CheckingValues(check, '0', '1'));
        if (check == '1')
        {
            working_workshops = true;
        }
    }return;
}

ofstream& operator << (ofstream& fout, tube& NewTube)
{
    fout /*<< NewTube.id*/ /*<< endl*/ << NewTube.length << endl << NewTube.diameter << endl << NewTube.status << endl;
    return fout;
}

ofstream& operator << (ofstream& fout, cs& NewCS)
{
    fout /*<< NewCS.id*/ /*<< endl*/ << NewCS.name << endl << NewCS.workshops << endl << NewCS.working_workshops << endl << NewCS.efficiency << endl;
    return fout;
}

void SaveAll(const vector <tube>& GroupTube, const vector <cs>& GroupCS)
{
    ofstream fout;
    fout.open("data.txt", ios::out);
    if (fout.is_open())
    {
        cout << "1. Сохранить информацию по трубам" << endl
            << "2. Сохранить информацию по компрессорным станциям" << endl
            << "3. Сохранить информацию по всем объектам" << endl;
        int i = 0;
        do {
            cin >> i;
        } while (!CheckingValues(i, 1, 3));

        switch (i)
        {
        case 1:
        {
            if (GroupTube.size() != 0)
            {
                for (tube NewTube : GroupTube)
                {
                    fout << GroupTube.size() << endl;
                    fout << NewTube;
                }
            }
            else
                cout << "Введены некорректные данные, сначала добавьте характеристики по трубам" << endl;
            break;
        }
        case 2:
        {
            if (GroupCS.size() != 0)
            {
            for (cs NewCS : GroupCS)
            {
                fout << GroupCS.size() << endl;
                fout << NewCS;
            }
            }
            else
                cout << "Введены некорректные данные, сначала добавьте характеристики по компрессорным станциям" << endl;
            break;
        }
        case 3:
        {
            if (GroupTube.size() != 0 || GroupCS.size() != 0)
            {
                for (tube NewTube : GroupTube)
                {
                    fout << GroupTube.size() << endl;
                    fout << NewTube;
                }
                for (cs NewCS : GroupCS)
                {
                    fout << GroupCS.size() << endl;
                    fout << NewCS;
                }
            }
            else
                cout << "Введены некорректные данные, сначала добавьте характеристики" << endl;
            break;
        }
        }
        fout.close();
    }
}

ifstream& operator >> (ifstream& fin, tube& NewTube) 
{
    /*fin >> NewTube.id;*/
    fin >> NewTube.length;
    fin >> NewTube.diameter;
    fin >> NewTube.status;
    return fin;
}

ifstream& operator >> (ifstream& fin, cs& NewCS)
{
    /*fin >> NewCS.id;*/
    fin >> NewCS.name;
    fin >> NewCS.workshops;
    fin >> NewCS.working_workshops;
    fin >> NewCS.efficiency;
    return fin;
}

void LoadAll(vector <tube>& GroupTube, vector <cs>& GroupCS)
{
    ifstream fin;
    fin.open("data.txt", ios::in);
    if (fin.is_open())
    {
        int NumberTube;
        int NumberCS;
        fin >> NumberTube;
        GroupTube.reserve(NumberTube);
        while (NumberTube--)
        {  
            tube NewTube;
            fin >> NewTube;
            GroupTube.push_back(NewTube);
        }
        fin >> NumberCS;
        GroupCS.reserve(NumberCS);
        while (NumberCS--) 
        {
            cs NewCS;
            fin >> NewCS;
            GroupCS.push_back(NewCS);
        }
        fin.close();
    }
}

ostream& operator << (ostream& out, const tube& NewTube)
{
    out /*<< "ID: " << NewTube.id << endl*/
        << "Длина трубы: " << NewTube.length << endl
        << "Диаметр трубы: " << NewTube.diameter << endl
        << "Статус трубы: " << NewTube.status << endl;
    return out;
}

ostream& operator << (ostream& out, const cs& NewCS)
{
    out /*<< "ID: " << NewCS.id << endl*/
        << "Название компрессорной станции: " << NewCS.name << endl
        << "Количество всех цехов компрессорной станции: " << NewCS.workshops << endl
        << "Количество работающих цехов компрессорной станции: " << NewCS.working_workshops << endl
        << "Эффективность компрессорной станции: " << NewCS.efficiency << endl;
    return out;
}

tube& SelectTube(vector <tube>& GroupTube)
{
    int index;
    cout << "Введите ID трубы: ";
    do {
        cin >> index;
    } while (!CheckingValues(index, 1, (int)GroupTube.size()));
    return GroupTube[index - 1];
}

cs& SelectCS(vector <cs>& GroupCS)
{
    int index;
    cout << "Введите ID компрессорной станции: ";
    do {
        cin >> index;
    } while (!CheckingValues(index, 1, (int)GroupCS.size()));
    return GroupCS[index - 1];
}

void OutPut (const vector <tube>& GroupTube, const vector <cs>& GroupCS)
{
    cout << "1. Вывести информацию по трубам" << endl
        << "2. Вывести информацию по компрессорным станциям" << endl
        << "3. Вывести информацию по всем объектам" << endl;
    int i = 0;
    do {
        cin >> i;
    } while (!CheckingValues(i, 1, 3));

    switch (i)
    {
        case 1:
        {
            for (tube NewTube : GroupTube)
            {
                cout << NewTube << endl;
            }return;
        }
        case 2:
        {
            for (cs NewCS : GroupCS)
            {
                cout << NewCS << endl;
            }return;
        }
        case 3:
        {
            for (tube NewTube : GroupTube)
            {
                cout << NewTube << endl;
            }return;
            for (cs NewCS : GroupCS)
            {
                cout << NewCS << endl;
            }return;
        } }
}

istream& operator >> (istream& in, tube& NewTube)
{
    do {
        cout << "Введите длину трубы: " << endl;
        cin >> NewTube.length;
    } while (!CheckingValues(NewTube.length, 0.0001));
    do {
        cout << "Введите диаметр трубы: " << endl;
        cin >> NewTube.diameter;
    } while (!CheckingValues(NewTube.diameter, 0.0001));
    char check = '0';
    do {
        cout << "Введите статус трубы: 1 - рабочее; 0 - в ремонте: " << endl;
        cin >> check;
    } while (!CheckingValues(check, '0', '1'));
    if (check == '1')
    {
        NewTube.status = true;
    }return in;
}

istream& operator >> (istream& in, cs& NewCS)
{
    cout << "Введите название компрессорной станции:" << endl;
    in >> ws;
    getline(cin, NewCS.name);
    do {
        cout << "Введите количество всех цехов компрессорной станции:" << endl;
        cin >> NewCS.workshops;
    } while (!CheckingValues(NewCS.workshops, 1));
    do {
        cout << "Введите количество работающих цехов компрессорной станции:" << endl;
        cin >> NewCS.working_workshops;
    } while (!CheckingValues(NewCS.working_workshops, 0, NewCS.workshops));
    do {
        cout << "Введите эффективность компрессорной станции от 0 до 100:" << endl;
        cin >> NewCS.efficiency;
    } while (!CheckingValues(NewCS.efficiency, 0, 100));
    return in;
}

int main()
{
    setlocale(LC_ALL, "rus"); 
    vector <tube> GroupTube;
    vector <cs> GroupCS;
    tube NewTube();
    cs NewCS();

    while (true)
    {
        consol();
        int i = 0;
        do {
            cin >> i;
        } while (!CheckingValues(i, 0,7));

        switch (i)
        {
            case 1:
            {
                tube NewTube;
                cin >> NewTube;
                GroupTube.push_back(NewTube);
                break;
            }
            case 2:
            {
                cs NewCS;
                cin >> NewCS;
                GroupCS.push_back(NewCS);
                break;
            }
            case 3:
            {
                OutPut(GroupTube, GroupCS);
                break;
            }
            case 4:
            {
                if (GroupTube.size() != 0)
                {
                    SelectTube(GroupTube).EditTube();
                }
                else
                    cout << "Введены некорректные данные, сначала добавьте характеристики трубы" << endl;
                break;
            }
            case 5:
            {
                if (GroupCS.size() != 0)
                {
                    SelectCS(GroupCS).EditCS();
                }
                else
                    cout << "Введены некорректные данные, сначала добавьте характеристики" << endl;
                break;
            }
            case 6:
            {
                SaveAll(GroupTube, GroupCS);
                break;
            }
            case 7:
            {
                LoadAll(GroupTube, GroupCS);
                break;
            }
            case 0:
            {
                return 0;
            }
            default:
            {
                cout << "Введите корректное значение пункта из меню:" << endl;
            }
        }}
}