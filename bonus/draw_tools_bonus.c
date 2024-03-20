/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:43:34 by samini            #+#    #+#             */
/*   Updated: 2023/06/11 16:58:01 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_square(t_data *data, double x, double y, int color)
{
	t_square	infos;

	infos.start_y = y * data->game_dims.m_scale;
	infos.start_x = x * data->game_dims.m_scale;
	infos.end_y = infos.start_y + TILE * data->game_dims.m_scale;
	infos.end_x = infos.start_x + TILE * data->game_dims.m_scale;
	infos.curr_y = infos.start_y;
	while (infos.curr_y < infos.end_y)
	{
		infos.curr_x = infos.start_x;
		while (infos.curr_x < infos.end_x)
		{
			my_mlx_pixel_put(data, infos.curr_x, infos.curr_y, color);
			infos.curr_x++;
		}
		infos.curr_y++;
	}
}

int	get_a(int color)
{
	return ((color >> 24) & 0xFF);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= data->game_dims.win_width
		|| y >= data->game_dims.win_height)
		return ;
	dst = data->paint.addr + (y * data->paint.line_length + x \
		* (data->paint.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_data *data, double endx, double endy, int color)
{
	t_line_vars	infos;

	infos.curr_player_x = data->game_dims.m_scale
		* (data->player.x - data->temp.min_x);
	infos.curr_player_y = data->game_dims.m_scale
		* (data->player.y - data->temp.min_y);
	endx = data->game_dims.m_scale * endx;
	endy = data->game_dims.m_scale * endy;
	infos.deltax = endx - infos.curr_player_x;
	infos.deltay = endy - infos.curr_player_y;
	infos.pixels = sqrt((infos.deltax * infos.deltax) \
		+ (infos.deltay * infos.deltay));
	infos.deltax /= infos.pixels;
	infos.deltay /= infos.pixels;
	infos.pixely = infos.curr_player_y;
	infos.pixelx = infos.curr_player_x;
	while (infos.pixels)
	{
		my_mlx_pixel_put(data, infos.pixelx, infos.pixely, color);
		infos.pixelx += infos.deltax;
		infos.pixely += infos.deltay;
		--infos.pixels;
	}
}

void	brightness(t_ray *ray)
{
	double	brightness;
	int		red;
	int		green;
	int		blue;

	red = (ray->text_color >> 16) & 0xFF;
	green = (ray->text_color >> 8) & 0xFF;
	blue = ray->text_color & 0xFF;
	brightness = (1 / ray->dist) * 350;
	if (brightness > 1)
		brightness = 1;
	red = (int)(red * brightness);
	green = (int)(green * brightness);
	blue = (int)(blue * brightness);
	ray->text_color = (red << 16) | (green << 8) | blue;
}
