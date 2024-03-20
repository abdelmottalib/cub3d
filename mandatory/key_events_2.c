/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <aqiouami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:30:23 by aqiouami          #+#    #+#             */
/*   Updated: 2023/06/11 16:30:24 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	movement_keys(t_data *data, int keycode)
{
	if (keycode == S || keycode == A)
		data->player.wd = -1;
	else if (keycode == W || keycode == D)
		data->player.wd = 1;
	else if (keycode == KEY_LEFT)
		data->player.td = -1;
	else if (keycode == KEY_RIGHT)
		data->player.td = 1;
}

void	navigation_keys(t_data *data, int keycode)
{
	if (keycode == TICK)
		data->game_flag = IN_GAME;
	if (keycode == C)
		data->game_flag = IN_SETTINGS;
	if (keycode == BACK || keycode == ENTER)
	{
		if (data->game_flag == IN_GAME)
			data->game_flag = IN_OPTIONS;
		else
			data->game_flag = IN_GAME;
	}
}

void	settings_keys(t_data *data, int keycode)
{
	if (keycode == M)
		if (data->game_flag == IN_SETTINGS)
			toggle_mouse(data);
	if (keycode == PLUS)
	{
		if (data->game_flag == IN_SETTINGS)
			data->player.ms += 1;
	}
	else if (keycode == SLASH)
	{
		if (data->game_flag == IN_SETTINGS)
		{
			if (data->shadow_flag == 0)
				data->shadow_flag = 1;
			else
				data->shadow_flag = 0;
		}
	}
	else if (keycode == MINUS)
	{
		if (data->game_flag == IN_SETTINGS)
			data->player.ms += -1;
	}
}

int	mouse_hook_2(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 1)
		shoot_gun(data);
	return (0);
}

int	handle_mouse_release(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 1)
		data->is_shooting = false;
	return (0);
}
