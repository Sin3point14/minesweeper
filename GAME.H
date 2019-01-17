void mine_placer(int mines[81])         //self explanatory
{
	for(int i=0;i<81;i++)
		mines[i]=0;
	randomize();
	for(i=1;i<=10;i++)
	{
		int a=random(81);
		for(;mines[a]==9;)
		{
			if(a==80)
				a=0;
			else
				a++;
		}
		mines[a]=9;
	}
	for(i=0;i<81;i++)
	{
		if(mines[i]==9)
		{
			if (((i>9)&&(i<17))||((i>18)&&(i<26))||((i>27)&&(i<35))||((i>36)&&(i<44))||((i>45)&&(i<53))||((i>54)&&(i<62))||((i>63)&&(i<71)))
			{
				int arr[]={-10,-9,-8,-1,+1,+8,+9,+10};
				for(int a=0;a<8;a++)
				{
					if(mines[i+arr[a]]!=9)
						mines[i+arr[a]]++;
				}
			}
			else if (i==0)
			{
				int arr[]={1,9,10};
				for(int a=0;a<3;a++)
				{
					if(mines[i+arr[a]]!=9)
						mines[i+arr[a]]++;
				}
			}
			else if (i==8)
			{
				int arr[]={-1,9,8};
				for(int a=0;a<3;a++)
				{
					if(mines[i+arr[a]]!=9)
						mines[i+arr[a]]++;
				}
			}
			else if (i==72)
			{
				int arr[]={1,-9,-8};
				for(int a=0;a<3;a++)
				{
					if(mines[i+arr[a]]!=9)
						mines[i+arr[a]]++;
				}
			}
			else if (i==80)
			{
				int arr[]={-1,-9,-10};
				for(int a=0;a<3;a++)
				{
					if(mines[i+arr[a]]!=9)
						mines[i+arr[a]]++;
				}

			}
			else if ((i>0)&&(i<8))
			{
				int arr[]={1,-1,9,10,8};
				for(int a=0;a<5;a++)
				{
					if(mines[i+arr[a]]!=9)
						mines[i+arr[a]]++;
				}
			}
			else if ((i>72)&&(i<80))
			{
				int arr[]={1,-1,-9,-10,-8};
				for(int a=0;a<5;a++)
				{
					if(mines[i+arr[a]]!=9)
						mines[i+arr[a]]++;
				}
			}
			else if (i%9==0)
			{
				int arr[]={1,-9,10,9,-8};
				for(int a=0;a<5;a++)
				{
					if(mines[i+arr[a]]!=9)
						mines[i+arr[a]]++;
				}
			}
			else
			{
				int arr[]={-1,-9,-10,9,8};
				for(int a=0;a<5;-a++)
				{
					if(mines[i+arr[a]]!=9)
						mines[i+arr[a]]++;
				}
			}

		}
	}
}
 int box_no(int& x, int& y)        // returns 0 indexed value of the box clicked
{
	if(getpixel(x,y)!=0)
		return((x-5)/33+((y-5)/33)*9);
	else
			return -1;
}

