/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:19:35 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/06 18:55:26 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	start_game(&d, &mlx);
	return (0);
}
#else
int	main(int ac, char **av)
{
	t_data	d;
	t_mlx	mlx;

	start_set(&d, &mlx);
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
	{
		error(MLX_INIT_FAIL);
		return (ft_free_data(&d), 1);
	}
	d.mlx = &mlx;
	printf("------------------\n");
	start_game(&d, &mlx);
	d.ac = ac;
	d.av = av;
	if (!set_all(&d))
		return (1);
	return (0);
}

#endif