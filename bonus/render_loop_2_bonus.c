/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:53:25 by samini            #+#    #+#             */
/*   Updated: 2023/06/19 11:17:56 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	options_menu(t_data *data)
{	
	t_infos	s;

	if (data->game_flag == IN_OPTIONS)
		mlx_put_image_to_window(data->mlx_v.mlx, data->mlx_v.mlx_win, \
	data->paint.img, 0, 0);
	else if (data->game_flag == IN_GAME)
	{
		check_xpm(data, "./background_8.xpm");
		s.img = mlx_xpm_file_to_image(data->mlx_v.mlx,
				"./background_8.xpm", &s.w, &s.h);
		mlx_put_image_to_window(data->mlx_v.mlx,
			data->mlx_v.mlx_win, s.img, 0, 0);
		render_menu(data);
		mlx_destroy_image(data->mlx_v.mlx, s.img);
	}
	else if (data->game_flag == IN_SETTINGS)
	{
		check_xpm(data, "./background_8.xpm");
		s.img = mlx_xpm_file_to_image(data->mlx_v.mlx,
				"./background_8.xpm", &s.w, &s.h);
		mlx_put_image_to_window(data->mlx_v.mlx,
			data->mlx_v.mlx_win, s.img, 0, 0);
		render_settings(data);
		mlx_destroy_image(data->mlx_v.mlx, s.img);
	}
}

void	render_menu(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		mlx_string_put(data->mlx_v.mlx, data->mlx_v.mlx_win,
			data->menu[i].x, data->menu[i].y, 0xffffff, data->menu[i].label);
	}
}

void	render_settings(t_data *data)
{
	int		i;
	char	*speed_number;
	char	*temp;

	temp = ft_itoa(data->player.ms);
	speed_number = ft_strjoin("speed: + or - : ", temp);
	free(temp);
	data->settings[0].label = speed_number;
	if (data->shadow_flag)
		data->settings[1].label = "shading: enabled [/]";
	else if (!data->shadow_flag)
		data->settings[1].label = "shading: disabled [/]";
	if (data->player.mouse_toggle == true)
		data->settings[2].label = "mouse: show [M]";
	else if (data->player.mouse_toggle == false)
		data->settings[2].label = "mouse: hide [M]";
	i = -1;
	while (++i < 4)
	{
		mlx_string_put(data->mlx_v.mlx, data->mlx_v.mlx_win,
			data->settings[i].x, data->settings[i].y,
			0xffffff, data->settings[i].label);
	}
	free(speed_number);
}
