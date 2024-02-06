#include "game.h"

void* Loud_File(char* strFileName, char* strDataType)
{
	FILE* fp;
	BT_userpass* root = NULL;
	userpass userTmp;
	GAMER_INFO *gamerTmp;
	GAME* gameTmp;
	fp = fopen(strFileName, "rb");
	if(!fp)
		fp = fopen(strFileName, "w+b");
	if (!strcmp(strDataType, "userpass"))
	{
		root = new BT_userpass;
		fread(&root->data, sizeof(userpass), 1, fp);
		root->left = root->right = NULL;
		while (fread(&userTmp,sizeof(userpass),1,fp)>0)
			Insert(root, userTmp);
		fclose(fp);
		return root;
	}
	else if (!strcmp(strDataType, "GAMER_INFO"))
	{
		gamerTmp = new GAMER_INFO;
		fread(gamerTmp, sizeof(GAMER_INFO), 1, fp);
		fclose(fp);
		return gamerTmp;
	}
	else if (!strcmp(strDataType, "GAME"))
	{
		char alaki;
		gameTmp = new GAME;
		fseek(fp, 0, SEEK_SET);
		fscanf(fp, "%d %d\n", &gameTmp->row, &gameTmp->col);
		gameTmp->map = (char**)malloc(sizeof(char*) * gameTmp->row);

		for (int i = 0; i < gameTmp->row; i++)
			gameTmp->map[i] = (char*)malloc(sizeof(char) * gameTmp->col);
		for (int i = 0; i < gameTmp->row; i++)
		{
			for (int j = 0; j < gameTmp->col; j++)
				fscanf(fp, "%c", &gameTmp->map[i][j]);
			fscanf(fp, "\n",&alaki);
		}
		fclose(fp);
		gameTmp->score = 0;
		gameTmp->nPills = NumberOfObjects(gameTmp->map, 'P', gameTmp->row, gameTmp->col);
		gameTmp->nGhosts = NumberOfObjects(gameTmp->map, 'G', gameTmp->row, gameTmp->col);
		return gameTmp;
	}

}

BT_userpass* Insert(BT_userpass* root, userpass data)
{
	if (!root)
	return	NewUserPass(data);
	if (strcmp(data.username, root->data.username) > 0)
		root->right = Insert(root->right, data);
	else
		root->left = Insert(root->left, data);

	return root;

}
BT_userpass* NewUserPass( userpass data)
{
	BT_userpass* Tmp;
	Tmp = new BT_userpass;
	Tmp->data = data;
	Tmp->left = Tmp->right = NULL;
	return Tmp;
}

userpass *Search(BT_userpass* root, char* strUsername)
{
	if (!strcmp(root->data.username, strUsername))
		return &root->data;
	if (strcmp(strUsername, root->data.username) > 0)
		Search(root->right, strUsername);
	else 
		Search(root->left, strUsername);
}

GAMER_INFO* LoginPage(BT_userpass* root)
{
	userpass* pUser=NULL;
	char Username[usernamelen], Password[passwordlen];
	char strFileName[addresslen],DataType[typelen];

	strcpy(strFileName, "Passwords.bin");
	strcpy(DataType, "userpass");
	root=(BT_userpass*)Loud_File(strFileName, DataType);
	pUser = Search(root, Username);
	if (!strcmp(Username, pUser->username) && !strcmp(Password, pUser->password))
	{
		strcpy(DataType, "GAMER_INFO");
		strcat(Username, ".txt");
		return (GAMER_INFO*)Loud_File(Username, DataType);
	}
	else
	{
		printf("WRONG password or username!\n\n Don't have account?\nSign Up");
	}
	
}


GAMER_INFO* SignUpPage(BT_userpass* root)
{
	GAMER_INFO Tmp;
	userpass pass_Tmp;
	FILE *fp;
	char strFileName[addresslen], DataType[typelen];
	strcpy(strFileName, "Passwords.bin");
	strcpy(DataType, "userpass");
	if (!root)
		root = (BT_userpass*)Loud_File(strFileName, DataType);
	if (Search(root, pass_Tmp.username))
		/// username already taken.
		;
	else
	{
		fp=fopen("password.bin", "a+b");
		fwrite(&pass_Tmp, sizeof(userpass), 1, fp);
		fclose(fp);
		strcat(pass_Tmp.username, ".txt");
		fp=fopen(pass_Tmp.username,"wb");
		fwrite(&Tmp, sizeof(GAMER_INFO), 1, fp);
		fclose(fp);
		return &Tmp;
	}
}
