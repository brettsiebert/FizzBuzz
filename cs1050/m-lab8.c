//Brett Siebert
//bsb8r
//lab 8
//section M
#include <stdio.h>
#include <math.h>
//prototype
int errorCheck(int );
int factorial(int );
void printArray(float *, int );
void maclaurinSeries(float *,int ,int );
//main
int main(void)
{
int test=1,x,run;
float macArray[10];
float *macArrayPtr=macArray;
printf("Enter a value to compute the Maclaurin series expansion (x): ");
scanf("%d",&x);
test=errorCheck(x);
if (test==0)
	{
	printf("x must be larger than 0 and less than 10. Please enter again: ");
	scanf("%d",&x);
	test=errorCheck(x);
	}
printf("\nEnter a value for the Maclaurin series to run (n):");
scanf("%d",&run);
test=errorCheck(run);
if (test==0)
	{
	printf("n must be larger than 0 and less than 10. Please enter again: ");
	scanf("%d",&run);
	test=errorCheck(run);
	}
maclaurinSeries(macArrayPtr,x,run);
printf("\nThe array for the Maclaurin series is: \n");
printArray(macArrayPtr,run);
printf("\n");
return 0;
}

int errorCheck(int x)
{
if (x>0&&x<11)
	return 1;
return 0;
}

int factorial(int x)
{
int fact=1,i;
for (i=1;i<=x;i++)
{
	fact=fact*i;
}
return fact;
}

void maclaurinSeries(float *macArrayPtr,int x,int run)
{
int i;
float total=1;
*macArrayPtr=1;
for (i=1;i<=run;i++)
{
if (i%2!=0)
{
total-=pow(x,i*2)/(factorial(2*i));
}
if (i%2==0)
{
total+=pow(x,i*2)/(factorial(2*i));
}
 *(macArrayPtr+i)=total;
}
}

void printArray(float *macArrayPtr,int run)
{
int i;
for (i=0;i<=run;++i)
	{
	printf("%.4f ",*(macArrayPtr+i));
	}
printf("\n");
printf("\n-----BONUS-----\n");
printf("\nThe reverse array is: \n");
for (i=run;i>=0;i--)
{
	printf("%.4f ",*(macArrayPtr+i));
}
}


