#include<stdio.h>
#include<conio.h>
main()
{
	char a;
	printf("Enter any Input:");
	scanf("%c", &a);
	
	if (a>='0' && a<='9')
{
	printf("The Entered Input is Digit");
}
	else if (a>='a' && a<='z')
{
	printf("The Entered Input is Alphabet");
}
	else if (a>='A' && a<='Z')
{
	printf("The Entered Input is Upper Case Alphabet");
}
	else 
{
	printf("The Entered Input is Special Character");
};
	getch();
	
}
