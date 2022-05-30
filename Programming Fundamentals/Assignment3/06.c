/*
• Assignment No = 06
• Section = G
• Std.Id = 19k-0362 
• Name = Areez Arsalan
*/
#include<stdio.h>
#include<string.h>
void main()
{
  int i,wc=0,c=0;
  char word[100];
  char ch;
  FILE *fpt;
  fpt=fopen("paragraph.txt","w");
  printf ("Enter a few lines of text:\n" ) ;
while ( strlen ( gets ( word ) ) > 0 )
{
fputs ( word, fpt );
fputs ( "\n", fpt );
}
  fclose(fpt);
fpt=fopen("paragraph.txt","r");
while ((ch = fgetc(fpt)) != EOF)
{
if (ch != ' ' && ch != '\n')
c++;	

if (ch==' ' || ch=='\n')
	wc++;
}
fclose(fpt);
printf("Total words:%d\n",wc);
printf("Total chars:%d",c);
}
