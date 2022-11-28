#include "tube.h"
#include "cs.h"
#include "OperatorOverloads.h"
#include "WorkingWithFiles.h"
#include "Checking.h"
#include <unordered_set>
using namespace std;

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

string EnteringFragmentName()
{
    string Name = "NoName";
    cout << "Введите фрагмент названия искомых объектов. " << endl << "Фильтр: ";
    cin >> ws;
    getline(cin, Name);
    return Name;
}

template<typename T, typename T1>
void FilterResults(unordered_map<int, T1>& Obj, unordered_map<int, int>& IDs, Filter<T, T1> f, T param)
{
    int count = 0;
    for (const auto& elem : Obj)
    {
        if (f(elem.second, param))
        {
            ++count;
            cout << "Номер в списке: " << count << endl;
            cout << "ID объекта: " << elem.first << endl << elem.second << endl;
            IDs.emplace(count, elem.first);
        }
    }
    if (count == 0)
    {
        cout << "Искомых объектов не найдено!" << endl;
        return;
    }
}

void OutPut (const unordered_map<int, tube>& GroupTube, unordered_map<int, cs>& GroupCS)
{
    cout << "1. Вывести информацию по трубам" << endl
        << "2. Вывести информацию по компрессорным станциям" << endl
        << "3. Вывести информацию по всем объектам" << endl
        << "4. Вывести информацию по фильтру название КС" << endl
        << "5. Вывести информацию по фильтру процента незадействованных цехов КС" << endl;


    int i = CheckingValues(1, 5);

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
            cout << "Трубы: " << endl;
            PrintObj(GroupTube);
            cout << "Компрессорные станции: " << endl;
            PrintObj(GroupCS);
            break;
        }
        case 4:
        {
            string Name = "NoName";
            unordered_map<int, int> IDs;

            if (GroupCS.size() == 0)
            {
                cout << "Необходимо сначала создать хотя бы один элемент!";
                return;
            }

            cout << endl;
            Name = EnteringFragmentName();


            FilterResults(GroupCS, IDs, CheckByName, Name);
            break;
        }
        case 5:
        {
            double Effectiveness = 0;
            unordered_map<int, int> IDs;

            if (GroupCS.size() == 0)
            {
                cout << "Необходимо сначала создать хотя бы один элемент!";
                return;
            }

 
            cout << "Введите процент незадействованных цехов (от 0 до 100): " << endl;
            Effectiveness = CheckingValues(0., 100.);

            FilterResults(GroupCS, IDs, CheckByEffectiveness, Effectiveness);
            break;
            
        }
    }
}


//Изменение объектов	
template<typename T>
using FilterEditing = void(*)(T&, unordered_set<int>&);
//Поэлементное редактирование списка труб
void Element_By_ElementEditingPipe(unordered_map<int, tube>& GroupP, unordered_set<int>& IDsP)
{
	for (const auto& elem : IDsP)
	{
		GroupP.at(elem).InputStatusCheck();
	}
}
void Element_By_ElementEditingCs(unordered_map<int, cs>& GroupCs, unordered_set<int>& IDsP)
{
	for (const auto& elem : IDsP)
	{
		GroupCs.at(elem).EditingWorkshop();
	}
}
//Пакетное редактирование статуса
void BatchEditingPipes(unordered_map<int, tube>& GroupP, unordered_set<int>& IDsP)
{
	cout << "Введите новый статус трубы (в ремонте - 0, в работоспособном состоянии - 1)" << endl;
	int Status = CheckingValues(0, 1); 
	for (const auto& elem : IDsP)
	{
		GroupP.at(elem).SetStatus(Status);
	}
}
//Пакетное  удаление
template<typename T>
void BatchErasePipes(T& Obj, unordered_set<int>& IDsP)
{
	for (const auto& elem : IDsP)
	{
		Obj.erase(elem);
	}
}
//Выбор действия с элементами
template<typename T>
void SelectingAnEditAction(T& Obj, unordered_set<int>& IDsP, FilterEditing<T> f)
{
	cout << endl << "Введите 1 для редактирования объектов или 0 для удаления." << endl;
	int item = CheckingValues(0, 1);
	switch (item)
	{
	case 1:
		f(Obj, IDsP);
		return;
	case 0:
		BatchErasePipes(Obj, IDsP);
		return;
	}
}
//Создание Set из всех элементов фильтра
void SelectingAllFilterElements(unordered_map<int, int>& IDs, unordered_set<int>& IDsP)
{
	for (const auto& elem : IDs)
	{
		IDsP.emplace(elem.second);
	}
}
//Что необходимо удалить или отредактировать 
void EnteringIDChange(unordered_map<int, int>& IDs, unordered_set<int>& IDsP)
{
	int Number = 0;
	cout << "Введите -1 для того, что бы выбрать все выведенные объекты" << endl
		<< "Или введите через Enter номера из списка интересующих вас объектов." << endl
		<< "Для завершения ввода введите 0" << endl;

	Number  = CheckingValues(-1, (int)IDs.size());
	while (Number != 0 && Number != -1)
	{
		IDsP.emplace(IDs.at(Number));
		Number = CheckingValues(0, (int)IDs.size());
	}
	if (Number == 0 && IDsP.size() == 0) { return; }
	if (Number == -1) { SelectingAllFilterElements(IDs, IDsP); }
}

