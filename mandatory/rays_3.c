/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:30:56 by samini            #+#    #+#             */
/*   Updated: 2023/06/11 16:30:57 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	horiz_distance(t_data *data)
{
	if (data->coord.horiz.found)
		data->coord.horiz.dist = calc_distance(data->player.x, \
		data->player.y, data->coord.horiz.x, data->coord.horiz.y);
	else
		data->coord.horiz.dist = __FLT_MAX__;
}

void	vert_distance(t_data *data)
{
	if (data->coord.vert.found)
		data->coord.vert.dist = calc_distance(data->player.x, \
		data->player.y, \
		data->coord.vert.x, data->coord.vert.y);
	else
		data->coord.vert.dist = __FLT_MAX__;
}

void	smallest_distance(t_data *data, t_ray *ray)
{
	if (data->coord.horiz.dist < data->coord.vert.dist)
	{
		ray->x = data->coord.horiz.x;
		ray->y = data->coord.horiz.y;
		ray->dist = data->coord.horiz.dist;
	}
	else
	{
		ray->x = data->coord.vert.x;
		ray->y = data->coord.vert.y;
		ray->dist = data->coord.vert.dist;
	}
	data->zbuffer[ray->zx] = ray->dist;
}

void	door_hit(t_data *data, t_ray *ray)
{
	if (data->coord.horiz.dist < data->coord.vert.dist)
	{
		if (ray->door_flag_h)
			ray->door_flag = true;
		else
			ray->door_flag = false;
		ray->hit_hotiz = true;
	}
	else
	{
		if (ray->door_flag_v)
			ray->door_flag = true;
		else
			ray->door_flag = false;
		ray->hit_vert = true;
	}
}

void	compare_horiz_vert(t_data *data, t_ray *ray)
{
	ray->hit_hotiz = false;
	ray->hit_vert = false;
	horiz_distance(data);
	vert_distance(data);
	smallest_distance(data, ray);
	door_hit(data, ray);
}
