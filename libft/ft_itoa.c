/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:10:51 by osavytsk          #+#    #+#             */
/*   Updated: 2017/11/14 18:53:07 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count(int n)
{
	int	c;

	c = 0;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		c++;
	}
	if (n < 0)
		return (c + 1);
	return (c);
}

char		*ft_itoa(int n)
{
	int		i;
	int		f;
	char	*pt;

	i = ft_count(n);
	f = 1;
	if (!(pt = (char*)malloc(sizeof(char) * i + 2)))
		return (NULL);
	if (n < 0)
	{
		f = -1;
		pt[0] = '-';
	}
	if (pt != NULL)
	{
		pt[i + 1] = '\0';
		while (n >= 10 || n <= -10)
		{
			pt[i] = n % 10 * f + '0';
			n = n / 10;
			i--;
		}
		pt[i] = n * f + '0';
	}
	return (pt);
}
