/*
• Assignment No = 03
• Section = G
• Std.Id = 19k-0362 
• Name = Areez Arsalan
*/
#include<stdio.h>
void main ()
{
int arr[5],i,curr,pre;
printf("Enter Five Numbers:\n");
for (i=0;i<5;i++)
{
scanf("%d",&arr[i]);
}
pre = arr[0]; 
arr[0] = arr[0] * arr[1]; 
   
    for (i=1; i<4; i++) 
    {
	curr = arr[i]; 
    arr[i] = pre * arr[i+1];   
    pre = curr; 
    } 
    arr[4]=curr*arr[4];
    printf("New Array\n");
for(i=0;i<5;i++)
printf("%d\n",arr[i]);
}

