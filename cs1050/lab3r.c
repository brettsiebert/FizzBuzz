//Brett Siebert
//bsb8r
//lab3
//section m

#include<stdio.h>
#include<math.h>
int main(void)
{
int rep;
do {
printf("Right triangle calculation type\n");
int selection;
printf("(1) Two triangle legs\n(2) One leg one hypotenuse\n");
printf("Please make a selection: ");
scanf("%d",&selection);
while (selection<1 || selection>2) {
	printf("Incorrect choice, please make a choice again\nRight triangle calculation type");
	printf("\n(1) Two triangle legs\n(2) One leg hypotenuse\n");
	printf("Please make a selection: ");
	scanf("%d",&selection); }
if (selection==1) {
	int leg1, leg2, leg1s, leg2s;
	printf("Enter a length for the first leg: ");
	scanf("%d",&leg1);
	while (leg1>100 || leg1<1) {
		printf("Incorrect value, length should be between 1-100\n");
		printf("Enter a length for the first leg: ");
		scanf("%d",&leg1); }
	printf("\nEnter a length for the second leg: ");
	scanf("%d",&leg2);
	while (leg2>100 || leg2<1) {
		printf("Incorrect value, length should be between 1-100\n");
		printf("Enter a length for the second leg: ");
		scanf("%d",&leg2); }
	leg1s=leg1*leg1;
	leg2s=leg2*leg2;
	printf("Calculation: %d + %d = c^2\n",leg1s,leg2s);
	float hypotenuse=sqrt((float)leg1s+leg2s);
	printf("Missing leg length = %.2f\n",hypotenuse); }
if (selection==2) {
	int leg1, leg1s, hypotenus, hyps;
	printf("Enter a length for the first leg: ");
	scanf("%d",&leg1);
	while (leg1>100 || leg1<1) {
		printf("Incorrect value, length should be between 1-100\n");
		printf("Enter a length for the first leg: ");
		scanf("%d",&leg1); }
	printf("\nEnter a length for the hypotenuse: ");
	scanf("%d",&hypotenus);
	while (hypotenus<=leg1) {
		printf("Incorrect value, hypotenuse length cannot be less than or equal to leg length\n");
		printf("Enter a length for the hypotenuse: ");
		scanf("%d",&hypotenus); }
	leg1s=leg1*leg1;
	hyps=hypotenus*hypotenus;
	printf("Calculation: %d + b^2 = %d\n",leg1s,hyps);
	float leg2a=sqrt((float)leg1s+hyps);
	printf("Missing leg length = %.2f\n",leg2a); }
printf("Do you wish to calculate again?\nPress 1 for no, 0 for yes: ");
scanf("%d",&rep);
}
while (rep==0);
}
