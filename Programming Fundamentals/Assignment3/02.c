/*
• Assignment No = 02
• Section = G
• Std.Id = 19k-0362 
• Name = Areez Arsalan
*/
#include<stdio.h>
#include<stdlib.h>
int sort (int num[],int c);
void main ()
{
	int num[5],c,i;
	printf("Enter Five Numbers:\n");
for (i=0;i<5;i++)
{
scanf("%d",&num[i]);
}
printf("Please choose:\n1.Ascending order\n2.Descending order\n");
scanf("%d",&c);
sort(num,c);
printf("The Sorted Array is:\n");
for (i=0;i<5;i++)
{
printf("%d\n",num[i]);
}

}
int sort (int num[],int c)
{
int i,j,temp,t;
if(c==1)
{
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		if(num[i]>num[j])
		{
			temp=num[i];
			num[i]=num[j];
			num[j]=temp;
			t++;
		}
	}
}	

if(c==2)
{
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		if(num[i]<num[j])
		{
			temp=num[i];
			num[i]=num[j];
			num[j]=temp;
			t++;
		}
	}
}	

if(t==0)
{
printf("Error,you entered wrong choice.");	
exit(1);
}
}
