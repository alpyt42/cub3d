/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:26:03 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/04 10:11:31 by ale-cont         ###   ########.fr       */
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
}
