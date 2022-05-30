#include<stdio.h>
#include<conio.h>
main()
{
	float a;
	float b;
	int bmi;
	
	printf("Enter you Height:");
	scanf("%f", &a);
	printf("Enter you Weight:");
	scanf("%f", &b);
	
	bmi= b*703/a*a;
	
	if (bmi<15)
{
	printf("Starvation");
}
	else if (bmi<17.5)
{
	printf("Anorexic");
}
	else if (bmi<18.5)
{
	printf("Underweight");
}
	else if (bmi>=18.5 && bmi<25)
{
	printf("Ideal");
}
	else if (bmi>=25 && bmi<30)
{
	printf("Overweight");
}
	else if (bmi>=30 && bmi<40)
{
	printf("Obese");
}
	else if (bmi>=40)
{
	printf("Morbidly");
};
	getch();
}
