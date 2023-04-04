/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:26:03 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/04 11:35:30 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_set(t_data *d, t_mlx *mlx)
{
	d->ac = 0;
	d->av = NULL;
	d->h_dico = NULL;
	d->fd_map = -1;
	d->map = NULL;
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->width = 1920;
	mlx->height = 1080;
}


void	start_player_orientation(t_data *d)
{
	if (d->player->orientation = 'N')
	{
		d->player->driry = -1;
		d->player->drirx = 0;		
	}
	if (d->player->orientation = 'S')
	{
		d->player->driry = 1;
		d->player->drirx = 0;
	}
	if (d->player->orientation = 'E')
	{
		d->player->drirx = 1;
		d->player->driry = 0;	
	}
	if (d->player->orientation = 'W')
	{
		d->player->drirx = -1;
		d->player->driry = 0;	
	}
}