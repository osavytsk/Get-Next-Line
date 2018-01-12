/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:49:45 by osavytsk          #+#    #+#             */
/*   Updated: 2017/11/10 17:00:50 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*pt;

	pt = (char *)malloc(sizeof(char) * (size + 1));
	if (!pt)
		return (NULL);
	ft_memset(pt, '\0', size + 1);
	return (pt);
}
