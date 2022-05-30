#include<stdio.h>
#include<conio.h>
main()
{
	float number1;
	float number2;
	char operations;
	
	printf("Enter the First Number:");
	scanf("%f", &number1);
	
	printf("Enter the Operation:");
	scanf(" %c", &operations);
	
	printf("Enter the Second Number:");
	scanf("%f", &number2);
	
	switch (operations)
{
		
	case '+':
	printf("Sum of Number1 and Number2 is: %f",number1+number2);
	break;
	
	case '-':
	printf("Subtraction of Number1 and Number2 is: %f",number1-number2);
	break;
	
	case '/':
	printf("Divison of Number1 and Number2 is: %f",number1/number2);
	break;
	
	case'*' :
	printf("Multiplication of Number1 and Number2 is: %f",number1*number2);
	break;


	default:
	printf("Invalid Operator");
}
	getch();
	
}
