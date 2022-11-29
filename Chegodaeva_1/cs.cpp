#include "cs.h"

int cs::MaxID = 0;


string cs::GetName() const
{
	return name;
}

int cs::GetWorkshop() const
{
	return workshops;
}

int cs::GetWorkingWorkshops() const
{
	return working_workshops;
}

int cs::GetID()
{
	return MaxID;
}

void cs::EditingWorkshop()
{
	cout << "Название для КС: " << name << endl;
	cout << "На данный момент из " << workshops << " цехов в работе: " << working_workshops << endl << endl;
	cout << "Введите 1 для увеличения количества работающих цехов на 1." << endl
		<< "Введите 0 для уменьшения количества работающих цехов на 1." << endl;

	while (true)
	{
		int item = CheckingValues(0, 1);

		if (item == 1)
		{
			if (StartWorkshop())
			{
				cout << "Данные сохранены." << endl;
				return;
			}
		}
		else
		{
			if (StopWorkshop())
			{
				cout << "Данные сохранены." << endl;
				return;
			}
		}
	}
}

bool cs::StartWorkshop()
{
	if (working_workshops == workshops)
	{
		cout << "Невозможно запустить в работу больше цехов, чем существует. Пожалуйста, повторите попытку ввода." << endl;
		return false;
	}
	else
	{
		++working_workshops;
		return true;
	}
}

bool cs::StopWorkshop()
{
	if (working_workshops == 0)
	{
		cout << "Невозможно осуществить останов цеха, так как сейчас нет цехов в работе. Пожалуйста, повторите попытку ввода." << endl;
		return false;
	}
	else
	{
		--working_workshops;
		return true;
	}
}