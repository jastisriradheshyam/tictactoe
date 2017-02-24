#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

#ifdef _WIN32
#define line 179
#define clear() system("cls")
#define chec 1
#define dash 196
#define plus 197

#else
#define line "\e(0\x78\e(B"
#define clear() system("tput reset")
#define chec 0
#define dash "\e(0\x71\e(B"
#define plus "\e(0\x6e\e(B"
#endif

using namespace std;
	
class tictac
{
	char tic_org[3][3],tempt[3][3];
	int i,j,opt,winplayer,p1,p2,count;
	char player[25],player1[25],player2[25];
	public:
		tictac()
		{
			winplayer=0;
			p1=0;
			p2=0;
			count=0;
			initialb();
		}
		int initialb();
		int check(char a[3][3]);
		void showbox(char tic[3][3]);
		void copy(char inital[3][3], char desti[3][3]);
		void start_menu();
		void game_play_1();
		void game_play_2();
		void position(int pos, char tic[3][3], char c);
		int errorcheck(char tic[3][3], char temp[3][3], char c, int p,int ch);
		int compmove(char tic[3][3], int pos, char sig, int count, int k);
		int retpos(int k, int l);
		int random_number(int min_num, int max_num);
};

int main()
{
	tictac obj;
	char y;
	do{
	obj.start_menu();
	cout<<"\n\t Want to play again:(Y/N)";
	cin>>y;
	}while(y=='y'||y=='Y');
	return 0;
}

void tictac::start_menu() /* For displaying menu */
{
	initialb();
	clear();
	cout<<"\n\n\n\t\t\t\tWELCOME\n";
	cout<<"\t\t\t\t1)For One player game\n";
	cout<<"\t\t\t\t2)For Two players game\n\t\t\t\t:";
	cin>>opt;
	
	switch(opt)
	{
		case 1:
				cout<<"\n\n\t\t\t\tEnter name of Player 1:";
				fflush(stdin);
				gets(player);
				game_play_1();
				break;
		case 2:
				cout<<"\n\n\t\t\t\tEnter name of Player 1:";
				fflush(stdin);
				gets(player1);
				cout<<"\t\t\t\tEnter name of Player 2:";
				fflush(stdin);
				gets(player2);
				game_play_2();
				
	}
	winplayer=0;
	count=0;
}

void tictac::position(int pos, char tic[3][3], char c)
{
	switch (pos)
	{
	case 1:
		tic[0][0] = c;
		break;
	case 2:
		tic[0][1] = c;
		break;
	case 3:
		tic[0][2] = c;
		break;
	case 4:
		tic[1][0] = c;
		break;
	case 5:
		tic[1][1] = c;
		break;
	case 6:
		tic[1][2] = c;
		break;
	case 7:
		tic[2][0] = c;
		break;
	case 8:
		tic[2][1] = c;
		break;
	case 9:
		tic[2][2] = c;
		break;
	}
}

int tictac::retpos(int k, int l)		/* Return position */
{
	if (k == 0)
	{
		return (l + 1);
	}
	else if (k == 1)
	{
		return (4 + l);
	}
	else if (k == 2)
	{
		return (l + 7);
	}
	return 0;
}

void tictac::copy(char inital[3][3], char desti[3][3])	/* Copy function :Works Fine */
{
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			desti[i][j] = inital[i][j];
}

int tictac::check(char a[3][3])			/* Check For Win */
{
	if (a[0][0] == a[0][1] && a[0][1] == a[0][2])
	{
		return 0;
	}
	else if (a[1][0] == a[1][1] && a[1][1] == a[1][2])
	{
		return 0;
	}
	else if (a[2][0] == a[2][1] && a[2][1] == a[2][2])
	{
		return 0;
	}
	else if (a[0][0] == a[1][0] && a[1][0] == a[2][0])
	{
		return 0;
	}
	else if (a[0][1] == a[1][1] && a[1][1] == a[2][1])
	{
		return 0;
	}
	else if (a[0][2] == a[1][2] && a[1][2] == a[2][2])
	{
		return 0;
	}
	else if (a[0][0] == a[1][1] && a[1][1] == a[2][2])
	{
		return 0;
	}
	else if (a[0][2] == a[1][1] && a[1][1] == a[2][0])
	{
		return 0;
	}
	return 1;
}

