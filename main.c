#include <stdio.h>
#include <stdlib.h>
#include "code.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	intro();
	char a[2047];
	scanf("%[^\n]s",a);
	isValid(a);
	return 0;
}
