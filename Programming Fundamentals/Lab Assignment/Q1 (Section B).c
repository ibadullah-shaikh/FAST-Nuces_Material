#include<stdio.h>
int main()
{
	int i,j;
	int arr1[3][3];
	int arr2[3][3];
	
	printf("Enter 9 Elements in First Matrix:");
	for (i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d", &arr1[i][j]);
		}
	}
	
	for(i=2;i>=0;i--)
	{
		for(j=2;j>=0;j--)
		{
			arr2[2-i][2-j]=arr1[i][j];
		}
	}
	system("cls");
	
	
	printf("Entered Matrix is:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}
	
	
	printf("Arranged Matrix:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
