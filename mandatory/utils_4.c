/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:49:10 by samini            #+#    #+#             */
/*   Updated: 2023/06/12 11:49:12 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	is_empty_line_safe(char *line)
{
	int		i;
	char	c;

	i = 0;
	while (line[i])
	{
		c = line[i];
		if (!(c == 32 || c == '\n'))
			return (false);
		i++;
	}
	return (true);
}

void	sanitize_lines(t_node *node)
{
	static bool		in_map;
	static t_node	*last;
	int				i;

	while (node)
	{
		if (in_map && is_empty_line_safe(node->data))
			return (printf("Error\nEmpty line after map.\n"), exit(1));
		check_boundaries(node, &in_map);
		if (in_map)
			check_begin_end(node->data);
		last = node;
		node = node->next;
	}
	if (!last)
		return (printf("Error\nInvalid map.\n"), exit(1));
	i = -1;
	while (last->data[++i])
		if (last->data[i] != ' ' && last->data[i] != '1')
			return (printf("Error\nInvalid boundaries.\n"), exit(1));
}

void	check_player_existence(bool has_player)
{
	if (has_player)
		return (printf("Error\nPlayer was found more than once.\n"),
			exit(1));
}

void	initial_calc(t_data *data, t_ray *ray)
{
	data->infos.ray_distance = ray->dist * \
		cos(ray->ra - data->player.ra);
	data->infos.plane_dist = (data->game_dims.win_width / 2) \
		/ tan(data->constants.fov / 2);
	data->infos.wall_height = CONSTANT / data->infos.ray_distance;
	data->infos.center = ((data->game_dims.win_height / 2) - \
		(data->infos.wall_height / 2));
}

void	calc_offs_x(t_data *data, t_ray *ray)
{
	double	mod_x;
	double	current_x;

	if (ray->hit_vert)
	{
		mod_x = fmod(ray->y, TILE);
		current_x = mod_x / TILE;
		data->infos.text_offs_x = current_x * 64;
	}
	else
	{
		mod_x = fmod(ray->x, TILE);
		current_x = mod_x / TILE;
		data->infos.text_offs_x = current_x * 64;
	}
}
