/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:17:53 by bjeana            #+#    #+#             */
/*   Updated: 2022/04/05 20:18:25 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_put_addr(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		map->texture[i].mlx_data_addr = mlx_get_data_addr(\
		map->texture[i].img_ptr, &map->texture[i].bits_per_pixel, \
		&map->texture[i].size_line, &map->texture[i].endian);
		i++;
	}	
}

void	ft_init_textures(t_map *map)
{
	int		i;
	int		width;
	int		height;

	map->texture = (t_img *)malloc(sizeof(t_img) * 4);
	if (map->texture == NULL)
		ft_putendl_error("Texture: Malloc error");
	i = 0;
	while (i < 4)
	{
		width = 0;
		height = 0;
		map->texture[i].img_ptr = \
		mlx_xpm_file_to_image(map->mlx, map->texture_path[i], &width, &height);
		if (height == 0 || width == 0)
			ft_putendl_error("Could not convert xpm file to image");
		i++;
	}
	ft_put_addr(map);
}