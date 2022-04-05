/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:06:32 by rbiodies          #+#    #+#             */
/*   Updated: 2022/04/05 12:54:25 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
// calculate ray position and direction
ray->camerax = 2 * x / (double)WIN_WIDTH - 1;
// x-coordinate in camera space
ray->raydirx = map->dirx + map->planex * ray->camerax;
//length of ray from one x or y-side to next x or y-side
double deltaDistX = (rayDirX == 0) ? 1e30 : std::abs(1 / rayDirX);
double deltaDistY = (rayDirY == 0) ? 1e30 : std::abs(1 / rayDirY);
*/
static void	ft_raycasting_preset(t_ray ray, int i)
{
	ray.camerax = 2 * i / (double)WIN_WIDTH - 1;
	ray.raydirx = ray.dirx + ray.planex * ray.camerax;
	ray.raydiry = ray.diry + ray.planey * ray.camerax;
	ray.deltadistx = fabs(1 / ray.raydirx);
	ray.deltadisty = fabs(1 / ray.raydiry);
}

/*
//which box of the map we're in
int mapX = int(posX);
int mapY = int(posY);

//length of ray from current position to next x or y-side
double sideDistX;
double sideDistY;

//what direction to step in x or y-direction (either +1 or -1)
int stepX;
int stepY;
*/
static void	ft_get_side_position(t_ray ray)
{
	if (ray.raydirx < 0)
	{
		ray.stepx = -1;
		ray.sidedistx = (ray.posx - ray.mapx) * ray.deltadistx;
	}
	else
	{
		ray.stepx = 1;
		ray.sidedistx = (ray.mapx + 1.0 - ray.posx) * ray.deltadistx;
	}
	if (ray.raydiry < 0)
	{
		ray.stepy = -1;
		ray.sidedisty = (ray.posy - ray.mapy) * ray.deltadisty;
	}
	else
	{
		ray.stepy = 1;
		ray.sidedisty = (ray.mapy + 1.0 - ray.posy) * ray.deltadisty;
	}
}

/*
int hit = 0; //was there a wall hit?
int side; //was a NS or a EW wall hit?
//perform DDA
while (hit == 0)
{
	//jump to next map square, either in x-direction, or in y-direction
	if (sideDistX < sideDistY)
	...
	//Check if ray has hit a wall
    if (worldMap[mapX][mapY] > 0) hit = 1;
	//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
	if(side == 0) perpWallDist = (sideDistX - deltaDistX);
	else          perpWallDist = (sideDistY - deltaDistY);
*/
/*
static void	ft_get_ray_hit(t_ray ray, char **map)
{
	ray.hit = 0;
	while (ray.hit == 0)
	{
		if (ray.sidedistx < ray.sidedistx)
		{
			ray.sidedistx += ray.deltadistx;
			ray.mapx += ray.stepx;
			ray.side = '0';
		}
		else
		{
			ray.sidedisty += ray.deltadisty;
			ray.mapy += ray.stepy;
			ray.side = '1';
		}
		if (map[ray.mapx][ray.mapy] == '1')
			ray.hit = 1;
	}
	if (ray.side == '0')
		ray.perpwalldist = (ray.sidedistx - ray.deltadistx);
	else
		ray.perpwalldist = (ray.sidedisty - ray.deltadisty);
}
*/

/*
//Calculate height of line to draw on screen
int lineHeight = (int)(h / perpWallDist);

//calculate lowest and highest pixel to fill in current stripe
int drawStart = -lineHeight / 2 + h / 2;
*/
static void	ft_get_texture_params(t_ray ray)
{
	ray.lineheight = (int)(WIN_HEIGHT / ray.perpwalldist);
	ray.drawstart = -ray.lineheight / 2 + WIN_HEIGHT / 2;
	if (ray.drawstart < 0)
		ray.drawstart = 0;
	ray.drawend = ray.lineheight / 2 + WIN_HEIGHT / 2;
	if (ray.drawend >= WIN_HEIGHT)
		ray.drawend = WIN_HEIGHT - 1;
}

int	ft_main_loop(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIN_WIDTH)
	{
		ft_raycasting_preset(data->ray, i);
		ft_get_side_position(data->ray);
		// ft_get_ray_hit(data->ray, data->map->array);
		ft_get_texture_params(data->ray);
		i++;
	}
	return (0);
}
