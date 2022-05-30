/*
• Assignment No = 07
• Section = G
• Std.Id = 19k-0362 
• Name = Areez Arsalan
*/
#include<stdio.h>
#include<string.h>
void search(int);
struct department{
	int dep;
	char dept[20];
};
struct employee{
	int ssn,id,age,salary;
	char desi[20];
	struct department d;
	}a[10];
void main()
{
	int i,ser;
	printf("\t\t\t\t\t     Enter the data of Employees\n");
	for(i=1;i<=10;i++)
	{
	printf("Enter ID of %d employee:",i);
	scanf("%d",&a[i].id);
	printf("Enter SSN of %d employee:",i);
	scanf("%d",&a[i].ssn);
	printf("Enter age of %d employee:",i);
	scanf("%d",&a[i].age);
	printf("Enter Designation of %d employee:",i);
	scanf("%s",&a[i].desi);
	printf("Enter salary of %d employee:",i);
	scanf("%d",&a[i].salary);
	printf("Enter Department Name of %d employee:",i);
	scanf("%s",&a[i].d.dept);
	printf("Enter Department Number of %d employee:",i);
	scanf("%d",&a[i].d.dep);
}
printf("Please choose how you to get information of Employee:\n1.By Entering Department Number.\n2.By Entering Department Name.\n");
scanf("%d",&ser);
search(ser);
}
void search (int ser)
{
	int i,depn,t=0;
	char depname[20];
	if(ser==1)
	{
		printf("Enter Department Number of Employee:");
	    scanf("%d",&depn);
for(i=1;i<=10;i++)
{

if (a[i].d.dep==depn)
{
	printf("The ID of employee is: %d\n",a[i].id);
	printf("The SSN of employee is: %d\n",a[i].ssn);
	printf("The age of employee is: %d\n",a[i].age);
	printf("The Designation of employee is: %s\n",a[i].desi);
	printf("The Salary of employee is: %d\n",a[i].salary);
	printf("-----------------------");
	t++;
}
}
}
if(ser==2)
{
	printf("Enter Department Name of Employee:");
	    scanf("%s",&depname);
    for(i=1;i<=10;i++)
{

if (strcmp(a[i].d.dept,depname)==0)
{
	printf("The ID of employee is: %d\n",a[i].id);
	printf("The SSN of employee is: %d\n",a[i].ssn);
	printf("The age of employee is: %d\n",a[i].age);
	printf("The Designation of employee is: %s\n",a[i].desi);
	printf("The Salary of employee is: %d\n",a[i].salary);
	printf("---------------------");
	t++;
}
}
}
if(t==0)
printf("You have enterd wrong Department name or Number");
}

