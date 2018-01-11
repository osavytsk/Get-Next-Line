#include "get_next_line.h"
#include <stdio.h>



// int	main(void){
//
// 	char *line;
//
// 	int fd[3];
//
//     fd[0] = open("/Users/osavytsk/gnl/qwe1.txt", O_RDONLY);
//     fd[1] = open("/Users/osavytsk/gnl/qwe2.txt", O_RDONLY);
//     fd[2] = open("/Users/osavytsk/gnl/qwe3.txt", O_RDONLY);
//
//     int i = 0;
//     while (i < 3 && get_next_line(fd[i], &line)) {
//         printf("%s\n", line);
//         free(line);
//         i = ( i == 2 ? 0 : i + 1);
//     }
//
////     if (line == NULL)
////         printf("line = %s\n", line);
////     free(line);
//
////     while (get_next_line(fd2, &line) > 0) {
////         printf("%s\n", line);
////         free(line);
////     }
////
////     while (get_next_line(fd3, &line) > 0) {
////         printf("%s\n", line);
////         free(line);
////     }
//
////    get_next_line(fd1, &line);
////    printf("%d\n", strcmp(line, "aaa"));
////    get_next_line(fd1, &line);
////    printf("%d\n", strcmp(line, "bbb"));
////    get_next_line(fd1, &line);
////    printf("%d\n", strcmp(line, "ccc"));
////    get_next_line(fd1, &line);
////    printf("%d\n", strcmp(line, "ddd"));
//	 close(fd[0]);
//	 close(fd[1]);
//	 close(fd[2]);
////    while (1);
// 	return 0;
// }



int main(void) {
    int ret;
    char *line_fd0;
    int p_fd0[2];
    int fd0 = 0;
    int out_fd0 = dup(fd0);

    char *line_fd1;
    int p_fd1[2];
    int fd1 = 1;
    int out_fd1 = dup(fd1);

    char *line_fd2;
    int p_fd2[2];
    int fd2 = 2;
    int out_fd2 = dup(fd2);

    char *line_fd3;
    int p_fd3[2];
    int fd3 = 3;
    int out_fd3 = dup(fd3);

    pipe(p_fd0);
    dup2(p_fd0[1], fd0);
    write(fd0, "aaa\nbbb\n", 8);
    dup2(out_fd0, fd0);
    close(p_fd0[1]);

    pipe(p_fd1);
    dup2(p_fd1[1], fd1);
    write(fd1, "111\n222\n", 8);
    dup2(out_fd1, fd1);
    close(p_fd1[1]);

    pipe(p_fd2);
    dup2(p_fd2[1], fd2);
    write(fd2, "www\nzzz\n", 8);
    dup2(out_fd2, fd2);
    close(p_fd2[1]);

    pipe(p_fd3);
    dup2(p_fd3[1], fd3);
    write(fd3, "888\n000\n", 8);
    dup2(out_fd3, fd3);
    close(p_fd3[1]);

    ret = get_next_line(p_fd0[0], &line_fd0);
    printf("aaa = %d\n", strcmp(line_fd0, "aaa"));
    printf("%d\n", ret);

    ret = get_next_line(p_fd1[0], &line_fd1);
    printf("111 = %d\n", strcmp(line_fd1, "111"));
    printf("%d\n", ret);

    ret = get_next_line(p_fd2[0], &line_fd2);
    printf("www = %d\n", strcmp(line_fd2, "www"));
    printf("%d\n", ret);

    ret = get_next_line(p_fd3[0], &line_fd3);
    printf("888 = %d\n", strcmp(line_fd3, "888"));
    printf("%d\n", ret);

    ret = get_next_line(p_fd0[0], &line_fd0);
    printf("bbb = %d\n", strcmp(line_fd0, "bbb"));
    printf("%d\n", ret);

    ret = get_next_line(p_fd1[0], &line_fd1);
    printf("222 = %d\n", strcmp(line_fd1, "222"));
    printf("%d\n", ret);

    ret = get_next_line(p_fd2[0], &line_fd2);
    printf("zzz = %d\n", strcmp(line_fd2, "zzz"));
    printf("%d\n", ret);

    ret = get_next_line(p_fd3[0], &line_fd3);
    printf("999 = %d\n", strcmp(line_fd3, "000"));
    printf("%d\n", ret);
    return 0;
}