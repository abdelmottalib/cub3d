/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:30:09 by aqiouami          #+#    #+#             */
/*   Updated: 2023/06/11 17:11:25 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdio.h>

void	draw(t_data *data)
{
	static int	a;

	draw_walls(data);
	draw_sprites(data);
	draw_gun(data);
	a++;
	if (a > 10)
	{
		a = 0;
		data->player.td = 0;
	}
}

void	update(t_data *data)
{
	update_walk_and_turn(data);
	cast_rays(data);
}

int	render_loop(t_data *data)
{
	update(data);
	draw(data);
	options_menu(data);
	return (0);
}
