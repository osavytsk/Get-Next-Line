/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:58:40 by osavytsk          #+#    #+#             */
/*   Updated: 2017/11/15 20:15:45 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	tmp = *alst;
	if (!tmp || !del)
		return ;
	while (tmp->next != NULL)
	{
		del(tmp->content, tmp->content_size);
		free(*alst);
		tmp = tmp->next;
		*alst = tmp;
	}
	del(tmp->content, tmp->content_size);
	free(*alst);
	*alst = (NULL);
}
