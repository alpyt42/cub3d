/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:56:24 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/06 16:22:37 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	finish_game(t_data *d)
{
	(void) d;
	exit(0);

}


int	start_game(t_data *d, t_mlx *mlx)
{
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "CUB3D");
	mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line, &mlx->endian);
	raycasting(d);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	printf("____________________________\n");
	printf("win : %p\n", d->mlx->win);
	//mlx_hook(d->mlx->win, 33, 1L << 17, finish_game, d);
	mlx_hook(d->mlx->win, 2, 1L << 0, handle_input, d);
	mlx_loop(mlx->mlx);
	return (0);
}