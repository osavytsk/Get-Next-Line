/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:18:23 by osavytsk          #+#    #+#             */
/*   Updated: 2017/11/11 18:36:37 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*pt;

	if (!s1)
		return (NULL);
	if (!s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	pt = ft_strnew(i);
	if (!pt)
		return (NULL);
	ft_strcpy(pt, s1);
	ft_strcat(pt, s2);
	return (pt);
}
