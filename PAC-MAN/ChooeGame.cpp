#include "game.h"

GAME* GameBar(void)
{
	int cmd = 0, option = 0;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	printf("pacman icon(double press enter)\n\n");
	printf("\tselect level\n\tchoose map\n\nback");
	_getch();

	while (true)
	{
	Get_Key:
		cmd = _getch();
		if (cmd == EnterKey)
		{
			if (option==1||option==2)
			{
				system("cls");
				return ChooseMap(option);
			}
			else if (option == 3)
			{
				return NULL;
			}
			else
				goto Get_Key;
		}
		switch (cmd)
		{
		case Down:
		{
			if (option < 3)
				option++;
			else
			{
				_getch();
				goto Get_Key;
			}
			break;
		}
		case Up:
		{
			if (option > 1)
				option--;
			else
			{
				_getch();
				goto Get_Key;
			}
			break;
		}
		}
		system("cls");
		switch (option)
		{
		case 1:
		{
			printf("pacman icon(double press enter)\n\n");
			SetConsoleTextAttribute(hConsole, 112);
			printf("\tSelect Level\n");
			SetConsoleTextAttribute(hConsole, 15);
			printf("\tChoose Map");
			printf("\n\n Back");
			_getch();
			break;
		}
		case 2:
		{
			printf("pacman icon(double press enter)\n\n");
			printf("\tSelect Level\n");
			SetConsoleTextAttribute(hConsole, 112);
			printf("\tChoose Map");
			SetConsoleTextAttribute(hConsole, 15);
			printf("\n\n Back");
			_getch();
			break;
		}
		case 3:
		{
			printf("pacman icon(double press enter)\n\n");
			printf("\tSelect Level\n");
			printf("\tChoose Map");
			SetConsoleTextAttribute(hConsole, 64);
			printf("\n\n Back");
			SetConsoleTextAttribute(hConsole, 15);
		}
		}
	}
}

	GAME* ChooseMap(int option)
	{
		FILE* GameList;
		char GameName[addresslen], type[typelen],buffer[23];
		int Dificullity,wanted,line=0,startPonit;
		/**/	strcpy(GameName, "mapA.txt");
		/**/	strcpy(type,"GAME");
		GAME* temp;
		GAMER_INFO alaki = {};
		strcpy(type, "GAME");
		if (option == 1)
		{
			printf("Choose Dificulity \n1.EASY\n2.MEDIUM\n3.HARD\n");
			scanf("%d", &wanted);
			temp = (GAME*)Loud_File(GameName, type); system("cls");
			return temp;
			//GameList = fopen("GameList.txt", "r");
			
		/*	while (fscanf(GameList, "%s %d", GameName, &Dificullity) > 0)
			{
				if (Dificullity == wanted)
				{
					startPonit =ftell(GameList);
					while (fscanf(GameList, "%s %d", GameName, &Dificullity) > 0 && Dificullity == wanted)
						++line;
					fseek(GameList,startPonit, SEEK_SET);
					fgets(buffer, (rand() % line) - 1,GameList);
					fscanf(GameList, "%s", GameName);
					temp =(GAME*) Loud_File(GameName, type);
					system("cls");
					printf("Press Enter To Start");
					_getch();
					return temp;
				}
			}*///printf("\n\t1.PLAY\t2.NEXT\t3.PREVIOUS\t4.BACK");PrintMapInConsole(temp, &alaki);
		}
	}