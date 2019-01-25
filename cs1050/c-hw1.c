//Brett Siebert
//bsb8r
//homework 1
#include <stdio.h>
#include <math.h>
void displayMenu();
int errorCheck(int option);
int errorCheckUnits(int units);
float getRate(int units, int option);
int charge(int option);

int main(void)
{
int option,test,units,connection,rep;
float rate=0.0,bill=0.0;
do {
printf("*****ELECTRICITY BILL CALCULATOR*****\n");
displayMenu();
printf("\nChoose the type of connection: ");
scanf("%d",&option);
test=errorCheck(option);
while (test==0) {
	printf("Invalid Choice! Please enter a valid choice\n");
	displayMenu();
	printf("\nChoose the type of connection: ");
	scanf("%d",&option);
	test=errorCheck(option);
}
printf("\nEnter the number of units (in kWh): ");
scanf("%d",&units);
test=errorCheckUnits(units);
while (test==0) {
	printf("Invalid Input!\nEnter the number of units (in kWh): ");
	scanf("%d",&units);
	test=errorCheckUnits(units); }
rate=getRate(units,option);
connection= charge(option);
bill=rate+(float)connection;
printf("Total energy charge for the customer is:$ %.2f\n",rate);
printf("Connection charge for this customer is: $ %d.00\n",connection);
printf("Total bill due from this connection is: $ %.2f\n",bill);
printf("Do you want to continue and calculate another bill? If yes enter 1, else 0: ");
scanf("%d",&rep);
}
while (rep==1);
}

void displayMenu()
{
printf("\n1. Residential\n2. Commercial\n3. Industrial\n");
}

int errorCheck(int option)
{
if (option==1||option==2||option==3)
	return 1;
return 0;
}

int errorCheckUnits(int units)
{
if (units>=1)
	return 1;
return 0;
}

float getRate(int units,int option)
{
float frate;
switch(option){
case 1:
	if (units<=200)
		frate=(float)units*.075;
	if (units>200&&units<=700)
		frate=(float)units*.1;
	if (units>700&&units<=1250)
		frate=(float)units*.135;
	if (units>1250)
		frate=(float)units*.15;
return (frate);
break;
case 2:
	if (units<=200)
		frate=(float)units*.105;
	if (units>300&&units<=1000)
		frate=(float)units*.14;
	if (units>1000&&units<=2000)
		frate=(float)units*.175;
	if (units>2000)
		frate=(float)units*.2;
return (frate);
break;
case 3:
	if (units<=500)
		frate=(float)units*.365;
	if (units>500&&units<=2000)
		frate=(float)units*.4;
	if (units>2000&&units<=3000)
		frate=(float)units*.455;
	if (units>3000)
		frate=(float)units*.5;
return (frate);
break;
default:
return 0;
break;
}
}

int charge(int option)
{
int x;
switch(option){
case 1:
	x=25;
	return (x);
break;
case 2:
	x=90;
	return (x);
break;
case 3:
	x=850;
	return (x);
break;
default:
return 0;
break;
}
}
