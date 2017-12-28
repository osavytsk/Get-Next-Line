/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:16:26 by osavytsk          #+#    #+#             */
/*   Updated: 2017/11/10 16:33:01 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*pt;

	pt = (unsigned char*)malloc(size);
	if (!pt)
		return (NULL);
	ft_bzero(pt, size);
	return (pt);
}
