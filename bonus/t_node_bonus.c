/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_node.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:31:25 by samini            #+#    #+#             */
/*   Updated: 2023/06/11 16:31:25 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_node	*new_node(char *data)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->data = data;
	n->next = NULL;
	return (n);
}

void	append_node(t_node **head, t_node *node)
{
	t_node	*temp;

	if (!head)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

void	free_nodes(t_node *head)
{
	t_node	*temp;
	t_node	*prev;

	temp = head;
	while (temp)
	{
		prev = temp->next;
		free(temp->data);
		free(temp);
		temp = prev;
	}
}

char	**nodes_to_array(t_node *head, size_t max)
{
	int		i;
	int		len;
	t_node	*temp;
	char	**arr;

	temp = head;
	len = 0;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	temp = head;
	arr = ft_calloc(len + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = ft_calloc(max + 1, sizeof(char));
		ft_memcpy(arr[i], temp->data, ft_strlen(temp->data));
		temp = temp->next;
		i++;
	}
	return (arr);
}
