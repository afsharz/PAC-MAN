#include "game.h"

char* UploadMap(const char*FileName)
{
	char* str;
	GAME* game;
	FILE* fp;
	fp = fopen(FileName, "r");
	if (!fp)
	{
		printf("\nError Loading Game\n");
		return 0;
	}
	game = (GAME*)malloc(sizeof(GAME));
	fscanf(fp, "%d %d", &game->col, &game->row);
	str = (char*)calloc(sizeof(char),( game->row* game->col)+1);
	fread(str, game->row * game->col ,1, fp);
	CreateMatrix(game,game->col,game->row,str);
	game->score = 0;
	//return game;

	
}

GAME* CreateMatrix( GAME *input, int col, int row,char* strMap)
{
	int k = 0;
	input->map = (char**)calloc(input->row, sizeof(char*));
	*input->map = (char*)calloc(input->col, sizeof(char));
	for (int i = 0; i < input->row; i++)
		for (int j = 0; j < input->col; j++)
			input->map[i][j] = strMap[k++];
	input->Ghost = (char**)malloc((input->nGhosts) * sizeof(char*));
	for (int i = 0; i < input->nGhosts; i++)
	{
		FindPositon('G',1, &input->Ghost[i], input->map, input->col, input->row);
	}

	return input;
}






void PrintMapInConsole(GAME* input,GAMER_INFO *user)
{
	printf("PLAYER:%s\nID:%s\n");
	printf("SCORE: %d \t\t\tLEVEL:%s",input->score,input->difficulty);
	int i, j, line;
	for (i = 0; i < (input->row) + 10; i++)
		printf("_");
	for (i = 0; i < input->row; i++)
	{
		for (line = 0; line < 5; line++)
		{
			printf("\t");

			for (j = 0; j < input->col; j++)
			{
				switch (input->map[i][j])
				{
				case '@':
				{

					break;
				}
				case 'P':
				{

					break;
				}
				case 'G':
				{

					break;
				}case '.':
				{
					printf(" ");
					break;
				}
				case ('|' || '-'):
				{
					printf(".");
					break;
				}
				}
			}

		}

	}
	for (int i = 0; i < (input->row) + 10; i++)
		printf("_");

}


int NumberOfObjects(char** strMap, char object, int row, int col)
{
	int Num = 0;
	for(int i=1;i<row-1;i++)
		for (int j = 0; j < col-1; j++)
			if (strMap[i][j] == object)
				Num++;
	return Num;
}