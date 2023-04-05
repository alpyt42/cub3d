/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:15:29 by amontalb          #+#    #+#             */
/*   Updated: 2023/04/05 15:12:33 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void    move(t_data *d)
{
    mlx_destroy_image(d->mlx->mlx, d->mlx->img);
    d->mlx->img = mlx_new_image(d->mlx->mlx, d->mlx->width, d->mlx->height);
	raycasting(d);
    mlx_put_image_to_window(d->mlx->mlx, d->mlx->win, d->mlx->img, 0, 0);
}


int	handle_input(int keysym, t_data *d)
{
    
	if (keysym == KEY_W)
	{
        d->player->x += d->player->dirx;
        d->player->y += d->player->diry;
        move (d);
	}
    if (keysym == KEY_S)
	{
        d->player->x -= d->player->dirx;
        d->player->y -= d->player->diry;
        move (d);
	}
	if (keysym == KEY_A)
	{
        d->player->x -= d->player->dirx;
        d->player->y -= d->player->diry;
        move (d);
	}
	// if (keysym == 0)
	// 	move_left(d);
	// if (keysym == 1)
	// 	move_down(d);
	// if (keysym == 2)
	// 	move_right(d);
	return (0);
}