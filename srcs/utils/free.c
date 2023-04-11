/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:08:11 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/11 17:29:09 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_mlx(t_mlx *mlx)
{
	if (mlx->mlx != NULL)
	{
		if (mlx->img)
			mlx_destroy_image(mlx->mlx, mlx->img);
		if (mlx->win)
			mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
}

static void	free_dico(void *content)
{
	t_dico	*dico;

	dico = content;
	if (dico->key)
		free(dico->key);
	if (dico->val)
		free(dico->val);
}

static void	free_imgs(t_data *d)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (d->imgs[i].ptr)
			mlx_destroy_image(d->mlx->mlx, d->imgs[i].ptr);
		// if (d->imgs[i].add)
		// 	mlx_destroy_image(d->mlx->mlx, d->imgs[i].add);
		// free(d->imgs[i++]);
	}
	free(d->imgs);
	if (d->imgback)
	{
		mlx_destroy_image(d->mlx->mlx, d->imgback->add);
		free(d->imgback);
	}
	if (d->imgwall)
	{
		mlx_destroy_image(d->mlx->mlx, d->imgwall->add);
		free(d->imgwall);
	}
}

void	*ft_free_data(t_data *d)
{
	if (d->h_dico)
		ft_lstclear(&d->h_dico, free_dico);
	if (d->map)
		ft_free_arr(d->map);
	if (d->imgs)
		free_imgs(d);
	if (d->col)
	{
		free(d->col[C]);
		free(d->col[F]);
		free(d->col);
	}
	if (d->fd_map > 0)
		close(d->fd_map);
	if (d->mlx)
		free_mlx(d->mlx);
	return (NULL);
}