int tictac::initialb() /*For clrearing the screen */
	{
		tic_org[0][0]='1';
		tic_org[0][1]='2';
		tic_org[0][2]='3';
		tic_org[1][0]='4';
		tic_org[1][1]='5';
		tic_org[1][2]='6';
		tic_org[2][0]='7';
		tic_org[2][1]='8';
		tic_org[2][2]='9';
	}
	
void tictac::showbox(char tic[3][3]) /*For desplaying the box */
{
	if(chec)
	{	
		printf("\n\n\t\t\t\t %c %c %c %c %c", tic[0][0], line, tic[0][1], line, tic[0][2]);
		printf("\n\t\t\t\t %c%c%c%c%c%c%c%c%c", dash, dash, plus, dash, dash, dash, plus, dash, dash);
		printf("\n\t\t\t\t %c %c %c %c %c", tic[1][0], line, tic[1][1], line, tic[1][2]);
		printf("\n\t\t\t\t %c%c%c%c%c%c%c%c%c", dash, dash, plus, dash, dash, dash, plus, dash, dash);
		printf("\n\t\t\t\t %c %c %c %c %c", tic[2][0], line, tic[2][1], line, tic[2][2]);
	}
	else
	{
		printf("\n\n\t\t\t\t %c %s %c %s %c", tic[0][0], line, tic[0][1], line, tic[0][2]);
		printf("\n\t\t\t\t %s%s%s%s%s%s%s%s%s",dash, dash, plus, dash, dash, dash, plus, dash, dash);
		printf("\n\t\t\t\t %c %s %c %s %c", tic[1][0], line, tic[1][1], line, tic[1][2]);
		printf("\n\t\t\t\t %s%s%s%s%s%s%s%s%s", dash, dash, plus, dash, dash, dash, plus, dash, dash);
		printf("\n\t\t\t\t %c %s %c %s %c", tic[2][0], line, tic[2][1], line, tic[2][2]);
	}
}

int tictac::errorcheck(char tic[3][3], char temp[3][3], char c, int p,int ch)	/* Error Checking */
{
	int po = 0;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			++po;
			if ((tic[i][j] == 'X' && temp[i][j] == 'O') || (tic[i][j] == 'O' && temp[i][j] == 'X')
				|| (po == p && temp[i][j] == c) || (p > 9))
			{
				copy(temp, tic);
				if(ch)
				{
					cout<<"\n\n\t\t Invalide input\a\n";
					showbox(tic);
				}
				return 1;
			}
		}
	return 0;
}

int tictac::compmove(char tic[3][3], int pos, char sig, int count, int k)
{
	int post, post1;
	char temp[3][3], temp1[3][3];	/* creating temporary matrix */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (tic[i][j] == sig)
			{
				post1 = retpos(i, j);
				break;
			}
		}
	if (count == 1)				/* For first run only */
	{
		post = random_number(1, 9);
		if (k == 1)
		{
			return post + 1;
		}
		else if (post1 == 1 && post == 1)
		{
			return 2;
		}
		else if (post1 == 9 && post == 9)
		{
			return 8;
		}
		else
		{
			for (i = 0; i < 3; i++)
				for (j = 0; j < 3; j++)
				{
					if (tic[i][j] != 'X')
					{
						post1 = retpos(i, j);
						if (post1 != post)
						{
							return post;
						}
					}
				}
		}
	}
	else						/* For 2 run Onwareds */
	{
		copy(tic, temp);
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				{
					post = retpos(i, j);
					if (temp[i][j] != 'X' && temp[i][j] != 'O')
					{
						position(post, temp, 'O');
					}
					if (check(temp) == 0)
					{
						return post;
					}

					position(post, temp, tic[i][j]);
				}
			}
			copy(tic,temp1);
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				post = retpos(i, j);
				if (tic[i][j] != 'X' && tic[i][j] != 'O')
				{
					position(post, temp1, 'X');
				}
				if (check(temp1) == 0)
				{
					return post;
				}
				position(post, temp1, tic[i][j]);
			}
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				if (tic[i][j] != 'X' && tic[i][j] != 'O')
				{
					post = retpos(i, j);
					return post;
				}
			}
	}
	return 0;
}

