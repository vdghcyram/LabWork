#include <iostream>

using namespace std;

void consol()
{
    int choice = 0;
    cout << "Меню:" << endl
        << "1. Добавить трубу" << endl
        << "2. Добавить КС" << endl
        << "3. Просмотр всех объектов" << endl
        << "4. Редактировать трубу" << endl
        << "5. Редактировать КС" << endl
        << "6. Сохранить" << endl
        << "7. Загрузить" << endl
        << "0. Выход" << endl;
    cin >> choice;
}

void tube()
{
    double dlina;
    cout << "Введите длину трубы:" << endl;
    cin >> dlina;
    do {
        cout << "Введите корректное значение:";
    } while (dlina < 0 || dlina == не буква)

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