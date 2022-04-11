/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ray_and_tex_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:19:48 by bjeana            #+#    #+#             */
/*   Updated: 2022/04/11 19:54:16 by bjeana           ###   ########.fr       */
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
	data->ray.posx = (double)data->player->x + 0.5;
	data->ray.posy = (double)data->player->y + 0.5;
}

void	ft_init_textures(t_map *map)
{
	int		i;
	int		width;
	int		height;

	map->texture = (t_img1 *)malloc(sizeof(t_img1) * 4);
	if (map->texture == NULL)
		ft_putendl_error("Texture: Malloc error");
	i = 0;
	while (i < 4)
	{
		map->texture[i].img_ptr = \
		mlx_xpm_file_to_image(map->mlx, map->texture_path[i], &width, &height);
		if (height <= 0 || width <= 0)
			ft_putendl_error("Could not convert xpm file to image");
		map->texture[i].mlx_data_addr = (int *)mlx_get_data_addr(\
		map->texture[i].img_ptr, &map->texture[i].bits_per_pixel, \
		&map->texture[i].size_line, &map->texture[i].endian);
		i++;
	}
}
