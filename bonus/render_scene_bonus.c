/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <aqiouami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:30:04 by aqiouami          #+#    #+#             */
/*   Updated: 2023/06/11 16:30:05 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdio.h>

void	initial_init(t_data *data)
{
	data-> game_dims.win_width = 1280;
	data-> game_dims.win_height = 832;
	data->game_dims.m_scale = 0.35;
	load_door_frames(data);
	init_settings(data);
	init_scene(data);
	data->test = 0;
	data->game_flag = 1;
	data->shadow_flag = 1;
	data->ray = NULL;
}

void	init_player(t_data *data)
{
	data->player.td = 0;
	data->player.mouse_toggle = false;
	data->player.sideways = false;
	data->player.wd = 0;
	if (data->player.direction == 'S')
		data->player.ra = M_PI / 2;
	else if (data->player.direction == 'E')
		data->player.ra = 0;
	else if (data->player.direction == 'W')
		data->player.ra = M_PI;
	else if (data->player.direction == 'N')
		data->player.ra = 1.5 * M_PI;
	data->player.ms = 5.0;
	data->player.rs = 2 * data->constants.deg2rad;
}

void	handle_hooks(t_data *data)
{
	mlx_mouse_hide();
	mlx_hook(data->mlx_v.mlx_win, 2, \
		0, key_check, data);
	mlx_hook(data->mlx_v.mlx_win, 17, \
		0, ft_close, NULL);
	mlx_hook(data->mlx_v.mlx_win, 6, \
		0, mouse_hook, data);
	mlx_hook(data->mlx_v.mlx_win, 3, \
		0, key_release, data);
	mlx_mouse_hook(data->mlx_v.mlx_win, mouse_hook_2, data);
	mlx_hook(data->mlx_v.mlx_win, 5, 0,
		handle_mouse_release, data);
}

void	render_scene(t_data *data)
{
	init_constants(data);
	initial_init(data);
	init_player(data);
	handle_hooks(data);
	mlx_loop_hook(data->mlx_v.mlx, render_loop, data);
	mlx_loop(data->mlx_v.mlx);
}
