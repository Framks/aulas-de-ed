#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
	Vector list1;
	for (int i = 0; i < 5; i++)
	{
		list1.push_back(i);
	}

	Vector list2(list1);

	for (int i = 0; i < 5; i++)
	{
		cout << list2[i] << endl;
	}
	// TESTAR A FUNÃO DE EMpTY pARA AS DUAS LISTAS CRIADAS
	cout << list1.empty() << endl
		 << list2.empty() << endl;

	// testar at
	cout << list1.at(2) << endl
		 << list2.at(1) << endl;

	// testar reserve
	list1.reserve(20);
	cout << list1.size() << endl;

	// testar o pop_back
	list1.pop_back();
	for (int i = 0; i < list1.size(); i++)
	{
		cout << list1[i] << endl;
	}
}