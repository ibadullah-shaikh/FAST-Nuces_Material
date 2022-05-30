#include<stdio.h>
int main()
{
    int x=10;
    float y=11.3;
    char z='c';    
    int *p=&x;
    float *pfloat=&y;
    char *pchar=&z;
    func1(&x,&y,&z);
    printf("%d,%.2f,%c",x,y,z);
}

func1(int *p1,float *p2, char *p3)
{
 printf("Enter num");
 scanf("%d",&*p1);
 
 *p2=3.33;
 *p3='A';   
}
