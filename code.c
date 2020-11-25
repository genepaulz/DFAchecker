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

int isFinal(int state)
{
	int flag=0,i=0;
	int f[3]= {8,14,17};
	for(i=0; i<3; i++)
		{
			if(state==f[i])
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
						if(isalpha(s[i]) || s[i]=='_')
							state=1;
						else state=18;
						break;
					case 1:
						if(isalpha(s[i]) || s[i]=='_')
							state=1;
						if(isdigit(s[i]))
							state=2;
						if(s[i]=='=')
							state=3;
						if(s[i]==' ' && s[i+1]!='=')
							state=18;
						break;
					case 2:
						if(isalpha(s[i]))
							state=1;
						if(isdigit(s[i]) || s[i]=='_')
							state=2;
						if(s[i]=='=')
							state=3;
						if(s[i]==' ' && s[i+1]!='=')
							state=18;
						break;
					case 3:
						if(isdigit(s[i]))
							state=4;
						else if(s[i]=='-')
							state=5;
						else if(s[i]=='.')
							state=6;

						else if(s[i]==39)
							state=9;

						else if(isalpha(s[i]))
							state=15;

						if(s[i]=='=')
							state=18;
						break;
					case 4:
						if(isdigit(s[i]))
							state=4;
						else if(s[i]==';')
							state=8;
						else if(s[i]=='.')
							state=6;
						if(s[i]==' ' && isdigit(s[i+1]))
								state=18;
						break;
					case 5:
						if(isdigit(s[i]))
							state=4;
						else if(s[i]=='.')
							state=6;
						else state=18;
						break;
					case 6:
						if(isdigit(s[i]))
							state=7;
						else state=18;
						break;
					case 7:
						if(isdigit(s[i]))
							state=7;
						if(s[i]==';')
							state=8;
						if(s[i]==' ' && isdigit(s[i+1]))
							state=18;
						break;
					case 8:
						break;
						break;
					case 9:
						if(isalpha(s[i]))
							state=10;
						else if(isdigit(s[i]))
							state=11;
						else
							state=12;
						break;
					case 10:
						if(s[i]==39)
							state=13;
						else state=18;
						break;
					case 11:
						if(s[i]==39)
							state=13;
						else state=18;
						break;
					case 12:
						if(s[i]==39)
							state=13;
						else state=18;
						break;
					case 13:
						if(s[i]==';')
						state=14;
						else state=18;
						break;
					case 14:
						break;
						break;
					case 15:
						if(isalpha(s[i]))
							state=15;
						else if(s[i]=='_')
							state=15;
						else if(isdigit(s[i]))
							state=16;
						else if(s[i]==';')
							state=17;
						break;
					case 16:
						if(isdigit(s[i]))
							state=16;
						else if(s[i]=='_')
							state=16;
						else if(isalpha(s[i]))
							state=15;
						else if(s[i]==';')
							state=17;
						break;
					case 17:
						break;
						break;
					case 18:
						if(!printed)
							{
								printf("Invalid\n");
								printed=1;
							}
						break;
				}
//			printf("%d\n",state);
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
