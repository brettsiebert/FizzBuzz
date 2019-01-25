//Brett Siebert
//bsb8r
//lab4
//section M
//
#include <stdio.h>
#include <math.h>

//Prototypes
int courseNumCheck(int x);
float getScore(void);
float getScorePoint(float score);
void  printComment(float gpa);
int scoreErrorCheck(float score);
int getUnit(void);

int main(void)
{
int coursenum, test, num, unit, tunit=0;
float total=0;
printf("STUDENT GPA CALCULATOR\n");
printf("\nEnter the Number of Courses: ");
scanf("%d",&coursenum);
test=courseNumCheck(coursenum);

while (test==0)
{
	printf("Error! Please enter a Number of Courses greater than 1: ");
	scanf("%d",&coursenum);
	test=courseNumCheck(coursenum);
}
while (coursenum>0)
{
	num= num+1;
	printf("Enter the student score for course %d (Precent): ",num);
	float score=getScore();
	while (scoreErrorCheck(score)==1) {
		printf("Error! Please enter a course unit greater than Zero: ");
		score=getScore(); }
	float point=getScorePoint(score);
	printf("Enter the number of units for course %d: ",num);
	unit=getUnit();
	tunit=tunit+unit;
	total=total+(unit*point);
	coursenum=coursenum-1;
}
float gpa=total/tunit;
printf("The Student GPA: %.2f\n",gpa);
printComment(gpa);
return (0);
}

int getUnit(void)
{
int u;
scanf("%d",&u);
return u;
}

int scoreErrorCheck(float score)
{
if (score<0) {
	return (1); }
return (0);
}

void  printComment(float gpa)
{
if (gpa>=3.8) {
	printf("COMMENT: Amazing!\n"); }
if (gpa<3.8&&gpa>=3.5) {
	printf("COMMENT: Great job!\n"); }
if (gpa<3.5&&gpa>=3) {
	printf("COMMENT: Good work!\n"); }
if (gpa<3&&gpa>=2.5) {
	printf("COMMENT: Satisfactory!\n"); }
if (gpa<2.5&&gpa>=2) {
	printf("COMMENT: Not Satisfactory!\n"); }
if (gpa<2) {
	printf("COMMENT: See You Next Semester.\n"); }
}

float getScorePoint(float score)
{
if (score>=90) {
	return (4); }
if (score>=80&&score<90) {
	return (3); }
if (score>=70&&score<80) {
	return (2); }
if (score>=60&&score<70) {
	return (1); }
else 
	return (0); 
}

float getScore(void)
{
float s;
scanf("%f",&s);
return s;
}

int courseNumCheck(int x)
{
if (x>1)
	{ return (1); }

	return (0);
}

