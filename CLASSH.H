class player{

	char pname[20];     //player name
	double time;      //player play time
	public:
	void gtime(double tt)
	{
		time=tt;
	}
	double rettime()
	{
		return time;
	}
	void dispname()
	{
		cout<<pname;
	}
	void ename()
	{
		gets(pname);
	}
};
void high(player curr_p)
{
	fstream f("high.dat",ios::binary|ios::in);     //highscore database
	int x;
	if(!f)
	{
		f.close();
		f.open("high.dat",ios::binary|ios::out);
	//	cout<<"if";
		cout<<"\n High score! Enter your name-"<<endl;
		curr_p.ename();
		f.write((char*)&curr_p,sizeof(curr_p));
		f.close();
	}
	else
	{
	//	cout<<"else";
		player test;
		int flag=-1,count=0;
		while(f.read((char*)&test,sizeof(test))&&count<=10)
		{
			count++;
			if(curr_p.rettime()<=test.rettime()&&flag==-1)
			{
				flag=(f.tellg())/sizeof(test)-1;
			      //	cout<<f.tellg()/sizeof(test);
			}
		}
		f.close();
		f.open("high.dat",ios::binary|ios::in|ios::out);
		if(count<10&&flag==-1)
			flag=count;
	  //	cout<<"\n flag"<<flag<<"\n";
		if(flag!=-1)
		{
			cout<<"\n High score! Enter your name-"<<endl;
			curr_p.ename();
			for(int i=(count-1);i>=flag;i--)
			{
				if(i<10)
				{
					f.seekp((i)*sizeof(test),ios::beg);
					x=f.tellg()/sizeof(test);
					f.read((char*)&test,sizeof(test));
					x=f.tellg()/sizeof(test);
					f.write((char*)&test,sizeof(test));
					x=f.tellg()/sizeof(test);
				}
			}
			f.seekp(flag*sizeof(test),ios::beg);
			x=f.tellg()/sizeof(test);
			f.write((char*)&curr_p,sizeof(curr_p));
			x=f.tellg()/sizeof(test);
		}
		f.close();
	}
}
void high_disp()       //dispace highscores
{
	cleardevice();
	fstream f;
	player t;
	f.open("high.dat",ios::binary|ios::in);
/*	f.read((char*)&t,sizeof(t));
	cout<<t.name;
	cout<<"\t"<<t.time;     */
	gotoxy(4,1);
	cout<<"Name";
	gotoxy(24,1);
	cout<<"Time";
	while(f.read((char*)&t,sizeof(t)))
	{
		gotoxy(1,f.tellg()/sizeof(t)+2);//........
		cout<<f.tellg()/sizeof(t)<<". ";
		gotoxy(4,f.tellg()/sizeof(t)+2);
		t.dispname();
		gotoxy(24,f.tellg()/sizeof(t)+2);
		cout<<t.rettime();
	}
	for(int i=f.tellg()/sizeof(t);i<11;i++)
	{
		gotoxy(1,i+3);
		cout<<i+1<<". ";
		gotoxy(4,i+3);
		cout<<"NA";
		gotoxy(24,i+3);
		cout<<"NA";
	}
}