#include<stdio.h>
#include<conio.h>
void main()
{
	int total;
	int tshirts;
	int formalshirts;
	int wristwatches;
	int ar;
	
	printf("\t\tSHOP OVER RS.3000 AND ENJOY 10%% DISCOUNT\n\n");
	printf("Enter total number of T-shirts purchased: ");
	scanf("%d", &tshirts);
	printf("Enter total number of Formal Shirts purchased: ");
	scanf("%d", &formalshirts);
	printf("Enter total number of Wrist Watches purchased: ");
	scanf("%d", &wristwatches);

	
	printf("\n\nTotal number of T-shirts purchased: %d", tshirts);
	printf("\nTotal number of Formal Shirts purchased: %d", formalshirts);
	printf("\nTotal number of Wrist Watches purchased: %d", wristwatches);
	total=(tshirts*500)+(formalshirts*1000)+(wristwatches*500);
	printf("\n\nTotal Amount: RS.%d", total);
	if (total>= 3000)

{

	printf("\nCongratulations! You have purchased items of over Rs.3000, Enjoy the 10%% discount on total.");
	ar=total*1/10;
	printf("\nAmount Returned to Customer RS: %d", ar);
}
	else 
	printf("\nPlease pay Total Amount:%d", total);
	

	
	
	getch();
	
}
