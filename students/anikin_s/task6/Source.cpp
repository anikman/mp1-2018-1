#include <iostream> 
#include <cstdio> 
#include <conio.h> 
#include <vector> 
#include <Windows.h> 
#include <clocale> 
#include <time.h> 

using namespace std;

struct Snake
{
	vector<int> x;
	vector<int> y;
	int headX, headY;
	int length;
	Snake(int _length = 5, int _headX = 0, int _headY = 0) : length(_length), headX(_headX), headY(_headY) {};
};
struct Fruit
{
	int fruitX, fruitY;
	Fruit(int _fruitX = 5, int _fruitY = 5) : fruitX(_fruitX), fruitY(_fruitY) {};
	void CreateFruit(int _width, int _height)
	{
		srand(time(NULL));
		fruitX = (rand() % _width) +1;
		fruitY = (rand() % _height) +1;
	}
};
struct Map
{
	int height, width;
	Snake Snake;
	Fruit Fruit;
	Map(int _height = 10, int _width = 10) : height(_height), width(_width) {}

	void gotoxy(int x, int y)
	{
		HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
		if (!Console)
			return;

		COORD pos;
		pos.X = x;
		pos.Y = y;

		SetConsoleCursorPosition(Console, pos);
	}
	
	void CreateSnake()
	{
		Snake.headX = (width + 2) / 2;
		Snake.headY = (height + 2) / 2;
		for (int i = 1; i < 5; i++)
		{
			Snake.x.push_back(Snake.headX + i);
			Snake.y.push_back(Snake.headY);
		}
	}

	void PaintMap()
	{
		for (int i = 0; i < width + 2; i++)
			cout << "#";
		for (int i = 1; i < height + 1; i++)
		{
			gotoxy(0, i);
			cout << "#";
			gotoxy(width + 1, i);
			cout << "#";
		}
		gotoxy(0, height + 1);
		for (int i = 0; i < width + 2; i++)
			cout << "#";
		gotoxy(width + 15, 0);
		cout << "Длина змейки: ";
		gotoxy(width + 15, 2);
		cout << "Ваша цель: 25";
		CreateSnake();
	}
};
class TheGame
{
private:
	int Direction;
	int Purpose;
	enum Directon { LEFT, RIGHT, UP, DOWN };
	Directon dir;
	bool GameOver;
	bool GameVictory;
	Map Map;

	void gotoxy(int x, int y)
	{
		HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
		if (!Console)
			return;

		COORD pos;
		pos.X = x;
		pos.Y = y;

		SetConsoleCursorPosition(Console, pos);
	}

public:
	TheGame(bool _GameOver = false, bool _GameVictory = false)
	{
		GameOver = _GameOver;
		GameVictory = _GameVictory;
		Purpose = 25;
		dir = LEFT;
	}
	void Input()
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 75:
				if (dir != RIGHT)
					dir = LEFT;
				break;
			case 77:
				if (dir != LEFT)
					dir = RIGHT;
				break;
			case 72:
				if (dir != DOWN)
					dir = UP;
				break;
			case 80:
				if (dir != UP)
					dir = DOWN;
				break;
			}
		}
	}
	void Logic()
	{
		int tmpX = Map.Snake.x[0];
		int tmpY = Map.Snake.y[0];
		int tmpXX, tmpYY;
		Map.Snake.x[0] = Map.Snake.headX;
		Map.Snake.y[0] = Map.Snake.headY;
		switch (dir)
		{
		case LEFT:
			Map.Snake.headX--;
			break;
		case RIGHT:
			Map.Snake.headX++;
			break;
		case UP:
			Map.Snake.headY--;
			break;
		case DOWN:
			Map.Snake.headY++;
			break;
		default:
			break;
		}
		for (int i = 1; i < Map.Snake.length - 1; i++)
		{
			tmpXX = Map.Snake.x[i];
			tmpYY = Map.Snake.y[i];
			Map.Snake.x[i] = tmpX;
			Map.Snake.y[i] = tmpY;
			tmpX = tmpXX;
			tmpY = tmpYY;
		}
		if (Map.Snake.headX > Map.width || Map.Snake.headX < 1 || Map.Snake.headY > Map.height || Map.Snake.headY < 1)
			GameOver = true;
		for (int i = 2; i < Map.Snake.length - 1; i++)
			if ((Map.Snake.x[i] == Map.Snake.headX) && (Map.Snake.y[i] == Map.Snake.headY))
				GameOver = true;
		if ((Map.Snake.headX == Map.Fruit.fruitX) && (Map.Snake.headY == Map.Fruit.fruitY))
		{
			MessageBeep(0);
			bool flag = true;
			while (flag)
			{
				flag = false;
				Map.Fruit.CreateFruit(Map.width, Map.height);
				for (int i = 0; i < Map.Snake.length - 1; i++)
					if ((Map.Fruit.fruitX == Map.Snake.x[i]) && (Map.Fruit.fruitY == Map.Snake.y[i]))
					{
						flag = true;
						break;
					}
			}
			Map.Snake.length++;
			gotoxy(Map.width + 28, 0);
			cout << Map.Snake.length;
			if (Map.Snake.length == Purpose)
				GameVictory = true;
			Map.Snake.x.push_back(0);
			Map.Snake.y.push_back(0);
		}
	}
	bool GetGameOver()
	{
		return GameOver;
	}
	bool GetGameVictory()
	{
		return GameVictory;
	}
	void MotionSnake()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(hConsole, &structCursorInfo);
		structCursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(hConsole, &structCursorInfo);

		for (int i = 1; i < Map.height + 1; i++)
		{
			for (int j = 1; j < Map.width + 1; j++)
			{
				if (i == Map.Snake.headY && j == Map.Snake.headX)
				{
					gotoxy(j, i);
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
					cout << "s";
				}
				else if (i == Map.Fruit.fruitY && j == Map.Fruit.fruitX)
				{
					gotoxy(j, i);
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 12));
					cout << "a";
				}
				else
				{
					bool print = false;
					for (int k = 0; k < Map.Snake.length - 1; k++)
					{
						if (Map.Snake.x[k] == j && Map.Snake.y[k] == i)
						{
							gotoxy(j, i);
							SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
							cout << "0";
							print = true;
						}
					}
					if (!print)
					{
						gotoxy(j, i);
						SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 0));
						cout << " ";
					}
				}
			}
		}
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
	}
	void Jury()
	{
		if (GameVictory)
		{
			gotoxy(Map.width + 15, 4);
			cout << "Вы победили ";
		}
		if (GameOver)
		{
			gotoxy(Map.width + 15, 4);
			cout << "Вы проиграли ";
		}
	}
	void CreateMap(int _width, int _height)
	{
		Map.width = _width;
		Map.height = _height;
		Map.PaintMap();
	}
};


int main()
{
	setlocale(LC_ALL, ("rus"));

	HWND hWnd = GetForegroundWindow();
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);

	int x, y;
	TheGame Game;
	cout << "Введите ширину карты: " << endl;
	cin >> x;
	cout << "Введите высоту карты: " << endl;
	cin >> y;
	system("cls");
	Game.CreateMap(x, y);
	while (!Game.GetGameOver() && !Game.GetGameVictory())
	{
		Game.MotionSnake();
		Game.Input();
		Game.Logic();
	}
	Game.Jury();
	system("pause");
}