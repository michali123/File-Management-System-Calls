#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "unistd.h"

void main(int argc, char* argv[]) {


//parent P
int a = 10, b = 25, fq = 0, fr = 0;
fq = fork(); // fork a child - call it Process Q
if (fq < 0){ //fq could not be exectued
		perror("fork");
			return;
	}
if(fq == 0){ // Child successfully forked
	a = a + b;
    printf("Process Q - Value of a: %d, Value of b: %d, Value of pid: %d\n", a, b, getpid());
	fr=fork();// fork another child - call it Process R
	if (fr < 0){ //fr could not be exectued
		perror("fork");
			return;
	}
	
	else if(fr!=0){
	b = b + 20;
	printf("Process Q - Value of a: %d, Value of b: %d, Value of pid: %d\n", a, b, getpid());

	}else{
	a = (a*b) + 30;
	printf("Process R - Value of a: %d, Value of b: %d, Value of pid: %d\n", a, b, getpid());
	}
}else{
	b = a + b - 5;
	printf("Process P - Value of a: %d, Value of b: %d, value of pid: %d\n", a, b, getpid());
}

return;
}