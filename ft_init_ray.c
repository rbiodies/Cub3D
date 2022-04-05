/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:19:48 by bjeana            #+#    #+#             */
/*   Updated: 2022/04/05 20:20:20 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_player_dir(t_data *data)
{
	if (data->player->dir == 'N')
	{
		data->ray.dirx = 0;
		data->ray.diry = -1;
	}
	else if (data->player->dir == 'S')
	{
		data->ray.dirx = 0;
		data->ray.diry = 1;
	}
	else if (data->player->dir == 'W')
	{
		data->ray.dirx = 1;
		data->ray.diry = 0;
	}
	else if (data->player->dir == 'E')
	{
		data->ray.dirx = -1;
		data->ray.diry = 0;
	}
}

static void	ft_plane_dir(t_data *data)
{
	if (data->player->dir == 'N')
	{
		data->ray.planex = 0.66;
		data->ray.planey = 0;
	}
	else if (data->player->dir == 'S')
	{
		data->ray.planex = -0.66;
		data->ray.planey = 0;
	}
	else if (data->player->dir == 'W')
	{
		data->ray.planex = 0;
		data->ray.planey = -0.66;
	}
	else if (data->player->dir == 'E')
	{
		data->ray.planex = 0;
		data->ray.planey = 0.66;
	}
}

void	ft_init_ray(t_data *data)
{
	ft_player_dir(data);
	ft_plane_dir(data);
	data->ray.posx = (double)data->player->x;
	data->ray.posy = (double)data->player->y;
}