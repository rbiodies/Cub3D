/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:10:16 by rbiodies          #+#    #+#             */
/*   Updated: 2022/04/01 15:35:36 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
void	init_mlx()
{
	
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
	// else if (key == A || key == LEFT)
	// 	ft_strafe();
	// else if (key == D || key == RIGHT)
	// 	ft_strafe();
	return (0);
}

static int	ft_program_close(void)
{
	ft_putendl_fd("Exit the game", 1);
	exit(EXIT_FAILURE);
}

int	ft_start_game(t_data *data)
{
	data->map->mlx = mlx_init();
	data->map->win = mlx_new_window(data->map->mlx, 640, 480, "cub3D");
	mlx_loop_hook(data->map->mlx, &ft_main_loop, data->map);
	mlx_hook(data->map->win, 2, 0, ft_key_press, NULL);
	mlx_hook(data->map->win, 17, 0, ft_program_close, NULL);
	mlx_loop(data->map->mlx);
	return (0);
}
