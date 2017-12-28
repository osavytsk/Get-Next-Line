/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:57:56 by osavytsk          #+#    #+#             */
/*   Updated: 2017/11/10 21:49:18 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*p;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	p = ft_strnew(i);
	j = 0;
	if (!p)
		return (NULL);
	while (s[j] != '\0')
	{
		p[j] = f(s[j]);
		j++;
	}
	return (p);
}
