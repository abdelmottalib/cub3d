/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <aqiouami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:27:50 by aqiouami          #+#    #+#             */
/*   Updated: 2023/06/11 16:27:51 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		parse_map(av[1], &data);
		render_scene(&data);
	}
	else
		printf("Error\nUsage: ./cub3D [map].cub\n");
}
