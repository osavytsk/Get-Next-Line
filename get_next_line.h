

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 666

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct			s_gnl
{
	char    			buf[BUFF_SIZE + 1];
	int     			ret;
    int                 fd;
	char    			*tmp;
	struct s_gnl		*next; 
}						t_gnl;

int						get_next_line(const int fd, char **line);

#endif