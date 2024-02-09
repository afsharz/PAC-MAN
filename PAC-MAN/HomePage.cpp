#include "game.h"
 int HomePage(void)
{
	  int cmd =0,option=0;
	  HANDLE hConsole;
	  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("pacman icon(double press enter)\n\n");
	printf("\tLog in\n");
	printf("\tSign Up");
	_getch();
		while (true)
		{
		Get_Key:

			cmd = _getch();
			if (cmd == 13)
			{
				if (option)
				{
					system("cls");
					return option;
				}

				else
					goto Get_Key;
			}
			switch (cmd)
			{
			case 'P'://down 
			{
				if (option < 2)
					option++;
				else
					goto Get_Key;
				break;
			}
			case 'H':
			{
				if (option > 1)
					option--;
				else
					goto Get_Key;
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
				printf("\tLog in\n");
				SetConsoleTextAttribute(hConsole, 15);
				printf("\tSign Up");
				_getch();
				break;
			}
			case 2:
			{
				printf("pacman icon(double press enter)\n\n");
				printf("\tLog in\n");
				SetConsoleTextAttribute(hConsole, 112);
				printf("\tSign Up");
				SetConsoleTextAttribute(hConsole, 15);
				_getch();
			}	break;
			}

		}
	
	
}


 GAME* UserMenu(GAMER_INFO* gamer)
 {
	 int option,cmd;
	 HANDLE hConsole;
	 hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	 first:
	 printInfo(gamer);
	 while (true)
	 {
	 Get_Key:
//		 option = BeautifulMenu(option);
		 cmd = _getch();
		 if (cmd == 13)
		 {
			 if (option)
			 {
				 system("cls");
				 if (option == 1)
				 {

				 }
				 else if (option == 2)
				 {
					 if (!gamer->UnfinishedGame.map[0])
					 {
						 printf("\nNo Unfinished Game Found!\n");
						 Sleep(3000);
						 system("cls");
						 goto Get_Key;
					 }
					 else
						 PlayGame(&gamer->UnfinishedGame,gamer);
					 goto first;
				 }
			 }

			 else
				 goto Get_Key;
		 }
		 switch (cmd)
		 {
		 case 'P'://down 
		 {
			 if (option < 2)
				 option++;
			 else
				 goto Get_Key;
			 break;
		 }
		 case 'H':
		 {
			 if (option > 1)
				 option--;
			 else
				 goto Get_Key;
			 break;
		 }
		 }
		 system("cls");
		 switch (option)
		 {
		 case 1:
		 {
			 printInfo(gamer);
			 SetConsoleTextAttribute(hConsole, 112);
			 printf("\tLog in\n");
			 SetConsoleTextAttribute(hConsole, 15);
			 printf("\tSign Up");
			 _getch();
			 break;
		 }
		 case 2:
		 {
			 printInfo(gamer);
			 printf("\tLog in\n");
			 SetConsoleTextAttribute(hConsole, 112);
			 printf("\tSign Up");
			 SetConsoleTextAttribute(hConsole, 15);
			 _getch();
		 }	break;
		 }
	 }
 }
 
 int BeautifulMenu(int option)
 {
	 int cmd;
	 cmd = _getch();
	 if (cmd == 13)
	 {
		 if (option)
		 {
			 system("cls");
			 return option;
		 }

		 else
			 return BeautifulMenu(option);
	 }
	 switch (cmd)
	 {
	 case 'P'://down 
	 {
		 if (option < 2)
			 option++;
		 break;
	 }
	 case 'H':
	 {
		 if (option > 1)
			 option--;
		 break;
	 }
	 }
	 return option;
 }


 void printInfo(GAMER_INFO* gamer)
 {
	 printf("pacman icon\n");
	 printf("%s\t%s\t%d\n", gamer->name, gamer->username, gamer->level);
	 printf("Start A New Game\nContinue Unfinished Game");
 }