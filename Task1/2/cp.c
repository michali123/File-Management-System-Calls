#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char* argv[]) {
if(!argv[1] || !argv[2]){
    printf("Error. Not enough arguments\n");
    return 0;
  }
  
  int buff_size = 2000;
  char *buffer[buff_size];
  //source
  int srcFD = open(argv[1], O_RDONLY);
  // destination
  int destFD = open(argv[2], O_CREAT | O_WRONLY );
  // number of bytes to be written into destination
		int bytes = read(srcFD,buffer,buff_size);
		if(write(destFD, buffer, bytes) == -1){
			perror("Oops there's an error"); /* This will explain why */
			return;
			//printf("Error writing to file\n");
		}
		printf("Writing content from: %s", argv[1]);
		printf(" to %s was executed succsseufly.\n", argv[2]);
		 close(srcFD);
		 close(destFD);
  return 0;
		
}