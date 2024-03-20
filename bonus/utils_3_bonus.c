/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:29:13 by aqiouami          #+#    #+#             */
/*   Updated: 2023/06/19 09:51:46 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	load_door_frames(t_data *data)
{
	char	*base_filename;
	int		frame;
	int		width;
	int		height;

	frame = -1;
	base_filename = ft_strdup("../texture/assets/door/DOOR_00.xpm");
	data->frames = (void **)malloc(43 * sizeof(void *));
	while (++frame < 43)
	{
		base_filename[28] = '0' + (frame / 10);
		base_filename[29] = '0' + (frame % 10);
		check_xpm(data, base_filename);
		data->frames[frame] = mlx_xpm_file_to_image(data->mlx_v.mlx,
				base_filename, &width, &height);
	}
	free(base_filename);
}

t_collision_type	door_animation(t_data *data, int map_x, int map_y)
{
	static int	counter;
	static int	frame;
	int			opened;

	opened = 0;
	if (++counter > 1000)
	{
		counter = 0;
		frame++;
		if (frame > 41)
		{
			frame = 0;
			opened = 1;
			data->txtr[4].img = data->frames[0];
			data->map_v.map[map_y][map_x] = 'O';
		}
		if (!opened)
			data->txtr[4].img = data->frames[frame];
		data->txtr[4].array = (unsigned int *)mlx_get_data_addr
			(data->txtr[4].img, &data->txtr[4].bits_per_pixel,
				&data->txtr[4].line_length, &data->txtr[4].endian);
		return (DOOR_COLLISION);
	}
	return (DOOR_COLLISION);
}

t_collision_type	check_collision(t_data *data, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	if (new_x < 0 || new_y < 0 || new_x >= data->map_v.n_col * TILE
		|| new_y >= data->map_v.n_rows * TILE)
		return (WALL_COLLISION);
	map_x = floor(new_x / TILE);
	map_y = floor(new_y / TILE);
	if (data->map_v.map[map_y][map_x] == 'D')
		return (door_animation(data, map_x, map_y));
	return (NO_COLLISION);
}

void	init_textures(bool *texture, bool *flceil)
{
	texture[NORTH] = false;
	texture[SOUTH] = false;
	texture[WEST] = false;
	texture[EAST] = false;
	flceil[0] = false;
	flceil[1] = false;
}

bool	check_texture(bool *texture, bool *flceil)
{
	if (!texture[NORTH] || !texture[SOUTH] || !texture[WEST]
		|| !texture[EAST] || !flceil[0] || !flceil[1])
		return (true);
	return (false);
}
