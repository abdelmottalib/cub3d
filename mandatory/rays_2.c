/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <aqiouami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:30:17 by aqiouami          #+#    #+#             */
/*   Updated: 2023/06/11 16:30:18 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	check_vertical(t_data *data, t_ray *ray)
{
	data->coord.vert.found = false;
	data->coord.vert.x = 0;
	data->coord.vert.y = 0;
	data->coord.vert.dist = 0;
	finding_vert_xinter_yinter(data, ray);
	finding_vert_xstep_ystep(data, ray);
	finding_vert_wallhit_x_y(data, ray);
}

void	finding_vert_xinter_yinter(t_data *data, t_ray *ray)
{
	if (ray->right)
		data->coord.xi = ceil(data->player.x / TILE) * \
			TILE;
	else
		data->coord.xi = floor(data->player.x / TILE) * \
			TILE;
	data->coord.yi = ((data->coord.xi - data->player.x) * \
		data->coord.tan_theta) + data->player.y;
}

void	finding_vert_xstep_ystep(t_data *data, t_ray *ray)
{
	data->coord.xs = TILE;
	if (ray->left)
		data->coord.xs *= -1;
	data->coord.ys = TILE * data->coord.tan_theta;
	if (ray->up && data->coord.ys > 0)
		data->coord.ys *= -1;
	if (ray->down && data->coord.ys < 0)
		data->coord.ys *= -1;
}

void	finding_vert_wallhit_x_y(t_data *data, t_ray *ray)
{
	double	nx;
	double	ny;

	nx = data->coord.xi;
	ny = data->coord.yi;
	while (!touch_vert_extremity(data))
	{
		if (has_wall_ray(data, nx - \
			(compare(ray->left, 1, -1)), \
			ny, ray))
		{
			if (ray->door_flag)
				ray->door_flag_v = true;
			data->coord.vert.found = true;
			data->coord.vert.x = nx;
			data->coord.vert.y = ny;
			break ;
		}
		nx += data->coord.xs;
		ny += data->coord.ys;
	}
}
