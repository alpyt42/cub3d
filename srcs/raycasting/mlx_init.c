/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:56:24 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/06 19:08:28 by amontalb         ###   ########.fr       */
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
	if (!mlx->win)
		return (error(MLX_WIN_FAIL), 1);
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

t_img	*create_img(t_mlx *mlx, int	width, int height)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (error(MALLOC_ERR));
	img->ptr = mlx_new_image(mlx->mlx, width, height);
	if (!img->ptr)
		return (error(MLX_IMG_FAIL));
	img->add = mlx_get_data_addr(img->ptr, &img->bpp, &img->len_line, &img->endian);
	img->bpp = img->bpp >> 3;
	return (img);
}

void	set_img_mlx(t_data *d)
{
	d->imgs[N].add = mlx_get_data_addr(d->imgs[N].ptr,
			&(d->imgs[N].bpp), &(d->imgs[N].len_line), &(d->imgs[N].endian));
	d->imgs[N].bpp = d->imgs[N].bpp >> 3;
	d->imgs[S].add = mlx_get_data_addr(d->imgs[S].ptr,
			&(d->imgs[S].bpp), &(d->imgs[S].len_line), &(d->imgs[S].endian));
	d->imgs[S].bpp = d->imgs[S].bpp >> 3;
	d->imgs[W].add = mlx_get_data_addr(d->imgs[W].ptr,
			&(d->imgs[W].bpp), &(d->imgs[W].len_line), &(d->imgs[W].endian));
	d->imgs[W].bpp = d->imgs[W].bpp >> 3;
	d->imgs[E].add = mlx_get_data_addr(d->imgs[E].ptr,
			&(d->imgs[E].bpp), &(d->imgs[E].len_line), &(d->imgs[E].endian));
	d->imgs[E].bpp = d->imgs[E].bpp >> 3;
}