#include<stdio.h>
#include<stdlib.h>

int suit(char x);
char suit2(int x);
int charToInt(char x[],int y);
char intToChar(int x);

int main()
{
	int z[6]={0};
	char x,y[3];
	
	for(int i=0;i<6;i++)
	{
		printf("請輸入6張撲克牌，第%d張:\n",i+1);
		
	 re:
	 	y[0]=y[1]=y[2]='\0';
		scanf("%c",&x);
		scanf("%s",&y);
		
		if(suit(x)==99||charToInt(y,3)==99)
		{
			printf("請重新輸入:\n");
			goto re;
		}
		
		z[i]+=suit(x);
		z[i]+=charToInt(y,3);
	}
	
	for(int i=0;i<6;i++)
		for(int j=i+1;j<6;j++)
			if(z[i]>z[j])
			{
				int o;
				o=z[i];
				z[i]=z[j];
				z[j]=o;
			}
	
	for(int i=0;i<6;i++)
		printf("%c  %s\n",suit2(z[i]),intToChar(z[i]));
	
	system("pause");
}

int suit(char x)
{
	switch(x)
	{
		case 's':
		case 'S':
			return 0;
		case 'h':
		case 'H':
			return 13;
		case 'd':
		case 'D':
			return 26;
		case 'c':
		case 'C':
			return 39;
		default:
			return 99;
	}
}

char suit2(int x)
{
	switch((x-1)/13)
	{
		case 0:
			return 's';
		case 1:
			return 'h';
		case 2:
			return 'd';
		case 3:
			return 'c';
	}
}

int charToInt(char x[],int y)
{
	if(x[1]=='\0')
		switch(x[0])
		{
			case 'a':
			case 'A':
			case '1':
				return 1;
			case '2':
				return 2;
			case '3':
				return 3;
			case '4':
				return 4;
			case '5':
				return 5;
			case '6':
				return 6;
			case '7':
				return 7;
			case '8':
				return 8;
			case '9':
				return 9;
			case 'j':
			case 'J':
				return 11;
			case 'q':
			case 'Q':
				return 12;
			case 'k':
			case 'K':
				return 13;
			default:
				return 99;
		}
	else if(x[0]=='1')
		switch(x[1])
		{
			case '0':
				return 10;
			case '1':
				return 11;
			case '2':
				return 12;
			case '3':
				return 13;
			default:
				return 99;
		}
	else
		return 99;
}

char intToChar(int x)
{
	switch(x%13)
	{
		case 1:
			return 'A';
		case 2:
			return '2';
		case 3:
			return '3';
		case 4:
			return '4';
		case 5:
			return '5';
		case 6:
			return '6';
		case 7:
			return '7';
		case 8:
			return '8';
		case 9:
			return '9';
		case 10:
			return '1';
		case 11:
			return 'J';
		case 12:
			return 'Q';
		case 0:
			return 'K';
			
	}
}
