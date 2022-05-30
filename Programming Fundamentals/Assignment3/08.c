/*
• Assignment No = 08
• Section = G
• Std.Id = 19k-0362 
• Name = Areez Arsalan
*/
#include<stdio.h>
void main()
{
	int num,min=0,sec=0,hours=0,day=0;
	printf("Enter seconds:");
	scanf("%d",&num);
	if(num>60)
{
	min=num/60;
	sec=num%60;
}
	if(min>60)
{
	hours=min/60;
	min=num%60;
}
	if(hours>24)
	{
	day=hours/24;
	hours=num%60;
   }
	printf("%d seconds is equivalent to %d Days, %d hours %d Minutes %d seconds",num,day,hours,min,sec);
	
}
