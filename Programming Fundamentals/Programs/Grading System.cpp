#include<stdio.h>
int main()
{
	int total,marks, mid1, mid2, assignment, quiz, final;
	printf("Enter Student's Mid 1 Marks:");
	scanf("%d", &mid1);
	printf("Enter Student's Mid 2 Marks:");
	scanf("%d", &mid2);
	printf("Enter Student's Assignment Marks:");
	scanf("%d", &assignment);
	printf("Enter Student's Quiz Marks:");
	scanf("%d", &quiz);
	printf("Enter Student's Final Marks:");
	scanf("%d", &final);
	
	total= mid1+mid2+assignment+quiz+final;
	printf("Student's total Marks are: %d", total);
	
	if(total>=90)
{	
	if(total<=100)
	{
	printf("\nA1 Grade");
	}
}
	else if(total>=80)
{
	if(total<90)
	{
	printf("\nA Grade");
	}
}
	else if(total>=70)
{
	if (total<80)
	{
	printf("\nB Grade");
	}
}
	else if(total>=60)
{
	if(total<70)
	{
	printf("\nC Grade");
	}
}
	else if(total>=50)
{
	if(total<60)
	{
	printf("\nD Grade");
	}
}
	else if(total<50)
{
	printf("\nSorry You are Fail");
}
	else 
{
	printf("\nInvalid Marks");
};
	return(0);
}
