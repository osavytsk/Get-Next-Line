/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:46:08 by osavytsk          #+#    #+#             */
/*   Updated: 2017/11/07 18:54:55 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i1;
	size_t	i2;
	char	*p;

	p = (char *)haystack;
	i1 = 0;
	if (*needle == '\0')
		return (p);
	while (haystack[i1] != '\0')
	{
		i2 = 0;
		while (haystack[i1 + i2] == needle[i2] && needle[i2] != '\0')
		{
			i2++;
			if (needle[i2] == '\0')
				return (p + i1);
		}
		i1++;
	}
	return (NULL);
}
