//Brett Siebert
//bsb8r
//lab11
//Section M
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 40
#define STRING_LENGTH 20
char filename[MAX];
typedef struct {
char county[MAX];
int zip;
char city[MAX];
int group;
} cityinfo;
cityinfo JimR[MAX];
//prototype
void get_size(int*);
int check_size(int);
void load_data(char*,int, cityinfo []);
void get_group(int*);
int check_group(int);
//code
int main(int argc, char *argv[])
{
if(argc!=2){
	printf("JIMR");
	exit(0);
}
printf("Enter the size of the input: ");
int x,size,groupS;
get_size(&size);
x=check_size(size);
while (x==0)
{
	printf("\n===================================");
	printf("\nInvalid Size Entered! Minimum is 4 and Maximum is 40!\n");
	printf("Please enter again: ");
	get_size(&size);
	x=check_size(size);
}
printf("\n=================================\n");
load_data(argv[1],size,JimR);
//	printf("%4s%2s%5s\n", "Name", "Id", "Grade");
//	fscanf(cfpointer,"%10s%d%d",name,&id,&grade);
printf("Enter the group number: ");
get_group(&groupS);
x=check_group(groupS);
while (x==0)
{
	printf("\n===================================");
	printf("\nInvalid group entered! Minimum is 1 and Maximum is 3!\n");
	printf("Please enter again: ");
	get_group(&groupS);
	x=check_group(groupS);
}
return 0;
}

void get_size(int *size)
{
scanf("%d",size);
}

int check_size(int size)
{
if (size>=4 && size<=MAX)
	return 1;
return 0;
}

void load_data(char *filename, int size, cityinfo JimR[])
{
int j;
FILE *fptr=fopen(filename,"r");
if (fptr==NULL)
{
	printf("Cannot open file\n");
	exit(0);
}
printf("%3s-%6s-%7s-%5s\n","s/n","County","ZipCode","City");
for (j=0;j<size;j++)
{
fscanf(fptr,"%s %d %s", JimR[j].county,&JimR[j].zip,JimR[j].city);
printf("%d %-20s %d %-20s\n",j+1, JimR[j].county,JimR[j].zip, JimR[j].city);
}
fclose(fptr);
}

void get_group(int *groupS)
{
scanf("%d",groupS);
}

int check_group(int groupS)
{
if (groupS>=1 && groupS<=3)
	return 1;
return 0;
}
