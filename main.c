#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void){

	char *line;

	int fd1;

    fd1 = open("/Users/osavytsk/gnl/test", O_RDONLY);

	while(get_next_line(fd1, &line) > 0) {
		printf("RESULT\t%s\n==========\n", line);
	}
	close(fd1);
	return 0;
}