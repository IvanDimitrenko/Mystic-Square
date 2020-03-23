#include<iostream>
#include<conio.h>
#include<algorithm>
#include<time.h>
#include"Prototype.h"
using namespace std;
void main(bool win)
{
	setlocale(LC_ALL, "");
	cout <<"************************************************\n"<< "*********************Пятнашки*******************\n"
		<< "************************************************\n";
	cout <<"\nVersion 0.1\n";
	system("pause");
	system("cls");
	char arr[c][r] = { '1', '2','3', '4', '5', '6','7', '8', '9','A' ,'B' ,'C', 'D','E', 'F', ' ' };
	srand(time(NULL));
	Game(arr);
}
void Tass(char arr[c][r])
{
	for (int i = 0; i < 5000; i ++)
	{
			swap(arr[rand()%4][rand() % 4], arr[rand() % 4][rand() % 4]);
	}
	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			if (arr[i][j] == ' ') {			
				x = j; y = i; break;		// поиск кординат 
			}	
}  //  можно сделать  своей же механикой двигать в рандомные места ну я сделал по своему
void Print(char arr[c][r])
{
	cout <<  "A - 10, B - 11, C -12, D - 13, E - 14, F - 15 \n w - up; s - down; a - left; d - right; z - autowin\n ";
	cout << " _______" << endl;  
	for (int i = 0; i < c; i++)
	{
		for (int y = 0; y < r; y++)
		{
			cout <<" "<< arr[i][y];
		}
		cout << '|' << endl;
	}
	cout << "X: " << x << " Y: " << y << endl;
	Walk(arr);
	system("cls");
}
void Game(char arr[c][r])
{
	Tass(arr);
	do
	{
		if(arr[0][0] == '1' && arr[1][1] == '6' && arr[3][3] == ' ' && arr[3][2] == 'F')
			Win(arr);
		Print(arr);
	} while (win);
}
void Walk(char arr[c][r])
{   char play;
	play = _getch();
	switch (play)
	{
	default: return Walk(arr);
		break;
	case 'w': Logic(Up,arr);
		 break;
	case 's': Logic(Down,arr);
		break;
	case 'a' :Logic(Left,arr);
		break;

	case 'd' :Logic(Right,arr);
		break;
	case 'z' :Logic(AutoWin, arr);
		break;
	}
}
void Logic(Direct dir, char arr[c][r]) // установка механики
 {  switch (dir)
	{
	case Up:
	{
		if (y > 0)
			swap(arr[y][x], arr[y - 1][x]);y--;
		break;
	}
	case Down:
	{
		if (y < 3)
		swap(arr[y][x], arr[y + 1][x]);y++;
	  break;
	}
	case Left:
	{
		if (x > 0)
		{
			swap(arr[y][x], arr[y][x - 1]);x--;
		}
		break;
	}
	case Right:
	{
		if (x < 3)
		{
			swap(arr[y][x], arr[y][x + 1]);x++;
		}
		break;
	}
	case AutoWin: AutoWin_(arr);
  }
}
void AutoWin_(char arr[c][r])
{
	for (int i = 0; i < c; i++)
	for (int j = 0; j < r ; j++)
			arr[i][j] = winboard[i][j];
}
bool Win(char arr[c][r])
{    for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
		{
			if (arr[i][j] == winboard[i][j])
				continue;
			else 
              win = true; return win;	
		}
		arr[3][3] = 'S';
		win = false;
		return win;
}
