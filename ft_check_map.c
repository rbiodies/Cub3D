/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:02:56 by rbiodies          #+#    #+#             */
/*   Updated: 2022/04/01 18:57:39 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_check_textures(char **texture)
{
	int	i;

	i = 0;
	while (texture[i] != NULL)
	{
		if (texture[i] == NULL)
			ft_putendl_error("Texture file is missing");
		if (ft_strcmp(".xpm", &texture[i][ft_strlen(texture[i]) - 4]) != 0)
			ft_putendl_error("Texture file doesn't have xpm extension");
		// if (open(texture[i], O_RDONLY) < 0)
		// 	ft_putendl_error("Could not open the texture file");
		i++;
	}
}

static void	ft_check_symbols(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'N' && map[i][j] != 'E' \
			&& map[i][j] != 'S' && map[i][j] != 'W' \
			&& map[i][j] != ' ' && map[i][j] != '0' && map[i][j] != '1')
				ft_putendl_error("Map has invalid symbol");
			j++;
		}
		i++;
	}
}

static void	ft_check_player(t_data *data)
{
	int	i;
	int	j;
	int	player;

	player = 0;
	i = 0;
	while (data->map->array[i] != NULL)
	{
		j = 0;
		while (data->map->array[i][j] != '\0')
		{
			if (data->map->array[i][j] == 'N' || data->map->array[i][j] == 'E' \
			|| data->map->array[i][j] == 'S' || data->map->array[i][j] == 'W')
			{
				player++;
				data->player->x = j;
				data->player->y = i;
			}
			j++;
		}
		i++;
	}
	if (player != 1)
		ft_putendl_error("Map doesn't have player or has too many players");
}

static void	ft_check_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->array[i] != NULL)
	{
		j = 0;
		while (data->map->array[i][j] != '\0')
		{
			if (i == 0 || j == 0 || i == data->map->height \
			|| j == (int)ft_strlen(data->map->array[i]) - 1)
				if (data->map->array[i][j] != '1')
					ft_putendl_error("Map doesn't have wall");
			j++;
		}
		i++;
	}
}

void	ft_check_map(t_data *data)
{
	ft_check_textures(data->map->texture);
	ft_check_symbols(data->map->array);
	ft_check_player(data);
	ft_check_walls(data);
}
