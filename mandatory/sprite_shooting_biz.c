/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_shooting_biz.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:31:05 by samini            #+#    #+#             */
/*   Updated: 2023/06/11 16:31:08 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	check_shootable(t_data *data, t_sprite *sprite, t_calculations c)
{
	int	center;

	center = c.sprite_leftx + ((c.sprite_rightx - c.sprite_leftx) / 2);
	if (sprite->distance * TILE < data->zbuffer[center]
		&& sprite->is_within_range)
		sprite->is_shootable = true;
	else
		sprite->is_shootable = false;
}

unsigned int	*get_color_buffer(t_data *data, t_sprite *sprite)
{
	unsigned int	*color_buffer;

	color_buffer = data->sprite_node->texture[data->anim_ptr].array;
	if (sprite->is_dead)
	{
		color_buffer = data->sprite_node->texture_dead[sprite->ptr].array;
	}
	return (color_buffer);
}

void	increment_anim_dead(t_sprite *sprite)
{
	static int	counter;

	if (sprite->is_dead)
	{
		if (sprite->ptr < NUM_ANIMATIONS - 1)
		{
			counter++;
			if (counter > 5)
			{
				sprite->ptr++;
				counter = 0;
			}
		}
	}
}
