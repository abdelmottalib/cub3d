/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:39:39 by samini            #+#    #+#             */
/*   Updated: 2023/06/12 12:29:16 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	prepare_gun(t_data *data)
{
	int		i;
	char	buffer[40];

	i = 0;
	while (i < GUN_ANIMATIONS)
	{
		ft_memcpy(buffer, "../texture/pistol/gun00.xpm",
			ft_strlen("../texture/pistol/gun00.xpm") + 1);
		buffer[21] = '0' + (i / 10);
		buffer[22] = '0' + (i % 10);
		check_xpm(data, buffer);
		data->gun_txtr[i].img = mlx_xpm_file_to_image(data->mlx_v.mlx,
				buffer, &data->gun_txtr[i].w, &data->gun_txtr[i].h);
		data->gun_txtr[i].array = (unsigned int *)mlx_get_data_addr
			(data->gun_txtr[i].img, &data->gun_txtr[i].bits_per_pixel,
				&data->gun_txtr[i].line_length, &data->gun_txtr[i].endian);
		i++;
	}
}

void	draw_gun_texture(t_data *data, int gun_ptr)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < data->gun_txtr[gun_ptr].h)
	{
		j = 0;
		while (j < data->gun_txtr[gun_ptr].w)
		{
			color = data->gun_txtr[gun_ptr].array[i
				* data->gun_txtr[gun_ptr].w + j];
			if (!(((color >> 24) & 0xFF) == 0xFF))
				my_mlx_pixel_put(data, j + GUN_X, i + GUN_Y, color);
			j++;
		}
		i++;
	}
}

void	draw_gun(t_data *data)
{
	static int	counter;
	static int	anim_ptr;
	int			gun_ptr;

	counter++;
	if (counter > 1)
	{
		anim_ptr = (anim_ptr + 1) % GUN_ANIMATIONS;
		counter = 0;
	}
	if (!data->is_shooting)
		gun_ptr = 0;
	else
		gun_ptr = anim_ptr;
	draw_gun_texture(data, gun_ptr);
}

void	kill_sprite(t_data *data, t_sprite *sprite)
{
	(void)data;
	sprite->is_dead = true;
}

void	shoot_gun(t_data *data)
{
	t_sprite	*sprite;

	data->is_shooting = true;
	sprite = data->sprite_node;
	while (sprite)
	{
		if (sprite->is_shootable && !sprite->is_dead)
			kill_sprite(data, sprite);
		sprite = sprite->next;
	}
}
