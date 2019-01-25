//Brett Siebert
//bsb8r
//lab9
//Section M
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50
//prototype
void get_size(int *);
int check_size(int);
void initialize_pointerArray(int *,int);
void print_pointerArray(int *,int);
int find_max(int *,int);
int find_min(int *,int);
void bubble_sort(int *,int);
float find_median(int *,int);
//code
int main(void)
{
srand(time(NULL));
int array[MAX],*pointer=array,size,x,largest,smallest;
float med;
printf("Enter the size of the pointer: ");
get_size(&size);
x=check_size(size);
while (x==0) {
	printf("Please enter again: ");
	get_size(&size);
	x=check_size(size); }
initialize_pointerArray(array,size);
print_pointerArray(pointer,size);
largest=find_max(pointer,size);
smallest=find_min(pointer,size);
printf("\nThe minimum of all the numbers= %d\n",smallest);
printf("The maximum of all the numbers= %d\n",largest);
bubble_sort(pointer,size);
med=find_median(pointer,size);
printf("The median of the pointer= %.2f\n",med);
return 0;
}

void get_size(int *size)
{
scanf("%d",size);
}

int check_size(int size)
{
if (size>0&&size<50)
	return 1;
return 0;
}

void initialize_pointerArray(int array[],int size)
{
for (int i=0;i<size;++i)
	array[i]=(rand()%10);
}

void print_pointerArray(int *pointer,int size)
{
printf("\nInput array\n");
for (int i=0;i<size;++i)
	printf("%1d ",*(pointer+i));
}

int find_max(int *pointer,int size)
{
int large,i;
for (i=1;i<size;i++)
{
	if (large<*(pointer+i))
		large=*(pointer+i);
}
return large;
}

int find_min(int *pointer,int size)
{
int small,i;
for (i=1;i<size;i++)
{
	if (small>*(pointer+i))
		small=*(pointer+i);
}
return small;
}

void bubble_sort(int *pointer,int size)
{
int i,j,t;
for (i=0;i<size-1;i++)
	for (j=0;j<size-i-1;j++)
		if (*(pointer+j)>*(pointer+j+1))
{
			t=*(pointer+j);
			*(pointer+j)=*(pointer+j+1);
			*(pointer+j+1)=t;
}
printf("The sorted pointer is:\n");
for (i=0;i<size;i++)
	printf("%1d ",*(pointer+i));
printf("\n");
}

float find_median(int *pointer,int size)
{
float median=0;
if (size%2==0)
	median=(*(pointer+(size-1)/2)+*(pointer+(size/2)))/2.0;
else
	median=*(pointer+size/2);
return median;
}
