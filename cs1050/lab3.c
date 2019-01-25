//Brett Siebert
//bsb8r
//lab3
//section f

#include<stdio.h>
#include<math.h>
int main(void)
{
int selection, num1; //declaring selection num and length/radius
printf("\nArea calculation\n");
printf("(1) Square \n(2) Cube \n(3) Circle\nPlease make a selection: ");
scanf("%d",&selection); //select what calculation they want
while (selection<=0 || selection>3) //Error trapping the selection
{
	printf("Incorrect choice\n\nArea calculation\n");
	printf("(1) Square \n(2) Cube \n(3) Circle\nPlease make a selection: ");
	scanf("%d",&selection);
}
if (selection==1) { //if they selected square
	printf("\nEnter a positive number: \n");
	scanf("%d",&num1);
while (num1<=0) { //error trap the number of choice
	printf("\nNumber can't be negative or zero\nEnter a positive number: ");
	scanf("%d",&num1); }
printf("Length of the side of square is %d\n",num1); //display length
int square=num1*num1;
printf("Area of square is %d\n",square); //display area
}
if (selection==2) { //if they selected cube
	printf("\nEnter a positive number: \n");
	scanf("%d",&num1);
while (num1<=0) { //error trap number of choice
	printf("\nNumber can't be negative or zero\nEnter a positive number: ");
	scanf("%d",&num1); }
printf("Length of the side of cube is %d\n",num1); //display length
int cube=6*num1*num1;
printf("Area of cube is %d\n",cube); //display area
}
if (selection==3) {
	printf("\nEnter a positive number: \n");
	scanf("%d",&num1);
while (num1<=0) {
	printf("\nNumber can't be negative or zero\nEnter a positive number: ");
	scanf("%d",&num1); }
printf("Radius of circle is %d\n",num1);
float area=3.14159*(float)num1*num1;
printf("Area of circle is %.2f\n",area);
}
return(0);
}

