#ifndef GAME_H
#define GAME_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include <synchapi.h>

#define namelen 100
#define usernamelen 50
#define passwordlen 20
#define addresslen 200
#define typelen 20
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

//typedef struct BST
//{
//	void* key;
//	struct BST* left;
//	struct BST* right;
// }BST;
typedef struct GAME
{
	int score;
	int difficulty;
	int nPills;
	int nGhosts;
	char** Ghost;
	char** map;
	int col, row;
}GAME;
typedef struct GAMER_INFO
{
	char name[namelen];
	char username[usernamelen];
	int level;
	GAME UnfinishedGame;
}GAMER_INFO;

void* Loud_File(char* strFileName, char* strDataType);
BT_userpass* Insert(BT_userpass* root, userpass data);
BT_userpass* NewUserPass(userpass data);
userpass* Search(BT_userpass* root,char *strUsername );
GAMER_INFO* LoginPage(BT_userpass* root);
GAMER_INFO* SignUpPage(BT_userpass* root);
void PlayGame(GAME* input, GAMER_INFO* user);
GAME* CreateMatrix(GAME* input, int col, int row, char* strMap);
char* FindPositon(const char object,int num,char** buff, char** Matrix, int col, int row);
void PrintMapInConsole(GAME* input, GAMER_INFO* user);// Design Part
int NumberOfObjects(char** strMap,char Object, int row, int col);
int MovingGhosts(GAME *input);

int HomePage(void);
GAME* UserMenu(GAMER_INFO* gamer);
int BeautifulMenu(int option);
void printInfo(GAMER_INFO* gamer);
void SaveData(GAMER_INFO* input);
#endif GAME_H
