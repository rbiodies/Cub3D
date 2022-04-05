/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:21:06 by maxim             #+#    #+#             */
/*   Updated: 2022/04/05 15:57:01 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*****LIBRARIES*****/
# include "../libft/inc/libft.h"
# include "../minilibx_opengl_20191021/mlx.h"
# include <fcntl.h>	// open
# include <math.h>	// fabs
# include <stdio.h>	// printf

/*****WINDOW_SIZES*****/
# define TEXWIDTH	64
# define TEXHIGHT	64
# define WIN_WIDTH	640
# define WIN_HEIGHT	480

/*****KEYS*****/
# define ESC	53
# define W		13
# define S		1
# define A		0
# define D		2
# define UP		126
# define DOWN	125
# define LEFT	123
# define RIGHT	124

/*****STRUCTURES*****/
/*
	double	deltadistx;	// the distance the ray has to travel to go from 1 x-side to the next x-side
	double	deltadisty;	// the distance the ray has to travel to go from 1 y-side to the next y-side
	int		mapx;		// the current square of the map the ray is in (the coordinates of that square)
	int		mapy;		// the current square of the map the ray is in (the coordinates of that square)
	double	sidedistx;	// the distance the ray has to travel from its start position to the first x-side
	double	sidedisty;	// the distance the ray has to travel from its start position to the first y-side
*/
typedef struct s_ray
{
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	deltadistx;
	double	deltadisty;
	int		stepx;
	int		stepy;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	posx;
	double	posy;
	int		hit;
	int		side;
	double	perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	movespeed;
	double	rotspeed;
	int		texnum;
	double	wallx;
	int		texx;
	double	step;
	double	texpos;
}	t_ray;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
}	t_player;

/*
	void	*img_ptr;		// the image instance;
	int		bits_per_pixel;	// a pointer to where the bpp is written;
	int		size_line;		// a pointer to where the line is written;
	int		endian;			// a pointer to where the endian is written;
*/
typedef struct s_img
{
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*mlx_data_addr;
}	t_img;

typedef struct s_map
{
	char	**texture_path;
	void	**texture;
	int		floor_color;
	int		ceil_color;
	int		height;
	char	**array;
	void	*mlx;
	void	*win;
}	t_map;

typedef struct s_data
{
	t_map		*map;
	t_player	*player;
	t_ray		ray;
	t_img		img;
}	t_data;

/*****FUNCTIONS*****/
/*****main.c*****/
void	ft_putendl_error(char *str);
/*****ft_parsing_map.c*****/
void	ft_parsing_map(t_data *data, char *filename);
int		get_next_line(int fd, char **line);
/*****ft_parse_colors.c*****/
int		ft_parsing_colors(t_map *map, char *line);
/*****ft_check.c*****/
void	ft_check_map(t_data *data);
/*****ft_start_game.c*****/
int		ft_start_game(t_data *data);
/*****ft_main_loop.c*****/
int		ft_main_loop(t_data *data);
/*****ft_key_press.c*****/
int		ft_key_press(int key, t_data *data);

#endif