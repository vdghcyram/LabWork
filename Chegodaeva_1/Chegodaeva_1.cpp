#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "tube.h"
#include "cs.h"
#include <unordered_map>
#include "OperatorOverloads.h"

using namespace std;
void consol()
{
    cout << "Меню:" << endl
        << "1. Добавить трубу" << endl
        << "2. Добавить КС" << endl
        << "3. Просмотр всех объектов" << endl
        //<< "4. Редактировать трубу" << endl
        //<< "5. Редактировать КС" << endl
        << "6. Сохранить" << endl
        << "7. Загрузить" << endl
        //<< "8. Удалить трубу" << endl
        //<< "9. Удалить КС" << endl
        << "0. Выход" << endl
        << "Введите номер пункта: ";
}

/*
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


void DeleteCS(unordered_map<int, cs>& GroupCS)
{
    int index;
    cout << "Введите index компрессорной станции: ";
    index = CheckingValues(1, cs::MaxCSID);
    GroupCS.erase(index);
}

void DeleteTube(unordered_map<int, tube>& GroupTube)
{
    int index;
    cout << "Введите index трубы: ";
    index = CheckingValues(1, tube::MaxTubeID);
    
    GroupTube.erase(index);
}
*/


string FileName()
{
    cout << endl << "Введите имя файла: " << endl;
    string way = "";
    cin >> ws;
    getline(cin, way);
    way.insert(0, "./Saves/");
    way.append(".txt");
    return way;
}

void SaveAll(const unordered_map<int, tube>& GroupTube, const unordered_map<int, cs>& GroupCS)
{
    ofstream fout;

    string way = FileName();

    fout.open(way, ios::out);
    if (fout.is_open())
    {
            fout << GroupTube.size() << endl; 
            fout << GroupCS.size() << endl;
            if (GroupTube.size() != 0 || GroupCS.size() != 0)
            {
                for (auto& elem : GroupTube)
                {
                    fout << elem.first << endl;
                    fout <<  elem.second << endl;
                }
                for (auto& elem : GroupCS)
                {
                    fout << elem.first << endl;
                    fout << elem.second << endl;
                }
            }
            else
                cout << "Введены некорректные данные, сначала добавьте характеристики" << endl;
    }
    fout.close();
}

template<typename T>
void ChangingID(const unordered_map<int, T> Object)
{
    int MaxId = 1;
    for (const auto& elem : Object)
    {
        if (MaxId < elem.first)
        {
            MaxId = elem.first;
        }
    }
    T::MaxID = MaxId;
}

void LoadAll( unordered_map<int, tube>& GroupTube,  unordered_map<int, cs>& GroupCS)
{

    ifstream fin;
    string way = FileName();
    fin.open(way, ios::in);
    if (fin.is_open())
    {
        int NumberTube;
        int NumberCS;
        int id;
        fin >> NumberTube;
        fin >> NumberCS;
        unordered_map<int, tube> GroupTube1;
        unordered_map<int, cs> GroupCS1;

        while (NumberTube>0)
        {  
            tube NewTube;
            fin >> id;
            fin >> NewTube;
            GroupTube1.emplace(id, NewTube);
            --NumberTube;
        }
        while (NumberCS>0) 
        {
            cs NewCS;
            fin >> id;
            fin >> NewCS;
            GroupCS1.emplace(id, NewCS);
            --NumberCS;
        }
        GroupTube.swap(GroupTube1);
        GroupCS.swap(GroupCS1);
        ChangingID(GroupTube);
        ChangingID(GroupCS);
        fin.close();
    }
}

tube& SelectTube(unordered_map<int, tube>& GroupTube)
{
    int index;
    cout << "Введите ID трубы: ";
    index = CheckingValues(1, (int)GroupTube.size());
    
    return GroupTube[index];
}

cs& SelectCS(unordered_map<int, cs>& GroupCS)
{
    int index;
    cout << "Введите ID компрессорной станции: ";
    index = CheckingValues(1, (int)GroupCS.size());
    
    return GroupCS[index];
}

template<typename T>
void PrintObj(const unordered_map<int, T>& Obj)
{
        for (const auto& elem : Obj)
            {
                cout << "ID объекта: " << elem.first << endl;
                cout << elem.second << endl;
                cout << endl;
            }
}

void OutPut (const unordered_map<int, tube>& GroupTube,const unordered_map<int, cs>& GroupCS)
{
    cout << "1. Вывести информацию по трубам" << endl
        << "2. Вывести информацию по компрессорным станциям" << endl
        << "3. Вывести информацию по всем объектам" << endl;
    
    int i = CheckingValues(1, 3);

    switch (i)
    {
        case 1:
        {
            PrintObj(GroupTube);
            break;
        }
        case 2:
        {
            PrintObj(GroupCS);
            break;
        }
        case 3:
        {
            cout <<"Трубы: "<< endl;
            PrintObj(GroupTube);
            cout <<"Компрессорные станции: "<< endl;
            PrintObj(GroupCS);
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus"); 
    vector <tube> GroupTube;
    vector <cs> GroupCS;
    unordered_map<int, tube> GroupTube1;
    unordered_map<int, cs> GroupCS1;

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
                GroupTube1.emplace(NewTube.MaxID, NewTube);
                GroupTube.push_back(NewTube);
                break;
            }
            case 2:
            {
                cs NewCS;
                cin >> NewCS;
                GroupCS1.emplace(NewCS.MaxID, NewCS);
                GroupCS.push_back(NewCS);
                break;
            }
            case 3:
            {
                OutPut(GroupTube1, GroupCS1);
                break;
            }
            /*
            case 4:
            {
                if (GroupTube1.size() != 0)
                {
                    SelectTube(GroupTube1).EditTube();
                }
                else
                    cout << "Введены некорректные данные, сначала добавьте характеристики трубы" << endl;
                break;
            }
            case 5:
            {
                if (GroupCS1.size() != 0)
                {
                    SelectCS(GroupCS1).EditCS();
                }
                else
                    cout << "Введены некорректные данные, сначала добавьте характеристики" << endl;
                break;
            }
            */
            case 6:
            {
                SaveAll(GroupTube1, GroupCS1);
                break;
            }
            case 7:
            {
                LoadAll(GroupTube1, GroupCS1);
                break;
            }
            /*
            case 8:
            {

                if (GroupTube1.size() != 0)
                {
                    DeleteTube(GroupTube1);
                }
                else
                    cout << "Введены некорректные данные, сначала добавьте характеристики трубы" << endl;
                break;
            }
            case 9:
            {
                if (GroupCS1.size() != 0)
                {
                    DeleteCS(GroupCS1);
                }
                else
                    cout << "Введены некорректные данные, сначала добавьте характеристики компрессорной станции" << endl;
                break;
            }
            */
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