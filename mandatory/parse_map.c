/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:30:46 by samini            #+#    #+#             */
/*   Updated: 2023/06/11 16:30:47 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void	parse_textures(int fd, t_data *data)
{
	char	**array;
	char	*line;
	bool	texture[4];
	bool	flceil[2];

	init_textures(texture, flceil);
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (is_empty_line(line))
			continue ;
		array = ft_split(line, ' ');
		free(line);
		if (check_texture(texture, flceil))
			get_data(data, array, texture, flceil);
		free_bins(array);
		if (check_texture(texture, flceil) == false)
			break ;
	}
}

void	parse_grid(t_data *data)
{
	char	**map;
	int		i;
	int		j;
	char	c;

	map = data->map_v.map;
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				data->player.x = j * TILE + TILE / 2;
				data->player.y = i * TILE + TILE / 2;
				data->player.direction = c;
			}
			if (c == 'P')
				append_sprite_node(&data->sprite_node,
					new_sprite_node(j, i, data));
			j++;
		}
	}
}

void	sanitize_grid(t_data *data)
{
	int		i;
	int		j;
	bool	has_player;
	char	c;

	i = -1;
	has_player = false;
	while (data->map_v.map[++i])
	{
		j = -1;
		while (data->map_v.map[i][++j])
		{
			c = data->map_v.map[i][j];
			if (c == '0' || c == 'P'
				|| c == 'N' || c == 'S' || c == 'W' || c == 'E')
				check_4sides(data->map_v.map, i, j);
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				check_player_existence(has_player);
				has_player = true;
			}
		}
	}
	if (!has_player)
		return (printf("Error\nNo player was found.\n"), exit(1));
}

void	scan_grid(int fd, t_data *data)
{
	t_node	*head;
	char	*line;
	size_t	max_length;
	size_t	rows;

	rows = 0;
	max_length = 0;
	head = NULL;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (max_length < ft_strlen(line))
			max_length = ft_strlen(line);
		append_node(&head, new_node(ft_strtrim(line, "\n")));
		rows++;
		free(line);
	}
	data->map_v.n_rows = rows;
	data->map_v.n_col = max_length;
	sanitize_lines(head);
	data->map_v.map = nodes_to_array(head, max_length);
	free_nodes(head);
}

void	parse_map(char *file, t_data *data)
{
	int	fd;

	data->mlx_v.mlx = mlx_init();
	data->sprite_node = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("Error\n"), exit(1));
	check_extension(file);
	parse_textures(fd, data);
	scan_grid(fd, data);
	sanitize_grid(data);
	parse_grid(data);
	prepare_gun(data);
}
