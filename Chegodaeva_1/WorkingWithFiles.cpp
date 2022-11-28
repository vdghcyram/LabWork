#include "WorkingWithFiles.h"

string FileName()
{
    cout << endl << "¬ведите им€ файла: " << endl;
    string way = "";
    cin >> ws;
    getline(cin, way);
    way.insert(0, "./Saves/");
    way.append(".txt");
    return way;
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

void LoadAll(unordered_map<int, tube>& GroupTube, unordered_map<int, cs>& GroupCS)
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

        while (NumberTube > 0)
        {
            tube NewTube;
            fin >> id;
            fin >> NewTube;
            GroupTube1.emplace(id, NewTube);
            --NumberTube;
        }
        while (NumberCS > 0)
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
                fout << elem.second << endl;
            }
            for (auto& elem : GroupCS)
            {
                fout << elem.first << endl;
                fout << elem.second << endl;
            }
        }
        else
            cout << "¬ведены некорректные данные, сначала добавьте характеристики" << endl;
    }
    fout.close();
}