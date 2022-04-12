/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:21:06 by maxim             #+#    #+#             */
/*   Updated: 2022/04/12 17:37:34 by bjeana           ###   ########.fr       */
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
# define TEXWIDTH	512
# define TEXHIGHT	512
# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

/*****KEYS*****/
# define ESC	53
# define W		13
# define S		1
# define A		0
# define D		2
// # define UP		126
// # define DOWN	125
# define LEFT	123
# define RIGHT	124

/*
camerax - координата x в пространстве камеры
*/

typedef struct s_ray
{
	double	posx;
	double	posy;
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
	int		side;
	double	perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	move;
	double	rot;
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

typedef struct s_img1
{
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		*mlx_data_addr;
}	t_img1;

typedef struct s_map
{
	char	**texture_path;
	t_img1	*texture;
	int		floor_color;
	int		ceil_color;
	int		height;
	char	**array;
	void	*mlx;
	void	*win;
	int		size;
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
void	ft_check_two_color(t_map *map);
int		ft_parsing_colors(t_map *map, char *line);
/*****ft_check.c*****/
void	ft_check_map(t_data *data);
/*****ft_start_game.c*****/
int		ft_start_game(t_data *data);
/*****ft_main_loop.c*****/
int		ft_main_loop(t_data *data);
/*****ft_key_press.c*****/
int		ft_key_press(int key, t_data *data);
/*****ft_background.c*****/
void	ft_init_backimg(t_data *data);
void	ft_put_pix(t_data *data, int x, int y, int color);
void	ft_draw_corf(t_data *data, int a, int b, int color);
/*****ft_init_textures.c*****/
void	ft_init_textures(t_map *map);
/*****ft_init_ray_and_tex.c*****/
void	ft_init_ray(t_data *data);
void	ft_init_textures(t_map *map);
/*****ft_main_loop_2.c*****/
void	ft_get_stripe_params(t_ray *ray);
void	ft_get_texture_side(t_ray *ray);
void	ft_define_wallx(t_ray *ray);
void	ft_fill_verticals(t_data *data, t_ray *ray, t_map *map, int x);
void	ft_distance_of_perpendicular_ray(t_ray *ray);

void	ft_minimap(t_data *data);
int		ft_minimap_error(t_data *data);
#endif