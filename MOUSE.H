
union REGS in,out;
void mouseaao()
//AAO MOUSE PYAARE MOUSE AA JAAO
{
	in.x.ax=1;
	int86(51,&in,&out);
}

void mousechhupaao()
{
	in.x.ax=2;
	int86(51,&in,&out);
}

void mousedikhaao(int a,int b)
{
	in.x.ax=4;
	in.x.cx=a;
	in.x.dx=b;
	int86(51,&in,&out);
}


void mouseinfo(int& xc,int& yc,int& bc)
{
	in.x.ax=3;
	int86(51,&in,&out);
	xc=out.x.cx;
	yc=out.x.dx;
	bc=out.x.bx;
}
void mouseroko(int x1,int y1,int x2,int y2)
{
	in.x.ax=7;
	in.x.cx=x1;
	in.x.dx=x2;
	int86(51,&in,&out);
	in.x.ax=8;
	in.x.cx=y1;
	in.x.dx=y2;
	int86(51,&in,&out);
}

