/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:50:49 by osavytsk          #+#    #+#             */
/*   Updated: 2017/11/07 20:02:23 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	i1;
	size_t	i2;
	size_t	t;
	char	*p;

	p = (char *)hay;
	i1 = 0;
	if (*need == '\0')
		return (p);
	while (hay[i1] != '\0' && i1 < len)
	{
		i2 = 0;
		t = i1;
		while (hay[i1 + i2] == need[i2] && i1 + i2 < len)
		{
			i2++;
			if (need[i2] == '\0')
				return (p + t);
		}
		i1++;
	}
	return (NULL);
}
