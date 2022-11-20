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
        << "8. Удалить трубу" << endl
        << "9. Удалить КС" << endl
        << "0. Выход" << endl
        << "Введите номер пункта: ";
}

template <typename T>
T CheckingValues(T beginning = numeric_limits<T>::min(), T end = numeric_limits<T>::max())
{   
    T variable;
    cin >> variable;
    while (cin.fail() || cin.peek() != '\n' || variable<beginning || variable>end)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Введите корректные данные от " << beginning << " до " << end << endl;
        cin >> variable;
    } 
    return variable;
}

void tube::EditTube()
{
    cout << "Введите обновленный статус трубы: 1 - рабочее; 0 - в ремонте: " << endl;
    status = CheckingValues(0, 1);
}

void cs::EditCS()
{
    cout << "Введите обновленное количество работающих цехов компрессорной станции:" << endl;
    working_workshops = CheckingValues(0, workshops);
}

void DeleteCS(vector <cs>& GroupCS)
{
    int index;
    cout << "Введите index компрессорной станции: ";
    index = CheckingValues(0, cs::MaxID);
    
    GroupCS.erase(GroupCS.begin()+index);
}

void DeleteTube(vector <tube>& GroupTube)
{
    int index;
    cout << "Введите index трубы: ";
    index = CheckingValues(0, tube::MaxID);
    
    GroupTube.erase(GroupTube.begin()+index);
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
        
        int i = CheckingValues(1, 3);

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
    out << "ID: " << NewTube.id << endl
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
    index = CheckingValues(0, (int)GroupTube.size() - 1);
    
    return GroupTube[index];
}

cs& SelectCS(vector <cs>& GroupCS)
{
    int index;
    cout << "Введите ID компрессорной станции: ";
    index = CheckingValues(0, (int)GroupCS.size() - 1);
    
    return GroupCS[index];
}

void OutPut (const vector <tube>& GroupTube, const vector <cs>& GroupCS)
{
    cout << "1. Вывести информацию по трубам" << endl
        << "2. Вывести информацию по компрессорным станциям" << endl
        << "3. Вывести информацию по всем объектам" << endl;
    
    int i = CheckingValues(1, 3);

    switch (i)
    {
        case 1:
        {
            for (tube NewTube : GroupTube)
            {
                cout << NewTube << endl;
            }
            break;
        }
        case 2:
        {
            for (cs NewCS : GroupCS)
            {
                cout << NewCS << endl;
            }
            break;
        }
        case 3:
        {
            for (tube NewTube : GroupTube)
            {
                cout << NewTube << endl;
            }
            for (cs NewCS : GroupCS)
            {
                cout << NewCS << endl;
            }
            break;
        }
    }
}

istream& operator >> (istream& in, tube& NewTube)
{
    
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
    CheckingValues(1, 10000);
   
    cout << "Введите количество работающих цехов компрессорной станции:" << endl;
    NewCS.working_workshops = CheckingValues(0, NewCS.workshops);
    
    cout << "Введите эффективность компрессорной станции от 0 до 100:" << endl;
    NewCS.efficiency = CheckingValues(0, 100);
   
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
        int i = CheckingValues(0, 9);
        
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
            case 8:
            {

                if (GroupTube.size() != 0)
                {
                    DeleteTube(GroupTube);
                }
                else
                    cout << "Введены некорректные данные, сначала добавьте характеристики трубы" << endl;
                break;
            }
            case 9:
            {
                if (GroupCS.size() != 0)
                {
                    DeleteCS(GroupCS);
                }
                else
                    cout << "Введены некорректные данные, сначала добавьте характеристики компрессорной станции" << endl;
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