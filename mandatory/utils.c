/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:29:07 by aqiouami          #+#    #+#             */
/*   Updated: 2023/06/19 09:51:44 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdio.h>
#include <unistd.h>

void	free_bins(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

bool	has_wall(t_data *data, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	if (new_x < 0 || new_y < 0 || new_x >= data->map_v.n_col * TILE
		|| new_y >= data->map_v.n_rows * TILE)
		return (true);
	map_x = floor(new_x / TILE);
	map_y = floor(new_y / TILE);
	if (data->map_v.map[map_y][map_x] == '1' \
		|| data->map_v.map[map_y][map_x] == 'D')
		return (true);
	return (false);
}

bool	can_walk(t_data *data, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	map_x = floor(new_x / TILE);
	map_y = floor(new_y / TILE);
	if (data->map_v.map[map_y][map_x] == '0'
		|| data->map_v.map[map_y][map_x] == 'O'
		|| data->map_v.map[map_y][map_x] == 'S'
		|| data->map_v.map[map_y][map_x] == 'W'
		|| data->map_v.map[map_y][map_x] == 'E'
		|| data->map_v.map[map_y][map_x] == 'N')
		return (true);
	return (false);
}

bool	has_wall_ray(t_data *data, double new_x, double new_y, t_ray *ray)
{
	size_t	map_x;
	size_t	map_y;
	size_t	limit;

	ray->door_flag = false;
	if (new_x < 0 || new_y < 0 || new_x >= data->map_v.n_col * TILE
		|| new_y >= data->map_v.n_rows * TILE)
		return (true);
	map_x = floor(new_x / TILE);
	map_y = floor(new_y / TILE);
	limit = ft_strlen(data->map_v.map[map_y]) - 1;
	if (map_x > limit)
		return (true);
	if (data->map_v.map[map_y][map_x] == '1')
		return (true);
	if (data->map_v.map[map_y][map_x] == 'D' && data->test)
		return (ray->door_flag = true, true);
	return (false);
}
