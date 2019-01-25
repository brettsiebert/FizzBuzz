//Brett Siebert
#include<stdio.h>
int main(void)
{
int j;
for (j=1;j<=100;j++)
{
	if (j%5!=0&&j%3!=0)printf("%d\n",j);
	if (j%5==0&&j%3!=0)printf("Buzz\n");
	if (j%5!=0&&j%3==0)printf("Fizz\n");
	if (j%5==0&&j%3==0)printf("FizzBuzz\n");
}
}
