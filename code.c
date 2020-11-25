#include "code.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


void intro()
{
	printf("Programming Assignment DFAChecker\n");
	printf("Submitted by Gene Paul M. Zafra BSCS-3\n");
	printf("Submitted to Maam Cherry Lyn Santa Romana\n\n");
}

int isFinal(int x)
{
	int flag = 0;
	int f[4]= {12,13,17,18};
	int i;
	for(i=0; i<4; i++)
		{
			if(x==f[i])
				{
					flag=1;
					break;
				}
		}
	return flag;
}

void isValid(char s[])
{
	int i=0;
	int len=strlen(s);
	int state=0;
	int printed=0;
	if(len<=1)
		{
			printf("Invalid\n");
			printed=1;
		}
	while(i<len)
		{
			switch(state)
				{
					case 0:
						if(isalpha(s[i]))
							state=1;
						else state=20;
						break;
					case 1:
						if(isalpha(s[i]))
							state=1;
						if(isdigit(s[i]))
							state=2;
						if(s[i]=='=')
							state=3;
						break;
					case 2:
						if(isalpha(s[i]))
							state=1;
						if(isdigit(s[i]))
							state=2;
						if(s[i]=='=')
							state=3;
						break;
					case 3:
						if(isdigit(s[i]))
							state=4;
						if(isalpha(s[i]))
							state=7;
						if(s[i]=='-')
							state=5;
						if(s[i]==39)
							state=6;
						break;
					case 4:
						if(isdigit(s[i]))
							state=4;
						if(s[i]==';')
							state=13;
						if(s[i]=='.')
							state=9;
						break;
					case 5:
						if(isdigit(s[i]))
							state=4;
						if(s[i]=='.')
							state=9;
						break;
					case 6:
						if(isalpha(s[i]))
							state=10;
						if(isdigit(s[i]))
							state=11;
						break;
					case 7:
						if(isalpha(s[i]))
							state=8;
						if(isdigit(s[i]))
							state=7;
						if(s[i]==';')
							state=12;
						break;
					case 8:
						if(isalpha(s[i]))
							state=8;
						if(isdigit(s[i]))
							state=7;
						if(s[i]==';')
							state=12;
						break;
					case 9:
						if(isdigit(s[i]))
							state=14;
						break;
					case 10:
						if(s[i]==39)
						state=15;
						break;
					case 11:
						if(s[i]==39)
						state=15;
						break;
					case 12:
						break;
						break;
					case 13:
						break;
						break;
					case 14:
						if(s[i]==';')
						state=17;
						break;
					case 15:
						if(s[i]==';')
						state=18;
						break;
					case 16:
						if(s[i]==';')
						state=18;
						break;
					case 17:
						break;
						break;
					case 18:
						;
						break;
					case 19:
						if(!printed)
							{
								printf("Invalid\n");
								printed=1;
							}
						break;
					case 20:
						if(!printed)
							{
								printf("Invalid\n");
								printed=1;
							}
						break;
					case 21:
						if(!printed)
							{
								printf("Invalid\n");
								printed=1;
							}
						break;
					case 22:
						if(!printed)
							{
								printf("Invalid\n");
								printed=1;
							}
						break;
				}
			if(printed)
				break;
			i++;
		}
	if(!isFinal(state) && !printed)
		{
			printf("Invalid\n");
			printed=1;
		}
	else if(!printed)
		{
			printf("Valid\n");
		}

}
