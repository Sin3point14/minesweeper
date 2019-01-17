/* Program to allow the user to play a game of minesweeper*/
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>
#include"MOUSE.H"
#include"GS.H"
#include"GAME.H"
#include"CLASSH.H"


void main(){
	clrscr();
	player p;     //stores player data, definition in classh.h
	int gd=DETECT,gm;
	clock_t t,ts;       // to calc play time
	int tf=0;
	initgraph(&gd,&gm,"c:\\tc\\bgi");       //graphics initialisation
	int co[81][2];       //stores cords of each box
	make_board(co);      //definition in GS.H
	int mines[81];       //stores no. of bombs or 9 if bomb is present
	int flags[81];       //gray box(0)/flagged(1)/question marked(2)/white box(-1)

	for(int i=0;i<81;i++)
		flags[i]=0;
	mine_placer(mines);       //definition in GAME.H
	mine_displayer(mines,co);      //HAX MODE
	mouseaao();       //definition in mouse.h
	mouseroko(5,5,297,297);       //definition in mouse.h
	int x,y,l=0,f;          // variables to store click cords, win/lose/continue, exception handling
	int c=0;
	do{
		while(!c)
		{
				mouseinfo(x,y,c);   //definition in mouse.h
			if(tf==0)
			{
				ts=clock();
				tf++;
			}
		}
		mousechhupaao();       //definition in mouse.h
		switch (c)
		{
			case 1: lclick(x,y,l,mines,co,flags);
				break;
			case 2: rclick(x,y,co,flags,f);
		}
		mouseaao();
		mousedikhaao(x,y);       //definition in mouse.h
		if(l!=1)
		win_check(l,flags,mines,f);        //definition in game.h
		c=0;
		delay(200);        //to prevent loss of pixels
	}while(l==0);
	mousechhupaao();
	gotoxy(1,23);
	t=clock();
	if(l==2)          //player won
	{
		show_mine(mines,co,flags);
	       //	cin>>p.time;
		cout<<"you win!"<<endl<<"time taken- "<<(t-ts)/CLK_TCK<<"s";
		p.gtime((t-ts)/CLK_TCK);      //CLK_TCK- Macro that stores ticks/second
		high(p);      //definition in classh.h
		getch();
	}
	else
	{
		cout<<"you lose....";
		getch();
	}
	high_disp();      //definition in classh.h
	getch();

 }