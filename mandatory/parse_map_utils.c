/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:30:43 by samini            #+#    #+#             */
/*   Updated: 2023/06/11 16:30:48 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	check_extension(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (i > 3)
		i -= 4;
	if (i == 0)
		return (printf("Error\nInvalid file\n"), exit(1));
	if (ft_strcmp(s + i, ".cub"))
		return (printf("Error\nInvalid file extension\n"), exit(1));
}

bool	is_empty_line(char *line)
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
	free (line);
	return (true);
}

bool	ft_isspace(int c)
{
	if (c == 32)
		return (true);
	return (false);
}

bool	ft_isvalid(int c)
{
	if (ft_isspace(c) || c == '1' || c == '0'
		|| c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}

void	check_4sides(char **map, int i, int j)
{
	if (!(ft_isvalid(map[i + 1][j]) && !ft_isspace(map[i + 1][j])))
		return (ft_putstr_fd("Error\nInvalid map\n", 2), exit(1));
	if (!(ft_isvalid(map[i - 1][j]) && !ft_isspace(map[i - 1][j])))
		return (ft_putstr_fd("Error\nInvalid map\n", 2), exit(1));
	if (!(ft_isvalid(map[i][j + 1]) && !ft_isspace(map[i][j + 1])))
		return (ft_putstr_fd("Error\nInvalid map\n", 2), exit(1));
	if (!(ft_isvalid(map[i][j - 1]) && !ft_isspace(map[i][j - 1])))
		return (ft_putstr_fd("Error\nInvalid map\n", 2), exit(1));
}
