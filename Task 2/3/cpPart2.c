#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]) {
if(!argv[1] || !argv[2]){
    printf("Error. Not enough arguments\n");
    return 0;
  }
  
  int fdSCR, fdTarget, buffSize = strlen(argv[1]);
  char buffer[2000];
  // open files
  fdSCR = open(argv[1],O_RDWR);
  
  if (fdSCR < 0) /* ah, there's an error */
	{
		printf("sorry, can not open filename\n");
		perror("open"); /* This will explain why */
		return;
	}
	
  fdTarget = open(argv[2], O_WRONLY | O_CREAT);
  if (fdTarget < 0) /* ah, there's an error */
	{
		printf("sorry, can not open filename\n");
		perror("open"); /* This will explain why */
		return;
	}

// number of bytes to be written into destination
		int charCount = 0; 
		while ((charCount = read(fdSCR,buffer,75)) > 0){
			int i = 0;
			while (i < charCount){
				if(buffer[i] == '5') 
					buffer[i] = 'O';
				i++;
			}
			write (fdTarget,buffer,charCount);
			write(fdTarget, "ABC", 3);
			
		}
	
		
		close(fdSCR);
		close(fdTarget);
		return 0;
		
}