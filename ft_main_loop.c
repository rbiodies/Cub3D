/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:06:32 by rbiodies          #+#    #+#             */
/*   Updated: 2022/04/05 17:25:53 by bjeana           ###   ########.fr       */
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
/*
// ray.deltadistx = fabs(1 / ray.raydirx);
// ray.deltadisty = fabs(1 / ray.raydiry);*/

// static void	ft_raycasting_preset(t_ray ray, int x)
// {
// 	ray.camerax = 2 * x / (double)WIN_WIDTH - 1;
// 	ray.raydirx = ray.dirx + ray.planex * ray.camerax;
// 	ray.raydiry = ray.diry + ray.planey * ray.camerax;

// 	ray.mapx = (int)ray.posx;
// 	ray.mapy = (int)ray.posy;

// 	ray.deltadistx = sqrt(1 + (ray.raydiry * ray.raydiry) \
// 	/ (ray.raydirx * ray.raydirx));
// 	ray.deltadisty = sqrt(1 + (ray.raydirx * ray.raydirx) \
// 	/ (ray.raydiry * ray.raydiry));
// }

static void	ft_raycasting_preset(t_ray *ray, int x)
{
	ray->camerax = 2 * x / (double)WIN_WIDTH - 1;
	ray->raydirx = ray->dirx + ray->planex * ray->camerax;
	ray->raydiry = ray->diry + ray->planey * ray->camerax;

	ray->mapx = (int)ray->posx;
	ray->mapy = (int)ray->posy;

	ray->deltadistx = sqrt(1 + (ray->raydiry * ray->raydiry) \
	/ (ray->raydirx * ray->raydirx));
	ray->deltadisty = sqrt(1 + (ray->raydirx * ray->raydirx) \
	/ (ray->raydiry * ray->raydiry));
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
static void	ft_get_side_position(t_ray *ray)
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

// static void	ft_get_ray_hit(t_ray ray, char **map)
// {
// 	int	hit;
	
// 	hit = 0;
// 	while (hit == 0)
// 	{
// 		if (ray.sidedistx < ray.sidedistx)
// 		{
// 			ray.sidedistx += ray.deltadistx;
// 			ray.mapx += ray.stepx;
// 			ray.side = '0';
// 		}
// 		else
// 		{
// 			ray.sidedisty += ray.deltadisty;
// 			ray.mapy += ray.stepy;
// 			ray.side = '1';
// 		}
// 		if (map[ray.mapx][ray.mapy] == '1')
// 			hit = 1;
// 	}
// 	if (ray.side == '0')
// 		ray.perpwalldist = (ray.sidedistx - ray.deltadistx);
// 	else
// 		ray.perpwalldist = (ray.sidedisty - ray.deltadisty);
// }

static void	ft_get_ray_hit(t_data *data, char **map)
{
	int	hit;
	
	hit = 0;
	while (hit == 0)
	{
		if (data->ray.sidedistx < data->ray.sidedistx)
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
		if (map[data->ray.mapy][data->ray.mapx] == '1')
			hit = 1;
	}
	if (data->ray.side == 0)
		data->ray.perpwalldist = (data->ray.sidedistx - data->ray.deltadistx);
	else
		data->ray.perpwalldist = (data->ray.sidedisty - data->ray.deltadisty);
}

static void	ft_get_texture_side(t_ray *ray)
{
	if (ray->side == '1' && ray->stepy < 0)
		ray->texnum = 0;
	else if (ray->side == '1' && ray->stepy > 0)
		ray->texnum = 1;
	else if (ray->side == '0' && ray->stepy > 0)
		ray->texnum = 2;
	else if (ray->side == '0' && ray->stepy < 0)
		ray->texnum = 3;
}

/*
//Calculate height of line to draw on screen
int lineHeight = (int)(h / perpWallDist);

//calculate lowest and highest pixel to fill in current stripe
int drawStart = -lineHeight / 2 + h / 2;

//calculate value of wallX
double wallX; //where exactly the wall was hit

The C library function double floor(double x) 
returns the largest integer value less than or equal to x

 //x coordinate on the texture
int texX = int(wallX * double(texWidth));

// How much to increase the texture coordinate per screen pixel
double step = 1.0 * texHeight / lineHeight;

// Starting texture coordinate
double texPos = (drawStart - h / 2 + lineHeight / 2) * step;
*/
void	ft_get_texture_params(t_ray *ray)
{
	ray->lineheight = (int)(WIN_HEIGHT / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + WIN_HEIGHT / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + WIN_HEIGHT / 2;
	if (ray->drawend >= WIN_HEIGHT)
		ray->drawend = WIN_HEIGHT - 1;
	ft_get_texture_side(ray);
	if (ray->side == '0')
		ray->wallx = ray->posx + ray->perpwalldist * ray->diry;
	else
		ray->wallx = ray->posx + ray->perpwalldist * ray->dirx;
	ray->wallx -= floor(ray->wallx);
	ray->texx = (int)(ray->wallx * (double)TEXWIDTH);
	if (ray->side == '0' && ray->dirx > 0)
		ray->texx = TEXWIDTH - ray->texx - 1;
	if (ray->side == '1' && ray->raydiry < 0)
		ray->texx = TEXWIDTH - ray->texx - 1;
	ray->step = 1.0 * TEXHIGHT / ray->lineheight;
	ray->texpos \
	= (ray->drawstart - WIN_HEIGHT / 2 + ray->lineheight / 2) * ray->stepx;
}

/*
// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
int texY = (int)texPos & (texHeight - 1);
...
//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
if(side == 1) color = (color >> 1) & 8355711;
*/
/*
static void	ft_fill_verticals(t_data *data, int x)
{
	int	y;
	int	texy;
	int	color;

	y = data->ray.drawstart;
	while (y < data->ray.drawend)
	{
		texy = (int)data->ray.texpos & (TEXHIGHT - 1);
		data->ray.texpos += data->ray.step;
		color = \
		data->map->texture[data->ray.texnum][TEXHIGHT * texy * data->ray.texx];
		if (data->ray.side == '1')
			color = (color >> 1) & 8355711;
		data->map->array[y][x] = color;
		y++;
	}
}
*/

int	ft_main_loop(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		ft_raycasting_preset(&data->ray, x);
		ft_get_side_position(&data->ray);
		ft_get_ray_hit(data, data->map->array);
		ft_get_texture_params(&data->ray);
		//ft_fill_verticals(data, x);
		x++;
	}
	return (0);
}
