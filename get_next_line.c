/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 03:18:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/01/12 03:18:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl        *ft_listing(t_gnl **list, int fd)
{
    t_gnl           *beg;
    t_gnl           *our;

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

static int          buf_manipul(t_gnl **tl, char ***line, char **s1, char **s2)
{
    int             i;

    i = 0;
    if (ft_strchr((*tl)->buf, '\n') == NULL)
    {
        *s1 = ft_strjoin(**line ? **line : "", (*tl)->buf);
        **line ? free(**line) : **line;
        **line = *s1;
        ft_bzero((*tl)->buf, BUFF_SIZE + 1);
        return (0);
    }
    else
    {
        while ((*tl)->buf[i] != '\n' && (*tl)->buf[i] != '\0')
            i++;
        *s2 = (ft_strsub((*tl)->buf, 0, i));
        *s1 = ft_strjoin(**line ? **line : "", *s2);
        free(*s2);
        **line ? free(**line) : **line;
        **line = *s1;
        *s1 = ft_strsub((*tl)->buf, (i + 1), (ft_strlen((*tl)->buf) - i));
        (*tl)->tmp ? free((*tl)->tmp) : (*tl)->tmp;
        (*tl)->tmp = *s1;
        return (1);
    }
}

static int          stat_manipul(t_gnl **list, char ***line)
{
    size_t          i;
    int             flag;
    char            *s1;

    i = 0;
    flag = 0;

    while ((*list)->tmp[i] != '\n' && (*list)->tmp[i] != '\0')
        i++;
    if ((*list)->tmp[i] == '\n')
        flag = 1;
    **line = ft_strsub((*list)->tmp, 0, i);
    s1 = ft_strsub((*list)->tmp, i + 1, (ft_strlen((*list)->tmp) - i));
    free((*list)->tmp);
    (*list)->tmp = s1;
    return (flag == 1 ? 1 : 0);
}

int                 get_next_line(const int fd, char **line)
{
    static t_gnl    *list;
    t_gnl           *tl;
    char            *s1;
    char            *s2;

    tl = ft_listing(&list, fd);
    ft_bzero(tl->buf, BUFF_SIZE + 1);
    tl->ret = 1;
    if (!line || fd < 0 || BUFF_SIZE < 1 || read(fd, tl->buf, 0) < 0)
        return (-1);
    *line = NULL;
    if (tl->tmp != NULL && tl->tmp[0] != '\0')
        if (stat_manipul(&tl, &line) == 1)
            return (1);
    while (tl->ret > 0 || tl->buf[0] != '\0')
    {
        tl->ret = (int) read(fd, tl->buf, BUFF_SIZE);
        if (buf_manipul(&tl, &line, &s1, &s2) == 1)
            return (1);
    }
    return tl->ret == 0 && (*line)[0] != '\0' ? 1 : tl->ret == 0 ? 0 : -1;
}
