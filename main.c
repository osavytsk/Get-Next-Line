#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void){

	char *line;

	int fd = open("qwe1.txt", O_RDONLY);

	while(get_next_line(fd, &line) > 0) {
		printf("RESULT\t%s\n==========\n", line);
	}
	close(fd);
	return 0;

}