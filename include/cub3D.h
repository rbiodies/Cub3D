/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:21:06 by maxim             #+#    #+#             */
/*   Updated: 2022/04/01 12:38:22 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*****LIBRARIES*****/
# include "../libft/inc/libft.h"
# include "../minilibx_opengl_20191021/mlx.h"
# include <fcntl.h>	// open
// # include <math.h>
# include <stdio.h>	// printf

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
typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	char	**texture;
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
}	t_data;

/*****FUNCTIONS*****/
/*****cub3D.c*****/
void	ft_putendl_error(char *str);
/*****ft_parsing_map.c*****/
void	ft_parsing_map(t_data *data, char *filename);
int		get_next_line(int fd, char **line);
/*****ft_parse_colors.c*****/
int		ft_parsing_colors(t_data *data, char *line);
/*****ft_check.c*****/
void	ft_check_map(t_data *data);
/*****ft_start_game.c*****/
int		ft_start_game(t_map *map);
/*****ft_main_loop.c*****/
int		ft_main_loop(t_map *map);

#endif