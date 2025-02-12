#pragma once
#include "Observer.h"
#include <vector>

template<typename T>
class Subject
{
public:
	void AddListener(Observer<T>* o)
	{
		m_Observers.push_back(o);
	}
	void RemoveListener(Observer<T>* o)
	{
		m_Observers.remove(o);
	}
	void Invoke(const T& value)
	{
		for (Observer<T>* o : m_Observers)
		{
			o->OnNotify(value);
		}
	}
private:
	std::vector<Observer<int>*> m_Observers;
};

