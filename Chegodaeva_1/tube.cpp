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
	cout << "Введите статус трубы " << name << " (в ремонте - 0, в работоспособном состоянии - 1) : " << endl;
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