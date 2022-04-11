/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_loop_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:00:30 by bjeana            #+#    #+#             */
/*   Updated: 2022/04/11 16:40:23 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* calculate height of line to draw on screen and
   lowest and highest pixel to fill in current stripe */
void	ft_get_stripe_params(t_ray *ray)
{
	ray->lineheight = (int)(WIN_HEIGHT / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + WIN_HEIGHT / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + WIN_HEIGHT / 2;
	if (ray->drawend >= WIN_HEIGHT)
		ray->drawend = WIN_HEIGHT - 1;
}

/* define side and its texture */
void	ft_get_texture_side(t_ray *ray)
{
	if (ray->side == 1 && ray->raydiry < 0)
		ray->texnum = 0;
	else if (ray->side == 1 && ray->raydiry > 0)
		ray->texnum = 1;
	else if (ray->side == 0 && ray->raydirx > 0)
		ray->texnum = 2;
	else if (ray->side == 0 && ray->raydirx < 0)
		ray->texnum = 3;
}

/* calculate value of wallX ana texX*/
/* floor rounding to the nearest whole number */
void	ft_define_wallx(t_ray *ray)
{
	if (ray->side == 0)
		ray->wallx = ray->posy + ray->perpwalldist * ray->diry;
	else
		ray->wallx = ray->posx + ray->perpwalldist * ray->dirx;
	ray->wallx -= floor(ray->wallx);
	ray->texx = (int)(ray->wallx * (double)TEXWIDTH);
	if (ray->side == 0 && ray->dirx > 0)
		ray->texx = TEXWIDTH - ray->texx - 1;
	if (ray->side == 1 && ray->raydiry < 0)
		ray->texx = TEXWIDTH - ray->texx - 1;
	ray->step = (double)TEXHIGHT / ray->lineheight;
	ray->texpos = (ray->drawstart - WIN_HEIGHT \
	/ 2 + ray->lineheight / 2) * ray->step;
}

void	ft_fill_verticals(t_data *data, t_ray *ray, t_map *map, int x)
{
	int	y;
	int	texy;
	int	color;

	y = ray->drawstart;
	while (y <= ray->drawend)
	{
		texy = (int)ray->texpos & (TEXHIGHT - 1);
		data->ray.texpos += data->ray.step;
		color = \
		map->texture[ray->texnum].mlx_data_addr[TEXWIDTH * texy + ray->texx];
		ft_put_pix(data, x, y, color);
		y++;
	}
}

/* calculate distance of perpendicular ray */
void	ft_distance_of_perpendicular_ray(t_ray *ray)
{
	if (ray->side == 0)
		ray->perpwalldist = (ray->sidedistx - ray->deltadistx);
	else
		ray->perpwalldist = (ray->sidedisty - ray->deltadisty);
}
