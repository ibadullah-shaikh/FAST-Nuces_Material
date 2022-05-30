#include<stdio.h>
#include<conio.h>
main ()
{
	int number1;
	int number2;
	float a;
	float b;
	char ch1;
	char ch2;
	
	
	printf("Enter Number 1: ");
	scanf("%d", &number1);
	printf("Enter Number 2: ");
	scanf("%d", &number2);
	
	printf("Enter Float 1: ");
	scanf("%f", &a);
	printf("Enter Float 2: ");
	scanf("%f", &b);
	
	printf("Enter Character 1: ");
	scanf(" %c", &ch1);
	printf("Enter Character 2: ");
	scanf(" %c", &ch2);
	
	printf("Arthematic Operations on Intergers");
	printf("\nNumber1 + Number2 %d", number1+number2);
	printf("\nNumber1 - Number2 %d", number1-number2);
	printf("\nNumber1 * Number2 %d", number1*number2);
	printf("\nNumber1 / Number2 %d", number1/number2);
		
	printf("\nArthematic Operations on Floats");
	printf("\nFloat1 + Float2 %f", a+b);
	printf("\nFloat1 - Float2 %f", a-b);
	printf("\nFloat1 * Float2 %f", a*b);
	printf("\nFloat1 / Float2 %f", a/b);
	
	printf("\nArthematic Operations on Characters");
	printf("\nCharacter1 + Character2 %c", ch1+ch2);
	printf("\nCharacter1 - Character2 %c", ch1-ch2);
	printf("\nCharacter1 * Character2 %c", ch1*ch2);
	printf("\nCharacter1 / Character2 %c", ch1/ch2);
	
	getch();
}
