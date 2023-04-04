/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:37:00 by amontalb          #+#    #+#             */
/*   Updated: 2023/04/04 11:23:38 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = &data->mlx->addr[(y * data->mlx->width) * 4  + x * 4];
	*(unsigned int*)dst = color;
}

int floor_ceiling(t_data *d)
{
	int x;
	int y;

	x = 0;
	while (x < d->mlx->width)
	{
		y = 0;
		while (y < d->mlx->height / 2)
		{
			my_mlx_pixel_put(d, x, y, 0x00FF0000);
			my_mlx_pixel_put(d, x, y + d->mlx->height / 2, 0x0000FF00);
			y++;	
		}
		x++;
	}

	return (0);
}
