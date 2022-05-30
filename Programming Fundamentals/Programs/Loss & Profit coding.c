#include<stdio.h>
main()
{
	int cprice;
	int sprice;
	int profit;
	int loss;
	printf("Enter the Cost Price of an Item:");
	scanf("%d", &cprice);
	printf("Enter the Selling Price of that Item:");
	scanf("%d", &sprice);
	
	if (sprice>cprice)
	{
		profit=sprice-cprice;
		printf("The profit is: Rs.%d", profit);
	}
	else 
	{
		loss=cprice-sprice;
		printf("The loss is: Rs.%d", loss);
	}
	return(0);
	
}
