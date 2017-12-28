/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:48:02 by osavytsk          #+#    #+#             */
/*   Updated: 2017/11/15 22:55:45 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	if (!(tmp = f(lst)))
		free(tmp);
	new = tmp;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(tmp->next = f(lst)))
			free(tmp);
		tmp = tmp->next;
	}
	return (new);
}