void mine_displayer(int mines[81],int co[81][2])        //HAX MODE
{
	for(int i=0;i<81;i++)
	{
		if(mines[i]==9)
			make_mine(co[i][0],co[i][1]);
   /*	else if(mines[i]==1)
			make_1(co[i][0],co[i][1]);
		else if(mines[i]==2)
			make_2(co[i][0],co[i][1]);
		else if(mines[i]==3)
			make_3(co[i][0],co[i][1]);
		else if(mines[i]==4)
			make_4(co[i][0],co[i][1]);
		else if(mines[i]==5)
			make_5(co[i][0],co[i][1]);
		else if(mines[i]==6)
			make_6(co[i][0],co[i][1]);   */
	}
}
void move(int a,int mines[81],int co[81][2],int flags[81])       //handles non-bomb holding box clicked except mines[boxno]=0
{
	if (flags[a]==0)
	{
		switch (mines[a])
		{
			case 0:white_box(co[a][0],co[a][1]);
				break;
			case 1:make_1(co[a][0],co[a][1]);
				break;
			case 2:make_2(co[a][0],co[a][1]);
				break;
			case 3:make_3(co[a][0],co[a][1]);
				break;
			case 4:make_4(co[a][0],co[a][1]);
				break;
			case 5:make_5(co[a][0],co[a][1]);
				break;
			case 6:make_6(co[a][0],co[a][1]);
				break;
			case 7:make_7(co[a][0],co[a][1]);
				break;
			case 8:make_8(co[a][0],co[a][1]);
				break;
		}
	}
	flags[a]=-1;
}
void mass_unlocker(int i,int mines[81],int co[81][2],int flags[81])	//special handling for mines[boxno]==0
{

	move(i,mines,co,flags);
			if (((i>9)&&(i<17))||((i>18)&&(i<26))||((i>27)&&(i<35))||((i>36)&&(i<44))||((i>45)&&(i<53))||((i>54)&&(i<62))||((i>63)&&(i<71)))
			{
				int arr[]={-10,-9,-8,-1,+1,+8,+9,+10};
				for(int a=0;a<8;a++)
				{
					if(mines[i+arr[a]]!=9 && flags[i+arr[a]]==0)
					{
						move(i+arr[a],mines,co,flags);
						if(mines[i+arr[a]]==0)
							mass_unlocker(i+arr[a],mines,co,flags);
					}

				}
			}
			else if (i==0)
			{
				int arr[]={1,9,10};
				for(int a=0;a<3;a++)
				{
					if(mines[i+arr[a]]!=9 && flags[i+arr[a]]==0)
					{
						move(i+arr[a],mines,co,flags);
						if(mines[i+arr[a]]==0)
							mass_unlocker(i+arr[a],mines,co,flags);
					}

				}
			}
			else if (i==8)
			{
				int arr[]={-1,9,8};
				for(int a=0;a<3;a++)
				{
					if(mines[i+arr[a]]!=9 && flags[i+arr[a]]==0)
					{
						move(i+arr[a],mines,co,flags);
						if(mines[i+arr[a]]==0)
							mass_unlocker(i+arr[a],mines,co,flags);
					}

				}
			}
			else if (i==72)
			{
				int arr[]={1,-9,-8};
				for(int a=0;a<3;a++)
				{
					if(mines[i+arr[a]]!=9 && flags[i+arr[a]]==0)
					{
						move(i+arr[a],mines,co,flags);
						if(mines[i+arr[a]]==0)
							mass_unlocker(i+arr[a],mines,co,flags);
					}

				}
			}
			else if (i==80)
			{
				int arr[]={-1,-9,-10};
				for(int a=0;a<3;a++)
				{
					if(mines[i+arr[a]]!=9 && flags[i+arr[a]]==0)
					{
						move(i+arr[a],mines,co,flags);
						if(mines[i+arr[a]]==0)
							mass_unlocker(i+arr[a],mines,co,flags);
					}

				}

			}
			else if ((i>0)&&(i<8))
			{
				int arr[]={1,-1,9,10,8};
				for(int a=0;a<5;a++)
				{
					if(mines[i+arr[a]]!=9 && flags[i+arr[a]]==0)
					{
						move(i+arr[a],mines,co,flags);
						if(mines[i+arr[a]]==0)
							mass_unlocker(i+arr[a],mines,co,flags);
					}

				}
			}
			else if ((i>72)&&(i<80))
			{
				int arr[]={1,-1,-9,-10,-8};
				for(int a=0;a<5;a++)
				{
					if(mines[i+arr[a]]!=9 && flags[i+arr[a]]==0)
					{
						move(i+arr[a],mines,co,flags);
						if(mines[i+arr[a]]==0)
							mass_unlocker(i+arr[a],mines,co,flags);
					}

				}
			}
			else if (i%9==0)
			{
				int arr[]={1,-9,10,9,-8};
				for(int a=0;a<5;a++)
				{
					if(mines[i+arr[a]]!=9 && flags[i+arr[a]]==0)
					{
						move(i+arr[a],mines,co,flags);
						if(mines[i+arr[a]]==0)
							mass_unlocker(i+arr[a],mines,co,flags);
					}

				}
			}
			else
			{
				int arr[]={-1,-9,-10,9,8};
				for(int a=0;a<5;-a++)
				{
					if(mines[i+arr[a]]!=9 && flags[i+arr[a]]==0)
					{
						move(i+arr[a],mines,co,flags);
						if(mines[i+arr[a]]==0)
							mass_unlocker(i+arr[a],mines,co,flags);
					}

				}
			}

}
void show_mine(int mines[81],int co[81][2],int flags[81])    //show mines at win or lose
{
	for (int i = 0; i < 81; ++i)
	{
		if (mines[i]==9)
		{
			switch (flags[i])
			{
			case -1:
				black_box(co[i][0],co[i][1]);
				make_mine(co[i][0],co[i][1]);
				break;
			case 0:
				make_mine(co[i][0],co[i][1]);
				break;
			case 1:
				gray_box(co[i][0],co[i][1]);
				make_wmine(co[i][0],co[i][1]);
				make_cross(co[i][0],co[i][1]);
				break;
			default:
				gray_box(co[i][0],co[i][1]);
				make_wmine(co[i][0],co[i][1]);
			}
		}
	}
}
void lclick(int x,int y,int& l,int mines[81],int co[81][2],int flags[81])	//self explanatory
{

	int bno=box_no(x,y);
	if (flags[bno]==0)
		{
			switch (mines[bno])
			{
			case 9: flags[bno]=-1;
				show_mine(mines,co,flags);
				l=1;
				white_box(393,145);
				white_box(426,145);
				break;
			case 1:
			case 2:
			case 3:
			case 7:
			case 8:
			case 4:
			case 5:
			case 6: move(bno,mines,co,flags);
				break;
			case 0: mass_unlocker(bno,mines,co,flags);
		}

	}
}
void rclick(int x,int y,int co[81][2],int flags[81],int f)       //self explanatory
{
	int bno=box_no(x,y);

	switch (flags[bno])
	{
		case 0: if (f!=10)
			{
			make_flag(co[bno][0],co[bno][1]);
			flags[bno]=1;
			}
			break;
		case 1: make_question(co[bno][0],co[bno][1]);
			flags[bno]=2;
			break;
		case 2: gray_box(co[bno][0],co[bno][1]);
			flags[bno]=0;
			break;
		case -1:;
	}
}
void win_check(int& l,int flags[81],int mines[81],int& b)	//+flag counter on the right
{
	int a=0;
	b=0;
	for(int i=0;i<81;i++)
	{
		if (flags[i]!=-1)
			a++;
		if (flags[i]==1)
			b++;
	}
	switch (b)
	{
		case 1:gray_box(393,145);
			gray_box(426,145);
			make_0(393,145,0);
			make_9(426,145,0);
			break;
		case 2:gray_box(393,145);
			gray_box(426,145);
			make_0(393,145,0);
			make_8(426,145,0);
			break;
		case 3:gray_box(393,145);
			gray_box(426,145);
			make_0(393,145,0);
			make_7(426,145,0);
			break;
		case 4:gray_box(393,145);
			gray_box(426,145);
			make_0(393,145,0);
			make_6(426,145,0);
			break;
		case 5:gray_box(393,145);
			gray_box(426,145);
			make_0(393,145,0);
			make_5(426,145,0);
			break;
		case 6:gray_box(393,145);
			gray_box(426,145);
			make_0(393,145,0);
			make_4(426,145,0);
			break;
		case 7:gray_box(393,145);
			gray_box(426,145);
			make_0(393,145,0);
			make_3(426,145,0);
			break;
		case 8:gray_box(393,145);
			gray_box(426,145);
			make_0(393,145,0);
			make_2(426,145,0);
			break;
		case 9:gray_box(393,145);
			gray_box(426,145);
			make_0(393,145,0);
			make_1(426,145,0);
			break;
		case 10:gray_box(393,145);
			gray_box(426,145);
			make_0(393,145,0);
			make_0(426,145,0);
			break;
		case 0: gray_box(393,145);
			gray_box(426,145);
			make_1(393,145,0);
			make_0(426,145,0);
			break;
	}
	if(a==10)
	{
		l=2;
		white_box(393,145);
		white_box(426,145);
		for (int i = 0; i < 81; ++i)
		{
			if(mines[i]==9)
			{
				if(flags[i]==0)
					flags[i]=-2;
			}
		}
	}
}
