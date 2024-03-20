/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <aqiouami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:29:42 by aqiouami          #+#    #+#             */
/*   Updated: 2023/06/11 16:29:43 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	check_walls(t_data *data, double new_x, double new_y, bool *wall_check)
{
	int		i;
	int		j;

	i = new_y - COLLISION_DISTANCE;
	*wall_check = false;
	while (i < new_y + COLLISION_DISTANCE)
	{
		j = new_x - COLLISION_DISTANCE;
		while (j < new_x + COLLISION_DISTANCE)
		{
			if (has_wall(data, j, i))
				*wall_check = true;
			j++;
		}
		i++;
	}
}

bool	slide_horiz(t_data *data, double new_x)
{
	int	i;
	int	j;

	i = new_x - COLLISION_DISTANCE;
	while (i < new_x + COLLISION_DISTANCE)
	{
		j = data->player.y - COLLISION_DISTANCE;
		while (j < data->player.y + COLLISION_DISTANCE)
		{
			if (has_wall(data, i, j))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	slide_vert(t_data *data, double new_y)
{
	int	i;
	int	j;

	i = new_y - COLLISION_DISTANCE;
	while (i < new_y + COLLISION_DISTANCE)
	{
		j = data->player.x - COLLISION_DISTANCE;
		while (j < data->player.x + COLLISION_DISTANCE)
		{
			if (has_wall(data, j, i))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	check_sliding(t_data *data, double new_x, double new_y, \
	bool *wall_check)
{
	bool	can_slide_vert;
	bool	can_slide_horiz;

	if (*wall_check == true)
	{
		can_slide_horiz = slide_horiz(data, new_x);
		can_slide_vert = slide_vert(data, new_y);
		if (can_slide_horiz)
			data->player.x = new_x;
		else if (can_slide_vert)
			data->player.y = new_y;
	}
}

void	limit_speed(t_data *data)
{
	if (data->player.ms >= 18)
		data->player.ms = 18;
	if (data->player.ms <= 2)
		data->player.ms = 2;
}
