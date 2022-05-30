#include<stdio.h>
#include<conio.h>
main()
{
	int number1;
	int number2;
	
	printf("Enter Number 1: ");
	scanf("%d", &number1);
	
	printf("Enter Number 2: ");
	scanf("%d", &number2);
	
	printf("Number1>Number2 %d", number1>number2);
	printf("\nNumber1<Number2 %d", number1<number2);
	printf("\nNumber1>=Number2 %d", number1>=number2);
	printf("\nNumber1<=Number2 %d", number1<=number2);
	printf("\nNumber1==Number2 %d", number1==number2);
	
	getch();
}
