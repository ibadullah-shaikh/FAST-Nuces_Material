#include<stdio.h>
#include<conio.h>
main()
{
	int age;
	printf("Enter Age:");
	scanf("%d",&age);
	if (age<=11)
{
	printf("pay RS.20");
}
	else if (age>11 && age<65)
{
	printf("pay RS. 50");
}
	else 
{
	printf("pay RS. 30");
};
	getch();
	
	
	
	
	
}
