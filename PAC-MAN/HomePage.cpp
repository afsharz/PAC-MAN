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
		 cmd =_getch();
		if (cmd == 13)
		{
			if (option)
				return option;
			else
				goto Get_Key;
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

			printf("pacman icon(double press enter)\n\n");
			printf("\tLog in\n");
			SetConsoleTextAttribute(hConsole, 112);
			printf("\tSign Up");
			SetConsoleTextAttribute(hConsole, 15);
			_getch();
			break;
		}

	}
}