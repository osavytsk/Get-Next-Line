#include "get_next_line.h"
#include <stdio.h>



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
//    get_next_line(fd1, &line);
//    printf("%d\n", strcmp(line, "bbb"));
//    get_next_line(fd1, &line);
//    printf("%d\n", strcmp(line, "ccc"));
//    get_next_line(fd1, &line);
//    printf("%d\n", strcmp(line, "ddd"));
	close(fd1);
//    while (1);
	return 0;
}