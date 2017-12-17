/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:13:53 by osavytsk          #+#    #+#             */
/*   Updated: 2017/11/07 21:29:25 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t				i;
	unsigned long int	res;
	int					flag;

	i = 0;
	res = 0;
	flag = 1;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' ||
	str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		flag = str[i] == '-' ? -1 : 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res >= 9223372036854775807 && flag == 1)
			return (-1);
		else if (res > 9223372036854775807 && flag == -1)
			return (0);
		i++;
	}
	return ((int)(res * flag));
}
