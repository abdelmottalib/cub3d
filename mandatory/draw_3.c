/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:30:25 by samini            #+#    #+#             */
/*   Updated: 2023/06/12 12:30:27 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_minimap(t_data *data)
{
	data->mp.player_x = data->player.x;
	data->mp.player_y = data->player.y;
	data->mp.map_height = data->map_v.n_rows * TILE;
	data->mp.map_width = data->map_v.n_col * TILE;
	data->mp.min_x = data->mp.player_x - 7 * TILE;
	data->mp.max_x = data->mp.player_x + 7 * TILE;
	data->mp.min_y = data->mp.player_y - 5 * TILE;
	data->mp.max_y = data->mp.player_y + 5 * TILE;
	data->mp.min_x = fmax(data->mp.min_x, 0);
	data->mp.max_x = fmin(data->mp.max_x, data->mp.map_width);
	data->mp.min_y = fmax(data->mp.min_y, 0);
	data->mp.max_y = fmin(data->mp.max_y, data->mp.map_height);
	data->temp.min_x = data->mp.min_x;
	data->temp.min_y = data->mp.min_y;
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	init_minimap(data);
	i = data->mp.min_y - 1;
	while (++i < data->mp.max_y)
	{
		j = data->mp.min_x - 1;
		while (++j < data->mp.max_x)
		{
			if (has_sprite(data, j, i))
				my_mlx_pixel_put(data, data->game_dims.m_scale
					* (j - data->mp.min_x),
					data->game_dims.m_scale * (i - data->mp.min_y), 0x00FF00);
			else if (has_wall_check(data, j, i))
				my_mlx_pixel_put(data, data->game_dims.m_scale
					* (j - data->mp.min_x),
					data->game_dims.m_scale * (i - data->mp.min_y), 0x000000);
			else if (can_walk(data, j, i))
				my_mlx_pixel_put(data, data->game_dims.m_scale
					* (j - data->mp.min_x),
					data->game_dims.m_scale * (i - data->mp.min_y), 0x999DA0);
		}
	}
}

void	draw_floor(t_data *data, int i)
{
	data->infos.g = data->infos.center + (int)data->infos.wall_height;
	while (data->infos.g < data->game_dims.win_height)
	{
		my_mlx_pixel_put(data, i, data->infos.g, data->color.floor);
		data->infos.g++;
	}
}

void	check_xpm(t_data *data, char *path)
{
	int		placeholder;
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx_v.mlx, path,
			&placeholder, &placeholder);
	if (!img)
		return (printf("Error\nInvalid xpm file\n"), exit(1));
	mlx_destroy_image(data->mlx_v.mlx, img);
}

void	check_boundaries(t_node *node, bool *in_map)
{
	int	i;

	if (!is_empty_line_safe(node->data) && !*in_map)
	{
		i = -1;
		while (node->data[++i])
			if (node->data[i] != ' ' && node->data[i] != '1')
				return (printf("Error\nInvalid boundaries.\n"), exit(1));
		*in_map = true;
	}
}
