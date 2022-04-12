/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_background.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:47:35 by bjeana            #+#    #+#             */
/*   Updated: 2022/04/12 17:37:28 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_backimg(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->map->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img.mlx_data_addr = mlx_get_data_addr(data->img.img_ptr, \
	&data->img.bits_per_pixel, &data->img.size_line, &data->img.endian);
}

void	ft_put_pix(t_data *data, int x, int y, int color)
{
	char	*pix;
	int		pos;

	pos = (y * data->img.size_line + x * (data->img.bits_per_pixel / 8));
	pix = data->img.mlx_data_addr + pos;
	*(unsigned int *)pix = color;
}

void	ft_draw_corf(t_data *data, int a, int b, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = a;
		while (y < b)
		{
			ft_put_pix(data, x, y, color);
			y++;
		}
		x++;
	}
}
