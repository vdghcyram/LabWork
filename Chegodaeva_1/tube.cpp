#include "tube.h"

int tube::MaxID = 0;



string tube::GetName() const
{
	return name;
};

bool tube::GetStatus() const
{
	return status;
}


void tube::InputStatusCheck()
{
	cout << "������� ������ ����� " << name << " (� ������� - 0, � ��������������� ��������� - 1) : " << endl;
	status = CheckingValues(0, 1);
}


void tube::SetStatus(bool PipeStatus)
{
	status = PipeStatus;
}

int tube::GetID()
{
	return MaxID;
}