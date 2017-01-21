#include <stdio.h>
int main()
{
	FILE * read_file = fopen("smalltextfile.txt","r");
	FILE * write_file = fopen("newtextfile.txt","a");

	char c;
	while((c=fgetc(read_file))!=EOF)
	{
		putchar(c);
		fputc(c,write_file);
	}
	remove("newtextfile.txt");
	fclose(write_file);
	fclose(read_file); 
	return 0;
}