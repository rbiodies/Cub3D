/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:10:16 by rbiodies          #+#    #+#             */
/*   Updated: 2022/04/03 13:05:13 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_position_preset(t_map *map, t_player *player)
{
	(void)map;
	(void)player;
}

/*
initial direction vector

the 2d raycaster version of camera plane

Field of view (FOV) is 2 * atan(0.66/1.0)=66°, 
which is perfect for a first person shooter game
*/
static void	ft_direction_preset(t_map *map, t_player *player)
{
	(void)player;
	map->dirx = -1;
	map->diry = 0;
	map->planex = 0;
	map->planey = 0.66;
}

static void	ft_init_textures(t_map *map)
{
	int		i;
	int		width;
	int		height;

	i = 0;
	while (map->texture_path[i] != NULL)
	{
		width = 0;
		height = 0;
		map->texture[i] = \
		mlx_xpm_file_to_image(map->mlx, map->texture_path[i], &width, &height);
		if (height == 0 || width == 0)
			ft_putendl_error("Could not convert xpm file to image");
		i++;
	}
}

static int	ft_program_close(void)
{
	ft_putendl_fd("Exit the game", 1);
	exit(EXIT_FAILURE);
}

int	ft_start_game(t_map *map, t_player *player)
{
	map->mlx = mlx_init();
	ft_position_preset(map, player);
	ft_direction_preset(map, player);
	map->texture = (void **)malloc(sizeof(void *) * 5);
	if (map->texture == NULL)
		ft_putendl_error("Texture: Malloc error");
	ft_init_textures(map);
	map->win = mlx_new_window(map->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	mlx_loop_hook(map->mlx, &ft_main_loop, map);
	mlx_hook(map->win, 2, 0, ft_key_press, NULL);
	mlx_hook(map->win, 17, 0, ft_program_close, NULL);
	mlx_loop(map->mlx);
	return (0);
}
