#include "iGraphics.h"
#include <string.h>

int ship_x = 660, ship_y = 10, j, jac = 0, lyf_lost = 0, pl = 0, lyf_lin = 225;
int fire_x, fire_y, i = 0, score = 0;
bool shoots=false, egn = false, evil_won = false, pl_won = false;
bool menu = true, start = false, instruction = false, high_score = false, end_game = false, back2main = false,game_on=false;
int evil_x = 572, evil_y = 464, dx = 2, dy = 4;
int k = 6, evil_dir, wait = 1;
char sc_board[8];

int mid = evil_x + 128 - 16, evil_dead = 0, evil_lin = 500;
int fire_x1 = mid - 44;
int fire_y1 = evil_y;
int fire_x2 = mid + 44;
int fire_y2 = evil_y;

void newgame()
{
	ship_x = 660;
	ship_y = 10;
	evil_x = 572;
	evil_y = 464;
	lyf_lin = 225;
	lyf_lost = 0;
	evil_dead = 0;
	evil_lin = 500;
	score = 0;
}
void main_menu()
{
	iClear();
	iSetColor(0, 200, 50);
	iText(200, 5, "Designed by Md. Shariar Kabir. Inspired from the game Zaxxon(1982). Please support the official release.");
	iSetColor(200, 0, 0);
	iRectangle(550, 100, 300, 525);
	iSetColor(0, 0, 200);
	iRectangle(600, 125, 200, 75);
	iRectangle(600, 225, 200, 75);
	iRectangle(600, 325, 200, 75);
	iRectangle(600, 425, 200, 75);
	iRectangle(600, 525, 200, 75);
	iSetColor(0, 200, 0);
	iText(675, 560, "START");
	iText(665, 460, "NEW GAME");
	iText(655, 360, "INSTRUCTION");
	iText(655, 260, "HIGH SCORES");
	iText(665, 160, "END GAME");

}
void instructions()
{
	iClear();
	iSetColor(200, 0, 200);
	iRectangle(450, 100, 500, 500);
	iSetColor(200, 200, 0);
	iText(555, 575, "Aliens wants to take over our planet.");
	iText(555, 550, "Your mission is to shoot down the alien");
	iText(555, 530, "spaceship.");
	iText(555, 510, "And prevent it from reaching earth");
	iText(555, 490, "Use the mouse to shoot.");
	iText(555, 470, "And the direction keys to move the ship.");
	iText(555, 450, "Save the humanity from it's extinction");
	iText(555, 420, "Alien ship is stronger than ours.So");
	iText(555, 400, "avoid any collision.");
	iText(555, 380, "But Alien ship is heavy.So use your speed");
	iText(555, 360, "to outsmart the enemy");
	iText(555, 330, "Good luck soldier.");
}
//void highscore
void backtomain()
{
	iSetColor(200, 0, 0);
	iRectangle(650, 25, 100, 50);
	iSetColor(0, 200, 0);
	iText(663, 48, "MAIN MENU");
}
void shoot()
{
	if (game_on)
	{
		if (fire_y > 720)
		{
			fire_y = ship_y + 64;
			shoots = false;
		}
		fire_y += 10;
	}
}
void random()
{
	if (game_on)
	{
		int j = rand() % 1000;
		k = j % 8;
		wait++;
	}
}
void evil_move()
{
	if (game_on)
	{
		if (evil_x < 0)
		{
			evil_dir = 1;
		}
		else if (evil_x>1144)
		{
			evil_dir = 2;
		}
		else if (k == 6)
		{
			evil_dir = 1;
		}
		else if (k == 7)
		{
			evil_dir = 2;
		}
		if (evil_dir == 1)
		{
			evil_x += dx;
		}
		if (evil_dir == 2)
		{
			evil_x -= dx;
		}
		if (wait == 2)
		{
			evil_y -= dy;
			wait = 0;
		}
	}
}
void evil_shoot()
{
	if (game_on)
	{
		if (jac == 0)
		{
			PlaySound("music\\ufo_shoot", NULL, SND_ASYNC);
			jac = 1;
		}
		if (fire_y1 < 0 && fire_y2 < 0)
		{
			mid = evil_x + 128 - 16;
			fire_x1 = mid - 44;
			fire_y1 = evil_y;
			fire_x2 = mid + 44;
			fire_y2 = evil_y;
			PlaySound("music\\ufo_shoot", NULL, SND_ASYNC);
		}
		fire_y1 -= 3;
		fire_y2 -= 3;
		iShowBMP2(fire_x1, fire_y1, "image\\evil_fire.bmp", 0);
		iShowBMP2(fire_x2, fire_y2, "image\\evil_fire.bmp", 0);
	}
}
void ship()
{
	iSetColor(200, 200, 200);
	iText(80 - 55, 40 + 1, "Player");
	iSetColor(200, 200, 200);
	iRectangle(80 - 1, 40 - 1, 225 + 2, 10 + 1);
	iSetColor(200, 0, 0);
	iFilledRectangle(80, 40, lyf_lin, 10);
	if (shoots == true)
	{
		shoot();
		iShowBMP2(fire_x, fire_y, "image\\fire.bmp", 200);

	}
	iShowBMP2(ship_x, ship_y, "image\\battleship.bmp", 0);
	if (egn == true)
	{
		iShowBMP2(ship_x + 1, ship_y - 50, "image\\egnition.bmp", 200);
		//PlaySound("music\\engine", NULL, SND_ASYNC);
		egn = false;
	}
	if (evil_y <= 0)
	{
		lyf_lost = 3;
		PlaySound("music\\explosion", NULL, SND_ASYNC);
	}
	if ((ship_x + 64 > evil_x + 16 && ship_x < evil_x + 256 - 16) && (ship_y + 64 > evil_y + 40 && ship_y < evil_y + 256 - 40))
	{
		lyf_lost = 3;
		PlaySound("music\\explosion", NULL, SND_ASYNC);
	}

	if ((fire_x1 + 11 >= ship_x && fire_x1 + 32 - 11 < ship_x + 64) && (fire_y1 <= ship_y + 55 && fire_y1 > ship_y))
	{
		PlaySound("music\\explosion", NULL, SND_ASYNC);
		Sleep(20);
		iShowBMP2(ship_x, ship_y, "image\\explosion.bmp", 0);
		lyf_lost++;
		lyf_lin -= 75;
		fire_y1 = -1;
	}
	if ((fire_x2 + 11 > ship_x && fire_x2 + 32 - 11 < ship_x + 64) && (fire_y2 <= ship_y + 55 && fire_y2 > ship_y))
	{
		PlaySound("music\\explosion", NULL, SND_ASYNC);
		Sleep(20);
		iShowBMP2(ship_x, ship_y, "image\\explosion.bmp", 0);
		lyf_lost++;
		lyf_lin -= 75;
		fire_y2 = -1;
	}

	if (lyf_lost == 3)evil_won = true;
}
void evil_ship()
{
	iSetColor(200, 200, 200);
	iText(80 - 55, 720 - 40 + 1, "Boss");
	iSetColor(200, 200, 200);
	iRectangle(80 - 1, 720 - 40 - 1, 500 + 2, 10 + 1);
	iSetColor(200, 0, 200);
	iFilledRectangle(80, 720 - 40, evil_lin, 10);
	iShowBMP2(evil_x, evil_y, "image\\boss_1.bmp", 0);
	evil_shoot();

	if ((fire_x + 8 > evil_x+90 && fire_x + 8 < evil_x + 256-90) && (fire_y >= evil_y + 50 && fire_y < evil_y + 256 - 10))
	{
		PlaySound("music\\hit", NULL, SND_ASYNC);
		evil_dead+=2;
		score += 10;
		evil_lin -= 10;
		fire_y = 721;
	}
	if (((fire_x + 8 > evil_x && fire_x + 8 <= evil_x + 90) || (fire_x + 8 >= evil_x + 256 - 90 && fire_x + 8 < evil_x + 256)) && (fire_y >= evil_y + 50 && fire_y < evil_y + 256 - 10))
	{
		PlaySound("music\\hit", NULL, SND_ASYNC);
		evil_dead++;
		score+=5;
		evil_lin -= 5;
		fire_y = 721;
	}

	if (evil_dead >= 100)pl_won = true;
		
}
void result()
{
	if (pl_won)
	{
		iClear();
		FILE *fp;
		fp = fopen("data.txt", "w");
		fclose(fp);
		iShowBMP(0, 0, "image\\win.bmp");
		PlaySound("music\\win", NULL, SND_ASYNC);
		if (pl == 1)
		{
			Sleep(10000);
			exit(0);
		}
		pl++;
	}
	if (evil_won)
	{
		iClear();
		FILE *fp;
		fp = fopen("data.txt", "w");
		fclose(fp);
		iShowBMP(0, 0, "image\\game_over.bmp");
		PlaySound("music\\fail", NULL, SND_ASYNC);
		if (pl == 1)
		{
			Sleep(4000);
			exit(0);
		}
		pl++;
	}
}
void scores()
{
	sprintf(sc_board, "%d", score);
	iText(1300, 680, sc_board);
}
/*
function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here
	
	iClear();
	if (menu)main_menu();
	if (game_on)
	{
		iClear();
		scores();
		ship();
		evil_ship();
		if (evil_won || pl_won)result();
	}
	if (instruction)instructions();
	//if (high_score)
	if(back2main)backtomain();

}


/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//printf("x = %d, y= %d\n",mx,my);
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		//printf("x = %d, y= %d\n",mx,my);
		if (!shoots&&game_on)
		{
			fire_x = ship_x + 32 - 8;
			fire_y = ship_y + 64;
			shoots = true;
			PlaySound("music\\shoot", NULL, SND_ASYNC);
		}
		if ((mx >= 600 && mx <= 800) && (my >= 525 && my <= 600) && menu)
		{
			game_on = true;
			start = true;
			back2main = false;
			instruction = false;
			menu = false;
			FILE *fp;
			fp = fopen("data.txt", "r");
			fscanf(fp, "%d%d%d%d%d%d%d", &ship_x, &ship_y, &evil_x, &evil_y, &fire_x1, &fire_x2, &score);
			//fscanf(fp, "%d%d%d%d", &lyf_lost, &lyf_lin, &evil_dead, &evil_lin);
			fclose(fp);
		}
		else if ((mx >= 600 && mx <= 800) && (my >= 425 && my <= 500) && menu)
		{
			game_on = true;
			newgame();
			start = true;
			back2main = false;
			instruction = false;
			menu = false;
		}
		else if ((mx >= 600 && mx <= 800) && (my >= 325 && my <= 400) && menu)
		{
			game_on = 0;
			instruction = true;
			back2main = true;
			menu = false;
		}
		else if ((mx >= 600 && mx <= 800) && (my >= 225 && my <= 300) && menu)
		{
			game_on = 0;
			high_score = true;
			back2main = true;
			menu = false;
		}
		else if ((mx >= 600 && mx <= 800) && (my >= 125 && my <= 200) && menu)
		{
			exit(0);
		}
		else if ((mx >= 650 && mx <= 750) && (my >= 25 && my <= 75) && back2main)
		{
			instruction = false;
			back2main = false;
			menu = true;
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == 'p')
	{
		FILE *fp;
		fp = fopen("data.txt", "w");
		mid = evil_x + 128 - 16;
		fprintf(fp, "%d %d %d %d %d %d %d", ship_x, ship_y, evil_x, evil_y, fire_x1, fire_x2, score);
		//fprintf(fp, "%d %d %d %d", lyf_lost, lyf_lin, evil_dead, evil_lin);
		fclose(fp);
		game_on = false;
		menu = true;
	}
	//place your codes for other keys here
}


void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_UP)
	{
		if (ship_y<650)ship_y += 10;
		egn = true;

	}
	if (key == GLUT_KEY_DOWN)
	{
		if (ship_y>0)ship_y -= 10;
		egn = true;
	}
	if (key == GLUT_KEY_RIGHT)
	{
		if (ship_x<1330)ship_x += 10;
		egn = true;
	}
	if (key == GLUT_KEY_LEFT)
	{
		if (ship_x>0)ship_x -= 10;
		egn = true;
	}
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
}


int main()
{
	//place your own initialization codes here. 
	iSetTimer(1000, random);

	iSetTimer(10, evil_move);
	iSetTimer(100, evil_shoot);
	iSetTimer(100, shoot);


	iInitialize(1400, 700, "Zaxxon");

	return 0;
}