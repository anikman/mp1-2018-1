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

	cout << "������� ������� ��������������" << endl;
	cin >> left >> right;
	s.SetBounds(left, right);
	cout << "������� ����� �������" << endl;
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
		cout << "1 - ��������� ������� ����� ���������������" << endl;
		cout << "2 - ��������� ������� ������ ���������������" << endl;
		cout << "3 - ��������� ������� ������� ���������������" << endl;
		cout << "4 - ������ ����� �������" << endl;
		cout << "5 - ������ ����� �������" << endl;
		cout << "6 - �������� �������" << endl;
		cout << "7 - �������� �������" << endl;
		cout << "0 - �����" << endl;
		cin >> op;
		switch (op)
		{
		case 1:
		{
			cout << "������� n" << endl;
			cin >> n;
			cout << s.CalcLeft(n);
			system("pause");
			break;
		}
		case 2:
		{
			cout << "������� n" << endl;
			cin >> n;
			cout << s.CalcRight(n);
			system("pause");
			break;
		}
		case 3:
		{
			cout << "������� n" << endl;
			cin >> n;
			cout << s.CalcMid(n);
			system("pause");
			break;
		}
		case 4:
		{
			cout << "������� ������� ��������������" << endl;
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
