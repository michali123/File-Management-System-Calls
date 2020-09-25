#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "unistd.h"

void main(int argc, char* argv[]) {
	char* filepath = "source.txt";
	int returnVal;
	//check file existance 
	returnVal = access(filepath, F_OK);
	if (returnVal == 0)
		printf("\n %s exists\n", filepath);
	else {
		if (errno == ENOENT)
			printf("%s does not exist\n", filepath);
		else if (errno == EACCES)
			printf("%s is not accessible\n", filepath);
		return 0;
	}
	/* Check read access. */
	returnVal = access(filepath, R_OK);
	if (returnVal == 0)
		printf("%s is readable\n",filepath);
	else
		printf("%s is not readable (access denied)\n", filepath);

	/* Check write access. */
	returnVal = access(filepath, W_OK);
	if (returnVal == 0)
		printf("%s is writable\n", filepath);
	else if (errno == EACCES)
		printf("%s is not writable (access denied)\n", filepath);
	else if (errno == EROFS)
		printf("%s is not writable (read-only filesystem)\n", filepath);
	return 0;


}


