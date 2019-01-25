//Brett Siebert
//bsb8r
//hw2
//section M
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 12
#define COL 6
#define MAX 25
//prototype
void initialSeats(char flight[ROW][COL],int count);
void displayMenu();
void printFlightMap(char flight[ROW][COL]);
int loginMatch(int, int);
int getTotalRevenue(char flight_1[ROW][COL],char flight_2[ROW][COL],char flight_3[ROW][COL]);
void flightMenu();
void seatReservation(char flight[ROW][COL]);
void getSafeString(char *string, int maxsize);
//global
int costMatrix[ROW][COL]=
{
{500,200,500,500,200,500},
{500,200,500,500,200,500},
{500,200,500,500,200,500},
{500,200,500,500,200,500},
{500,200,500,500,200,500},
{500,200,500,500,200,500},
{500,200,500,500,200,500},
{500,200,500,500,200,500},
{500,200,500,500,200,500},
{500,200,500,500,200,500},
{500,200,500,500,200,500},
{500,200,500,500,200,500}
};

//main
int main(void)
{
srand(time(NULL));
char flight_1[ROW][COL], flight_2[ROW][COL], flight_3[ROW][COL],name[MAX];
int option, count, passcode=0, adminPasscode=105018, test=1,loop=0,val=0,plane,maxsize=25;
count=(rand()%20+1);
initialSeats(flight_1,count);
initialSeats(flight_2,count);
initialSeats(flight_3,count);
printf("*******WELCOME TO MIZZOU AIRLINE BOOKING SYSTEM********\n");
do {
displayMenu();
printf("\nChoose an option: ");
scanf("%d",&option);
if (option>3||option<1) {
	printf("Wrong option! Choose a right option\n");
	displayMenu();
	printf("\nChoose an option: ");
	scanf("%d",&option);
}
if (option==1) {
	printf("Enter the login passcode to log in as admin: ");
	scanf("%d",&passcode);
	test=loginMatch(passcode,adminPasscode);
	while (test==0) {
		printf("Invalid Passcode combination\n");
		printf("\nEnter the login passcode to log in as admin: ");
		scanf("%d",&passcode);
		test=loginMatch(passcode,adminPasscode); }
	printf("Printing the Flight Map of flight Columbia to Miami...");
	printFlightMap(flight_1);
	printf("\nPrinting the Flight Map of flight Columbia to Nashville...");
	printFlightMap(flight_2);
	printf("\nPrinting the Flight Map of flight Columbia to Las Vegas...");
	printFlightMap(flight_3);
	val=getTotalRevenue(flight_1,flight_2,flight_3);
	printf("\nThe total earning from all the flights:$%d",val);
	printf("\nYou are logged out now!\n");
}
if (option==2) {
	flightMenu();
	printf("Choose a flight: ");
	scanf("%d",&plane);
	while (plane>3||plane<1) {
		flightMenu();
		printf("Choose a flight: ");
		scanf("%d",&plane);
}	
	printf("Enter your first name: ");
	getSafeString(name,maxsize);
	if (plane==1) {
		seatReservation(flight_1);
		printf("Congrats %s!!, your flight MIA1050 is booked, enjoy your trip\n",name);
		printf("\nEnjoy your Thanksgiving break:)\n"); 
		}
	if (plane==2) {
		seatReservation(flight_2);
		printf("Congrats %s!!, your flight BNA1050 is booked, enjoy your trip\n",name);
		printf("\nEnjoy your Thanksgiving break:)\n");
		}
	if (plane==3) {
		seatReservation(flight_3);
		printf("Congrats %s!!, your flight LAS1050 is booked, enjoy your trip\n",name);
		printf("\nEnjoy your Thanksgiving break:)\n");
		}
}
if (option==3)
	loop=1;
} while (loop==0);
printf("\nTerminating the Program\nThank you for using Mizzou Airline Booking System.\n");
}
//functions
void initialSeats(char flight[ROW][COL], int count)
{
int i,j,row,col;
for (j=0;j<ROW;++j)
	for (i=0;i<COL;++i) {
		flight[j][i]='O';
}
for (i=0;i<count;++i) {
	row=(rand()%20+1);
	col=(rand()%20+1);
	flight[row][col]='X';
}	
}

void displayMenu()
{
printf("\n1.)Admin Log-in\n2.)Reserve a seat\n3.)Exit");
}

void printFlightMap(char flight[ROW][COL])
{
int i,j;
for (j=0;j<ROW;++j) {
	printf("\n");
	for (i=0;i<COL;++i) 
		printf("%c ",flight[j][i]);
}
}

int loginMatch(int passcode, int adminPasscode)
{
if (passcode==adminPasscode)
	return 1;
return 0;
}

int getTotalRevenue(char flight_1[ROW][COL],char flight_2[ROW][COL],char flight_3[ROW][COL])
{
int i,j,rev=0;
for (j=0;j<ROW;++j)
	for (i=0;i<COL;++i)
{
		if (flight_1[j][i]=='X')
			rev+=costMatrix[j][i];
		if (flight_2[j][i]=='X')
			rev+=costMatrix[j][i];
		if (flight_3[j][i]=='X')
			rev+=costMatrix[j][i]; 
}
return rev;
}

void flightMenu()
{
printf("\n1.)COU---->MIA\n2.)COU---->BNA\n3.)COU---->LAS\n");
}

void seatReservation(char flight[ROW][COL])
{
int i,j,srow,scol,rep;
for(j=0;j<ROW;++j) {
	printf("\n");
	for (i=0;i<COL;++i)
		printf("%c ",flight[j][i]);
}
do 
{
printf("\nWhich Seat row do you want?: ");
scanf("%d",&srow);
while (srow>11||srow<0) {
	printf("Seat rows are between 0 to 11\nTry Again. Which seat row do you want?: ");
	scanf("%d",&srow);
}
printf("Which seat column do you want?: ");
scanf("%d",&scol);
while (scol>5||scol<0) {
	printf("Seat columns are between 0 to 5\nTry Again. Which seat column do you want?: ");	
	scanf("%d",&scol);
}
if (flight[srow][scol]=='X') {
	printf("Sorry!! Someone has reserved that seat. Please try again.\n");
	rep=0;
}
else 
	rep=1;
} while (rep==0); 
}

void getSafeString(char *string, int maxsize)
{
int indexcur=0;
char charcur = '\n';

// Spin until we get something other than newline
while ('\n'==charcur)
{
	charcur = getc(stdin);
}
while (indexcur<(maxsize-1) && '\n'!=charcur)
{
if ('\n'!=charcur)
{
string[indexcur] = charcur;
}
indexcur++;
charcur = getc(stdin);
}
string[indexcur] = '\0';

// Spin until they hit enter
while ('\n'!=charcur)
{
charcur = getc(stdin);
}
}

