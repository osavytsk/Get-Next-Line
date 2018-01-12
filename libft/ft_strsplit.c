/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:10:46 by osavytsk          #+#    #+#             */
/*   Updated: 2017/11/17 20:17:24 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[0] != c && *s)
	{
		i++;
		count++;
	}
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_len(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static void		*ft_errors(char ***tmp)
{
	size_t	i;

	i = 0;
	while ((*tmp)[i] != NULL)
	{
		free((*tmp)[i]);
		(*tmp)[i] = NULL;
		i++;
	}
	free(*tmp);
	*tmp = NULL;
	return (NULL);
}

static void		ft_mod_strncpy(char **tmp, const char *s, size_t i, size_t k)
{
	ft_strncpy(tmp[k], s, i);
	tmp[k][i] = '\0';
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tmp;
	size_t	wrd;
	size_t	i;
	size_t	k;

	if (!s)
		return (NULL);
	wrd = ft_count((char *)s, c);
	k = 0;
	if (!(tmp = (char **)malloc(sizeof(char*) * (wrd + 1))))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			i = ft_len((char *)s, c);
			if (!(tmp[k] = (char *)malloc(sizeof(char) * (i + 1))))
				return (ft_errors(&tmp));
			ft_mod_strncpy(tmp, s, i, k++);
			s = s + i - 1;
		}
		s++;
	}
	tmp[k] = NULL;
	return (tmp);
}
