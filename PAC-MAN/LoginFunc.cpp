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
		root->left = root->right = NULL;
		root->data = {};
		fread(&root->data, sizeof(userpass), 1, fp);
		
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
		gameTmp->Ghost = (char**)malloc(sizeof(char*) * gameTmp->nGhosts);
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
	if (!root)
		return NULL;
	if (!strcmp(root->data.username, strUsername))
		return &root->data;
	if (strcmp(strUsername, root->data.username) > 0)
		Search(root->right, strUsername);
	else 
		Search(root->left, strUsername);
}

GAMER_INFO* LoginPage(BT_userpass* root)
{
	int cmd;
	userpass* pUser=NULL;
	char Username[usernamelen], Password[passwordlen];
	char strFileName[addresslen],DataType[typelen];
	first:
	printf("Enter your username\n");
	scanf("%s",Username);
	printf("Enter your password\n");
	scanf("%s", Password);
	strcpy(strFileName, "Passwords.txt");
	strcpy(DataType, "userpass");
	root=(BT_userpass*)Loud_File(strFileName, DataType);
	pUser = Search(root, Username);
	if (!strcmp(Username, pUser->username) && !strcmp(Password, pUser->password))
	{
		strcpy(DataType, "GAMER_INFO");
		strcat(Username, ".txt");
		system("cls");
		return (GAMER_INFO*)Loud_File(Username, DataType);
	}
	else
	{
		printf("WRONG password or username!\n\n 1.Try Again\n\n Don't have an account?\n2.Sign Up");
		scanf("%d", &cmd);
		if (cmd == 2)
		{
			system("cls");
			return SignUpPage(root);
			
		}
		else
		{
			system("cls");
			goto first;
		}
	}
	
}


GAMER_INFO* SignUpPage(BT_userpass* root)
{
	GAMER_INFO Tmp;
	userpass pass_Tmp;
	FILE *fp;
	char strFileName[addresslen], DataType[typelen];
	strcpy(strFileName, "Passwords.txt");
	strcpy(DataType, "userpass");
	printf("Enter Your Name\n");
	scanf("%s", Tmp.name);
	printf("Choose a username \n");
	scanf("%s", pass_Tmp.username);
	if (!root)
		root = (BT_userpass*)Loud_File(strFileName, DataType);
	while (Search(root, pass_Tmp.username))
	{
		printf("This username is already taken.Pick something else.\n ");
		scanf("%s", pass_Tmp.username);
	}
	printf("enter your password\n");
	scanf("%s", pass_Tmp.password);
	strcpy(Tmp.username, pass_Tmp.username);
	Tmp.level = 0;
	Tmp.UnfinishedGame = {};
	Tmp.Unfinish = false;
		fp=fopen(strFileName, "r+b");
		fwrite(&pass_Tmp, sizeof(userpass), 1, fp);
		fclose(fp);
		strcat(pass_Tmp.username, ".txt");
		fp=fopen(pass_Tmp.username,"wb");
		fwrite(&Tmp, sizeof(GAMER_INFO), 1, fp);
		fclose(fp);
		system("cls"); 
		printf("WELCOME TO PAC-MAN CLUB!");
		Sleep(1500);
		system("cls");
		return &Tmp;
}


bool UpdateUserData(GAMER_INFO* input) 
{
	bool BeSucc;
	char tmp[addresslen];
	FILE* fp;
	strcpy(tmp, input->username);
	strcat(tmp,".txt");
	fp = fopen(tmp, "wb");
	BeSucc=fwrite(input, sizeof(GAMER_INFO), 1, fp);
	fclose(fp);
	return BeSucc;
}