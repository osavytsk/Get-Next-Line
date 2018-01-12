/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:40:23 by osavytsk          #+#    #+#             */
/*   Updated: 2017/11/11 19:30:47 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	size_t	k;
	char	*pt;

	if (!s)
		return (NULL);
	k = 0;
	i = 0;
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n')
		i++;
	j = ft_strlen(s) - 1;
	if (i == j + 1)
		return (ft_strnew(0));
	while ((s[j] == '\t' || s[j] == ' ' || s[j] == '\n') && j >= 0)
		j--;
	if (!(pt = ft_strnew(j - i + 1)))
		return (NULL);
	while (i <= j)
		pt[k++] = s[i++];
	return (pt);
}
