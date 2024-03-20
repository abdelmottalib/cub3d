/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:35:05 by samini            #+#    #+#             */
/*   Updated: 2023/06/11 16:53:02 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_ray	*ft_lstnew_ray(double new)
{
	t_ray	*node;

	new = fmod(new, 2 * M_PI);
	if (new < 0)
		new = (2 * M_PI) + new;
	node = malloc(sizeof(t_ray));
	if (!node)
		return (NULL);
	node->ra = new;
	node->x = 0;
	node->y = 0;
	node->dist = 0;
	node->down = (node->ra > 0 && node->ra < M_PI);
	node->up = !node->down;
	node->right = (node->ra < M_PI * 0.5 \
	|| node->ra > 1.5 * M_PI);
	node->left = !node->right;
	node->next = NULL;
	return (node);
}

t_ray	*ft_lstlast_ray(t_ray *lst)
{
	if (lst)
	{
		while (lst && lst->next)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}

void	ft_lstadd_back_ray(t_ray **lst, t_ray *new)
{
	t_ray	*temp;

	if (*lst)
	{
		temp = ft_lstlast_ray(*lst);
		temp->next = new;
	}
	else if (!new)
		return ;
	else
	{
		*lst = new;
		return ;
	}
}

void	ft_lstdelone_ray(t_ray *lst, void (*del)(void *))
{
	if (lst && del)
		free(lst);
}

void	ft_lstclear_ray(t_ray **lst, void (*del)(void *))
{
	t_ray	*node;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		node = *lst;
		*lst = (*lst)->next;
		ft_lstdelone_ray(node, del);
	}
	*lst = NULL;
}
