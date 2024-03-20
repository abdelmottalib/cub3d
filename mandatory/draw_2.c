/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:30:27 by aqiouami          #+#    #+#             */
/*   Updated: 2023/06/11 16:59:53 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_ceiling(t_data *data, int i)
{
	data->infos.g = 0;
	while (data->infos.g < data->infos.center)
	{
		my_mlx_pixel_put(data, i, data->infos.g, data->color.ceiling);
		data->infos.g++;
	}
}

void	texture_spec(t_ray *ray)
{
	if (ray->door_flag)
		ray->type = DOOR;
	else if (ray->left && ray->hit_vert)
		ray->type = WEST;
	else if (ray->right && ray->hit_vert)
		ray->type = EAST;
	else if ((ray->hit_hotiz) && ray->up)
		ray->type = NORTH;
	else if ((ray->hit_hotiz) && ray->down)
		ray->type = SOUTH;
}

void	trump_walls_2(t_data *data, t_ray *ray, int i)
{
	int		y;
	double	current_y;

	ray_cast(data, ray, 1);
	initial_calc(data, ray);
	y = 0;
	calc_offs_x(data, ray);
	while (y < (int)data->infos.wall_height)
	{
		current_y = y / data->infos.wall_height;
		data->infos.text_offs_y = 64 * current_y;
		texture_spec(ray);
		ray->text_color = data->txtr[ray->type]. array[\
		(TEXTURE_WIDTH * data->infos.text_offs_y) + data->infos.text_offs_x];
		if (((ray->text_color >> 24) & 0xFF) == 0xFF)
		{
			y++;
			continue ;
		}
		if (data->shadow_flag)
			brightness(ray);
		my_mlx_pixel_put(data, i, y + data->infos.center, ray->text_color);
		y++;
	}
}

void	behind_door(t_data *data, t_ray *ray, int i)
{
	data->draw_door = 1;
	ray_cast(data, ray, 0);
	initial_calc(data, ray);
	draw_ceiling(data, i);
	draw_floor(data, i);
	trump_walls(data, ray, i);
}

void	trump_walls(t_data *data, t_ray *ray, int i)
{
	int		y;
	double	current_y;

	y = 0;
	calc_offs_x(data, ray);
	while (y < (int)data->infos.wall_height)
	{
		current_y = y / data->infos.wall_height;
		data->infos.text_offs_y = 64 * current_y;
		texture_spec(ray);
		ray->text_color = data->txtr[ray->type]. array[\
		(TEXTURE_WIDTH * data->infos.text_offs_y) + data->infos.text_offs_x];
		if (((ray->text_color >> 24) & 0xFF) == 0xFF)
		{
			behind_door(data, ray, i);
			return ;
		}
		if (data->shadow_flag)
			brightness(ray);
		my_mlx_pixel_put(data, i, y + data->infos.center, ray->text_color);
		y++;
	}
}
