/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:10:55 by soleksiu          #+#    #+#             */
/*   Updated: 2017/12/13 14:35:48 by soleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>
#include "get_next_line.h"


int     get_next_line(const int fd, char **line)
{
    char	buf[BUFF_SIZE + 1];
    int				ret;
    size_t			index;
	static  char	*tmp;

    ft_strclr(*line);


	// if (!*line)
	// 	ft_strnew(0);
    ret = 1;
    index = 0;
    if (fd == -1 || BUFF_SIZE < 1)
        return (-1);
    if (buf[0])
           *line = ft_strjoin(*line, buf);

    while (ret > 0)
    {
        ret = read(fd, buf, BUFF_SIZE);
        if (ft_strchr(buf, '\n') == NULL) {
            *line = ft_strjoin(*line, buf);
        }
        else 
        {
            while (buf[index] != '\n')
            {
                index++;
            }
            *line = ft_strjoin(*line, ft_strsub(buf, 0, index));
            tmp = ft_strsub(buf, index + 1, BUFF_SIZE - index);
            ft_bzero((void *)buf, BUFF_SIZE);
            ft_strcat(buf, tmp);
    		printf("BUF\t%s\n", buf);
            printf("TMP\t%s\n", tmp);
            printf("LIN\t%s\n", *line);
            return 1;
        }
    }
    // printf("BUF\t%s\n", buf);
    // if (ret == 0)
    // {
    // 	*line = ft_strdup(buf);
    //     return (0);
    // }
    // else if (ret == -1)
    //     return (-1);
}

