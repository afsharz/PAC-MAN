#include "game.h"

////char* UploadMap(const char*FileName)
//{
//	char* str;
//	GAME* game;
//	FILE* fp;
//	fp = fopen(FileName, "r");
//	if (!fp)
//	{
//		printf("\nError Loading Game\n");
//		return 0;
//	}
//	game = (GAME*)malloc(sizeof(GAME));
//	fscanf(fp, "%d %d", &game->col, &game->row);
//	str = (char*)calloc(sizeof(char),( game->row* game->col)+1);
//	fread(str, game->row * game->col ,1, fp);
//	CreateMatrix(game,game->col,game->row,str);
//	game->score = 0;
//	//return game;
//
//	
//}

//GAME* CreateMatrix( GAME *input, int col, int row,char* strMap)
//{
//	int k = 0;
//	for (int i = 0; i < input->row; i++)
//		for (int j = 0; j < input->col; j++)
//			input->map[i][j] = strMap[k++];
//	input->Ghost = (char**)malloc((input->nGhosts) * sizeof(char*));
//	for (int i = 0; i < input->nGhosts; i++)
//	{
//		FindPositon('G',1, &input->Ghost[i], input->map, input->col, input->row);
//	}
//
//	return input;
//}






void PrintMapInConsole(GAME* input,GAMER_INFO *user)
{
	printf("PLAYER:%s\nID:%s\n",user->name,user->username);
	printf("SCORE: %d \t\t\t%s'S LEVEL:%d\n",input->score, user->name,user->level);
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int i, j, line;
	SetConsoleTextAttribute(hConsole, 2);
	for (i = 0; i < (input->col) ; i++)
	{
		SetConsoleTextAttribute(hConsole, 2);
		printf("______");
	}
	SetConsoleTextAttribute(hConsole, 15);
	//printf("\n");
		
	for (i = 0; i < input->row; i++)
	{
		for (line = 0; line < 5; line++)
		{
			printf("\n");

			for (j = 0; j < input->col; j++)
			{
				switch (input->map[i][j])
				{
				case '@':
				{
					SetConsoleTextAttribute(hConsole, 6);
					switch (line)
					{
					case 0:
					{
						printf(" .--. ");
						break;
					}
					case 1:
					{
						printf("/ _.-'");
						break;
					}case 2:
					{printf("\\  '-.");
						break;
					}case 3:
					{printf(" '--' ");
						break;
					}
					case 4:
					{printf("      ");
						break;
					}
					}
					SetConsoleTextAttribute(hConsole, 15);
					break;
				}
				case 'P':
				{
					SetConsoleTextAttribute(hConsole, 4);
					switch (line)
					{
					case 0:
					{
						printf("      ");
						break;
					}
					case 1:
					{
						printf("      ");
						break;
					}
					case 2:
					{
						printf("   @  ");
						break;
					}
					case 3:
					{
						printf("      ");
						break;
					}
					case 4:
					{
						printf("      ");
						break;
					}
					}
					SetConsoleTextAttribute(hConsole, 15);
					break;
				}
				case 'G':
				{
					SetConsoleTextAttribute(hConsole, 13);
					switch (line)
					{
					case 0:
					{
						printf("  .-. ");
						break;
					}
					case 1:
					{
						printf(" | OO|");
						break;
					}case 2:
					{
						printf(" |   |");
						break;
					}case 3:
					{
						printf(" '^^^'");
						break;
					}
					case 4:
					{
						printf("      ");
						break;
					}
					SetConsoleTextAttribute(hConsole, 15);
					break;
					}
					break;
				}
				case '.':
				{
					printf("      ");
					break;
				}
				case '-' :
				{
					SetConsoleTextAttribute(hConsole, 1);
					//if (line != 0 && line != 4)
						printf("888888");
					//else
					//	printf("      ");
					SetConsoleTextAttribute(hConsole, 15);
					break;
				}
				case '|':
				{
					SetConsoleTextAttribute(hConsole, 1);
					//if (line != 0 && line != 4)
						printf("888888");
					//else
						//printf("      ");
					SetConsoleTextAttribute(hConsole, 15);
					break;
				}
				}
			}

		}

	}
	printf("\n");
	for (i = 0; i < (input->col); i++)
	{
		SetConsoleTextAttribute(hConsole, 2);
		printf("______");
	}
	SetConsoleTextAttribute(hConsole, 15);
}


int NumberOfObjects(char strMap[15][15], char object, int row, int col)
{
	int Num = 0;
	for(int i=1;i<row-1;i++)
		for (int j = 0; j < col-1; j++)
			if (strMap[i][j] == object)
				Num++;
	return Num;
}