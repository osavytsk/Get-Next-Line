/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 20:03:54 by osavytsk          #+#    #+#             */
/*   Updated: 2017/11/05 20:48:06 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t dln;
	size_t sln;

	i = 0;
	dln = ft_strlen(dst);
	sln = ft_strlen(src);
	if (dln >= size)
		return (sln + size);
	while (src[i] != '\0' && i < (size - dln - 1))
	{
		dst[dln + i] = src[i];
		i++;
	}
	dst[dln + i] = '\0';
	return (dln + sln);
}
