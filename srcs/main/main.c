/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:19:35 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/11 16:12:05 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	finish_game(t_data *d)
{
	ft_free_data(d);
	exit(0);
}

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
	if (!start_mlx(&d, &mlx))
		return (1);
	mlx_hook(d.mlx->win, 2, 1L << 0, handle_input, &d);
	mlx_hook(d.mlx->win, 17, 1L << 0, finish_game, &d);
	mlx_loop(mlx.mlx);
	return (0);
}
