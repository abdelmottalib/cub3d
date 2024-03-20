/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:31:12 by samini            #+#    #+#             */
/*   Updated: 2023/06/11 16:31:13 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	append_sprite_node(t_sprite **head, t_sprite *node)
{
	t_sprite	*temp;

	if (!head)
		return ;
	if (!*head)
		return ((void)(*head = node));
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

void	remove_freeless(t_sprite **head, t_sprite *to_remove)
{
	t_sprite	*temp;

	if (*head == to_remove)
	{
		*head = (*head)->next;
		return ;
	}
	temp = *head;
	while (temp->next)
	{
		if (temp->next == to_remove)
		{
			temp->next = temp->next->next;
			return ;
		}
		temp = temp->next;
	}
}

void	sort_sprites(t_sprite **head)
{
	t_sprite	*biggest;
	t_sprite	*temp;

	if (!(*head)->next)
		return ;
	biggest = *head;
	temp = *head;
	while (temp)
	{
		if (temp->distance > biggest->distance)
			biggest = temp;
		temp = temp->next;
	}
	remove_freeless(head, biggest);
	biggest->next = *head;
	*head = biggest;
	sort_sprites(&(*head)->next);
}
