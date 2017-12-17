/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 23:15:28 by osavytsk          #+#    #+#             */
/*   Updated: 2017/11/15 23:15:41 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int i)
{
	if (i == 0)
		return (0);
	else if (i == 1)
		return (1);
	else if (i > 1)
		return (ft_fibonacci(i - 1) + ft_fibonacci(i - 2));
	else
		return (-1);
}
