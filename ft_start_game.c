/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:10:16 by rbiodies          #+#    #+#             */
/*   Updated: 2022/04/02 19:00:21 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static void	init_mlx(void)
// {
// }

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
		// map->texture[i] = \
		// mlx_xpm_file_to_image(map->mlx, map->texture_path[i], &width, &height);
		if (height == 0 || width == 0)
		// 	ft_putendl_error("Could not convert xpm file to image");
		i++;
	}
}

static int	ft_key_press(int key)
{
	if (key == ESC)
	{
		ft_putendl_fd("\033[0;36mYou Enter the ESC Key. Good Bye! :)\033[0m", 1);
		exit(EXIT_SUCCESS);
	}
	// else if (key == W || key == UP)
	// 	ft_move();
	// else if (key == S || key == DOWN)
	// 	ft_move();
	// else if (key == A)
	// 	ft_strafe();
	// else if (key == D)
	// 	ft_strafe();
	// else if (key == LEFT)
	//	
	// else if (key == RIGHT)
	//	
	return (0);
}

static int	ft_program_close(void)
{
	ft_putendl_fd("Exit the game", 1);
	exit(EXIT_FAILURE);
}

int	ft_start_game(t_map *map)
{
	map->texture = (void **)malloc(sizeof(void *) * 5);
	if (map->texture == NULL)
		ft_putendl_error("Texture: Malloc error");
	ft_init_textures(map);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, 640, 480, "cub3D");
	mlx_hook(map->win, 2, 0, ft_key_press, NULL);
	mlx_hook(map->win, 17, 0, ft_program_close, NULL);
	mlx_loop(map->mlx);
	return (0);
}
