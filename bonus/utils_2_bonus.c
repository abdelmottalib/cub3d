/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <aqiouami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:29:38 by aqiouami          #+#    #+#             */
/*   Updated: 2023/06/11 16:29:39 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	touch_horiz_extremity(t_data *data)
{
	if (data->coord.horiz.nx <= 0
		&& data->coord.horiz.nx >= (data->map_v.n_col) * TILE
		&& data->coord.horiz.ny <= 0
		&& data->coord.horiz.ny >= (data->map_v.n_rows) * TILE)
		return (true);
	return (false);
}

bool	touch_vert_extremity(t_data *data)
{
	if (data->coord.vert.nx <= 0
		&& data->coord.vert.nx >= (data->map_v.n_col) * TILE
		&& data->coord.vert.ny <= 0
		&& data->coord.vert.ny >= (data->map_v.n_rows) * TILE)
		return (true);
	return (false);
}

double	compare(bool expression, double exp_true, double exp_false)
{
	if (expression == true)
		return (exp_true);
	else
		return (exp_false);
}

double	calc_distance(double x0, double y0, double x1, double y1)
{
	return (sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0)));
}

int	make_color(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}
