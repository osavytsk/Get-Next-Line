

#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>
#include "get_next_line.h"


int     get_next_line(const int fd, char **line)
{
    char	buf[BUFF_SIZE + 1];
    int		ret;
    size_t			index;
	static  char	*tmp;
    int     flag;
    char    *s;

//    ft_strclr(*line);
    ft_bzero(buf, BUFF_SIZE + 1);
    ret = 1;
    index = 0;
    flag = 0;
    *line = NULL;
    if (!line || fd == -1 || BUFF_SIZE < 1)
        return (-1);
    if (tmp != NULL)
    {
        while (tmp[index] != '\n' && tmp[index] != '\0')
            index++;
        if (tmp[index] == '\n')
            flag = 1;
        *line = ft_strsub(tmp, 0, index);
        s = ft_strsub(tmp, (unsigned int) index + 1, (ft_strlen(tmp) - index));
        free(tmp);
        tmp = s;
        if (flag == 1)
            return (1);
    }
    index = 0;
    while (ret > 0)
    {
        ret = (int) read(fd, buf, BUFF_SIZE);
        if (ft_strchr(buf, '\n') == NULL)
        {
            s = ft_strjoin(*line ? *line : "" , buf);
            if (*line)
                free(*line);
            *line = s;
        }
        else 
        {
            while (buf[index] != '\n' && buf[index] != '\0')
                index++;
            s = ft_strjoin(*line ? *line : "", ft_strsub(buf, 0, index));
            if (*line)
                free(*line);
            *line = s;
            s = ft_strsub(buf, (unsigned int) (index + 1), (ft_strlen(buf) - index));
            if (tmp)
                free(tmp);
            tmp = s;
//            if (tmp[0] == '\0' && buf[0] == '\0')
//                return 0;
//            else
                return 1;

        }
    }
    if (ret == 0 && *line[0] != '\0')
        return 1;
    return -1;
}
