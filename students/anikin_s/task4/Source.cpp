#include <cstdio>
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <clocale>
#include <cmath>

using namespace std;

struct Date
{
	int day, month, year;
	Date(int dd = 0, int mm = 0, int yy = 0) : day(dd), month(mm), year(yy) {}
	//Date operator=(const Date&s)
	//{
	//	day = s.day;
	//	month = s.month;
	//	year = s.year;
	//	return *this;
	//}

	/*Date(const Date&s)
	{
		day = s.day;
		month = s.month;
		year = s.year;
	}*/

	/*void SetDay(int dd)
	{
		day = dd;
	}
	void SetMonth(int mm)
	{
		month = mm;
	}
	void SetYear(int yy)
	{
		year = yy;
	}*/
	int GetDay()
	{
		return day;
	}
	int GetMonth()
	{
		return month;
	}
	int GetYear()
	{
		return year;
	}
};

struct Time
{
	int hour;
	Time(int hh = 0) : hour(hh) {}

	/*Time operator=(const Time&s)
	{
		hour = s.hour;
		return *this;
	}*/

	/*Time(const Time&s)
	{
		hour = s.hour;
	}*/

	/*void SetHour(int hh)
	{
		hour = hh;
	}*/

	int GetHour()
	{
		return hour;
	}

	/*~Time() {}*/
};

class Thermometer
{
	int degree;
	Date d;
	Time t;
	vector<vector<int>> year365;
	double mid;
public:
	Thermometer(Date dd, Time tt, int deg = 0) : d(dd), t(tt)
	{
		year365.resize(1250);
		for (int i = 0; i < year365.size(); i++)
			year365[i].resize(24);
	}
	Thermometer operator=(const Thermometer&s)
	{
		d = s.d;
		t = s.t;
		degree = s.degree;
		return *this;
	}
	/*Thermometer(const Thermometer&s)
	{
		d = s.d;
		t = s.t;
		degree = s.degree;
	}*/

	void SetDegree(Date dd, Time tt, int deg)
	{
		year365[CodeNumberForDay(dd)][GetHourT(tt)] = deg;
	}
	int GetDegree(Date dd, Time tt)
	{
		return year365[CodeNumberForDay(dd)][GetHourT(tt)];
	}

	int GetDayT(Date d)
	{
		return d.GetDay();
	}
	int GetMonthT(Date d)
	{
		return d.GetMonth();
	}
	int GetYearT(Date d)
	{
		return d.GetYear();
	}
	int GetHourT(Time t)
	{
		return t.GetHour();
	}

	int CodeNumberForDay(Date dd)
	{
		int number;
		number = GetDayT(dd) + (GetMonthT(dd)*100);
		return number;
	}
	int FirstCodeMonth(int mm)
	{
		int first;
		switch (mm)
		{
		case 1:		
		{
			first = 101;
			break;
		}
		case 2:
		{
			first = 201;
			break;
		}
		case 3:
		{
			first = 301;
			break;
		}
		case 4:
		{
			first = 401;
			break;
		}
		case 5:
		{
			first = 501;
			break;
		}
		case 6:
		{
			first = 601;
			break;
		}
		case 7:
		{
			first = 701;
			break;
		}
		case 8:
		{
			first = 801;
			break;
		}
		case 9:
		{
			first = 901;
			break;
		}
		case 10:
		{
			first = 1001;
			break;
		}
		case 11:
		{
			first = 1101;
			break;
		}
		case 12:
		{
			first = 1201;
			break;
		}
		}
		return first;
	}
	int LastCodeMonth(int mm)
	{
		int last;
		switch (mm)
		{
		case 1:
		{
			last = 131;
			break;
		}
		case 2:
		{
			last = 228;
			break;
		}
		case 3:
		{
			last = 331;
			break;
		}
		case 4:
		{
			last = 430;
			break;
		}
		case 5:
		{
			last = 531;
			break;
		}
		case 6:
		{
			last = 630;
			break;
		}
		case 7:
		{
			last = 731;
			break;
		}
		case 8:
		{
			last = 831;
			break;
		}
		case 9:
		{
			last = 930;
			break;
		}
		case 10:
		{
			last = 1031;
			break;
		}
		case 11:
		{
			last = 1130;
			break;
		}
		case 12:
		{
			last = 1231;
			break;
		}
		}
		return last;
	}
	void SetSeriesOfDegrees(Date dd, int i, int deg)
	{
			year365[CodeNumberForDay(dd)][i] = deg;
	}
	double GetMiddleDate(Date dd)
	{
		for (int i = 0; i < 24; i++)
			mid += year365[CodeNumberForDay(dd)][i];
		mid /= 24;
		return mid;
	}
	double GetMiddleMonth(int mm)
	{
		for (int i = FirstCodeMonth(mm); i <= LastCodeMonth(mm); i++)
			for (int l = 0; l < 24; l++)
				mid += year365[i][l];
		mid /= (LastCodeMonth(mm) - FirstCodeMonth(mm));
		return mid;
	}
	double GetMiddle()
	{
		for (int i = 1; i < 13; i++)
		{
			for (int z = FirstCodeMonth(i); z <= LastCodeMonth(i); z++)
				for (int l = 0; l < 24; l++)
					mid += year365[z][l];
		}
		mid /= 365;
		return mid;
	}
	double GetMiddleDay(int mm)
	{
		for (int i = FirstCodeMonth(mm); i <= LastCodeMonth(mm); i++)
			for (int l = 5; l < 17; l++)
				mid += year365[i][l];
		mid /= (LastCodeMonth(mm) - FirstCodeMonth(mm));
		return mid;
	}
	double GetMiddleNight(int mm)
	{
		for (int i = FirstCodeMonth(mm); i <= LastCodeMonth(mm); i++)
			for (int l = 0; l < 5; l++)
				mid += year365[i][l];
		for (int i = FirstCodeMonth(mm); i <= LastCodeMonth(mm); i++)
			for (int l = 17; l < 24; l++)
				mid += year365[i][l];
		mid /= (LastCodeMonth(mm) - FirstCodeMonth(mm));
		return mid;
	}
	void Save()
	{
		ofstream File("Thermometer.txt");
		for (int i = 1; i < 13; i++)
		{
			for (int z = FirstCodeMonth(i); z <= LastCodeMonth(i); z++)
				for (int l = 0; l < 24; l++)
				{
					File << year365[z][l] << endl;
				}
		}
	}
	void Read()
	{
		ifstream File("Thermometer.txt");
		for (int i = 1; i < 13; i++)
		{
			for (int z = FirstCodeMonth(i); z <= LastCodeMonth(i); z++)
				for (int l = 0; l < 24; l++)
					File >> year365[z][l];
		}
		File.close();
	}
	~Thermometer()
	{
		year365.erase(year365.begin(), year365.begin() + year365.size());
	}
};

