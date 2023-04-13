/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:26:03 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/13 13:13:05 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*set_color_img(t_data *d)
{
	d->col = (int **)malloc(sizeof(int *) * 2);
	if (!d->col)
		return (error(MALLOC_ERR));
	d->col[C] = NULL;
	d->col[F] = NULL;
	d->col[C] = (int *)malloc(sizeof(int) * 3);
	d->col[F] = (int *)malloc(sizeof(int) * 3);
	if (!d->col[C] || !d->col[F])
		return (error(MALLOC_ERR));
	d->imgs = malloc(sizeof(t_img) * 4);
	if (!d->imgs)
		return (error(MALLOC_ERR));
	return ("");
}

void	*start_set(t_data *d, t_mlx *mlx)
{
	d->player = malloc(sizeof(t_player));
	if (!d->player)
		return (error(MALLOC_ERR));
	d->ac = 0;
	d->av = NULL;
	d->fd_map = -1;
	d->h_dico = NULL;
	d->imgs = NULL;
	d->ray = NULL;
	d->col = NULL;
	d->map = NULL;
	d->sizex = -1;
	d->sizey = -1;
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->width = 1600;
	mlx->height = 1000;
	return (NULL);
}

void	start_player_orientation(t_data *d)
{
	if (d->player->orientation == 'N')
	{
		d->player->diry = -1;
		d->player->dirx = 0;
	}
	if (d->player->orientation == 'S')
	{
		d->player->diry = 1;
		d->player->dirx = 0;
	}
	if (d->player->orientation == 'E')
	{
		d->player->dirx = -1;
		d->player->diry = 0;
	}
	if (d->player->orientation == 'W')
	{
		d->player->dirx = 1;
		d->player->diry = 0;
	}
}

void	start_plan_vector(t_data *d)
{
	if (d->player->orientation == 'N')
	{
		d->player->planx = -0.66;
		d->player->plany = 0;
	}
	if (d->player->orientation == 'S')
	{
		d->player->planx = 0.66;
		d->player->plany = 0;
	}
	if (d->player->orientation == 'E')
	{
		d->player->planx = 0;
		d->player->plany = 0.66;
	}
	if (d->player->orientation == 'W')
	{
		d->player->planx = 0;
		d->player->plany = -0.66;
	}
}
