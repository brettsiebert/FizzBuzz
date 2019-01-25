#include<stdio.h>
#include<math.h>
int main(void)
{
int int1, int2, sum, diff, prod, root;
printf("Enter the first number: ");
scanf("%d", &int1);
while (int1<0)
{
printf("Enter a non-negative number: ");
scanf("%d", &int1);
}
printf("Enter the second number: ");
scanf("%d", &int2);
while (int2<0)
{
printf("Enter a non-negative number: ");
scanf("%d", &int2);
}
printf("ADDITION\n");
sum=int1+int2;
printf("The sum of %d and %d is %d.\n",int1,int2,sum);
printf("SUBTRACTION\n");
diff=int1-int2;
printf("The difference between %d and %d is %d.\n",int1,int2,diff);
printf("MULTIPLICATION\n");
prod=int1*int2;
printf("The product of %d and %d is %d.\n",int1,int2,prod);
printf("DIVISION\n");
while (int1==0)
{
printf("Cannot divide by zero!\n");
printf("Enter a new number: \n");
scanf("%d", &int1);
}
while (int2==0)
{
printf("Cannot divide by zero!\n");
printf("Enter a new number: \n");
scanf("%d", &int2);
}
if (int1>=int2) {
float div=(float)int1/int2;
printf("%d divided by %d is %.2f\n",int1,int2,div);
printf("%d is the bigger number.\n",int1);
}
if (int2>int1) {
float div=(float)int1/int2;
printf("%d divided by %d is %.2f\n",int2,int1,div);
printf("%d is the bigger number.\n",int2);
}
printf("SQUARE ROOT\n");
printf("Enter a number for the square root operation: \n");
scanf("%d", &root);
while (root<1) {
printf("Cannot take the square root of a negative number or zero.\n");
printf("Try again: \n");
scanf("%d", &root);
}
double result;
result= sqrt(root);
printf("The square root of %d is %.2lf\n",root,result);
}
