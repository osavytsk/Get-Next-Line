#include "get_next_line.h"

t_gnl *     ft_listing(t_gnl **list, int fd)
{
    t_gnl   *beg;
    t_gnl   *our;

    beg = *list;
    while ((*list)->next != NULL)
    {
        if ((*list)->fd == fd)
        {
            our = *list;
            *list = beg;
            return (our);
        }
        *list = (*list)->next;
    }
    *list = beg;
    our = (t_gnl*)malloc(sizeof(t_gnl));
    our->fd = fd;
    beg = our;
    *list = our->next;
    return (our);
}



//int     buf_manipul()
// {
//     char    *s2;


// }

int         stat_manipul(char **tmp, char ***line, char **s1)
{
    size_t      index;
    int         flag;

    index = 0;
    flag = 0;

    while ((*tmp)[index] != '\n' && (*tmp)[index] != '\0')
        index++;
    if ((*tmp)[index] == '\n')
        flag = 1;
    **line = ft_strsub(*tmp, 0, index);
    *s1 = ft_strsub(*tmp, (unsigned int) index + 1, (ft_strlen(*tmp) - index));
    free(*tmp);
    *tmp = *s1;
    if (flag == 1)
        return (1);
    return (0);
}

int     get_next_line(const int fd, char **line)
{
    static  t_gnl *list;
    // char    buf[BUFF_SIZE + 1];
    // int     ret;
    size_t          index;
    // static  char    *tmp;
    char    *s1;
    char    *s2;

    if (!list)
        list = (t_gnl*)malloc(sizeof(t_gnl));
    ft_listing(&list, fd);
//go next po list and find fd | if list->fd == fd | return teckyshiy list
//list vernut' v nachalo
// elsi nety fd create new list with this fd with malloc(in begin of our lists)

    ft_bzero(buf, BUFF_SIZE + 1);
    ret = 1;
    index = 0;
    if (!line || fd < 0 || BUFF_SIZE < 1 || read(fd, buf, 0) < 0)
        return (-1);
    *line = NULL;
    if (tmp != NULL && tmp[0] != '\0')
        if (stat_manipul(&tmp, &line, &s1) == 1)
            return (1);
    while (ret > 0 || buf[0] != '\0')
    {
        ret = (int) read(fd, buf, BUFF_SIZE);
        if (ft_strchr(buf, '\n') == NULL)
        {
            s1 = ft_strjoin(*line ? *line : "" , buf);
            if (*line)
                free(*line);
            *line = s1;
            ft_bzero(buf, BUFF_SIZE + 1);
        }
        else 
        {
            while (buf[index] != '\n' && buf[index] != '\0')
                index++;
            s1 = ft_strjoin(*line ? *line : "", s2 = (ft_strsub(buf, 0, index)));
            free(s2);
            if (*line)
                free(*line);
            *line = s1;
            s1 = ft_strsub(buf, (unsigned int)(index + 1), (ft_strlen(buf) - index));
            if (tmp)
                free(tmp);
            tmp = s1;
                return (1);
        }
    }
    if (ret == 0 && *line[0] != '\0')
        return (1);
    if (ret == 0)
        return (0);
    return (-1);
}