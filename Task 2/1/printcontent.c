#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
int main() {
int fd;
fd = open ("check.txt",  O_CREAT| O_RDWR);
char msg[120] = "You can discover more about a person in an hour of play than in a year of conversation. by Plato";

if (fd < 0) /* ah, there's an error */
	{
		printf("sorry, can not open filename\n");
		perror("open"); /* This will explain why */
		return;
	}
	else{
		printf ("\n check.txt opened with read and write access.\n");
		write (fd, msg, sizeof(msg));
		read(fd, msg, sizeof(msg));
		printf("%s - was written to check.txt file.\n", msg);
		close(fd);
		
	}
	return 0;
}
	