int tictac::random_number(int min_num, int max_num)	/* Generate Random No. */
{
	int result = 0, low_num = 0, hi_num = 0;
	if (min_num < max_num)
	{
		low_num = min_num;
		hi_num = max_num + 1;	/* this is done to include max_num in output. */
	}
	else
	{
		low_num = max_num + 1;	/* this is done to include max_num in output. */
		hi_num = min_num;
	}
	srand(time(NULL));
	result = (rand() % (hi_num - low_num)) + low_num;
	return result;
}

void tictac::game_play_1()
{
	int k=0;
	
	cout<<"\n "<<player<<": X\n";
	cout<<" Computer: O\n";
	showbox(tic_org);
	while (winplayer == 0)
		{
			do
			{
				copy(tic_org, tempt);
				cout<<"\n\t"<<player<<" :Enter the postion:";
				cin>>p1;
				position(p1, tic_org, 'X');
				
			}
			while (errorcheck(tic_org, tempt, 'X', p1,1)== 1);
			++count;
			if (check(tic_org) == 0)
			{
				winplayer = 1;
				break;
			}
			if (count > 8)
			{
				break;
			}
			do
			{					/* do changes */
				copy(tic_org, tempt);
				p2 = compmove(tic_org, p1, 'X', count, k);
				position(p2, tic_org, 'O');
					showbox(tic_org);
			}while ((k = errorcheck(tic_org, tempt, 'O', p2,0)) == 1);	/* error check */
			++count;
			k = 0;
			if (check(tic_org) == 0)
			{
				winplayer = 2;
				break;
			}
		}
		clear();
		showbox(tic_org);
		if (winplayer == 1)
		{
			cout<<"\n\n\t\t\t\t "<<player<<" wins!!!! ";
		}
		else if (winplayer == 2)
		{
			cout<<"\n\n\t\t\t\t Computer wins!!!!";
		}
		else
		{
			cout<<"\n\n \t\t\t\t\t Draw!!!";
		}
}
void tictac::game_play_2()
{
		showbox(tic_org);
		while (winplayer == 0)
		{
			do
			{
				copy(tic_org, tempt);
				cout<<"\n\n\t"<<player1<<" :Enter the postion:";
				cin>>p1;
				position(p1, tic_org, 'X');
				showbox(tic_org);
			}while (errorcheck(tic_org, tempt, 'X', p1,1) == 1);
			++count;
			if (check(tic_org) == 0)
			{
				winplayer = 1;
				break;
			}
			if (count > 8)
			{
				break;
			}
			do
			{
				copy(tic_org, tempt);
				cout<<"\n\n\t"<<player2<<" :Enter the postion:";
				cin>>p2;
				position(p2, tic_org, 'O');
				showbox(tic_org);
			}while (errorcheck(tic_org, tempt, 'O', p2,1) == 1);
			++count;
			if (check(tic_org) == 0)
			{
				winplayer = 2;
				break;
			}
		}
		clear();
		showbox(tic_org);
		if (winplayer == 1)
		{
			cout<<"\n\n\t\t\t"<<player1<<" wins!!!!";
		}
		else if (winplayer == 2)
		{
			cout<<"\n\n\t\t\t "<<player2<<" wins!!!!";
		}
		else
		{
			cout<<"\n\n\t\t\t\tDraw!!!";
		}
}

