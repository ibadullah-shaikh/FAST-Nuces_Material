#include<stdio.h>
main()
{
	int i=0, sum;
	do
	{
		sum=sum+i;
		i=i+1;
		printf("%d\n", i);
		i++;
		
	}
	while (i<50);
	printf("\nSum of Odd Number from 1 to 50 is:%d", sum);
	return(0);
}
