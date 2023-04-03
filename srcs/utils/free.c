/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:08:11 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/03 17:30:46 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_mlx(t_mlx *mlx)
{
	if (mlx->mlx != NULL)
	{
		if (mlx->win != NULL)
			mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
}

void	free_dico(void *content)
{
	t_dico	*dico;

	dico = content;
	if (dico->key)
		free(dico->key);
	if (dico->val)
		free(dico->val);
}

void	*ft_free_data(t_data *d)
{
	if (d->h_dico)
		ft_lstclear(&d->h_dico, free_dico);
	if (d->map)
		ft_free_arr(d->map);
	if (d->mlx)
		free_mlx(d->mlx);
	if (d->fd_map > 0)
		close(d->fd_map);
	return (NULL);
}
