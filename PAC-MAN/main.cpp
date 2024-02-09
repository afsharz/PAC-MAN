#include "game.h"

int main()
{
	int cmd;
	GAME game;
	GAMER_INFO *gamer;
	BT_userpass *userpass=NULL;
	cmd=HomePage();
	switch (cmd)
	{
	case 1:
	{
		gamer = LoginPage(userpass);
		UserMenu(gamer);

		break;
	}
	case 2:
	{
		gamer = SignUpPage(userpass);
		UserMenu(gamer);
		break;
	}
	}
	
	return 0;
}


