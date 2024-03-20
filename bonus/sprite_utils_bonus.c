/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:50:47 by samini            #+#    #+#             */
/*   Updated: 2023/06/12 11:50:48 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	load_dead_sprites(t_data *data, t_sprite *node)
{
	int		i;
	char	buffer[40];

	i = 0;
	while (i < NUM_ANIMATIONS)
	{
		ft_memcpy(buffer, "../texture/ghostdead0.xpm",
			ft_strlen("../texture/ghostdead0.xpm") + 1);
		buffer[20] = '0' + i;
		check_xpm(data, buffer);
		node->texture_dead[i].img = mlx_xpm_file_to_image
			(data->mlx_v.mlx, buffer,
				&node->texture_dead[i].w, &node->texture_dead[i].h);
		node->texture_dead[i].array = (unsigned int *)mlx_get_data_addr
			(node->texture_dead[i].img, &node->texture_dead[i].bits_per_pixel,
				&node->texture_dead[i].line_length,
				&node->texture_dead[i].endian);
		i++;
	}
}

void	load_ghost_sprites(t_data *data, t_sprite *node)
{
	int		i;
	char	buffer[40];

	i = 0;
	while (i < NUM_ANIMATIONS)
	{
		ft_memcpy(buffer, "../texture/ghost0.xpm",
			ft_strlen("../texture/ghost0.xpm") + 1);
		buffer[16] = '0' + i;
		check_xpm(data, buffer);
		node->texture[i].img = mlx_xpm_file_to_image(data->mlx_v.mlx,
				buffer, &node->texture[i].w, &node->texture[i].h);
		node->texture[i].array = (unsigned int *)mlx_get_data_addr
			(node->texture[i].img, &node->texture[i].bits_per_pixel,
				&node->texture[i].line_length, &node->texture[i].endian);
		i++;
	}
	load_dead_sprites(data, node);
}

t_sprite	*new_sprite_node(int x, int y, t_data *data)
{
	t_sprite	*node;

	node = ft_calloc(sizeof(t_sprite), 1);
	if (!node)
		return (NULL);
	node->x = x;
	node->y = y;
	load_ghost_sprites(data, node);
	node->angle = 0;
	node->distance = 0;
	node->is_visible = false;
	node->ptr = 0;
	node->next = NULL;
	return (node);
}
