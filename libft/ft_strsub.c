/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:59:46 by osavytsk          #+#    #+#             */
/*   Updated: 2017/11/11 18:15:56 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*pt;

	if (!s)
		return (NULL);
	i = 0;
	pt = ft_strnew(len);
	if (!pt)
		return (NULL);
	while (i < len)
	{
		pt[i] = s[start];
		i++;
		start++;
	}
	return (pt);
}
