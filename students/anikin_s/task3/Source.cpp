#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

class Integral
{
private:

	int left;
	int right;
	double F;
	double calc(int x)
	{
		switch (x)
		{
		case 0:
		{
			return sin(x);
			break;
		}
		case 1:
		{
			return cos(x);
			break;
		}
		case 2:
		{
			return exp(x);
			break;
		}
		}
		return 0;
	}
public:
	Integral(int a=0, int b=0, double f=0)
	{}
	~Integral()
	{}

	Integral(const Integral&s)
	{
		left = s.left;
		right = s.right;
		F = s.F;
	}
	Integral operator=(const Integral&s)
	{
		left = s.left;
		right = s.right;
		F = s.F;
		return *this;
	}
	void SetBounds(int a, int b)
	{
		left = a;
		right = b;
	}
	void SetF(double f)
	{
		F = f;
	}
	double GetLeftBound()
	{
		return left;
	}
	double GetRightBound()
	{
		return right;
	}
	double GetFNum()
	{
		return F;
	}
	double CalcLeft(int n)
	{
		int h;
		double total = 0;
		h = (right - left) / n;
		for (int i = 0; i < n; i++)
			total += calc(left + h * i);
		total *= h;
		return total;
	}
	double CalcMid(int n)
	{
		int h;
		double total = 0;
		h = (right - left) / n;
		for (int i = 0; i < n; i++)
			total = calc(left + h * (i + 0.5));
		total *= h;
		return total;
	}
	double CalcRight(int n)
	{
		int h;
		double total = 0;
		h = (right - left) / n;
		for (int i = 0; i <= n; i++)
			total += calc(left + h * i);
		total *= h;
		return total;
	}
};

int main(int left, int right, double F)
{
	setlocale(LC_ALL, "rus");

	Integral s;

	cout << "Введите пределы интегрирования" << endl;
	cin >> left >> right;
	s.SetBounds(left, right);
	cout << "Введите номер функции" << endl;
	cout << "0 - sin" << endl;
	cout << "1 - cos" << endl;
	cout << "2 - exp" << endl;
	cin >> F;
	s.SetF(F);

	int op;
	int n;
	bool integral = 1;
	while (integral)
	{
		cout << "1 - Посчитать методом левых прямоугольников" << endl;
		cout << "2 - Посчитать методом правых прямоугольников" << endl;
		cout << "3 - Посчитать методом средних прямоугольников" << endl;
		cout << "4 - Задать новые пределы" << endl;
		cout << "5 - Задать новую функцию" << endl;
		cout << "6 - Показать пределы" << endl;
		cout << "7 - Показать функцию" << endl;
		cout << "0 - Выход" << endl;
		cin >> op;
		switch (op)
		{
		case 1:
		{
			cout << "Введите n" << endl;
			cin >> n;
			cout << s.CalcLeft(n);
			system("pause");
			break;
		}
		case 2:
		{
			cout << "Введите n" << endl;
			cin >> n;
			cout << s.CalcRight(n);
			system("pause");
			break;
		}
		case 3:
		{
			cout << "Введите n" << endl;
			cin >> n;
			cout << s.CalcMid(n);
			system("pause");
			break;
		}
		case 4:
		{
			cout << "Введите пределы интегрирования" << endl;
			cin >> left >> right;
			s.SetBounds(left, right);
			system("pause");
			break;
		}
		case 5:
		{
			cout << "0 - sin" << endl;
			cout << "1 - cos" << endl;
			cout << "2 - exp" << endl;
			cin >> F;
			s.SetF(F);
			system("pause");
			break;
		}
		case 6:
		{
			cout << "Left = " << s.GetLeftBound() << endl;
			cout << "Right = " << s.GetRightBound() << endl;
			system("pause");
			break;
		}
		case 7:
		{
			if (s.GetFNum() == 0)
				cout << "sin" << endl;
			if (s.GetFNum() == 1)
				cout << "cos" << endl;
			if (s.GetFNum() == 2)
				cout << "exp" << endl;
			system("pause");
			break;
		}
		case 0:
		{
			integral = 0;
			break;
		}
		}
	}
	return 0;
}
