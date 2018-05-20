# include "iGraphics.h"

int evil_x = 572, evil_y = 464, dx = 2, dy = 4;// , mid = evil_x + 128 - 16;;
int k = 6, evil_dir, wait = 1 ;// fire_x1, fire_y1, fire_x2, fire_y2;

int mid = evil_x + 128 - 16;
int fire_x1 = mid - 44;
int fire_y1 = evil_y;
int fire_x2 = mid + 44;
int fire_y2 = evil_y;
bool shoots;
/*
function iDraw() is called again and again by the system.

*/
void random()
{
	int j = rand() % 1000;
	k = j % 8;
	wait++;
}
void evil_move()
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
	if (wait==2)
	{
		evil_y -= dy;
		wait = 0;
	}
	
}
void evil_shoot()
{

	if (fire_y1 < 0)
	{
	mid = evil_x + 128 - 16;
	fire_x1 = mid - 44;
	fire_y1 = evil_y;
	fire_x2 = mid + 44;
	fire_y2 = evil_y;
	}

	fire_y1 -= 5;
	fire_y2 -= 5;
	
}
/*void position()
{
	if (shoots == false)
	{
		shoots = true;
		mid = evil_x + 128 - 16;
		fire_x1 = mid - 44;
		fire_y1 = evil_y;
		fire_x2 = mid + 44;
		fire_y2 = evil_y;
	}
}*/

void iDraw()
{
	//place your drawing codes here
	iClear();
	iShowBMP2(evil_x, evil_y, "image\\boss_1.bmp",0);
	iShowBMP2(fire_x1, fire_y1, "image\\evil_fire.bmp", 0);
	iShowBMP2(fire_x2, fire_y2, "image\\evil_fire.bmp", 0);

}

/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
		//printf("x = %d, y= %d\n",mx,my);


	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
		//place your codes here	


	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		exit(0);
	}
	//place your codes for other keys here
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}


int main()
{
	//place your own initialization codes here.
	iSetTimer(1000, random);
	iSetTimer(10, evil_move);
	iSetTimer(10, evil_shoot);
	iInitialize(1400, 720, "demooo");
	return 0;
}