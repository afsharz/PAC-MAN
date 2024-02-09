#include "game.h"
int HomePage(void)
{
	int cmd=0, option = 0;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("pacman icon(double press enter)\n\n");
	printf("\tLog in\n");
	printf("\tSign Up\n\nExit");
	_getch();
	while (true)
	{
	Get_Key:
		cmd = _getch();
		if (cmd == EnterKey) {
			if (option) {
				system("cls");
				return option;
			}
			else
			{
				goto Get_Key;
			}
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
				goto Get_Key;
				_getch();
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
			printf("\tLog in\n");
			SetConsoleTextAttribute(hConsole, 15);
			printf("\tSign Up\n\n");
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
			printf("\n\nExit");
			_getch();
			break;
		}
		case 3:
		{
			printf("pacman icon(double press enter)\n\n");
			printf("\tLog in\n");
			
			printf("\tSign Up");
			SetConsoleTextAttribute(hConsole, 112);
			printf("\n\nExit");
			SetConsoleTextAttribute(hConsole, 15);
			_getch();
			break;
		}
		}

	}


}


 GAME* UserMenu(GAMER_INFO* gamer)
 {
	 int option, cmd;
	 HANDLE hConsole;
	 hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	 first:
	 printInfo(gamer,true);
	 while (true)
	 {
	 Get_Key:

		 cmd = _getch();
		 if (cmd == EnterKey)
		 {
			 if (option)
			 {
				 system("cls");
				 if (option == 1)
				 {
					 GameBar();
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
				 else if (option == 3)
				 {
					 free(gamer);
					 system("cls");
					 printf("\n\n\t\tHope to see you soon!");
					 Sleep(2000);
					 return NULL;
				 }
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
			 printInfo(gamer,false);
			 SetConsoleTextAttribute(hConsole, 112);
			 printf("\tNew Game\n");
			 SetConsoleTextAttribute(hConsole, 15);
			 printf("\tContinue Unfinished Game\n");
			 printf("\nLog out");
			 _getch();
			 break;
		 }
		 case 2:
		 {
			 printInfo(gamer, false);
			 printf("\tNew Game\n");
			 SetConsoleTextAttribute(hConsole, 112);
			 printf("\tContinue Unfinished Game\n");
			 SetConsoleTextAttribute(hConsole, 15);
			 printf("\nLog out");
			 _getch();
			 break;
		 }
		 case 3:
		 {
			 printInfo(gamer, false);
			 printf("\tNew Game\n");
			 printf("\tContinue Unfinished Game\n");
			 SetConsoleTextAttribute(hConsole, 112);
			 printf("\nLog out");
			 SetConsoleTextAttribute(hConsole, 15);
			 _getch();
			 break;
		 }
		 }
	 }

 }
 
 int BeautifulMenu(int option)
 {
	 int cmd;
	 cmd = _getch();
	 if (cmd == EnterKey)
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
	 case Down://down 
	 {
		 if (option < 2)
			 option++;
		 break;
	 }
	 case Up:
	 {
		 if (option > 1)
			 option--;
		 break;
	 }
	 }
	 return option;
 }


 void printInfo(GAMER_INFO* gamer,bool IsFirst)
 {
	 printf("pacman icon\n");
	 printf("%s\t%s\t%d\n", gamer->name, gamer->username, gamer->level);
	 if(IsFirst)
	 printf("\tStart A New Game\n\tContinue Unfinished Game\n\nLog out");
 }