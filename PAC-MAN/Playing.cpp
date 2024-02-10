#include "game.h"


void PlayGame(GAME* input, GAMER_INFO* user)
{
	bool BeSucc;
	int arrow;
	char cmd;
	char* position;
	position =FindPositon('@',1,&position, input->map, input->col, input->row);
	FindPositon('G',input->nGhosts,input->Ghost,input->map,input->col,input->row);
	PrintMapInConsole(input,user);
	system("cls");
	 while (_getch() != 0)
	{
		 system("cls");
		switch (_getch())
		{
		case Down:
		{
			if (*(position + input->col) == '.')
			{
				*(position + input->col) = *position;
				*position = '.';
				position = position + input->col;
			}
			else if (*(position + input->col) == 'G')
			{
				Sleep(2000);
				system("cls");
				printf("\nGAME OVER :( \n");
				_getch();
				return;
			}
			else if (*(position + input->col) == 'P')
			{
				input->score++;
				input->nPills--;
				*(position + input->col) = *position;
				*position = '.';
				position = position + input->col;
			}
				break;
		}
		case Right:
		{
			if (*(position + 1) == '.')
			{
				*(position + 1) = *position;
				*position = '.';
				position = position + 1;
			}
			else if (*(position + 1) == 'G')
				printf("game over");
			else if (*(position + 1) == 'P')
			{
				input->score++;
				*(position + 1) = *position;
				*position = '.';
				position = position + 1;
			}
				break;
		}
		case Left:
		{
			if (*position - 1 == '.')
			{
				*(position - 1) = *position;
				*position = '.';
				position = position - 1;
			}
			else if (*position - 1 == 'G')
			{
				user->level--;
				printf("\ngame over\n");
			}
			else if (*position - 1 == 'P')
			{
				input->score++;
				*(position - 1) = *position;
				*position = '.';
				position = position - 1;
			}
				break;
		}
		case Up:
		{
			if (*(position - input->col) == '.')
			{
				*(position - input->col) = *position;
				*position = '.';
				position = position - input->col;
			}
			else if (*(position - input->col) == 'G')
				printf("game over");
			else if (*(position - input->col) == 'P')
			{
				input->score++;
				*(position - input->col) = *position;
				*position = '.';
				position = position - input->col;
			}
				break;
		}
		}
		PrintMapInConsole(input,user);
		printf("\nPress 0 to Exit");
		if (!input->nPills) // print 'win' if there is no more pills 
		{
			user->level += 3;
			printf("\n\t\tYOU WIN!\n");
			Sleep(3000);
			return;
		}
		_getch();
	}
	 printf("Do you want to save the game and play it later?\n1.YES\n2.NO");
		 scanf("%c", &cmd);
		 if (cmd == 1)
		 {
			 user->UnfinishedGame = *input;
			 user->Unfinish = true;

		 }
		 else
			 user->UnfinishedGame = {};
		 UpdateUserData(user);

}

char* FindPositon(const char object, int num, char** buff, char** Matrix, int col, int row)
{
	if (num == 1)
	{
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				if (Matrix[i][j] == object)
					return &(Matrix[i][j]);
	}
	else
		for (int k = 0; k < num; k++)
			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					if (Matrix[i][j] == object)
						*(buff + k) = &(Matrix[i][j]);
	}

int MovingGhosts(GAME* input,GAMER_INFO *user)
{
	int arrow;
	while (true)
	{
		if (_kbhit())
			return _getch();
		for (int i = 0; i < input->nGhosts; i++)
		{
			first:
			arrow = rand() % 4;
			Sleep(1000);
			switch (arrow)
			{
			case '0'://down
			{
				if (*(input->Ghost[i] + input->col) == '.')
				{
					*(input->Ghost[i] + input->col) = *input->Ghost[i];
					*input->Ghost[i] = '.';
					input->Ghost[i] = input->Ghost[i] + input->col;
				}
				else if (*(input->Ghost[i] + input->col) == '@')
					printf("\ngame over :( \n");
				else
					goto first;
				break;
			}
			case 1://right
			{
				if (*(input->Ghost[i] + 1) == '.')
				{
					*(input->Ghost[i] + 1) = *input->Ghost[i];
					*input->Ghost[i] = '.';
					input->Ghost[i] = input->Ghost[i] + 1;
				}
				else if (*(input->Ghost[i] + 1) == '@')
					printf("game over");
				else goto first;
				break;
			}
			case 2://left
			{
				if (*input->Ghost[i] - 1 == '.')
				{
					*(input->Ghost[i] - 1) = *input->Ghost[i];
					*input->Ghost[i] = '.';
					input->Ghost[i] = input->Ghost[i] - 1;
				}
				else if (*input->Ghost[i] - 1 == '@')
				{
					printf("\ngame over\n");
				}
				else
					goto first;
				break;
			}
			case 3: //up
			{
				if (*(input->Ghost[i] - input->col) == '.')
				{
					*(input->Ghost[i] - input->col) = *input->Ghost[i];
					*input->Ghost[i] = '.';
					input->Ghost[i] = input->Ghost[i] - input->col;
				}
				else if (*(input->Ghost[i] - input->col) == '@')
					printf("game over");
				else
					goto first;
				break;
			}

			}
		}
		PrintMapInConsole(input,user);
	}
}

//void PrintMapInConsole(GAME* input, GAMER_INFO* user)
//{
//	int i, j, line;
//	for ( i = 0; i < (input->row) + 10; i++)
//		printf("_");
//	for (i = 0; i < input->row; i++)
//	{
//		for (line = 0; line < 5; line++)
//		{
//			printf("\t");
//			
//			for (j = 0; j < input->col;j++)
//			{
//				switch (input->map[i][j])
//				{
//				case '@':
//				{
//
//					break;
//				}
//				case 'P':
//				{
//
//					break;
//				}
//				case 'G':
//				{
//
//					break;
//				}case '.':
//				{
//					printf(" ");
//					break;
//				}
//				case ('|'||'-'):
//				{
//					printf(".");
//					break;
//				}
//				}
//			}
//			
//		}
//	
//	}
//	for (int i = 0; i < (input->row) + 10; i++)
//		printf("_");
//}