/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:40:17 by rbiodies          #+#    #+#             */
/*   Updated: 2022/04/05 10:30:55 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_key_esc(void)
{
	ft_putendl_fd("\033[0;36mYou Enter the ESC Key. Good Bye! :)\033[0m", 1);
	exit(EXIT_SUCCESS);
}

/*
rotate to the left
both camera direction and camera plane must be rotated
rotate to the right
both camera direction and camera plane must be rotated
*/
static void	ft_key_press_2(int key, t_ray ray)
{
	double	olddirx;
	double	oldplanex;

	olddirx = ray.dirx;
	oldplanex = ray.planex;
	if (key == A || key == LEFT)
	{
		ray.dirx = ray.dirx * cos(ray.rotspeed) - ray.diry * sin(ray.rotspeed);
		ray.diry = olddirx * sin(ray.rotspeed) + ray.diry * cos(ray.rotspeed);
		ray.planex \
		= ray.planex * cos(ray.rotspeed) - ray.planey * sin(ray.rotspeed);
		ray.planey \
		= oldplanex * sin(ray.rotspeed) + ray.planey * cos(ray.rotspeed);
	}
	else if (key == D || key == RIGHT)
	{
		ray.dirx \
		= ray.dirx * cos(-ray.rotspeed) - ray.diry * sin(-ray.rotspeed);
		ray.diry = olddirx * sin(-ray.rotspeed) + ray.diry * cos(-ray.rotspeed);
		ray.planex \
		= ray.planex * cos(-ray.rotspeed) - ray.planey * sin(-ray.rotspeed);
		ray.planey \
		= oldplanex * sin(-ray.rotspeed) + ray.planey * cos(-ray.rotspeed);
	}
}

/*
speed modifiers
double moveSpeed //the constant value is in squares/second
double rotSpeed //the constant value is in radians/second
move forward if no wall in front of you
move backwards if no wall behind you
*/
int	ft_key_press(int key, t_data *data)
{
	data->ray.movespeed = 0.08;
	data->ray.rotspeed = 0.08;
	if (key == ESC)
		ft_key_esc();
	else if (key == W || key == UP)
	{
		if (data->map->array[(int)(data->ray.posx + data->ray.dirx \
		* data->ray.movespeed)][(int)(data->ray.posy)] == '0')
			data->ray.posx += data->ray.dirx * data->ray.movespeed;
		if (data->map->array[(int)(data->ray.posx)][(int)(data->ray.posy \
		+ data->ray.diry * data->ray.movespeed)] == '0')
			data->ray.posy += data->ray.diry * data->ray.movespeed;
	}
	else if (key == S || key == DOWN)
	{
		if (data->map->array[(int)(data->ray.posx - data->ray.dirx \
		* data->ray.movespeed)][(int)(data->ray.posy)] == '0')
			data->ray.posx -= data->ray.dirx * data->ray.movespeed;
		if (data->map->array[(int)(data->ray.posx)][(int)(data->ray.posy \
		- data->ray.diry * data->ray.movespeed)] == '0')
			data->ray.posy -= data->ray.diry * data->ray.movespeed;
	}
	else
		ft_key_press_2(key, data->ray);
	return (0);
}
