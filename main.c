#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void){

	char *line;

	int fd1;

    fd1 = open("/Users/osavytsk/gnl/qwe1.txt", O_RDONLY);

    while (get_next_line(fd1, &line) > 0) {
        printf("%s\n", line);
        free(line);
    }


//    get_next_line(fd1, &line);
//    printf("%d\n", strcmp(line, "aaa"));
//    free(line);
//    get_next_line(fd1, &line);
//    printf("%d\n", strcmp(line, "bbb"));
//    free(line);
//    get_next_line(fd1, &line);
//    printf("%d\n", strcmp(line, "ccc"));
//    free(line);
//    get_next_line(fd1, &line);
//    printf("%d\n", strcmp(line, "ddd"));
//    free(line);
//    while (1);
	close(fd1);
	return 0;
}