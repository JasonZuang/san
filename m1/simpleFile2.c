/*
	I used the unix manuals for research on these function calls.
	I also used some online resources:
	http://www.techytalk.info/linux-system-programming-open-file-read-file-and-write-file/comment-page-1/
	http://www.makelinux.net/books/lkd2/ch05lev1sec3
*/

//needed to include all this in order to do the system calls.
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	ssize_t read_in; //used to store the the ssize_t returned by the read system call function
	char charArrayStorage [8]; //the char array buffer for reading in the chars. I gave it an arbitray value of 8
	int input = open("smalltextfile.txt",O_RDONLY);
	int output = open("newtextfile.txt",O_WRONLY|O_CREAT|O_APPEND,0666);

	while((read_in = read(input,&charArrayStorage,8))>0)
	{
		write(output,charArrayStorage,read_in);//writing to the the new file
		write(1,charArrayStorage,8);//writing to the terminal
	}
	unlink("newtextfile.txt");//deletes the new text file
	close(input);
	close(output);

	return 0;
}