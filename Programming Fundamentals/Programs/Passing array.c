#include<stdio.h>
void array (int num[][2][2],int size);
void main ()
{	
int num[2][2][2];
int size=2;
array(num,size);
}
void array (int num[][2][2],int size)
{

int i,j,k;
for (i=0;i<size;i++)
{
	for(j=0;j<2;j++)
{
    for(k=0;k<2;k++)
    {
	
printf("Enter the element of Array [%d][%d][%d]:",i,j,k);
scanf("%d",&num[i][j][k]);
}
}
}
}

