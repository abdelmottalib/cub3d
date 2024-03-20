/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:31:22 by samini            #+#    #+#             */
/*   Updated: 2023/06/11 16:31:22 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <math.h>

void	increment_anim_counter(t_data *data, int *anim_counter)
{
	(*anim_counter)++;
	if (*anim_counter > 7)
	{
		*anim_counter = 0;
		data->anim_ptr++;
		data->anim_ptr %= NUM_ANIMATIONS;
	}
}

t_calculations	store_calculations(t_data *data, t_sprite *sprite,
		double playerx, double playery)
{
	t_calculations	c;

	c.sprite_height = data->infos.plane_dist / sprite->distance;
	c.sprite_width = c.sprite_height;
	c.sprite_topy = ((double)data->game_dims.win_height
			/ 2) - (c.sprite_height / 2);
	if (c.sprite_topy < 0)
		c.sprite_topy = 0;
	c.sprite_boty = ((double)data->game_dims.win_height
			/ 2) + (c.sprite_height / 2);
	if (c.sprite_boty > data->game_dims.win_height)
		c.sprite_boty = data->game_dims.win_height;
	c.sprite_angle = -data->player.ra + atan2(sprite->y + SPR_CENTER_OFFSET
			- playery, sprite->x + SPR_CENTER_OFFSET - playerx);
	c.sprite_screen_posx = tan(c.sprite_angle) * data->infos.plane_dist;
	c.sprite_leftx = ((double)data->game_dims.win_width
			/ 2) + c.sprite_screen_posx - c.sprite_width / 2;
	c.sprite_rightx = c.sprite_leftx + c.sprite_width;
	c.texture_width = sprite->texture[0].w;
	c.texture_height = sprite->texture[0].h;
	return (c);
}

void	draw_sprites(t_data *data)
{
	static int	anim_counter;

	if (!data->sprite_node)
		return ;
	increment_anim_counter(data, &anim_counter);
	sort_sprites(&data->sprite_node);
	check_sprite_visibility(data, data->player.x / TILE, data->player.y / TILE);
	render_visible_sprites(data, data->player.x / TILE, data->player.y / TILE);
}
