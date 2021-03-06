#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

double f1(double x)
{
	return sin(x);
}
double f2(double x)
{
	return cos(x);
}
double f3(double x)
{
	return exp(x);
}
//y = f(x)

class Integral
{
private:
	int left;
	int right;
	double total;
	double(*F)(double x);	
public:
	Integral(int a=0, int b=0, int f=0)
	{}

	/*~Integral()
	{}*/

	/*Integral(const Integral&s)
	{
		left = s.left;
		right = s.right;
		F = s.F;
	}*/

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
	void SetFunction(double(*FF)(double x))
	{
		F = FF;
	}
	double GetLeftBound()
	{
		return left;
	}
	double GetRightBound()
	{
		return right;
	}
	double CalcLeft(int n)
	{
		total = 0;
		int h;
		h = (right - left) / n;
		for (int i = 0; i < n; i++)
			total += F(left + h * i);
		total *= h;
		return total;
	}
	double CalcMid(int n)
	{
		total = 0;
		int h;
		h = (right - left) / n;
		for (int i = 0; i < n; i++)
			total += F(left + h * (i + 0.5));
		total *= h;
		return total;
	}
	double CalcRight(int n)
	{
		total = 0;
		int h;
		h = (right - left) / n;
		for (int i = 0; i <= n; i++)
			total += F(left + h * i);
		total *= h;
		return total;
	}
	void Show()
	{
		cout << total << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");

	int left;
	int right;
	int fnum = 0;
	Integral s;

	cout << "Введите пределы интегрирования" << endl;
	cin >> left >> right;
	s.SetBounds(left, right);
	cout << "Введите номер функции" << endl;
	cout << "1 - sin" << endl;
	cout << "2 - cos" << endl;
	cout << "3 - exp" << endl;
	cin >> fnum;
	switch (fnum)
	{
	case 1: 
	{
		s.SetFunction(f1);
		break;
	}
	case 2:
	{
		s.SetFunction(f2);
		break;
	}
	case 3:
	{
		s.SetFunction(f3);
		break;
	}
	}

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
			s.CalcLeft(n);
			s.Show();
			system("pause");
			break;
		}
		case 2:
		{
			cout << "Введите n" << endl;
			cin >> n;
			s.CalcRight(n);
			s.Show();
			system("pause");
			break;
		}
		case 3:
		{
			cout << "Введите n" << endl;
			cin >> n;
			s.CalcMid(n);
			s.Show();
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
			cout << "1 - sin" << endl;
			cout << "2 - cos" << endl;
			cout << "3 - exp" << endl;
			cin >> fnum;
			switch (fnum)
			{
			case 1:
			{
				s.SetFunction(f1);
				break;
			}
			case 2:
			{
				s.SetFunction(f2);
				break;
			}
			case 3:
			{
				s.SetFunction(f3);
				break;
			}
			}
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
			if (fnum == 1)
				cout << "sin" << endl;
			if (fnum == 2)
				cout << "cos" << endl;
			if (fnum == 3)
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