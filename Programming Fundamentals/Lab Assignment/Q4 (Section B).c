#include<stdio.h>
void main()
{
	int i,n,m;
	int arr[10]={1,2,3,4,5};
	printf("Queue is:");
	for(i=0;i<5;i++)
	{
		printf("%d ",arr[i]);
	}
	
	printf("\nWhat do you want to do ?\n1.Add Number in Queue?\n2.Delete Number from Queue?\nYour Choice:");
	scanf("%d",&n);
	
	switch (n)
	{
		case 1:
			{
			printf("Enter Number to add:");
			scanf("%d",&m);
			printf("Queue is:");
			for(i=0;i<5;i++)
			{
				printf("%d ",arr[i]);
			}
			printf("%d",m);
			break;
			}
			
		case 2:
			{
				printf("Queue after deleting a number is:");
				for(i=1;i<5;i++)
				{
					printf("%d ",arr[i]);
				}
				break;
			}
			
			default:
			printf("Invalid Choice...");
			
	}
	
}
