#include<stdio.h>
#include<conio.h>
#include<string.h>

void mysubstring (char []);
int main()
{
	char arr[50];
	printf("Enter a String:");
	gets(arr);
	
	mysubstring(arr);
}
void mysubstring (char arr[])
{
	int i,j;
	
	j=strlen(arr);
	printf("\nSubstrings are:\n");
	for (i=0;i<j;i++)
	{
		printf("%c",arr[i]);
		if(arr[i]==' ')
		printf("\n");
	}
	
}