template<typename T>
void InputAndCheckingAvailabilityID(unordered_map<int, T>& Obj, int& ID)
{
	do
	{
		ID = CheckingValues(0, T::GetID());
		if (ID == 0)
			break;
		else if (CheckingAvailabilityID(ID, Obj))
			break;
	} while (true);
}
//Ввод ID для дальнейшего редактирования
template<typename T>
void InputIDsP(unordered_map<int, T>& Obj, unordered_set<int>& IDsP)
{
	cout << "Введите через Enter ID объектов, которые нужно изменить." << endl
		<< "Для завершения ввода введите 0" << endl;
	int ID;
	InputAndCheckingAvailabilityID(Obj, ID);
	while (ID != 0)
	{
		IDsP.emplace(ID);
		InputAndCheckingAvailabilityID(Obj, ID);
	}
	cout << endl;
}
//Изменение объектов
template<typename T>
void ChangingObjectsPipe(unordered_map<int, tube>& GroupP, Filter<T, tube> f, T param)
{
	unordered_map<int, int> IDs;
	FilterResults(GroupP, IDs, f, param);
	unordered_set<int> IDsP;
	EnteringIDChange(IDs, IDsP);

	SelectingAnEditAction(GroupP, IDsP, BatchEditingPipes);
}
//Изменение объектов
void ChangingObjects(unordered_map<int, tube>& GroupP, unordered_map<int, cs>& GroupCs)
{
	string Name = "NoName";
	unordered_set<int> IDsObj;
	bool Status = false;
	int SizePipes = GroupP.size();
	int SizeCs = GroupCs.size();
	cout << "1. Редактирование по фильтру названия труб" << endl
		<< "2. Редактирование по фильтру статуса трубы" << endl
		<< "3. Редактирование по ID труб" << endl
		<< "4. Редактирование по ID КС" << endl
		<< "0. Для возврата в главное меню." << endl << endl;

	int item = CheckingValues(0, 4);

	switch (item)
	{
	case 1:
		if (GroupP.size() == 0)
            {
                cout << "Необходимо сначала создать хотя бы один элемент!";
                return;
            }

		cout << endl;
		Name = EnteringFragmentName();

		ChangingObjectsPipe(GroupP, CheckByName, Name);
		return;

	case 2:
        if (GroupP.size() == 0)
        {
            cout << "Необходимо сначала создать хотя бы один элемент!";
            return;
        }

		cout << endl;
		cout << "Введите 1, если статус искомых труб 'В работе' или 0, если их статус 'В ремонте'" << endl;
		Status = CheckingValues(0, 1);

		ChangingObjectsPipe(GroupP, CheckByStatus, Status);
       
		return;
	case 3:
        if (GroupP.size() == 0)
        {
            cout << "Необходимо сначала создать хотя бы один элемент!";
            return;
        }

		InputIDsP(GroupP, IDsObj);
		SelectingAnEditAction(GroupP, IDsObj, Element_By_ElementEditingPipe);
		return;
	case 4:
        if (GroupCs.size() == 0)
        {
            cout << "Необходимо сначала создать хотя бы один элемент!";
            return;
        }

		InputIDsP(GroupCs, IDsObj);
		SelectingAnEditAction(GroupCs, IDsObj, Element_By_ElementEditingCs);
		return;
	case 0:
		return;
	}

	return;
}


void consol()
{
    cout << "Меню:" << endl
        << "1. Добавить трубу" << endl
        << "2. Добавить КС" << endl
        << "3. Просмотр объектов" << endl
        << "4. Редактировать объекты" << endl
        << "5. Сохранить" << endl
        << "6. Загрузить" << endl
        << "0. Выход" << endl
        << "Введите номер пункта: ";
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
            case 4:
            {
                ChangingObjects(GroupTube1, GroupCS1);
                break;
            }
            case 5:
            {
                SaveAll(GroupTube1, GroupCS1);
                break;
            }
            case 6:
            {
                LoadAll(GroupTube1, GroupCS1);
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