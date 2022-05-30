#include<stdio.h>
#include<conio.h>
main()
{
	char x;
	int y;
	float z;
	double p;
	
	
	//Enter Gender as M for (male) and F for (female)
	printf("Enter your Gender:");
	scanf("%c",&x);
	
	printf("Enter your Age:");
	scanf("%d",&y);
	
	printf("Enter Value of pie:");
	scanf("%f",&z);
	
	printf("Enter double:");
	scanf("%lf", &p);
	
	printf("%c", x);
	printf("\n\t %d", y);
	printf("\n\t\t %f", z);
	printf("\n\t\t\t %lf", p);
	
	getch();
	
}
