/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <aqiouami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:30:21 by aqiouami          #+#    #+#             */
/*   Updated: 2023/06/11 16:30:22 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdio.h>

int	key_check(int keycode, t_data *data)
{
	if (keycode == A || keycode == D)
		data->player.sideways = true;
	if (keycode == ESC)
		exit(0);
	settings_keys(data, keycode);
	navigation_keys(data, keycode);
	movement_keys(data, keycode);
	return (0);
}

void	toggle_mouse(t_data *data)
{
	if (!data->player.mouse_toggle)
	{
		mlx_mouse_show();
		data->player.mouse_toggle = true;
	}
	else
	{
		mlx_mouse_hide();
		data->player.mouse_toggle = false;
	}
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == A || keycode == D)
		data->player.sideways = false;
	if (keycode == W || keycode == S || keycode == A || keycode == D)
		data->player.wd = 0;
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		data->player.td = 0;
	return (1);
}

int	mouse_hook(int x, int y __attribute__((unused)), t_data *data)
{
	static int	last_x = 640;
	static int	flag = 1;

	if (abs(last_x - x) > 2)
	{
		if (x > last_x && !data->player.mouse_toggle)
			data->player.td = !flag * abs(last_x - x) * 0.1;
		else if (x < last_x && !data->player.mouse_toggle)
			data->player.td = !flag * -1 * abs(last_x - x) * 0.1;
		if (data->player.td >= 5)
			data->player.td = 5;
		if (data->player.td <= -5)
			data->player.td = -5;
		flag = 0;
	}
	else
		data->player.td = 0;
	last_x = x;
	if (x < 0 || x > data->game_dims.win_width)
	{
		flag = 1;
		mlx_mouse_move(data->mlx_v.mlx_win, (int)(data->game_dims.win_width / \
			2), (int)data->game_dims.win_height / 2);
	}
	return (0);
}

int	ft_close(void)
{
	exit(1);
	return (0);
}
