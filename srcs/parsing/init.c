/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:26:03 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/04 12:44:52 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*set_color(t_data *d)
{
	d->col = (int **)ft_calloc(sizeof(int *), 2);
	if (!d->col)
		return (error(MALLOC_ERR));
	d->col[C] = (int *)ft_calloc(sizeof(int), 3);
	d->col[F] = (int *)ft_calloc(sizeof(int), 3);
	if (!d->col[C] || !d->col[F])
		return (error(MALLOC_ERR));
	// d->imgs = (t_img **)malloc(sizeof(t_img *) * 4);
	// if (!d->imgs)
	// 	return (error(MALLOC_ERR));
	return ("");
}

void	*set_all(t_data *d)
{
	if (!parse(d))
		return (NULL);
	return ("");
}

void	start_set(t_data *d, t_mlx *mlx)
{
	d->ac = 0;
	d->av = NULL;
	d->h_dico = NULL;
	d->fd_map = -1;
	d->map = NULL;
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->width = 1600;
	mlx->height = 1000;
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
		d->player->dirx = 1;
		d->player->diry = 0;	
	}
	if (d->player->orientation == 'W')
	{
		d->player->dirx = -1;
		d->player->diry = 0;	
	}
}