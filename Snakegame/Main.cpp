#include<iostream>
#include<conio.h>
#include <windows.h>
using namespace std;
bool gameover;//since its result will be in true or false
const int width = 70;//it should be fixed
const int height = 50;
int x, y, fruitx, fruity, score;
int tailx[100], taily[100], ntail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };//This code is a enum declaration. After declaration, you can define variable of type seasons. And this variable of type seasons(winter,summer,3rd,4th) can only have one of those 4 values. For example:

// 

COORD coord = { 0, 0 };



eDirection dir;

void setup()//3. setup fun def.
{
	gameover = false;//4. from here it will check data type of variables and provide space in memory
	dir = STOP;
	x = width / 3;
	y = height / 2;
	fruitx = rand() % width;
	fruity = rand() % height;
	score = 0;
}
void draw()//7. yes draw fun is here come inside draw now
{
	const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, coord);
	//system("cls");//8. it will clear the screen
	for (int i = 0; i < width + 2; i++)//9. it will generate a loop for width. if cond is true then print
		cout << "*";//10. print it till cond is true
	cout << endl;//11. when cond false then change the line 
	for (int i = 0; i < height; i++)//12. now it will enter in other for loop, if cond is true the enter
	{
		for (int j = 0; j < width; j++)//13. now entered here if cond is true the go in block
		{
			if (j == 0)//14. if true
				cout << "*";//15. print 
			if (i == y && j == x)
				cout << "@";
			else if (i == fruity && j == fruitx)

				cout << "f";//
			else
			{
				bool print = false;
				for (int k = 0; k < ntail; k++)
				{
					if (tailx[k] == j && taily[k] == i)
					{
						cout << "8";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}
			if (j == width - 1)
				cout << "*";
		}//close for j
		cout << endl;

	}//close fvor i
	for (int i = 0; i < width + 2; i++)
		cout << "*";


}//close for draw fun
void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case'd':
			dir = RIGHT;
			break;
		case'w':
			dir = UP;
			break;
		case's':
			dir = DOWN;
			break;
		case'x':
			gameover = true;
			break;
		default:
			cout << "wrong input";

		}
	}
}
void logic()
{
	int prevx = tailx[0];
	int prevy = taily[0];
	int prev2x, prev2y;
	tailx[0] = x;
	taily[0] = y;
	for (int i = 1; i < ntail; i++)
	{
		prev2x = tailx[i];
		prev2y = taily[i];
		tailx[i] = prevx;
		taily[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
	}
	switch (dir)
	{
	case LEFT:
		x = x - 1;
		break;
	case RIGHT:
		x = x + 1;
		break;
	case UP:
		y = y - 1;
		break;
	case DOWN:
		y = y + 1;
		break;
	default:
		break;
	}
	//if (x > width || x<0 || y>height || y < 0)
	//gameover = true;
	if (x >= width)
		x = 0;
	else
		if (x < 0)
			x = width - 1;
	if (y >= height)
		y = 0;
	else
		if (y < 0)
			y = height - 1;
	for (int i = 0; i < ntail; i++)
		if (tailx[i] == x && taily[i] == y)
			gameover = true;
	if (x == fruitx && y == fruity)
	{
		score += 10;
		fruitx = rand() % width;
		fruity = rand() % height;
		ntail++;
	}
}

void main()//1. first of all main will start
{


	setup();//2. setup fun will be called
	while (!gameover)//5. inside loop cond will check if game is not over then do and come in side while 
	{
		draw();//6. draw fun is calling now it will check where is it's def & declaration 
		cout << endl << endl << endl;
		cout << "score==" << score << endl;
		input();
		logic();
		//Sleep(10);
		Sleep(40); //speed of snake

	}
	_getch();
}
