/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:26:52 by amontalb          #+#    #+#             */
/*   Updated: 2023/04/13 16:33:23 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(t_data *d)
{
	raycasting(d);
	display_map(d);
	mlx_put_image_to_window(d->mlx->mlx, d->mlx->win, d->mlx->img, 0, 0);
}

void	look_left(t_data *d)
{
	if (d->player->orientation == 'N')
		d->player->orientation = 'W';
	else if (d->player->orientation == 'W')
		d->player->orientation = 'S';
	else if (d->player->orientation == 'S')
		d->player->orientation = 'E';
	else if (d->player->orientation == 'E')
		d->player->orientation = 'N';
	start_player_orientation(d);
	start_plan_vector(d);
	move (d);
}

void	look_right(t_data *d)
{
	if (d->player->orientation == 'N')
		d->player->orientation = 'E';
	else if (d->player->orientation == 'E')
		d->player->orientation = 'S';
	else if (d->player->orientation == 'S')
		d->player->orientation = 'W';
	else if (d->player->orientation == 'W')
		d->player->orientation = 'N';
	start_player_orientation(d);
	start_plan_vector(d);
	move (d);
}

int	avoid_wall(int keysym, t_data *d)
{
	if (keysym == KEY_W)
	{
		if (d->map[(int)(d->player->x)][(int)(d->player->y)] == '1')
		{
			d->player->x -= d->player->dirx;
			d->player->y -= d->player->diry;
			return (1);
		}
	}
	if (keysym == KEY_S)
	{
		if (d->map[(int)(d->player->x)][(int)(d->player->y)] == '1')
		{
			d->player->x += d->player->dirx;
			d->player->y += d->player->diry;
			return (1);
		}
	}
	return (0);
}

void	move_right(t_data *d)
{
	if (d->player->orientation == 'E'
		&& d->map[(int)(d->player->x + 1)][(int)(d->player->y)] != '1')
	{
		d->player->x += 1;
		move(d);
	}
	else if (d->player->orientation == 'S'
		&& d->map[(int)(d->player->x)][(int)(d->player->y - 1)] != '1')
	{
		d->player->y -= 1;
		move(d);
	}
	else if (d->player->orientation == 'W'
		&& d->map[(int)(d->player->x - 1)][(int)(d->player->y)] != '1')
	{
		d->player->x -= 1;
		move(d);
	}
	else if (d->player->orientation == 'N'
		&& d->map[(int)(d->player->x)][(int)(d->player->y + 1)] != '1')
	{
		d->player->y += 1;
		move(d);
	}
}

void	move_left(t_data *d)
{
	if (d->player->orientation == 'E'
		&& d->map[(int)(d->player->x - 1)][(int)(d->player->y)] != '1')
	{
		d->player->x -= 1;
		move(d);
	}
	else if (d->player->orientation == 'S'
		&& d->map[(int)(d->player->x)][(int)(d->player->y + 1)] != '1')
	{
		d->player->y += 1;
		move(d);
	}
	else if (d->player->orientation == 'W'
		&& d->map[(int)(d->player->x + 1)][(int)(d->player->y)] != '1')
	{
		d->player->x += 1;
		move(d);
	}
	else if (d->player->orientation == 'N'
		&& d->map[(int)(d->player->x)][(int)(d->player->y - 1)] != '1')
	{
		d->player->y -= 1;
		move(d);
	}
}

int	handle_input(int keysym, t_data *d)
{
	if (keysym == KEY_W || keysym == 13)
	{
		d->player->x += d->player->dirx;
		d->player->y += d->player->diry;
		if (avoid_wall(keysym, d))
			return (0);
		move (d);
	}
	if (keysym == KEY_S || keysym == 1)
	{
		d->player->x -= d->player->dirx;
		d->player->y -= d->player->diry;
		if (avoid_wall(keysym, d))
			return (0);
		move (d);
	}
	if (keysym == 65363)
		look_right(d);
	if (keysym == 65361)
		look_left(d);
	if (keysym == KEY_A)
		move_left(d);
	if (keysym == KEY_D)
		move_right(d);
	return (0);
}
