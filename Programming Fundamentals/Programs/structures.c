#include <stdio.h>

int main()
{

struct mystruct{
  int c;
  int x[3];
  char ch[5];
  int d2[2][2];
};

struct mystruct a;
   int i = 0;
   printf("plz enter the value of c:\n");
   scanf("%d",&a.c);
   
   while (i<3)
   {
       printf("\nPlease enter 3 values of x:");
       scanf("%d",&a.x[i]);
	    i++;
   }
   
   i=0;
    while (i<5)
   {
       printf("Please enter the lame char of charachters:");
       scanf("%c\n",&a.ch[i]);
	    i++;
   }  

    printf("\n");
fflush(stdin);
   int r,c;
   for(r=0;r<2;r++)
    {
        for(c=0;c<2;c++)
            {
               printf("Enter the %dx%d matrix element\n",r,c);
			   scanf("%d",&a.d2[r][c]); 
			   i++;
            }
            printf("\n");
    }
   
    return 0;
}
