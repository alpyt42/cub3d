/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:33:40 by amontalb          #+#    #+#             */
/*   Updated: 2023/04/17 12:13:16 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_step(t_data *d)
{
	if (d->ray->raydirx < 0)
	{
		d->ray->stepx = -1;
		d->ray->sidedistx = ((d->player->x - d->ray->mapx)
				* d->ray->deltadistx);
	}
	else
	{
		d->ray->stepx = 1;
		d->ray->sidedistx = ((1 + d->ray->mapx - d->player->x)
				* d->ray->deltadistx);
	}
	if (d->ray->raydiry < 0)
	{
		d->ray->stepy = -1;
		d->ray->sidedisty = ((d->player->y - d->ray->mapy)
				* d->ray->deltadisty);
	}
	else
	{
		d->ray->stepy = 1;
		d->ray->sidedisty = ((1 + d->ray->mapy - d->player->y)
				* d->ray->deltadisty);
	}
}

void	ray_to_wall(t_data *d)
{
	while (d->ray->hit == 0)
	{
		if (d->ray->sidedistx < d->ray->sidedisty)
		{
			d->ray->sidedistx += d->ray->deltadistx;
			d->ray->mapx += d->ray->stepx;
			d->ray->side = 0;
		}
		else
		{
			d->ray->sidedisty += d->ray->deltadisty;
			d->ray->mapy += d->ray->stepy;
			d->ray->side = 1;
		}
		if (d->map[d->ray->mapx][d->ray->mapy] == '1')
			d->ray->hit = 1;
	}
	if (d->ray->side == 0)
		d->ray->p_to_wall_dist = (d->ray->sidedistx - d->ray->deltadistx);
	else
		d->ray->p_to_wall_dist = (d->ray->sidedisty - d->ray->deltadisty);
}

void	size_wall(t_data *d)
{
	d->ray->height = (int)(d->mlx->height / (d->ray->p_to_wall_dist));
	d->ray->draw_start = fmax((d->ray->height / 2) + (d->mlx->height / 2), 0);
	d->ray->draw_end = fmin(-(d->ray->height / 2) + (d->mlx->height / 2),
			d->mlx->height - 1);
}

int	init_ray(t_data *d, float i)
{
	t_ray	*ray;

	ray = (t_ray *)malloc(sizeof(t_ray));
	d->ray = ray;
	d->ray->hit = 0;
	d->ray->mapx = (int)d->player->x;
	d->ray->mapy = (int)d->player->y;
	d->ray->camerax = 2 * i / d->mlx->width - 1.0;
	d->ray->raydirx = d->player->dirx + d->player->planx * d->ray->camerax;
	d->ray->raydiry = d->player->diry + d->player->plany * d->ray->camerax;
	d->ray->deltadistx = sqrt(1 + (d->ray->raydiry * d->ray->raydiry)
			/ (d->ray->raydirx * d->ray->raydirx));
	d->ray->deltadisty = sqrt(1 + (d->ray->raydirx * d->ray->raydirx)
			/ (d->ray->raydiry * d->ray->raydiry));
	return (0);
}

int	raycasting(t_data *d)
{
	int	x;

	x = 0;
	floor_ceiling(d);
	while (x < d->mlx->width)
	{
		init_ray(d, x);
		init_step(d);
		ray_to_wall(d);
		size_wall(d);
		hit_point(d);
		draw_wall(d, x);
		free(d->ray);
		x++;
	}
	return (0);
}
