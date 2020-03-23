#pragma once
const int r = 4;
const int c = 4;
int x, y;
const char winboard[c][r] = { '1', '2','3', '4', '5', '6','7', '8', '9','A' ,'B' ,'C', 'D','E', 'F', ' ' };
bool win = true;
void AutoWin_(char arr[c][r]);
void Print(char arr[c][r]);
void Tass(char arr[c][r]);
void Game(char arr[c][r]);
void Walk(char arr[c][r]);
bool Win(char arr[c][r]);
enum Direct{Up,Down,Left,Right,AutoWin}; Direct dir;
void Logic(Direct dir,char arr[c][r]);