void main()
{
	int month;
	int degree=0;
	Date d(1, 1, 1);
	Time t(0);

	setlocale(LC_ALL, "rus");

	cout << "Введите дату и час" << endl;
	cout << "Год:" << endl;
	cin >> d.year;
	//d.SetYear(year);
	cout << "Месяц:" << endl;
	cin >> d.month;
	//d.SetMonth(month);
	cout << "День:" << endl;
	cin >> d.day;
	//d.SetDay(day);
	cout << "Час:" << endl;
	cin >> t.hour;
	//t.SetHour(hour);
	Thermometer s(d, t, degree);
	cout << "Введите наблюдение (температуру в градусах Цельсия)" << endl;
	cin >> degree;
	s.SetDegree(d, t, degree);
	cout << endl;

	int op;
	bool work = 1;
	while (work)
	{
		system("cls");
		cout << "Выберите команду:" << endl;
		cout << "1 - узнать дату" << endl;
		cout << "2 - узнать температуру в выбранном наблюдении и задать новую" << endl;
		cout << "3 - установить серию наблюдений" << endl;
		cout << "4 - средняя температура в выбранный день" << endl;
		cout << "5 - средняя температура в месяце" << endl;
		cout << "6 - средняя температура за год" << endl;
		cout << "7 - средняя дневная температура за месяц" << endl;
		cout << "8 - средняя ночная температура за месяц" << endl;
		cout << "9 - сохранить в файл" << endl;
		cout << "10 - прочитать из файла" << endl;
		cout << "0 - Выход" << endl;
		cin >> op;
		switch (op)
		{
		case 1:
		{
			cout << s.GetDayT(d) << "." << s.GetMonthT(d) << "." << s.GetYearT(d) << endl;
			cout << s.GetHourT(t) << ":00" << endl;
			system("pause");
			break;
		}
		case 2:
		{
			cout << "Введите дату и час" << endl;
			cout << "Год:" << endl;
			cin >> d.year;
			//d.SetYear(year);
			cout << "Месяц:" << endl;
			cin >> d.month;
			//d.SetMonth(month);
			cout << "День:" << endl;
			cin >> d.day;
			//d.SetDay(day);
			cout << "Час:" << endl;
			cin >> t.hour;
			//t.SetHour(hour);
			cout << s.GetDegree(d, t) << endl;
			cout << "Введите новую температуру" << endl;
			cout << "(если не требуется, то введите то же самое значение наблюдения)" << endl;
			cin >> degree;
			s.SetDegree(d, t, degree);
			system("pause");
			break;
		}
		case 3:
		{
			cout << "Введите дату" << endl;
			cout << "Год:" << endl;
			cin >> d.year;
			//d.SetYear(year);
			cout << "Месяц:" << endl;
			cin >> d.month;
			//d.SetMonth(month);
			cout << "День:" << endl;
			cin >> d.day;
			//d.SetDay(day);
			cout << "Введите температуру на каждый час дня" << endl;
			for (int i = 0; i < 24; i++)
			{
				cout << i << ":00" << endl;
				cin >> degree;
				s.SetSeriesOfDegrees(d, i, degree);
			}
			system("pause");
			break;
		}
		case 4:
		{
			cout << "Введите дату" << endl;
			cout << "Год:" << endl;
			cin >> d.year;
			//d.SetYear(year);
			cout << "Месяц:" << endl;
			cin >> d.month;
			//d.SetMonth(month);
			cout << "День:" << endl;
			cin >> d.day;
			//d.SetDay(day);
			cout << s.GetMiddleDate(d) << endl;
			system("pause");
			break;
		}
		case 5:
		{
			cout << "Выберите месяц" << endl;
			cin >> month;
			cout << s.GetMiddleMonth(month) << endl;
			system("pause");
			break;
		}
		case 6:
		{
			cout << s.GetMiddle() << endl;
			system("pause");
			break;
		}
		case 7:
		{
			cout << "Выберите месяц" << endl;
			cin >> month;
			cout << s.GetMiddleDay(month) << endl;
			system("pause");
			break;
		}
		case 8:
		{
			cout << "Выберите месяц" << endl;
			cin >> month;
			cout << s.GetMiddleNight(month) << endl;
			system("pause");
			break;
		}
		case 9:
		{
			s.Save();
			system("pause");
			break;
		}
		case 10:
		{
			s.Read();
			system("pause");
			break;
		}
		case 0:
		{
			work = 0;
			system("pause");
			break;
		}
		}
	}
}