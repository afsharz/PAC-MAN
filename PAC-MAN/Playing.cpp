#include "game.h"

void PlayGame(GAME* input, GAMER_INFO* user)
{
	int arrow;
	char cmd;
	char* position;
	position =FindPositon('@',1,&position, input->map, input->col, input->row);
	FindPositon('G',input->nGhosts,input->Ghost,input->map,input->col,input->row);
	PrintMapInConsole(input);
	system("cls");
	 while (_getch() != 0)
	{
		 system("cls");
		switch (_getch())
		{
		case 'P'://down
		{
			if (*(position + input->col) == '.')
			{
				*(position + input->col) = *position;
				*position = '.';
				position = position + input->col;
			}
			else if (*(position + input->col) == 'G')
				printf("\ngame over :( \n");
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
		case 'M'://right
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
		case 'K'://left
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
		case 'H'://up
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
		PrintMapInConsole(input);
		if (!input->nPills) // print 'win' if there is no more pills 
		{
			user->level += 3;
			printf("\n\t\tYOU WIN!\n");
			_getch();
		}
		_getch();
	}
	 printf("Do you want to save the game and play it later?\nYES\nNO");
		 scanf("%c", &cmd);
		// if (cmd == y)
			// savedata;
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

int MovingGhosts(GAME* input)
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
		PrintMapInConsole(input);
	}
}