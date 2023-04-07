/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:19:35 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/07 09:32:23 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	finish_game(t_data *d)
{
	(void) d;
	exit(0);

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
	if (!start_mlx(&d, &mlx))
		return (1);
	//mlx_hook(d.mlx->win, 33, 1L << 17, finish_game, d);
	mlx_hook(d.mlx->win, 2, 1L << 0, handle_input, &d);
	mlx_loop(mlx.mlx);
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
	mlx_hook(d.mlx->win, 33, 1L << 17, finish_game, &d);
	mlx_hook(d.mlx->win, 2, 1L << 0, handle_input, &d);
	mlx_loop(mlx.mlx);
	return (0);
}

#endif