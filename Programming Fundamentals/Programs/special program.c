#include<stdio.h>
void main ()
{
int i,j,k,l;
for (i=1;i<=5;i++)
{			
for (j=i;j<=5;j++)
printf("*");
for (l=1;l<i;l++)
printf(" ");
for (k=1;k<i;k++)
printf(" ");
for (j=i;j<=5;j++)
printf("*");
printf("\n");
}
for (i=1;i<=5;i++)
{
for (k=1;k<=i;k++)
printf("*");
for (j=i;j<5;j++)
printf(" ");

for (l=i;l<5;l++)
printf(" ");
for (k=1;k<=i;k++)
printf("*");

printf("\n");
}
}





