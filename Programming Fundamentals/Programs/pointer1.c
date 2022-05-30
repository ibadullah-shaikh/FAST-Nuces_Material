#include<stdio.h>
void change (int *p);
void main()
{
int p;
printf("Enter value:");
scanf("%d",&p);	
change(&p);
printf("The new value is:%d",p);
}
void change (int *p)
{
	printf("Enter new value:");
	scanf("%d",*&p);
}
