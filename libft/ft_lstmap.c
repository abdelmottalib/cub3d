/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:18:48 by samini            #+#    #+#             */
/*   Updated: 2022/10/10 14:32:48 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*temp;
	t_list	*p;

	if (!lst || !f || !del)
		return (NULL);
	temp = f(lst->content);
	p = ft_lstnew(temp);
	lst = lst->next;
	while (lst)
	{
		temp = f(lst->content);
		ft_lstadd_back(&p, ft_lstnew(temp));
		lst = lst->next;
	}
	return (p);
}
