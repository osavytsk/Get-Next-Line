#include "get_next_line.h"

t_gnl *     ft_listing(t_gnl **list, int fd)
{
    t_gnl   *beg;
    t_gnl   *our;

    beg = *list;
    while ((*list) != NULL)
    {
        if ((*list)->fd == fd)
        {
            our = *list;
            *list = beg;
            return (our);
        }
        *list = (*list)->next;
    }
    our = (t_gnl*)malloc(sizeof(t_gnl));
    our->fd = fd;
    *list = our;
    our->next = beg;
    return (our);
}

//int     buf_manipul()
// {
//     char    *s2;


// }

int         stat_manipul(t_gnl **list, char ***line)
{
    size_t      index;
    int         flag;
    char        *s1;

    index = 0;
    flag = 0;

    while ((*list)->tmp[index] != '\n' && (*list)->tmp[index] != '\0')
        index++;
    if ((*list)->tmp[index] == '\n')
        flag = 1;
    **line = ft_strsub((*list)->tmp, 0, index);
    s1 = ft_strsub((*list)->tmp, index + 1, (ft_strlen((*list)->tmp) - index));
    free((*list)->tmp);
    (*list)->tmp = s1;
    if (flag == 1)
        return (1);
    return (0);
}

int     get_next_line(const int fd, char **line)
{
    static  t_gnl *list;
    t_gnl *tmp_list;
    size_t          index;
    char    *s1;
    char    *s2;

    tmp_list = ft_listing(&list, fd);
    ft_bzero(tmp_list->buf, BUFF_SIZE + 1);
    tmp_list->ret = 1;
    index = 0;
    if (!line || fd < 0 || BUFF_SIZE < 1 || read(fd, tmp_list->buf, 0) < 0)
        return (-1);
    *line = NULL;
    if (tmp_list->tmp != NULL && tmp_list->tmp[0] != '\0')
        if (stat_manipul(&tmp_list, &line) == 1)
            return (1);
    while (tmp_list->ret > 0 || tmp_list->buf[0] != '\0')
    {
        tmp_list->ret = (int) read(fd, tmp_list->buf, BUFF_SIZE);
        if (ft_strchr(tmp_list->buf, '\n') == NULL)
        {
            s1 = ft_strjoin(*line ? *line : "" , tmp_list->buf);
            if (*line)
                free(*line);
            *line = s1;
            ft_bzero(tmp_list->buf, BUFF_SIZE + 1);
        }
        else 
        {
            while (tmp_list->buf[index] != '\n' && tmp_list->buf[index] != '\0')
                index++;
            s1 = ft_strjoin(*line ? *line : "", s2 = (ft_strsub(tmp_list->buf, 0, index)));
            free(s2);
            if (*line)
                free(*line);
            *line = s1;
            s1 = ft_strsub(tmp_list->buf, (index + 1), (ft_strlen(tmp_list->buf) - index));
            if (tmp_list->tmp)
                free(tmp_list->tmp);
            tmp_list->tmp = s1;
                return (1);
        }
    }
    if (tmp_list->ret == 0 && (*line)[0] != '\0')
        return (1);
    if (tmp_list->ret == 0)
        return (0);
    return (-1);
}