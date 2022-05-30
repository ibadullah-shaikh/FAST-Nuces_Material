#include<stdio.h>
#include<conio.h>
int main()
{
	int i,n,age,exp,hrs,sal;
	printf("Enter the Number of Employees:");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		printf("Enter the age of %d Employee:", i);
		scanf("%d",&age);
		printf("Enter the Experience of %d Employee:", i);
		scanf("%d",&exp);
		printf("Enter the Working Hours of %d Employee:", i);
		scanf("%d",&hrs);
		if (age>50 && exp>10 && hrs>240)
		{
			sal=hrs*500;
			printf("Salaray of %d Employee is:%d\n\n",i,sal);
		}
		else if (age>40 &&age<=50 && exp>6 &&exp<=10 && hrs>200&&hrs<=240)
		{
			sal=hrs*425;
			printf("Salaray of %d Employee is:%d\n\n",i,sal);
		}
		else if (age>30 &&age<=40 && exp>3 &&exp<=6 && hrs>160&&hrs<=200)
		{
			sal=hrs*375;
			printf("Salaray of %d Employee is:%d\n\n",i,sal);
		}	
		else if (age>22 &&age<=30 && exp>1 &&exp<=3 && hrs>120&&hrs<=160)
		{
			sal=hrs*300;
			printf("Salaray of %d Employee is:%d\n\n",i,sal);
		}
		else 
		printf("Invalid Parameters...");
	}
	
	getch();
}
