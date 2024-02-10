#ifndef GAME_H
#define GAME_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <synchapi.h>

#define namelen 100
#define usernamelen 50
#define passwordlen 20
#define addresslen 200
#define typelen 20
#define Up 'H'
#define Down 'P'
#define Left 'K'
#define Right 'M'
#define EnterKey 13
#define x1 input->Ghost_x
#define y1 input->Ghost_y

//#define HORIZENTICAL_MENU int cmd=0,option=0;Get_Key:cmd = _getch();if (cmd == EnterKey){if (option){system("cls");return ChooseMap(option);}else goto Get_Key;}switch (cmd){case Right:{if (cmd < 4)cmd++;else goto Get_Key;break;}case Left:{if (cmd > 1)cmd--;else goto Get_Key;break;}}
using namespace std;
typedef struct userpass
{
	char username[usernamelen];
	char password[passwordlen];
}userpass;

typedef struct BT_userpass
{
	userpass data;
	struct BT_userpass* left;
	struct BT_userpass* right;
}BT_userpass;


typedef struct GAME
{
	int score;
	int difficulty;
	int nPills, nGhosts;
	int Ghost_x[6], Ghost_y[6];
	char map[15][15];
	int col, row;
}GAME;
typedef struct GAMER_INFO
{
	char name[namelen];
	char username[usernamelen];
	int level;
	bool Unfinish;
	GAME UnfinishedGame;
}GAMER_INFO;

void* Loud_File(char* strFileName, char* strDataType);
BT_userpass* Insert(BT_userpass* root, userpass data);
BT_userpass* NewUserPass(userpass data);
userpass* Search(BT_userpass* root,char *strUsername );
GAMER_INFO* LoginPage(BT_userpass* root);
GAMER_INFO* SignUpPage(BT_userpass* root);
void FreeMemory(BT_userpass* root);
void PlayGame(GAME* input, GAMER_INFO* user);
//GAME* CreateMatrix(GAME* input, int col, int row, char* strMap);
char* FindPositon(const char object,int num, char Matrix[15][15], int col, int row,int *x,int *y);
void PrintMapInConsole(GAME* input, GAMER_INFO* user);// Design Part
int NumberOfObjects(char strMap[15][15], char Object, int row, int col);
int MovingGhosts(GAME *input, GAMER_INFO* user);
GAME* GameBar(void);
GAME* ChooseMap(int option);
bool UpdateUserData(GAMER_INFO *input);

int HomePage(void);
GAME* UserMenu(GAMER_INFO* gamer);
//int BeautifulMenu(int option);
void printInfo(GAMER_INFO* gamer,bool IsFirst);
//void SaveData(GAMER_INFO* input);
#endif GAME_H
