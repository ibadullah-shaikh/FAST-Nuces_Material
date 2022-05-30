#include<stdio.h>
main()
{
	int i,n, a,sum;
	float ave;
	printf("Enter the n Numbers you want to find Average:");
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the Number:");
		scanf("%d", &a);
		sum=sum+a;
		printf("\n");
	};
	ave=sum/n;
	printf("Averge is: %f", ave);
	return(0);
}
