/* program to store n students records using malloc/calloc */
#include<stdio.h>
#include<stdlib.h>
struct student
{
int rolln;
char name[10];
};
int main()
{int n,i;
struct student *rec;

rec=(struct student*)malloc(2*sizeof(struct student));
if(rec==NULL)
printf("memory not found/not empty \n");

for(i=0;i<2;i++)
{//for records of students
printf("enter details of students in record rolln -name- percent \n");
scanf("%d %s ",&(rec+i)->rolln,(rec+i)->name);
}

printf("%d \n %s \n Entry-1 \n",(rec+i)->rolln,(rec+i)->name);
printf(" %d \n %s \n Entry-2 \n",(rec+i)->rolln,(rec+i)->name);
void free(void *rec);
rec=NULL;
return 0;
}

