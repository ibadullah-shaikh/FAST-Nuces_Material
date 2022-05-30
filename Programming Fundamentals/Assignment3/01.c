/*
• Assignment No = 01
• Section = G
• Std.Id = 19k-0362 
• Name = Areez Arsalan
*/
#include<stdio.h>
void main ()
{
int num[5],i,max=-999,min=999,dif;
printf("Enter Five Numbers:\n");
for (i=0;i<5;i++)
{
scanf("%d",&num[i]);
if(num[i]>max)
max=num[i];
if(num[i]<min)
min=num[i];
}
printf("Max is:%d\n",max);
printf("Min is:%d\n",min);
printf("The maximum difference is: %d",max-min);
}
