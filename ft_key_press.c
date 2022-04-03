/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:40:17 by rbiodies          #+#    #+#             */
/*   Updated: 2022/04/03 12:40:48 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_key_press(int key)
{
	if (key == ESC)
	{
		ft_putendl_fd("\033[0;36mYou Enter the ESC Key. Good Bye! :)\033[0m", 1);
		exit(EXIT_SUCCESS);
	}
	/*
	else if (key == W || key == UP)
		ft_move();
	else if (key == S || key == DOWN)
		ft_move();
	else if (key == A)
		ft_strafe();
	else if (key == D)
		ft_strafe();
	else if (key == LEFT)
		
	else if (key == RIGHT)
	
	*/
	return (0);
}
