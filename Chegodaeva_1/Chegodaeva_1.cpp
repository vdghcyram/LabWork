#include <iostream>
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

struct tube
{
    double length;
    double diameter;
    bool status;
};

void InputTube(tube& NewTube)
{
    do{
        cout << "Введите длину трубы: " << endl;
        cin >> NewTube.length;
    }while (!CheckingValues(NewTube.length, 0.0001));
    do{
        cout << "Введите диаметр трубы: " << endl;
        cin >> NewTube.diameter;
    }while (!CheckingValues(NewTube.diameter,0.0001));
    char check = '0';
    do{
        cout << "Введите статус трубы: 1 - рабочее; 0 - в ремонте: " << endl;
        cin >> check;
    }while (!CheckingValues(check,'0','1'));
    if (check == '1')
    {
        NewTube.status = true;
    }
}

void PrintTube(const tube& NewTube)
{
    cout << "Длина трубы: " << NewTube.length << endl
        << "Диаметр трубы: " << NewTube.diameter << endl
        << "Статус трубы: " << NewTube.status <<endl;
}

void EditTube(tube& NewTube)
{
    char check = '0';
    do {
        cout << "Введите обновлённый статус трубы: " << endl;
        cin >> NewTube.status;
    } while (!CheckingValues(check, '0', '1'));
    if (check == '1')
    {
        NewTube.status = true;
    }
}

struct cs
{
    string name;
    int workshops;
    int working_workshops;
    int efficiency;
};

void InputCS(cs& NewCS)
{
    cout << "Введите название компрессорной станции:" << endl;
    cin >> NewCS.name;
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

}

void PrintCS(const cs& NewCS)
{
    cout << "Название компрессорной станции: " << NewCS.name <<endl
        << "Количество всех цехов компрессорной станции: " << NewCS.workshops << endl
        << "Количество работающих цехов компрессорной станции: " << NewCS.working_workshops << endl
        << "Эффективность компрессорной станции: " << NewCS.efficiency << endl;
}

void EditCS(cs& NewCS)
{
    do {
        cout << "Введите обновлённое количество работающих цехов компрессорной станции: " << endl;
        cin >> NewCS.working_workshops;
    } while (!CheckingValues(NewCS.working_workshops, 0, NewCS.workshops));
}

void SaveAll(const tube& NewTube, const cs& NewCS)
{
    ofstream fout;
    fout.open("data.txt", ios::out);
    NonExistentValues(NewTube, NewCS);
    if (fout.is_open())
    {
        fout << NewTube.length << endl << NewTube.diameter << endl << NewTube.status << endl;
        fout << NewCS.name << endl << NewCS.workshops << endl << NewCS.working_workshops << endl << NewCS.efficiency << endl;
        fout.close();
    }

}

void LoadAll()
{
    ifstream fin;
    fin.open("data.txt", ios::in);
    if (fin.is_open())
    {
        tube NewTube;
        fin >> NewTube.length;
        fin >> NewTube.diameter;
        fin >> NewTube.status;
        cs NewCS;
        fin >> NewCS.name;
        fin >> NewCS.workshops;
        fin >> NewCS.working_workshops;
        fin >> NewCS.efficiency;
        fin.close();
    }
}

void NonExistentValues(tube& NewTube, cs& NewCS)
{
    if ((NewCS.workshops == 0) || (NewTube.length == 0))
    {
        cout << "Введены некорректные данные, сначала добавьте характеристики трубы и компрессорной станции" << endl;
        return;
    }
}

void OutPut(tube& NewTube, cs& NewCS)
{
    cout << "1. Вывести информацию по трубе" << endl
        << "2. Вывести информацию по компрессорной станции" << endl
        << "3. Вывести информацию по всем объектам" << endl;
    int i = 0;
    do {
        cin >> i;
    } while (!CheckingValues(i, 1, 3));

    switch (i)
    {
        case 1:
        {
            NonExistentValues(NewTube, NewCS);
            PrintTube(NewTube);
            return;
        }
        case 2:
        {
            NonExistentValues(NewTube, NewCS);
            PrintCS(NewCS);
            return;
        }
        case 3:
        {
            NonExistentValues(NewTube, NewCS);
            PrintTube(NewTube);
            PrintCS(NewCS);
            return;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus"); 

    tube NewTube = {0,0,0};
    cs NewCS = {"",0,0,0};

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
                InputTube(NewTube);
                break;
            }
            case 2:
            {
                InputCS(NewCS);
                break;
            }
            case 3:
            {
                OutPut(NewTube, NewCS);
                break;
            }
            case 4:
            {
                NonExistentValues(NewTube, NewCS);
                EditTube(NewTube);
                break;
            }
            case 5:
            {
                NonExistentValues(NewTube, NewCS);
                EditCS(NewCS);
                break;
            }
            case 6:
            {
                SaveAll(NewTube, NewCS);
                break;
            }
            case 7:
            {
                LoadAll();
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
        }
    }
}