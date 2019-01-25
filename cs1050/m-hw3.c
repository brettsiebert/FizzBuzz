//Brett Siebert
//bsb8r
//hw3
//Section M
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX 255
char filename[MAX];
//prototype
int get_record_count(char*);
int load_data(char*,int*,float*,int);
void print_data(int*,float*,int);
//
int main(int argc, char *argv[])
{
if (argc!=2){
	printf("Cannot open the file\n");
	exit(0);
}
int size=get_record_count(argv[1]);
int *account=malloc(sizeof(int)*MAX);
float *balance=malloc(sizeof(float)*MAX);
printf("%d records in the file\n",size);
load_data(argv[1],account,balance,size);
print_data(account,balance,size);
free(account);
free(balance);
return 0;
}

int get_record_count(char *filename)
{
int c=0;
char lineboi[MAX];
FILE *fptr=fopen(filename,"r");
while (fgets(lineboi,sizeof lineboi, fptr) != NULL){
	c++;
}
fclose(fptr);
return c;
}

int load_data(char *filename,int *account,float *balance,int size)
{
int i;
FILE *fptr=fopen(filename,"r");
if (fptr==NULL)
{
	printf("Cannot open file\n");
	exit (0);
}
for(i=0;i<size;i++) {
	fscanf(fptr,"%d %f",&account[i],&balance[i]); }

fclose(fptr);
return (0);
}

void print_data(int *account,float *balance,int size)
{
int i;
printf("Account No.  Amount");
for(i=0;i<size;i++) {
	printf("\n%d         %.2f",*(account+i),*(balance+i) ); }
printf("\n");
}
