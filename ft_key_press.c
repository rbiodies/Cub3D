/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:40:17 by rbiodies          #+#    #+#             */
/*   Updated: 2022/04/11 15:09:39 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_key_esc(void)
{
	ft_putendl_fd("\033[0;36mYou Enter the ESC Key. Good Bye! :)\033[0m", 1);
	exit(EXIT_SUCCESS);
}

void	ft_move_round(int key, t_ray *ray)
{
	double	olddirx;
	double	oldplanex;

	olddirx = ray->dirx;
	oldplanex = ray->planex;
	if (key == LEFT)
	{
		ray->dirx \
		= ray->dirx * cos(-ray->rot) - ray->diry * sin(-ray->rot);
		ray->diry = olddirx * sin(-ray->rot) + ray->diry * cos(-ray->rot);
		ray->planex \
		= ray->planex * cos(-ray->rot) - ray->planey * sin(-ray->rot);
		ray->planey \
		= oldplanex * sin(-ray->rot) + ray->planey * cos(-ray->rot);
	}
	else if (key == RIGHT)
	{
		ray->dirx = ray->dirx * cos(ray->rot) - ray->diry * sin(ray->rot);
		ray->diry = olddirx * sin(ray->rot) + ray->diry * cos(ray->rot);
		ray->planex \
		= ray->planex * cos(ray->rot) - ray->planey * sin(ray->rot);
		ray->planey \
		= oldplanex * sin(ray->rot) + ray->planey * cos(ray->rot);	
	}
}

int	ft_move_rl(int key, t_data *data)
{
	if (key == A)
	{
		if (data->map->array[(int)(data->ray.posy)][(int)(data->ray.posx \
		- data->ray.planex * data->ray.move)] != '1')
			data->ray.posx -= data->ray.planex * data->ray.move;
		if (data->map->array[(int)(data->ray.posy \
		+ data->ray.planey * data->ray.move)][(int)(data->ray.posx)] != '1')
			data->ray.posy -= data->ray.planey * data->ray.move;
	}
	else if (key == D)
	{
		if (data->map->array[(int)(data->ray.posy)][(int)(data->ray.posx \
		+ data->ray.planex * data->ray.move)] != '1')
			data->ray.posx += data->ray.planex * data->ray.move;
		if (data->map->array[(int)(data->ray.posy \
		- data->ray.planey * data->ray.move)][(int)(data->ray.posx)] != '1')
			data->ray.posy += data->ray.planey * data->ray.move;
	}
	return (0);
}

int	ft_move_uw(int key, t_data *data)
{
	if (key == W)
	{
		if (data->map->array[(int)(data->ray.posy)][(int)(data->ray.posx \
		+ data->ray.dirx * data->ray.move)] != '1')
			data->ray.posx += data->ray.dirx * data->ray.move;
		if (data->map->array[(int)(data->ray.posy \
		+ data->ray.diry * data->ray.move)][(int)(data->ray.posx)] != '1')
			data->ray.posy += data->ray.diry * data->ray.move;
	}
	else if (key == S)
	{
		if (data->map->array[(int)(data->ray.posy)][(int)(data->ray.posx \
		- data->ray.dirx * data->ray.move)] != '1')
			data->ray.posx -= data->ray.dirx * data->ray.move;
		if (data->map->array[(int)(data->ray.posy \
		- data->ray.diry * data->ray.move)][(int)(data->ray.posx)] != '1')
			data->ray.posy -= data->ray.diry * data->ray.move;
	}
	return (0);
}

int	ft_key_press(int key, t_data *data)
{
	data->ray.move = 0.08;
	data->ray.rot = 0.04;
	if (key == ESC)
		ft_key_esc();
	else if (key == W || key == S)
		ft_move_uw(key, data);
	else if (key == A || key == D)
		ft_move_rl(key, data);
	else if (key == LEFT || key == RIGHT)
		ft_move_round(key, &data->ray);
	return (0);
}
