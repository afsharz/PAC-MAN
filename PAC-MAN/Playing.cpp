#include "game.h"


void PlayGame(GAME* input, GAMER_INFO* user)
{
	int *x, *y;
	x = (int*)malloc(sizeof(int));
	y = (int*)malloc(sizeof(int));
	bool BeSucc;
	int arrow;
	char cmd;
	FindPositon('@',1, input->map, input->col, input->row,x,y);
	FindPositon('G',input->nGhosts,input->map,input->col,input->row,input->Ghost_x,input->Ghost_y);
	PrintMapInConsole(input,user);
	_getch();
	cmd= _getch();
	 while (cmd)
	{
		switch (cmd)
		{
		case Down:
		{
			if (input->map[(*x)+1][*y] == '.')
			{
				input->map[(*x) + 1][*y] = input->map[*x][*y];
				input->map[*x][*y] = '.';
				(*x)++;
			}
			else if (input->map[(*x) + 1][*y] == 'G')
			{
				Sleep(2000);
				system("cls");
				printf("\nGAME OVER :( \n");
				_getch();
				return;
			}
			else if (input->map[(*x )+ 1][*y] == 'P')
			{
				input->score++;
				input->nPills--;
				input->map[(*x) + 1][*y] = input->map[*x][*y];
				input->map[*x][*y] = '.';
				(*x)++;
			}
				break;
		}
		case Right:
		{
			if (input->map[*x][*y+1] == '.')
			{
				input->map[*x][*y + 1] = input->map[*x][*y ];
				input->map[*x][*y] = '.';
				(*y)++;
			}
			else if (input->map[*x][*y + 1] == 'G')
				printf("game over");
			else if (input->map[*x][*y + 1] == 'P')
			{
				input->score++;
				input->nPills--;
				input->map[*x][(*y) + 1] = input->map[*x][*y];
				input->map[*x][*y] = '.';
				(*y)++;
				
			}
				break;
		}
		case Left:
		{
			if (input->map[*x][(*y)-1]== '.')
			{
				input->map[*x][*y-1] = input->map[*x][*y];
				input->map[*x][*y] = '.';
				(*y)--;

			}
			else if (input->map[*x][*y-1]== 'G')
			{
				user->level--;
				printf("\ngame over\n");
			}
			else if (input->map[*x][(*y) - 1] == 'P')
			{
				input->score++;
				input->nPills--;
				input->map[*x][(*y)-1] = input->map[*x][*y];
				input->map[*x][*y] = '.';
				(*y)--;
			}
				break;
		}
		case Up:
		{
			if (input->map[(*x)-1][*y] == '.')
			{
				input->map[(*x)-1][*y] = input->map[*x][*y];
				input->map[*x][*y] = '.';
				(*x)--;
			}
			else if (input->map[(*x)-1][*y] == 'G')
				printf("game over");
			else if (input->map[(*x) - 1][*y] == 'P')
			{
				input->score++;
				input->nPills--;
				input->map[(*x) - 1][*y] = input->map[*x][*y];
				input->map[*x][*y] = '.';
				(*x)--;
			}
				break;
		}
		}
		system("cls");
		
		PrintMapInConsole(input,user);
		printf("\nPress 0 to Exit");
		if (!input->nPills) // print 'win' if there is no more pills 
		{
			user->level += 3;
			printf("\n\t\tYOU WIN!\n");
			Sleep(3000);
			return;
		}
		
		while (true)
		{
			cmd=MovingGhosts(input, user);
			system("cls");
			PrintMapInConsole(input, user);
			Sleep(1000);
			if (_kbhit())
			{
				_getch();
				cmd = _getch();
				break;
			}
		}
		/*_getch();
		cmd = _getch();*/
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

char* FindPositon(const char object, int num , char Matrix[15][15], int col, int row, int* x, int* y)
{
	if (num == 1)
	{
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				if (Matrix[i][j] == object)
				{
					*x = i;
					*y = j;
					return &(Matrix[i][j]);
				}
					
	}
	else
		for (int k = 0; k < num; k++)
			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					if (Matrix[i][j] == object)
					{
						*(x + sizeof(int)* k) = i;
						*(y + sizeof(int) * k) = j;
					}
}

int MovingGhosts(GAME* input,GAMER_INFO *user)
{
	while (false)
		return 0;
	int arrow;
		for (int i = 0; i < input->nGhosts; i++)
		{
			first:
			arrow = rand() % 4;
			
			switch (arrow)
			{
			case '0'://down
			{
				if (input->map[x1[i]+1][y1[i]] == '.')
				{
					input->map[x1[i]+1][y1[i]] = input->map[x1[i]][y1[i]];
					input->map[x1[i]][y1[i]] = '.';
					x1[i]++;
				}
				else if (input->map[x1[i] + 1][y1[i]] == '@')
					printf("\ngame over :( \n");
				else
					goto first;
				break;
			}
			case 1://right
			{
				if (input->map[x1[i]][y1[i]+1] == '.')
				{
					input->map[x1[i]][y1[i] + 1] = input->map[x1[i]][y1[i]];
					input->map[x1[i]][y1[i]] = '.';
					y1[i]++  ;
				}
				else if (input->map[x1[i]][y1[i] + 1] == '@')
					printf("game over");
				else goto first;
				break;
			}
			case 2://left
			{
				if (input->map[x1[i]][y1[i]-1] == '.')
				{
					input->map[x1[i]][y1[i] - 1] = input->map[x1[i]][y1[i]];
					input->map[x1[i]][y1[i]] = '.';
					y1[i]--;
				}
				else if (input->map[x1[i]][y1[i]-1]== '@')
				{
					printf("\ngame over\n");
				}
				else
					goto first;
				break;
			}
			case 3: //up
			{
				if (input->map[x1[i]-1][y1[i]] == '.')
				{
					input->map[x1[i] - 1][y1[i]] = input->map[x1[i]][y1[i]];
					input->map[x1[i]][y1[i]] = '.';
					x1[i]--;
				}
				else if (input->map[x1[i] - 1][y1[i]] == '@')
					printf("game over");
				else
					goto first;
				break;
			}

			}
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