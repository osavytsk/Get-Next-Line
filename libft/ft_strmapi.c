/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:50:01 by osavytsk          #+#    #+#             */
/*   Updated: 2017/11/10 21:55:33 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	i;
	int		j;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	p = ft_strnew(i);
	j = 0;
	if (!p)
		return (NULL);
	while (s[j] != '\0')
	{
		p[j] = f(j, s[j]);
		j++;
	}
	return (p);
}
