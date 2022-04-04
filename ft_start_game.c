/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:10:16 by rbiodies          #+#    #+#             */
/*   Updated: 2022/04/04 11:36:29 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_init_textures(t_map *map)
{
	int		i;
	int		width;
	int		height;

	map->texture = (void **)malloc(sizeof(void *) * 5);
	if (map->texture == NULL)
		ft_putendl_error("Texture: Malloc error");
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
	exit(EXIT_SUCCESS);
}

static void	ft_init_mlx(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
}

static void	ft_player_dir(t_data *data)
{
	if (data->player->dir == 'N')
	{
		data->ray.dirx = 0;
		data->ray.diry = 1;
	}
	else if (data->player->dir == 'S')
	{
		data->ray.dirx = 0;
		data->ray.diry = -1;
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
		data->ray.planey = 0.66;
	}
	else if (data->player->dir == 'E')
	{
		data->ray.planex = 0;
		data->ray.planey = -0.66;
	}
}

static void	ft_init_ray(t_data *data)
{
	ft_player_dir(data);
	ft_plane_dir(data);
}

static void	ft_init_backimg(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->map->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img.mlx_data_addr = mlx_get_data_addr(data->img.img_ptr, \
	&data->img.bits_per_pixel, &data->img.size_line, &data->img.endian);
}

static void	ft_put_pix(t_data *data, int x, int y, int color)
{
	char	*pix;
	int		pos;

	pos = (y * data->img.size_line + x * (data->img.bits_per_pixel / 8));
	pix = data->img.mlx_data_addr + pos;
	*(unsigned int *)pix = color;
}

static void	ft_draw_corf(t_data *data, int a, int b, int color)
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

static int	ft_drawer(t_data *data)
{
	ft_init_backimg(data);
	ft_draw_corf(data, 0, WIN_HEIGHT / 2, data->map->ceil_color);
	ft_draw_corf(data, WIN_HEIGHT / 2, WIN_HEIGHT, data->map->floor_color);
	mlx_put_image_to_window(\
	data->map->mlx, data->map->win, data->img.img_ptr, 0, 0);
	mlx_destroy_image(data->map->mlx, data->img.img_ptr);
	return (0);
}

static void	ft_move(t_data *data)
{
	mlx_loop_hook(data->map->mlx, ft_main_loop, data);
	mlx_hook(data->map->win, 2, 0, ft_key_press, NULL);
	mlx_hook(data->map->win, 17, 0, ft_program_close, NULL);
	mlx_loop(data->map->mlx);
}

int	ft_start_game(t_data *data)
{
	ft_init_mlx(data->map);
	ft_init_ray(data);
	ft_init_textures(data->map);
	ft_drawer(data);
	ft_move(data);
	return (0);
}
