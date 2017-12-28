

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 600

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

// typedef struct			s_gnl
// {
// 	char				*buff;
// 	struct s_gnl		*next; 
// }						l_gnl;

int						get_next_line(const int fd, char **line);

#endif