#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <locale.h>
#include <cstring>


using namespace std;

class TPolinom
{
private:
	int n;
	double *a;
public:
	TPolinom(int _n, double *_a)
	{
		n = _n;
		a = new double[n + 1];
		for (int i = 0; i <= n; i++)
			a[i] = _a[i];
	}
	TPolinom operator=(const TPolinom&s)
	{
		if (this == &s)
			return *this;
		if (n != s.n)
		{
			delete[] a;
			a = new double[n + 1];
		}
		for (int i = 0; i <= n; i++)
			a[i] = s.a[i];
		return *this;
	}
	TPolinom(const TPolinom&s)
	{
		n = s.n;
		a = new double[n + 1];
		for (int i = 0; i <= n; i++)
			a[i] = s.a[i];
	}
	void Out()
	{
		for (int i = n; i >= 0; i--)
		{
			if (a > 0)
			{
				if (i == n)
					cout << "" << a[i] << "x^" << i << " ";
				else
					cout << "+" << a[i] << "x^" << i << " ";
			}
			if (a < 0)
				cout << "-" << abs(a[i]) << "x^" << i << " ";
		}
		cout << "\n";
	}
	int Out_n()
	{
		return n;
	}
	double Find_a(int i)
	{
		return a[i];
	}
	double Calc(int x)
	{
		double total = 0;
		double monom = 0;
		for (int i = 0; i <= n; i++)
		{
			monom = pow(x, n - i)*a[n - i];
			total += monom;
		}
		return total;
	}
	TPolinom Diff()
	{
		double *ad;
		int tmp;
		tmp = n;
		ad = new double[n + 1];
		for (int i = tmp; i > 0; i--)
		{
			ad[i - 1] = a[i] * i;
		}
		TPolinom dif(tmp - 1, ad);
		return dif;
	}
	~TPolinom()
	{
		delete[] a;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	double a[12];
	int op;
	cout << "Введите степень полинома " << endl;
	cin >> n;
	cout << "Введите коэффициенты для каждого монома " << endl;
	for (int i = n; i >= 0; i--)
	{
		cout << "a" << i << "= ";
		cin >> a[i];
	}

	TPolinom sa(n, a);

	cout << "Для вывода полинома на экран введите 1" << endl;
	cout << "Для вывода степени полинома введите 2" << endl;
	cout << "Для того, чтобы узнать коэффициент по его порядковому номеру, введите 3" << endl;
	cout << "Для вычисления значения полинома в определенной точке Х введите 4" << endl;
	cout << "Для нахождения производной полинома введите 5" << endl;
	cin >> op;
	switch (op)
	{
	case 1:
	{
		sa.Out();
		system("pause");
		break;
	}
	case 2:
	{
		cout << "Степень полинома = " << sa.Out_n() << endl;
		system("pause");
		break;
	}
	case 3:
	{
		int i = 0;
		cout << "Введите порядковый номер коэффициента" << endl;
		cin >> i;
		cout << sa.Find_a(i);
		cout << "\n";
		system("pause");
		break;
	}
	case 4:
	{
		int x;
		cout << "Введите Х" << endl;
		cin >> x;
		cout << sa.Calc(x);
		cout << "\n";
		system("pause");
		break;
	}
	case 5:
	{
		TPolinom sa1(sa.Diff());
		sa1.Out();
		cout << "\n";
		system("pause");
		break;
	}
	}
}