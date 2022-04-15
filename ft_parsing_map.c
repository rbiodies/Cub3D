/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:28:10 by rbiodies          #+#    #+#             */
/*   Updated: 2022/04/12 19:04:45 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_check_filename(char *filename)
{
	int		fd;
	char	*line;
	int		i;
	int		height;

	fd = open(filename, O_DIRECTORY);
	if (fd > 0)
		ft_putendl_error("This is folder");
	fd = open(filename, O_RDONLY);
	if (fd < 0 || ft_strcmp(".cub", &filename[ft_strlen(filename) - 4]) != 0)
		ft_putendl_error("Could not open map");
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] == '1')
			height++;
		free(line);
	}
	if (height < 3)
		ft_putendl_error("Height of map is too few");
	return (height);
}

static void	ft_init(t_map *map)
{
	map->texture_path = (char **)ft_calloc(sizeof(char *), 5);
	if (map->texture_path == NULL)
		ft_putendl_error("Texture Path: Malloc error");
	map->floor_color = -1;
	map->ceil_color = -1;
	map->array \
	= (char **)ft_calloc(sizeof(char *), map->height + 1);
	if (map->array == NULL)
		ft_putendl_error("Array: Malloc error");
}

static int	ft_parsing_textures(char **path, char *line)
{
	int	i;

	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0 \
	|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
			i = 0;
		else if (ft_strncmp(line, "SO ", 3) == 0)
			i = 1;
		else if (ft_strncmp(line, "WE ", 3) == 0)
			i = 2;
		else
			i = 3;
		if (path[i] != NULL)
			ft_putendl_error("This texture is existing already");
		path[i] = ft_strdup(line + 3);
		return (1);
	}
	return (0);
}

static void	ft_get_data(t_map *map, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_parsing_textures(map->texture_path, line + i))
		return ;
	else if (ft_parsing_colors(map, line + i))
		return ;
	else if (line[i] == '1')
	{
		while (map->array[j] != NULL)
			j++;
		map->array[j] = ft_strdup(line);
	}
	else if (line[i] != '\n')
		ft_putendl_error("Unknown symbol or no wall or miss symbol");
}

void	ft_parsing_map(t_data *data, char *filename)
{
	int		fd;
	char	*line;

	data->map->height = ft_check_filename(filename);
	ft_init(data->map);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_putendl_error("Could not open map");
	while (get_next_line(fd, &line) > 0)
	{
		ft_get_data(data->map, line);
		free(line);
	}
	close(fd);
	if (data->map->array == NULL)
		ft_putendl_error("Map is empty");
	ft_check_map(data);
}
