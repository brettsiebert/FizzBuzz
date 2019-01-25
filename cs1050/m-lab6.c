//Brett Siebert
//bsb8r
//lab6
//section M
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15
//prototype
int check_error(int size);
void initialize_2Darray(int[MAX][MAX],int size);
void print_2Darray(int[MAX][MAX],int size);
int findTwos(int array[][MAX],int size);
int findEvenOdd(int[MAX][MAX],int size);
void printTranspose(int [MAX][MAX], int size);
void flattenArray(int[MAX][MAX],int size);

int main(void)
{
srand(time(NULL));
int array[MAX][MAX];
int size, check, twos, sizeb=0, odd=0, even=0;
printf("Enter the size of the 2-D array: ");
scanf("%d",&size);
check=check_error(size);	//call error check
while (check==0) {
	printf("Please enter a value between 1-15 only: ");
	scanf("%d",&size);
	check=check_error(size); }
initialize_2Darray(array,size);	//initialize array
printf("THE FIRST 2-D array is: ");
print_2Darray(array,size);	//print array
twos=findTwos(array,size);	//find twos
printf("\nThe number of twos in 2-D array: %d\n",twos);
even=findEvenOdd(array,size);	//find evens
sizeb=size*size;
odd=sizeb-even;
printf("The number of Even numbers: %d\n",even);
printf("The number of Odd numbers: %d\n",odd);
printf("The transpose of the 2-D Array is ");
printTranspose(array,size);	//find transpose
printf("\nThe flattend array is \n");
flattenArray(array,size);	//flatten array
return 0;
}

int check_error(int size)
{
if (size>0&&size<16)
	{return 1;}
return 0;
}

void initialize_2Darray(int array[MAX][MAX],int size)
{
int i=0,j=0;
for (j=0;j<size;++j)
{
for (i=0;i<size;++i)
	array[j][i]=(rand()%9);
}
}


void print_2Darray(int array[MAX][MAX],int size)
{
int x,j;
for (j=0;j<size;++j)
{
printf("\n");
for (x=0;x<size;++x)
{
	printf("%3d",array[j][x]);
}
}
}

int findTwos(int array[MAX][MAX],int size)
{
int x=0,j,i;
for (j=0;j<size;++j)
{
	for (i=0;i<size;++i) {
		if(array[j][i]==2)
			x=x+1; }
}
return x;
}

int findEvenOdd(int array[MAX][MAX], int size)
{
int x=0,j,i;
for (j=0;j<size;++j)
{
	for (i=0;i<size;++i) {
		if(array[j][i]%2==0)
			x=x+1; }
}
return x;
}

void printTranspose(int array[MAX][MAX], int size)
{
int i,j;
for (j=0;j<size;++j)
{
printf("\n");
	for (i=0;i<size;++i) {
		printf("%3d",array[i][j]);
}
}
}

void flattenArray(int array[MAX][MAX],int size)
{
int x,j;
for (j=0;j<size;++j) {
	for(x=0;x<size;++x)
		printf("%d ",array[j][x]);
}
printf("\n");
}
