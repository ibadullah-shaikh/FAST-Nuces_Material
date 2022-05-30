#include<stdio.h>
#include<string.h>
main()
{
	int len,*l;
	char name[]="IBADULLAH",*ptr;
	ptr=&name[0];
	//len=strrev(ptr);
	//l=&len;
	printf("Reverse:%s",strrev(ptr));
}
