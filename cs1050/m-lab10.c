//Brett Siebert
//bsb8r
//lab10
//section M
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
//prototype
int getString(char *);
int checkString(char *,int);
void cipherString(char*,int,int);

int main(void)
{
srand(time(NULL));
char* string;
string= malloc(sizeof(char)* 20+1);
getString(string);
return 0;
}

int getString(char* string)
{
int size,x;
printf("Enter the size of the string: ");
scanf("%d",&size);
while (size>20||size<1)
{
	printf("\nPlease enter again: ");
	scanf("%d",&size);
}
printf("Please enter the string: ");
x=checkString(string,size);
while (x==0)
{
printf("Please enter a valid string: ");
x=checkString(string,size);
}
return 0;
}

int checkString(char* string, int size)
{
int i;
scanf("%20s",string);
if (strlen(string)!=size)
{
	printf("Your string is not equal to the length you entered above\n.");
	return 0;
}
for (i=0;i>size;i++)
{
	if((i>='A' && i<='Z') || (i>='a' && i<='z'))
	{
	return 0;
}
}
return 1;
}


