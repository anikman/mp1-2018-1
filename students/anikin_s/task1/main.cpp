#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <locale.h>

using namespace std;

class TFraction
{
private:
	double num1; //числитель первой дроби
	double denom1; //знаменатель первой дроби
	double num2; //числитель второй дроби
	double denom2; //знаменатель второй дроби
	double numtot;
	double denomtot;
public:
	TFraction() : num1(0), denom1(0), num2(0), denom2(0)
	{}
	void set()
	{
		cout << "Введите числитель и знаменатель первой дроби (дробь дожна быть несократимой, а знаменатель не равен нулю)\n" << endl;
		cin >> num1;
		cin >> denom1;
		cout << "Введите числитель и знаменатель второй дроби (дробь дожна быть несократимой, а знаменатель не равен нулю)\n" << endl;
		cin >> num2; 
		cin >> denom2;
		if (((denom2 = 0) || (num2 >= denom2))||((denom1 = 0) || (num1 >= denom1)))
			return;
	}
	void operation()
	{
		char op;
		cout << "Выберите операцию: сложение(+), вычитание(-), умножение(*) или деление(:)\n";
		cin >> op;
		switch (op)
		{
		case '+':
			if (denom1 == denom2)
			{
				numtot = num1 + num2;
				denomtot = denom1;
			}
			else
			{
				denomtot = denom1 * denom2;
				numtot = (num1 * denom2) + (num2 * denom1);
			}
			break;
		case '-':
			if (denom1 == denom2)
			{
				numtot = num1 - num2;
				denomtot = denom1;
			}
			else
			{
				denomtot = denom1 * denom2;
				numtot = (num1 * denom2) - (num2 * denom1);
			}
			break;
		case '*':
			numtot = num1 * num2;
			denomtot = denom1 * denom2;
			break;
		case ':':
			numtot = num1 * denom2;
			denomtot = denom1 * num2;
			break;
		}
	}
	void show()
	{
		cout << "Итог: " << numtot << "/" << denomtot << endl;
	}
};
int main()
{
	setlocale(LC_ALL, "rus");
	TFraction a1;
	a1.set();
	a1.operation();
	a1.show();
	system("pause");
	return 0;
 }