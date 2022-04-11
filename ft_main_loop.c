/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:06:32 by rbiodies          #+#    #+#             */
/*   Updated: 2022/04/11 19:42:38 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* calculate ray position and direction */
/* which box of the map we're in */
static void	ft_ray_pos_and_dir(t_ray *ray, int x)
{
	ray->camerax = 2 * x / (double)WIN_WIDTH - 1;
	ray->raydirx = ray->dirx + ray->planex * ray->camerax;
	ray->raydiry = ray->diry + ray->planey * ray->camerax;
	ray->mapx = (int)ray->posx;
	ray->mapy = (int)ray->posy;
}

/* length of ray from one x or y-side to next x or y-side */
static void	ft_delta(t_ray *ray)
{
	if (ray->raydirx != 0)
		ray->deltadistx = sqrt(1 + (ray->raydiry * ray->raydiry) \
		/ (ray->raydirx * ray->raydirx));
	else
		ray->deltadistx = 1e30;
	if (ray->raydiry != 0)
		ray->deltadisty = sqrt(1 + (ray->raydirx * ray->raydirx) \
		/ (ray->raydiry * ray->raydiry));
	else
		ray->deltadisty = 1e30;
}

/* calculate step and initial sideDist */
static void	ft_init_step_and_sidedist(t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - ray->posx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - ray->posy) * ray->deltadisty;
	}
}

/* make step and check if ray has hit a wall */
static void	ft_get_ray_hit(t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->ray.sidedistx < data->ray.sidedisty)
		{
			data->ray.sidedistx += data->ray.deltadistx;
			data->ray.mapx += data->ray.stepx;
			data->ray.side = 0;
		}
		else
		{
			data->ray.sidedisty += data->ray.deltadisty;
			data->ray.mapy += data->ray.stepy;
			data->ray.side = 1;
		}
		if (data->map->array[data->ray.mapy][data->ray.mapx] == '1')
			hit = 1;
	}
}

int	ft_main_loop(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		ft_ray_pos_and_dir(&data->ray, x);
		ft_delta(&data->ray);
		ft_init_step_and_sidedist(&data->ray);
		ft_get_ray_hit(data);
		ft_distance_of_perpendicular_ray(&data->ray);
		ft_get_stripe_params(&data->ray);
		ft_get_texture_side(&data->ray);
		ft_define_wallx(&data->ray);
		ft_fill_verticals(data, &data->ray, data->map, x);
		x++;
	}
	return (0);
}
