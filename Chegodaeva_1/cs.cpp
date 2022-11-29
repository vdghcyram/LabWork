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
	cout << "�������� ��� ��: " << name << endl;
	cout << "�� ������ ������ �� " << workshops << " ����� � ������: " << working_workshops << endl << endl;
	cout << "������� 1 ��� ���������� ���������� ���������� ����� �� 1." << endl
		<< "������� 0 ��� ���������� ���������� ���������� ����� �� 1." << endl;

	while (true)
	{
		int item = CheckingValues(0, 1);

		if (item == 1)
		{
			if (StartWorkshop())
			{
				cout << "������ ���������." << endl;
				return;
			}
		}
		else
		{
			if (StopWorkshop())
			{
				cout << "������ ���������." << endl;
				return;
			}
		}
	}
}

bool cs::StartWorkshop()
{
	if (working_workshops == workshops)
	{
		cout << "���������� ��������� � ������ ������ �����, ��� ����������. ����������, ��������� ������� �����." << endl;
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
		cout << "���������� ����������� ������� ����, ��� ��� ������ ��� ����� � ������. ����������, ��������� ������� �����." << endl;
		return false;
	}
	else
	{
		--working_workshops;
		return true;
	}
}