#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50
//prototypes
int check_error(int x);
void initialize_array(int[],int);
void print_array(int[],int);
float average(int[],int);
float std_dev(int[],int);

int main(void)
{
int array[MAX];
srand(time(NULL));
int input,check;
printf("Enter the number of elements to be generated: ");
scanf("%d",&input);
check=check_error(input);
while (check==0) {
	printf("Please enter a number between 1 and 50: ");
	scanf("%d",&input);
	check=check_error(input); }
initialize_array(array,input);
printf("The array is:\n");
print_array(array,input);
float avg=average(array,input);
printf("\nThe average of the array is %.2f",avg);
float sd=std_dev(array,input);
printf("\nThe standard deviation of the array is %.2f\n",sd);

return 0;
}

int check_error(int x)
{
if (x>0&&x<=50)
	{ return 1; }
return 0;
}

void initialize_array(int array[],int input)
{
int i;
for (i=0;i<input;++i)
{
	array[i]=(rand()%9+1);
}
}
void print_array(int array[], int input)
{
int x;
for (x=0;x<input;++x)
{
	printf("%d ",array[x]);
}
}

float average(int array[],int input)
{
float av=0.0,sum=0.0;
int z;
for (z=0;z<input;z++) {
sum=sum+array[z]; }
av=sum/input;
return av;
}

float std_dev(int array[],int input)
{
float std=0.0,mean,sum2=0.0;
int e;
for (e=0; e<input; ++e); {
sum2=sum2+array[e];
}
mean=sum2/input;
for (e=0; e<input;e++) {
std=std+ pow(array[e]-mean, 2); }
return sqrt(std/10);
}

