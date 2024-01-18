#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

	/*
	Паттерн Стратегия позволяет вынести алгоритм поведения объекта за его пределы.
	Для решения заданной проблемы может быть представлено несколько алгоритмов.
	Инкапсулирование всех алгоритмов внутри класса-владельца грозит нагромождением кода
	и отсутствием возможности расширения работы класса,  а именно добавления дополнительных алгоритмов.
	А при данной структуре клиент может выбирать, какой алгоритм поведения объекта ему необходим.
	*/

class RouteStrategy abstract
{
public:
	virtual void buildRoute() abstract;
};

class RoadStrategy: public RouteStrategy
{
public:
	void buildRoute() override
	{
		cout << "Прокладка пути для автомобиля";
	}
};

class WalkingStrategy : public RouteStrategy
{
public:
	void buildRoute() override
	{
		cout << "Прокладка пути для пешехода ";
	}
};

class PublicTransportStrategy : public RouteStrategy
{
public:
	void buildRoute() override
	{
		cout << "Прокладка пути для общественного транспорта ";
	}
};

class Navigator
{
	
	RouteStrategy* routestrategy;

public:
	void SetRouteStrategy(RouteStrategy* strategy)
	{
		routestrategy = strategy;
	}
	
	void Navigate()
	{
		routestrategy->buildRoute();

	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	Navigator  n;
	PublicTransportStrategy a;
	n.SetRouteStrategy(&a);
	n.Navigate();

	system("pause");
	return 0;
}
	
