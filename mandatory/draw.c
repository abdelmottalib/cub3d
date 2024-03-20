/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:30:30 by aqiouami          #+#    #+#             */
/*   Updated: 2023/06/12 12:34:15 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdio.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

bool	has_sprite(t_data *data, double new_x, double new_y)
{
	int			map_x;
	int			map_y;
	t_sprite	*temp;

	map_x = floor(new_x / TILE);
	map_y = floor(new_y / TILE);
	if (data->map_v.map[map_y][map_x] == 'P')
	{
		temp = data->sprite_node;
		while (temp)
		{
			if (temp->x == map_x && temp->y == map_y)
				break ;
			temp = temp->next;
		}
		if (!temp)
			return (false);
		return (true);
	}
	return (false);
}

bool	has_wall_check(t_data *data, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	map_x = floor(new_x / TILE);
	map_y = floor(new_y / TILE);
	if (data->map_v.map[map_y][map_x] == '1'
		|| data->map_v.map[map_y][map_x] == 'D')
		return (true);
	return (false);
}

void	draw_rays(t_data *data)
{
	t_ray	*temp;

	temp = data->ray;
	while (temp)
	{
		if (temp->dist < 100)
			draw_line(data, temp->x - data->temp.min_x,
				temp->y - data->temp.min_y, 0xe5e500);
		else
			draw_line(data, data->player.x - data->temp.min_x
				+ (cos(temp->ra) * 100), data->player.y - data->temp.min_y
				+ (sin(temp->ra) * 100), 0xe5e500);
		temp = temp->next;
	}
}

void	draw_walls(t_data *data)
{
	t_ray	*ray;
	int		i;

	ray = data->ray;
	i = 0;
	while (ray)
	{
		data->draw_door = 0;
		initial_calc(data, ray);
		draw_ceiling(data, i);
		trump_walls(data, ray, i);
		if (data->draw_door)
			trump_walls_2(data, ray, i);
		draw_floor(data, i);
		ray = ray->next;
		i++;
	}
}
