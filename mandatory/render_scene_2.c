/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:30:07 by aqiouami          #+#    #+#             */
/*   Updated: 2023/06/12 12:28:34 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_constants(t_data *data)
{
	data->constants.deg2rad = M_PI / 180;
	data->constants.fov = 60 * data->constants.deg2rad;
}

void	init_settings(t_data *data)
{
	data->menu[0] = (t_menu){"Continue [Enter]", 600, 350};
	data->menu[1] = (t_menu){"Settings [c]", 600, 400};
	data->menu[2] = (t_menu){"Quit [Esc]", 600, 450};
	data->settings[0] = (t_menu){NULL, 600, 350};
	data->settings[1] = (t_menu){"shadows: [/]", 600, 400};
	data->settings[2] = (t_menu){"show mouse: show or hide [M]", 600, 450};
	data->settings[3] = (t_menu){"back: backspace", 600, 500};
}

void	init_scene(t_data *data)
{
	data->mlx_v.mlx_win = mlx_new_window(data->mlx_v.mlx, \
		data->game_dims.win_width, data->game_dims.win_height, "Hello world!");
	data->paint.img = mlx_new_image(data->mlx_v.mlx, \
		data->game_dims.win_width, data->game_dims.win_height);
	data->paint.addr = mlx_get_data_addr(data->paint.img, \
		&data->paint.bits_per_pixel, &data->paint.line_length, \
			&data->paint.endian);
	check_xpm(data, "../texture/assets/door/door_00.xpm");
	data->txtr[4].img = mlx_xpm_file_to_image(data->mlx_v.mlx, \
		"../texture/assets/door/door_00.xpm", &data->txtr[4].h, \
			&data->txtr[4].w);
	data->txtr[4].array = \
		(unsigned int *)mlx_get_data_addr(data->txtr[4].img, \
		&data->txtr[4].bits_per_pixel, &data->txtr[4].line_length, \
			&data->txtr[4].endian);
}
