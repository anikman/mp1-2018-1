#include <stdio.h>
#include <iostream>
#include <cmath>
#include <locale.h>


using namespace std;

class TPolinom
{
private:
	int n;
	double *a;
public:
	TPolinom(int _n, double *_a) : n(_n), a(_a)
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
			a = new double[s.n + 1];
		}
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
	void Diff()
	{
		double *new_a;
		new_a = new double[n+1];
		for (int i = n; i > 0; i--)
		{
			new_a[i] = a[i] * i;
		}
		for (int i = n-1; i >= 0; i--)
		{
			if (a > 0)
			{
				if (i == n-1)
					cout << "" << new_a[i + 1] << "x^" << i << " ";
				else
					cout << "+" << new_a[i + 1] << "x^" << i << " ";
			}
			if (a < 0)
				cout << "-" << abs(new_a[i + 1]) << "x^" << i << " ";
		}
		cout << "\n";
		delete[] new_a;
	}
	~TPolinom();
};

TPolinom :: ~TPolinom()
{
	delete[] a;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	double a[12];
	int op;
	cout << "������� ������� �������� " << endl;
	cin >> n;
	cout << "������� ������������ ��� ������� ������ " << endl;
	for (int i = n; i >= 0; i--)
	{
		cout << "a" << i << "= ";
		cin >> a[i];
	}

	TPolinom sa(n, a);

	cout << "��� ������� �������: ";
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
	cout << "��� ������ ������� �������� ������� 1" << endl;
	cout << "��� ����, ����� ������ ����������� �� ��� ����������� ������, ������� 2" << endl;
	cout << "��� ���������� �������� �������� � ������������ ����� � ������� 3" << endl;
	cout << "��� ���������� ����������� �������� ������� 4" << endl;
	cin >> op;
	switch (op)
	{
	case 1:
	{
		cout << "������� �������� = " << n << endl;
		system("pause");
		break;
	}
	case 2:
	{
		int i = 0;
		cout << "������� ���������� ����� ������������" << endl;
		cin >> i;
		cout << sa.Find_a(i);
		cout << "\n";
		system("pause");
		break;
	}
	case 3:
	{
		int x;
		cout << "������� �" << endl;
		cin >> x;
		cout << sa.Calc(x);
		cout << "\n";
		system("pause");
		break;
	}
	case 4:
	{
		sa.Diff();
		cout << "\n";
		system("pause");
		break;
	}
	}
}