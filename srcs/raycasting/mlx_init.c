/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:56:24 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/04 18:57:14 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start_game(t_data *d, t_mlx *mlx)
{
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "CUB3D");
	mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line, &mlx->endian);
	floor_ceiling(d);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	raycasting(d);
	mlx_loop(mlx->mlx);
	return (0);
}