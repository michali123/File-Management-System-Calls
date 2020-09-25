#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "unistd.h"

void main(int argc, char* argv[]) {
	
	int child_one = fork(), child_two ;
	int status;
	if (child_one < 0){ //child one could not be exectued
		perror("fork");
			return;
	}
	else if (child_one == 0 ){
		printf ("I am child one, my PID is: %d \n", getpid());
	} else { // creating child_two inside the the parent block
		child_two = fork();
		if (child_two < 0){
			perror("fork");
			return;
			
		} else if (child_two == 0) {
			printf ("I am child two, my PID is: %d \n", getpid());

		} else{
		int pid_one = waitpid(child_one, &status ,0);
		printf("child one termninated with status: %d \n", pid_one);
		int pid_two = waitpid(child_two, &status ,0);
 		printf("child two termninated with status: %d \n", pid_two);
	
		}
	}
	
	return 0;
	
}
