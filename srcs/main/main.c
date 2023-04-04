/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:19:35 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/04 18:38:38 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	start_game(t_data *d, t_mlx *mlx)
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

#ifdef ALRIC
int	main(int ac, char **av)
{
	t_data	d;
	t_mlx	mlx;

	start_set(&d, &mlx);
	d.mlx = &mlx;
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
	{
		error(MLX_INIT_FAIL);
		return (ft_free_data(&d), 1);
	}
	d.ac = ac;
	d.av = av;
	if (!set_all(&d))
		return (1);
	// start_game(&d, &mlx);
	return (0);
}

#else

int	main(int ac, char **av)
{
	t_data	d;
	t_mlx	mlx;

	start_set(&d, &mlx);
	d.mlx = &mlx;
	mlx.mlx = mlx_init();
	// if (mlx.mlx == NULL)
	// {
	// 	error(MLX_INIT_FAIL);
	// 	return (ft_free_data(&d), 1);
	// }
	start_game(&d, &mlx);
	d.ac = ac;
	d.av = av;
	if (!set_all(&d))
		return (1);
	return (0);
}

#endif