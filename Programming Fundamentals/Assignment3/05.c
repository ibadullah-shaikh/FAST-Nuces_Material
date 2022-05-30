/*
• Assignment No = 05
• Section = G
• Std.Id = 19k-0362 
• Name = Areez Arsalan
*/
#include<stdio.h>
#include<stdio.h>
void check(int num[],int n);
void main()
{
	int num[5],n,i;
	printf("Enter number:");
	scanf("%d",&n);
	printf("Now Enter numbers of Array:\n");
	for(i=0;i<5;i++)
	scanf("%d",&num[i]);
	check(num,n);
}
void check(int num[],int n)
{
	int i,index,t;
	for(i=0;i<5;i++)
	{
		if(num[i]==n)
		{
		index=i;
		t++;
	    }
} 
if(t==1)
printf("Index is: num[%d]",index+1);
else
printf("Error value not found in Array.");
}
