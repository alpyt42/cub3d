/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:11:29 by amontalb          #+#    #+#             */
/*   Updated: 2023/04/06 17:12:04 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void move_right(t_data *d)
{
    float olddirx;
    float oldplanx;

    olddirx = d->player->dirx;
    oldplanx = d->player->planx;
    d->player->dirx = d->player->dirx * cos(-60) - d->player->diry * sin(-60);
    d->player->diry = olddirx * sin(-60) + d->player->y * cos(-60);
    d->player->planx = d->player->planx * cos(-60) - d->player->plany * sin(-60);
    d->player->plany = oldplanx * sin(-60) + d->player->plany * cos(-60);
}

void    move(t_data *d)
{
    mlx_destroy_image(d->mlx->mlx, d->mlx->img);
    printf("img : %p\n", d->mlx->img);
    d->mlx->img = mlx_new_image(d->mlx->mlx, d->mlx->width, d->mlx->height);
	raycasting(d);
    mlx_put_image_to_window(d->mlx->mlx, d->mlx->win, d->mlx->img, 0, 0);
    d->mlx->addr = mlx_get_data_addr(d->mlx->img, &d->mlx->bpp, &d->mlx->size_line, &d->mlx->endian);
}


int	handle_input(int keysym, t_data *d)
{
    
	if (keysym == KEY_W  || keysym == 13)
	{
        d->player->x += d->player->dirx;
        d->player->y += d->player->diry;
        move (d);
	}
    if (keysym == KEY_S || keysym == 1)
	{
        d->player->x -= d->player->dirx;
        d->player->y -= d->player->diry;
        move (d);
	}
	if (keysym == KEY_D || keysym == 2)
	{
        printf("test\n");
        move_right(d);
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