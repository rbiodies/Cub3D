/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:02:56 by rbiodies          #+#    #+#             */
/*   Updated: 2022/04/03 09:49:59 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_check_textures(char **path)
{
	int	i;
	int	fd;

	i = 0;
	while (path[i] != NULL)
	{
		if (path[i] == NULL)
			ft_putendl_error("Texture file is missing");
		if (ft_strcmp(".xpm", &path[i][ft_strlen(path[i]) - 4]) != 0)
			ft_putendl_error("Texture file doesn't have xpm extension");
		fd = open(path[i], O_RDONLY);
		if (fd < 0)
			ft_putendl_error("Could not open the texture file");
		close(fd);
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

static void	ft_check_player(char **map, t_player *player)
{
	int	i;
	int	j;
	int	count_player;

	count_player = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' \
			|| map[i][j] == 'S' || map[i][j] == 'W')
			{
				count_player++;
				player->x = j;
				player->y = i;
			}
			j++;
		}
		i++;
	}
	if (count_player != 1)
		ft_putendl_error("Map doesn't have player or has too many players");
}

static void	ft_check_walls(char	**map, int height)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
			{
				if (i == 0 || j == 0 \
				|| i == height - 1 || j == (int)ft_strlen(map[i]) - 1)
					ft_putendl_error("Map doesn't have wall");
				else if (map[i - 1][j - 1] == ' ' || map[i - 1][j] == ' ' \
				|| map[i - 1][j + 1] == ' ' || map[i][j + 1] == ' ' \
				|| map[i + 1][j + 1] == ' ' || map[i + 1][j] == ' ' \
				|| map[i + 1][j - 1] == ' ' || map[i][j - 1] == ' ')
					ft_putendl_error("Map doesn't have wall");
			}
			j++;
		}
		i++;
	}
}

void	ft_check_map(t_data *data)
{
	ft_check_textures(data->map->texture_path);
	ft_check_symbols(data->map->array);
	ft_check_player(data->map->array, data->player);
	ft_check_walls(data->map->array, data->map->height);
}
