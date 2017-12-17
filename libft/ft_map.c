/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 23:15:47 by osavytsk          #+#    #+#             */
/*   Updated: 2017/11/15 23:15:56 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_map(int *tab, int lenght, int (*f) (int))
{
	int i;
	int *r;

	r = (int *)malloc(sizeof(*r) * lenght);
	i = 0;
	while (i < lenght)
	{
		r[i] = f(tab[i]);
		i++;
	}
	return (r);
}
