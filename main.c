#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void){

	char *line;

	int fd1;

    fd1 = open("/Users/osavytsk/gnl/qwe1.txt", O_RDONLY);

    get_next_line(fd1, &line);
    printf("%d\n", strcmp(line, "aaa"));
    get_next_line(fd1, &line);
    printf("%d\n", strcmp(line, "bbb"));
    get_next_line(fd1, &line);
    printf("%d\n", strcmp(line, "ccc"));
    get_next_line(fd1, &line);
    printf("%d\n", strcmp(line, "ddd"));
	close(fd1);
	return 0;
}