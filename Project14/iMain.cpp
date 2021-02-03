
#include "iGraphics.h"


int gamestate=0;

int playerX=470,playerY=0,flag;
float x=400,y=601;
float a=600,b=601;
float c=550,d=601;
int score =0;
char score1[5];
int play=0;

void collision()
{
	if ( ((playerX+44 >= x && playerX <= x+44) && (playerY+88 >= y && playerY <= y+80)) || ((playerX+44 >= a && playerX <= a+44) && (playerY+88 >= b && playerY <= b+80)) || ((playerX+44 >= c && playerX <= c+46) && (playerY+88 >= d && playerY <= d+80)) ){

		printf("over\n");
	gamestate=2;
	}
}

void scoreshow()
{

	_itoa_s(score, score1, 10);

}
void villain1(){
	y=y-0.5;
	if (y<=0)
	{
		y=600;
		x=310+rand()%350;
		score++;
	}collision();
}
void villain2(){
	b=b-0.3;
	if(b<=0){
		b=600;
		a=rand()%300+360;
		score++;
	}collision();
}
void villain3(){
	d=d-0.4;
	if(d<=0){
		d=600;
		c=rand()%300+360;
		score++;
	}collision();
}



void iDraw()
{
	if(gamestate==0){
		iShowBMP(0,0,"main.bmp");
		iSetColor(0,0,0);
		iText(5, 80,"Press F1 or P for Play ",GLUT_BITMAP_HELVETICA_18);
		iText(5, 50,"Press F2 or I for Instructions ",GLUT_BITMAP_HELVETICA_18);
		if(play==1){
			iShowBMP(0,0, "instruction.bmp");
		}
	}
		
	if(gamestate==1)
	{
	iClear();
	iSetColor(0,208,0);
	iFilledRectangle(0,0,1000,600);
	iSetColor(72,72,72);
	iFilledRectangle(300,0,400,600);
	iSetColor(255,255,255);
	iFilledRectangle(300,0,10,600);
	iFilledRectangle(690,0,10,600);
	iSetColor(0,0,0);
	iText(7,580,"SCORE : ",GLUT_BITMAP_HELVETICA_18);
	iText(90, 580, score1, GLUT_BITMAP_HELVETICA_18);
	iShowBMP2(x,y,"vil2.bmp",0);
	iShowBMP2(a,b,"vil1.bmp",0);
	iShowBMP2(c,d,"vil3.bmp",0);
	iShowBMP2(playerX,playerY,"hero.bmp",0);
		villain1();
		villain2();
		villain3();
	}
	if(gamestate==2){
		iShowBMP(0,0,"gameover.bmp");
		iSetColor(255,255,0);
		iText(450, 300,"SCORE : ",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(550, 300, score1, GLUT_BITMAP_TIMES_ROMAN_24);
	}

}

void iMouseMove(int mx, int my)
{

}


void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
		printf("x axis %d y axis %d \n",mx,my);
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
}

void iKeyboard(unsigned char key)
{
	
	if(key == 'q')
	{
		exit(0);
	}
	if(key== 'a')
	{
	playerX=playerX-25;
	if(playerX < 310)
	{
	
	playerX=310;}
	
	collision();
	}
	
		if(key== 'd'){
	playerX=playerX+25;
	if(playerX > 646){
	
	playerX=646;}

	collision();
	}
			if(key== 's'){
	playerY=playerY-25;
	if(playerY < 0){
	
	playerY=0;}

	collision();
	}
				if(key== 'w')
				{
	playerY=playerY+25;
	if(playerY > 512){
	
	playerY=512;}
	collision();
				}
				if(key=='p')
					gamestate=1;
				if(key== 'i')
					play=1;
				
	
}

void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	if(key== GLUT_KEY_LEFT){
	playerX=playerX-10;
	if(playerX < 310){
	
	playerX=310;}
	collision();
	}
	
		if(key== GLUT_KEY_RIGHT){
	playerX=playerX+10;
	if(playerX > 646){
	
	playerX=646;}
	collision();
		}
		if(key== GLUT_KEY_DOWN){
	playerY=playerY-10;
	if(playerY < 0){
	
	playerY=0;}
	collision();
	}
				if(key== GLUT_KEY_UP){
	playerY=playerY+10;
	if(playerY > 512){
	
	playerY=512;}
	collision();
}
				if(key==GLUT_KEY_F1)
					gamestate=1;
				if(key== GLUT_KEY_F2)
					play=1;
}

int main()
{
	iSetTimer(300,scoreshow);
	iInitialize(1000, 600, "CAR RACING");
	return 0;
}	