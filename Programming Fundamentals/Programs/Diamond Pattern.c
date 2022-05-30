#include<stdio.h>
main()
{
	int i,j,k,n;
	printf("Enter no. of Rows:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			printf(" ");
		}
		for(k=1;k<(i*2)-1;k++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	for(i=n;i>0;i--)
	{
		for(j=0;j<n-i;j++)
		{
			printf(" ");
		}
		for(k=1;k<(i*2)-1;k++)
		{
			printf("*");
		}
		printf("\n");
	}
}
