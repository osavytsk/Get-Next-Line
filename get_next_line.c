/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 00:54:21 by osavytsk          #+#    #+#             */
/*   Updated: 2017/12/10 00:54:31 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static	l_list;

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	read(fd, l_list->buff, BUFF_SIZE)
}