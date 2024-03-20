/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <aqiouami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:30:14 by aqiouami          #+#    #+#             */
/*   Updated: 2023/06/11 16:30:15 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ray_cast(t_data *data, t_ray *ray, int flag)
{
	if (flag)
		data->test = 1;
	else if (!flag)
		data->test = 0;
	ray->door_flag = false;
	ray->door_flag_v = false;
	ray->door_flag_h = false;
	ray->x = 0;
	ray->y = 0;
	ray->dist = 0;
	data->coord.tan_theta = tan(ray->ra);
	check_horizontal(data, ray);
	check_vertical(data, ray);
	compare_horiz_vert(data, ray);
}

void	check_horizontal(t_data *data, t_ray *ray)
{
	data->coord.horiz.found = false;
	data->coord.horiz.x = 0;
	data->coord.horiz.y = 0;
	data->coord.horiz.dist = 0;
	finding_horiz_xinter_yinter(data, ray);
	finding_horiz_xstep_ystep(data, ray);
	finding_horiz_wallhit_x_y(data, ray);
}

void	finding_horiz_xinter_yinter(t_data *data, t_ray *ray)
{
	if (ray->down)
		data->coord.yi = ceil(data->player.y / TILE) * \
			TILE;
	else
		data->coord.yi = floor(data->player.y / TILE) * \
			TILE;
	data->coord.xi = ((data->coord.yi - data->player.y) / \
	data->coord.tan_theta) + data->player.x;
}

void	finding_horiz_xstep_ystep(t_data *data, t_ray *ray)
{
	data->coord.ys = TILE;
	if (ray->up)
		data->coord.ys *= -1;
	data->coord.xs = TILE / data->coord.tan_theta;
	if (ray->left && data->coord.xs > 0)
		data->coord.xs *= -1;
	if (ray->right && data->coord.xs < 0)
		data->coord.xs *= -1;
}

void	finding_horiz_wallhit_x_y(t_data *data, t_ray *ray)
{
	double	nx;
	double	ny;

	nx = data->coord.xi;
	ny = data->coord.yi;
	while (!touch_horiz_extremity(data))
	{
		if (has_wall_ray(data, nx, ny - (compare(ray->up, 1, 0)), ray))
		{
			if (ray->door_flag)
				ray->door_flag_h = true;
			data->coord.horiz.found = true;
			data->coord.horiz.x = nx;
			data->coord.horiz.y = ny;
			break ;
		}
		nx += data->coord.xs;
		ny += data->coord.ys;
	}
}
