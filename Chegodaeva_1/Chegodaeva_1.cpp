#include <iostream>

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

int main()
{
    setlocale(LC_ALL, "rus");       //Поддержка русского языка
    consol();
    return 0;

    switch ()
        case 1:
            tube();
            break;
        case 2:
            ks();
            break;
        case 3:
            all();
            break;
        case 4:
            edit_tube();
            break;
        case 5:
            edit_ks();
            break;
        case 6:
            save();
            break;
        case 7:
            load();
            break;

}