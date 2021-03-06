/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 21:31:06 by osavytsk          #+#    #+#             */
/*   Updated: 2018/01/14 21:31:18 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl		*ft_listing(t_gnl **list, int fd)
{
	t_gnl			*beg;
	t_gnl			*our;

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
	our->tmp = NULL;
	*list = our;
	our->next = beg;
	return (our);
}

static int			buf_manipul(t_gnl **tl, char ***line)
{
	int				i;

	i = 0;
	if (ft_strchr((*tl)->buf, '\n') == NULL)
	{
		(*tl)->s1 = ft_strjoin(**line ? **line : "", (*tl)->buf);
		**line ? free(**line) : **line;
		**line = (*tl)->s1;
		ft_bzero((*tl)->buf, BUFF_SIZE + 1);
		return (0);
	}
	else
	{
		while ((*tl)->buf[i] != '\n' && (*tl)->buf[i] != '\0')
			i++;
		(*tl)->s2 = (ft_strsub((*tl)->buf, 0, i));
		(*tl)->s1 = ft_strjoin(**line ? **line : "", (*tl)->s2);
		free((*tl)->s2);
		**line ? free(**line) : **line;
		**line = (*tl)->s1;
		(*tl)->s1 = ft_strsub((*tl)->buf, (i + 1), (ft_strlen((*tl)->buf) - i));
		(*tl)->tmp ? free((*tl)->tmp) : (*tl)->tmp;
		(*tl)->tmp = (*tl)->s1;
		return (1);
	}
}

static int			stat_manipul(t_gnl **list, char ***line)
{
	size_t			i;
	int				flag;

	i = 0;
	flag = 0;
	while ((*list)->tmp[i] != '\n' && (*list)->tmp[i] != '\0')
		i++;
	if ((*list)->tmp[i] == '\n')
		flag = 1;
	**line = ft_strsub((*list)->tmp, 0, i);
	(*list)->s1 = ft_strsub((*list)->tmp, i + 1, (ft_strlen((*list)->tmp) - i));
	free((*list)->tmp);
	(*list)->tmp = (*list)->s1;
	return (flag == 1 ? 1 : 0);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl	*list;
	t_gnl			*tl;

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
		tl->ret = (int)read(fd, tl->buf, BUFF_SIZE);
		if (buf_manipul(&tl, &line) == 1)
			return (1);
	}
	if (tl->ret != 0 || (*line)[0] == '\0')
	{
		free(tl->s1);
		return (tl->ret == 0 ? 0 : -1);
	}
	else
		return (1);
}
