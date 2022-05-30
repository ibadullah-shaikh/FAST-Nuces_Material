#include<stdio.h>
#include<conio.h>
main()
{
	int a;
	int b;
	printf("Enter First Number:");
	scanf("%d", &a);
	printf("Enter Second Number:");
	scanf("%d", &b);
	if (a>b)
{
	printf("First Number is greater than Second Number");
}
	else if (a<b)
{
	printf("Second Number is greater than First Number");
}
	else if (a=b)
{
	printf("First Number is Equal Second Number");
}
	else 
{
	printf ("First Number is not equal to Second Number");
};
	getch();
	
}
