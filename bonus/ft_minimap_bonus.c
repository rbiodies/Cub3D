/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:08:29 by bjeana            #+#    #+#             */
/*   Updated: 2022/04/11 18:10:59 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_draw_player(t_data *data, int a, int b, int color)
{
	int	x;
	int	y;
	int	copy_a;

	y = 0;
	a = a * 8;
	b = b * 8;
	while (y < 8)
	{
		x = 0;
		copy_a = a;
		while (x < 8)
		{
			ft_put_pix(data, copy_a, b, color);
			x++;
			copy_a++;
		}
		b++;
		y++;
	}
}
static  void	ft_draw_wall(t_data *data, int a, int b, int color)
{
	int	x;
	int	y;
	int	copy_a;

	y = 0;
	a = a * 8;
	b = b * 8;
	while (y < 8)
	{
		x = 0;
		copy_a = a;
		while (x < 8)
		{
			ft_put_pix(data, copy_a, b, color);
			x++;
			copy_a++;
		}
		b++;
		y++;
	}
}

void	ft_minimap(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map->array[y] != NULL)
	{
		x = 0;
		while (data->map->array[y][x] != '\0')
		{
			if (data->map->array[y][x] == '1')
				ft_draw_wall(data, x + 1, y + 1, 24);
			else if (data->map->array[y][x] == 'N' || data->map->array[y][x] == 'S' ||\
			data->map->array[y][x] == 'W' || data->map->array[y][x] == 'E')
				ft_draw_player(data, x + 1, y + 1, 9172004);
			x++;
		}
		y++;
	}
}