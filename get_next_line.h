/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 21:31:24 by osavytsk          #+#    #+#             */
/*   Updated: 2018/01/14 21:31:32 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct			s_gnl
{
	char				buf[BUFF_SIZE + 1];
	int					ret;
	int					fd;
	char				*tmp;
	char				*s1;
	char				*s2;
	struct s_gnl		*next;
}						t_gnl;

int						get_next_line(const int fd, char **line);

#endif
