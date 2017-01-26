#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	clock_t t1,t2;
	FILE * time_file = fopen("timing.txt","a");

	t1 = clock();
	//C code for 385 byte file
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


	t2 = clock();
	fprintf(time_file,"Time for C code for 385 bytes: %f \n",((float)t2)-((float)t1));

	t1 = clock();
	
	//code for system call for 385 byte file
	ssize_t read_in; 	char charArrayStorage [8]; 
	int input = open("smalltextfile.txt",O_RDONLY);
	int output = open("newtextfile.txt",O_WRONLY|O_CREAT|O_APPEND,0666);

	while((read_in = read(input,&charArrayStorage,8))>0)
	{
		write(output,charArrayStorage,read_in);
		write(1,charArrayStorage,8);
	}
	unlink("newtextfile.txt");
	close(input);
	close(output);

	t2 = clock();
	fprintf(time_file,"Time for system call code for 385 bytes: %f \n",((float)t2)-((float)t1));

	//Code for the 2 MB text file

	t1 = clock();
	
	//C code for 2 megabyte file
	read_file = fopen("largetextfile.txt","r");
	write_file = fopen("newtextfile.txt","a");

	while((c=fgetc(read_file))!=EOF)
	{
		putchar(c);
		fputc(c,write_file);
	}
	remove("newtextfile.txt");
	fclose(write_file);
	fclose(read_file); 


	t2 = clock();
	fprintf(time_file,"Time for C code for 2 megabytes: %f \n",((float)t2)-((float)t1));

	t1 = clock();
	
	//code for system call for 2 megabyte file 
	input = open("largetextfile.txt",O_RDONLY);
	output = open("newtextfile.txt",O_WRONLY|O_CREAT|O_APPEND,0666);

	while((read_in = read(input,&charArrayStorage,8))>0)
	{
		write(output,charArrayStorage,read_in);
		write(1,charArrayStorage,8);
	}
	unlink("newtextfile.txt");
	close(input);
	close(output);

	t2 = clock();
	fprintf(time_file,"Time for system call code for 2 megabytes: %f \n",((float)t2)-((float)t1));


}	