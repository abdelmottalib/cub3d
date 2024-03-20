/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:29:40 by aqiouami          #+#    #+#             */
/*   Updated: 2023/06/15 10:52:26 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdio.h>

void	normalize_player_angle(t_data *data)
{
	data->player.ra = fmod(data->player.ra, 2 * M_PI);
	if (data->player.ra < 0)
		data->player.ra = (2 * M_PI) + data->player.ra;
}

void	update_walk_and_turn(t_data *data)
{
	bool	wall_check;
	double	new_x;
	double	new_y;
	double	move_step;

	data->player.ra += data->player.td * data->player.rs;
	normalize_player_angle(data);
	limit_speed(data);
	move_step = data->player.wd * data->player.ms;
	new_x = data->player.x + cos(data->player.ra) * move_step;
	new_y = data->player.y + sin(data->player.ra) * move_step;
	if (data->player.sideways)
	{
		new_x = data->player.x + cos(data->player.ra + \
			(M_PI / 2)) * move_step;
		new_y = data->player.y + sin(data->player.ra + \
			(M_PI / 2)) * move_step;
	}
	check_door(data);
	check_walls(data, new_x, new_y, &wall_check);
	check_sliding(data, new_x, new_y, &wall_check);
	data->player.x = data->player.x + (!wall_check * (new_x - data->player.x));
	data->player.y = data->player.y + (!wall_check * (new_y - data->player.y));
}

void	cast_rays(t_data *data)
{
	double	ray_angle;
	int		i;
	t_ray	*temp;

	ray_angle = data->player.ra - (data->constants.fov / 2);
	ft_lstclear_ray(&data->ray, free);
	i = 0;
	while (i < data->game_dims.win_width)
	{
		temp = ft_lstnew_ray(ray_angle);
		ft_lstadd_back_ray(&data->ray, temp);
		temp->zx = i;
		ray_cast(data, temp, 1);
		ray_angle += (data->constants.fov / data->game_dims.win_width);
		i++;
	}
}

void	enable_doors(t_data *data)
{
	int	i;
	int	j;
	int	distance;

	i = -1;
	while (data->map_v.map[++i])
	{
		j = -1;
		while (data->map_v.map[i][++j])
		{
			if (data->map_v.map[i][j] == 'O')
			{
				distance = fabs(data->player.x - j * TILE) + \
					fabs(data->player.y - i * TILE);
				if (distance > 200)
					data->map_v.map[i][j] = 'D';
			}
		}
	}
}

void	check_door(t_data *data)
{
	int	i;
	int	j;

	i = data->player.y - DOOR_DISTANCE;
	enable_doors(data);
	while (i < data->player.y + DOOR_DISTANCE)
	{
		j = data->player.x - DOOR_DISTANCE;
		while (j < data->player.x + DOOR_DISTANCE)
		{
			check_collision(data, j, i);
			j++;
		}
		i++;
	}
}
