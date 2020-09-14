#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "unistd.h"

int main() {
	// giving permission to the text file to read and write and read only as well.
	int fd = open("destination.txt", O_RDONLY | O_WRONLY | O_CREAT);
	// if file is not in the directory then file "destination" is created.
	if (fd < 0) /* ah, there's an error */
	{
		printf("sorry, I couldn't open filename\n");
		perror("open"); /* This will explain why */
		return;
	}
	else {
		printf("Open() Successful, fd value is : %d \n", fd);
		}
	//closing the file.
	close(fd);
	return 0;
}