//Function are made self-explanantory by their names

void white_box(int i,int j)
{	
	setfillstyle(1,15);
	setcolor(7);
	int box[10]={i,j,i+30,j,i+30,j+30,i,j+30,i,j};
	fillpoly(4,box);
}
void gray_box(int i,int j)
{	
	setfillstyle(1,7);
	setcolor(7);
	int box[10]={i,j,i+30,j,i+30,j+30,i,j+30,i,j};
	fillpoly(4,box);
}
void black_box(int i,int j)
{
	setfillstyle(1,0);
	setcolor(7);
	int box[10]={i,j,i+30,j,i+30,j+30,i,j+30,i,j};
	fillpoly(4,box);
}
void make_mine(int x,int y)
{
	setcolor(4);
	line(x+15,y+25,x+15,y+5);
	line(x+25,y+15,x+5,y+15);
	line(x+8,y+8,x+22,y+22);
	line(x+22,y+8,x+8,y+22);
	setfillstyle(1,4);
	fillellipse(x+15,y+15,6,6);
}
void make_1(int x,int y,int c=9)
{
	white_box(x,y);
	setcolor(c);
	line(x+15,y+5,x+15,y+25);
}
void make_2(int x,int y,int c=4)
{
	white_box(x,y);
	setcolor(c);
	line(x+10,y+5,x+20,y+5);
	line(x+20,y+5,x+20,y+15);
	line(x+20,y+15,x+10,y+15);
	line(x+10,y+15,x+10,y+25);
	line(x+10,y+25,x+20,y+25);
}
void make_3(int x,int y,int c=2)
{
	white_box(x,y);
	setcolor(c);
	line(x+10,y+5,x+20,y+5);
	line(x+20,y+5,x+20,y+25);
	line(x+20,y+25,x+10,y+25);
	line(x+10,y+15,x+20,y+15);
}
void make_4(int x,int y,int c=1)
{
	white_box(x,y);
	setcolor(c);
	line(x+10,y+5,x+10,y+15);
	line(x+10,y+15,x+20,y+15);
	line(x+20,y+5,x+20,y+25);
}
void make_5(int x,int y,int c=6)
{
	white_box(x,y);
	setcolor(c);
	line(x+20,y+5,x+10,y+5);
	line(x+10,y+5,x+10,y+15);
	line(x+10,y+15,x+20,y+15);
	line(x+20,y+15,x+20,y+25);
	line(x+20,y+25,x+10,y+25);
}
void make_6(int x,int y,int c=0)
{
	white_box(x,y);
	setcolor(c);
	line(x+20,y+5,x+10,y+5);
	line(x+10,y+5,x+10,y+25);
	line(x+10,y+25,x+20,y+25);
	line(x+20,y+25,x+20,y+15);
	line(x+20,y+15,x+10,y+15);
}
void make_7(int x,int y,int c=0)
{
	white_box(x,y);
	setcolor(c);
	line(x+10,y+5,x+20,y+5);
	line(x+20,y+5,x+15,y+25);
}
void make_8(int x,int y,int c=0)
{
	white_box(x,y);
	setcolor(c);
	line(x+10,y+5,x+10,y+25);
	line(x+10,y+25,x+20,y+25);
	line(x+20,y+25,x+20,y+5);
	line(x+20,y+5,x+10,y+5);
	line(x+10,y+15,x+20,y+15);
}
void make_9(int x,int y,int c=0)
{
	white_box(x,y);
	setcolor(c);
	line(x+10,y+5,x+10,y+15);
	line(x+10,y+25,x+20,y+25);
	line(x+20,y+25,x+20,y+5);
	line(x+20,y+5,x+10,y+5);
	line(x+10,y+15,x+20,y+15);
}
void make_0(int x,int y,int c=0)
{
	white_box(x,y);
	setcolor(c);
	line(x+10,y+5,x+10,y+25);
	line(x+10,y+25,x+20,y+25);
	line(x+20,y+25,x+20,y+5);
	line(x+20,y+5,x+10,y+5);
}
void make_wmine(int x,int y)
{
	setcolor(15);
	line(x+15,y+25,x+15,y+5);
	line(x+25,y+15,x+5,y+15);
	line(x+8,y+8,x+22,y+22);
	line(x+22,y+8,x+8,y+22);
	setfillstyle(1,15);
	fillellipse(x+15,y+15,6,6);
}
void make_cross(int x, int y)
{
	setcolor(4);
	line(x+2,y+2,x+28,y+28);
	line(x+2,y+28,x+28,y+2);
}
void make_flag(int x, int y)
{
	gray_box(x,y);
	setcolor(15);
	setfillstyle(1,15);
	line(x+15,y+15,x+15,y+25);
	setfillstyle(1,4);
	setcolor(4);
	int t[8]={x+15,y+5,x+5,y+15,x+15,y+15};
	fillpoly(3,t);
}
void make_question(int x,int y)
{
	gray_box(x,y);
	setfillstyle(1,15);
	setcolor(15);
	line(x+10,y+10,x+10,y+5);
	line(x+10,y+5,x+20,y+5);
	line(x+20,y+5,x+20,y+15);
	line(x+20,y+15,x+15,y+15);
	line(x+15,y+15,x+15,y+23);
	pieslice(x+15,y+25,0,360,1);
}

void make_board(int test[81][2])
{
	int x=0;
	for(int j=5;j<=297;j+=33)
	{
		for(int i=5;i<=297;i+=33,x++)
		{
			test[x][0]=i;
			test[x][1]=j;
			gray_box(i,j);
		}
	}
	gray_box(360,145);
	gray_box(393,145);
	gray_box(426,145);
	make_mine(360,145);
	make_1(393,145,0);
	make_0(426,145,0);
}

