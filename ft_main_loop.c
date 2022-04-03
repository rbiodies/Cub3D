/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:06:32 by rbiodies          #+#    #+#             */
/*   Updated: 2022/04/03 14:38:58 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
calculate ray position and direction

x-coordinate in camera space

deltaDistX and deltaDistY are the distance the ray has to travel to go 
from 1 x-side to the next x-side, or from 1 y-side to the next y-side
*/
int	ft_main_loop(t_map *map)
{
	t_raycasting	*ray;
	int				x;

	ray = (t_raycasting *)malloc(sizeof(t_raycasting));
	if (ray == NULL)
		ft_putendl_error("Raycasting: Malloc error");
	x = 0;
	while (x < WIN_WIDTH)
	{
		ray->camerax = 2 * x / (double)WIN_WIDTH - 1;
		ray->raydirx = map->dirx + map->planex * ray->camerax;
		ray->raydiry = map->diry + map->planey * ray->camerax;
		ray->deltadistx = fabs(1 / ray->raydirx);
		ray->deltadisty = fabs(1 / ray->raydiry);
		x++;
	}
	return (0);
}
