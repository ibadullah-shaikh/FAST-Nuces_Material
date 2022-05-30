#include<stdio.h>
void main ()
{
	int n,i,r=0;
	printf("Enter a number:");
	scanf("%d",&n);
	while(n!=0)
	{
	
		r=r*10;
		r=r+n%10;
		n=n/10;
		i++;
    }  
printf("Total num: %d",r);
}
