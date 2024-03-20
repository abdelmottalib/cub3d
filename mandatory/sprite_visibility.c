/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_visibility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:31:18 by samini            #+#    #+#             */
/*   Updated: 2023/06/11 16:31:19 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	compute_sprite_data(t_sprite *sprite, double playerx, double playery,
		double angle_sprite_player)
{
	if (angle_sprite_player < MARGIN)
		sprite->is_within_range = true;
	else
		sprite->is_within_range = false;
	sprite->is_visible = true;
	sprite->angle = angle_sprite_player;
	sprite->distance = calc_distance(sprite->x + SPR_CENTER_OFFSET, sprite->y
			+ SPR_CENTER_OFFSET, playerx, playery);
}

void	check_sprite_visibility(t_data *data, double playerx, double playery)
{
	t_sprite	*sprite;
	double		angle_sprite_player;

	sprite = data->sprite_node;
	while (sprite)
	{
		angle_sprite_player = data->player.ra - atan2(sprite->y
				+ SPR_CENTER_OFFSET - playery, sprite->x + SPR_CENTER_OFFSET
				- playerx);
		if (angle_sprite_player > M_PI)
			angle_sprite_player -= M_PI * 2;
		if (angle_sprite_player < -M_PI)
			angle_sprite_player += M_PI * 2;
		angle_sprite_player = fabs(angle_sprite_player);
		if (angle_sprite_player < ((double)FOV_ANGLE / 2) * (M_PI / 180)
			+ MARGIN)
			compute_sprite_data(sprite, playerx, playery, angle_sprite_player);
		else
			sprite->is_visible = false;
		sprite = sprite->next;
	}
}

void	draw_column(t_data *data, t_sprite *sprite, int x, t_calculations c)
{
	double			y;
	unsigned int	*color_buffer;
	unsigned int	color;

	c.texel_width = (c.texture_width / c.sprite_width);
	c.texture_offset_x = (x - c.sprite_leftx) * c.texel_width;
	y = c.sprite_topy;
	while (y < c.sprite_boty)
	{
		c.dist_from_top = y + c.sprite_height / 2
			- (double)data->game_dims.win_height / 2;
		c.texture_offset_y = c.dist_from_top * (c.texture_height
				/ c.sprite_height);
		if (x > 0 && x < data->game_dims.win_width && y > 0
			&& y < data->game_dims.win_height)
		{
			color_buffer = get_color_buffer(data, sprite);
			color = color_buffer[(c.texture_width * c.texture_offset_y)
				+ c.texture_offset_x];
			if (sprite->distance * TILE < data->zbuffer[x] && color != 0x3A4041
				&& !(((color >> 24) & 0xFF) == 0xFF))
				my_mlx_pixel_put(data, x, y, color);
		}
		y++;
	}
}

void	render_sprite_texture(t_data *data, t_sprite *sprite, t_calculations c)
{
	int	x;

	x = c.sprite_leftx;
	increment_anim_dead(sprite);
	check_shootable(data, sprite, c);
	while (x < c.sprite_rightx)
	{
		draw_column(data, sprite, x, c);
		x++;
	}
}

void	render_visible_sprites(t_data *data, double playerx, double playery)
{
	t_calculations	calculations;
	t_sprite		*sprite;

	sprite = data->sprite_node;
	while (sprite)
	{
		if (!sprite->is_visible)
		{
			sprite = sprite->next;
			continue ;
		}
		calculations = store_calculations(data, sprite, playerx, playery);
		render_sprite_texture(data, sprite, calculations);
		sprite = sprite->next;
	}
}
