/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loaders_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:31:28 by samini            #+#    #+#             */
/*   Updated: 2023/06/14 17:31:25 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	sanitize_colors(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (printf("Error\nInvalid colors.\n"), exit(1));
}

void	get_texture(t_data *data, char *id, char *value, bool texture[4])
{
	char			*arr[2];
	t_texture_type	type;

	type = NORTH;
	if (!ft_strcmp(id, "SO"))
		type = SOUTH;
	else if (!ft_strcmp(id, "WE"))
		type = WEST;
	else if (!ft_strcmp(id, "EA"))
		type = EAST;
	if (texture[type] == true)
		return (printf("Error\nRepeated texure type\n"), exit(1));
	arr[0] = id;
	arr[1] = value;
	check_xpm(data, value);
	data->txtr[type].img = mlx_xpm_file_to_image
		(data->mlx_v.mlx, arr[1], &data->txtr[type].h, &data->txtr[type].w);
	data->txtr[type].array = (unsigned int *)mlx_get_data_addr(
			data->txtr[type].img, &data->txtr[type].bits_per_pixel,
			&data->txtr[type].line_length, &data->txtr[type].endian);
	texture[type] = true;
}

void	get_floor(t_data *data, char *value, bool *flceil)
{
	char	**colors;
	int		i;
	int		rgb[3];

	if (flceil[0] == true)
		return (printf("Error\nRepeated floor entry\n"), exit(1));
	sanitize_colors(value);
	colors = ft_split(value, ',');
	if (!colors)
		return (ft_putstr_fd("Error\nCouldn't allocate memory\n", 2), exit(1));
	i = 0;
	while (colors[i])
		i++;
	if (i != 3)
		return (printf("Error\nInvalid colors.\n"), exit(1));
	rgb[0] = ft_atoi(colors[0]);
	rgb[1] = ft_atoi(colors[1]);
	rgb[2] = ft_atoi(colors[2]);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0
		|| rgb[1] > 255 || rgb[2] < 0 || rgb[2] > 255)
		return (printf("Error\nInvalid color value.\n"), exit(1));
	data->color.floor = make_color(rgb[0], rgb[1], rgb[2]);
	flceil[0] = true;
	free_bins(colors);
}

void	get_ceiling(t_data *data, char *value, bool *flceil)
{
	char	**colors;
	int		i;
	int		rgb[3];

	if (flceil[1] == true)
		return (printf("Error\nRepeated ceiling entry\n"), exit(1));
	sanitize_colors(value);
	colors = ft_split(value, ',');
	if (!colors)
		return (ft_putstr_fd("Error\nCouldn't allocate memory\n", 2), exit(1));
	i = 0;
	while (colors[i])
		i++;
	if (i != 3)
		return (printf("Error\nInvalid colors.\n"), exit(1));
	rgb[0] = ft_atoi(colors[0]);
	rgb[1] = ft_atoi(colors[1]);
	rgb[2] = ft_atoi(colors[2]);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0
		|| rgb[1] > 255 || rgb[2] < 0 || rgb[2] > 255)
		return (printf("Error\nInvalid color value.\n"), exit(1));
	data->color.ceiling = make_color(rgb[0], rgb[1], rgb[2]);
	flceil[1] = true;
	free_bins(colors);
}

void	get_data(t_data *data, char **arr, bool texture[4], bool flceil[2])
{
	char	*id;
	char	*value;

	if (!arr)
		return (ft_putstr_fd("Error\nCouldn't allocate memory\n", 2), exit(1));
	if (!arr[0] || !arr[1] || arr[2])
		return (printf("Error\nInvalid map\n"), exit(1));
	id = arr[0];
	value = ft_strtrim(arr[1], "\n");
	if (!ft_strcmp(id, "NO") || !ft_strcmp(id, "SO")
		|| !ft_strcmp(id, "WE") || !ft_strcmp(id, "EA"))
		get_texture(data, id, value, texture);
	else if (!ft_strcmp(id, "F"))
		get_floor(data, value, flceil);
	else if (!ft_strcmp(id, "C"))
		get_ceiling(data, value, flceil);
	else
		return (printf("Error\nInvalid identifier\n"), exit(1));
	free(value);
}
