#include<stdio.h>
main()
{
	int count;
	int grade;
	int average;
	int total;
	total=0;
	count=1;
	while(count<=10)
	{
	printf("Enter Student's Grade:");
	scanf("%d", &grade);
	total=total+grade;
	count=count+1;
	//grade++;
	}
	average=total/10;
	printf("Class average is: %d", average);
	return(0);
}
