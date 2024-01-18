#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

	/*
	������� ��������� ��������� ������� �������� ��������� ������� �� ��� �������.
	��� ������� �������� �������� ����� ���� ������������ ��������� ����������.
	���������������� ���� ���������� ������ ������-��������� ������ �������������� ����
	� ����������� ����������� ���������� ������ ������,  � ������ ���������� �������������� ����������.
	� ��� ������ ��������� ������ ����� ��������, ����� �������� ��������� ������� ��� ���������.
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
		cout << "��������� ���� ��� ����������";
	}
};

class WalkingStrategy : public RouteStrategy
{
public:
	void buildRoute() override
	{
		cout << "��������� ���� ��� �������� ";
	}
};

class PublicTransportStrategy : public RouteStrategy
{
public:
	void buildRoute() override
	{
		cout << "��������� ���� ��� ������������� ���������� ";
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
	
