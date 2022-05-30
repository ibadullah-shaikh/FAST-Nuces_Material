#include<stdio.h>
#include<conio.h>
int main()
{
	int n;
	int m,i,j=0,k=1,convert;
	printf("Enter the Decimal Number:");
	scanf("%f",&n);
	printf("Enter the Conversion Type...\n");
	printf("1.Binary\n2.Octal\n3.Hexa-Decimal\n\nYour Choice:");
	scanf("%d",&m);
	
	switch(m)
	{
		case 1:
		{
				convert=n;
				while(convert!=0)
				{
					i=convert%2;
					j=j+(i*k);
					convert=convert/2;
					j=j*10;
				}
				printf("Binary Conversion of %d is:%d",n,j);
				break;
		}
		
		case 2:
			{
				convert=n;
				while(convert!=0)
				{
					i=convert%8;
					j=j+(i*k);
					convert=convert/8;
					k=k*10;
				}
				printf("Octal Conversion of %d is:%d",n,j);
				break;
			}
			
			case 3:
				{
					printf("Hexa-Decimal Conversion of %d is:%x",n,n); 
					break;
				} 
				
			default:
			printf("Invalid...!!");
		}
			
}
	
	

