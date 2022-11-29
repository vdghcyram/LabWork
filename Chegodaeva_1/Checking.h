#pragma once
#include <unordered_map>
#include "tube.h"
#include "cs.h"

template <typename T>
T CheckingValues(T beginning = numeric_limits<T>::min(), T end = numeric_limits<T>::max())
{
    T variable;
    cin >> variable;
    while (cin.fail() || cin.peek() != '\n' || variable<beginning || variable>end)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Введите корректные данные от " << beginning << " до " << end << endl;
        cin >> variable;
    }
    return variable;
}

template<typename T, typename T1>
using Filter = bool(*)(const T1&, T param);

template<typename T>
bool CheckByName(const T& Obj, string param)
{
    return  (Obj.GetName().find(param) != string::npos);
}

template<typename T>
bool CheckByEffectiveness(const T& Cs, double param)
{
    double Workshop = Cs.GetWorkshop();
    double WorkingWorkshops = Cs.GetWorkingWorkshops();
    double Effectiveness = param / 100;
    return((1 - WorkingWorkshops / Workshop) >= Effectiveness);
}

template<typename T>
bool CheckByStatus(const T& P, bool param)
{
    return(P.GetStatus() == param);
}

template<typename T>
bool CheckingAvailabilityID(int ID, const unordered_map<int, T>& Obj)
{
    if (Obj.find(ID) == Obj.end())
    {
        cout << "ID не найден." << endl;
        return false;
    }
    return true;
}

template<typename T>
bool CheckingAvailability(const unordered_map<int, T>& GroupObj)
{
    if (GroupObj.size() == 0)
    {
        cout << "Необходимо сначала создать хотя бы один элемент!\n";
        return true;
    }
}
