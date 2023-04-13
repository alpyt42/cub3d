/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:35:39 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/13 14:03:25 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void printmap(t_data *d, int x, int y, int color)
{
	int dx;
	int dy;
	int pixel_x;
	int pixel_y;

	dy = -1;
	while (++dy < 10)
	{
		dx = -1;
		while (++dx < 10)
		{
			pixel_x = x * 10 + dx;
			pixel_y = y * 10 + dy;
			my_mlx_pixel_put(d, pixel_x, pixel_y, color);
		}
	}
}

static void	dis_map(t_data *d, int color, int zoomed[2], int pos[2])
{
	int tile_x;
	int tile_y;
	int x;
	int y;

	y = -1;
	while (++y < 26)
	{
		x = -1;
		while (++x < 26)
		{
			tile_x = zoomed[0] + x;
			tile_y = zoomed[1] + y;
			if (!d->map[tile_y][tile_x] || d->map[tile_y][tile_x] == '1')
				color = 0x000000;
			else if (d->map[tile_y][tile_x] == ' ')
				color = 0x000000;
			else if (tile_x == pos[0] && tile_y == pos[1])
				color = 0xFF0000;
			else if (d->map[tile_y][tile_x] == '0')
				color = 0x888888;
			printmap(d, x, y, color);
		}
	}
}

void	display_map(t_data *d)
{
	int color;
	int zoomed[2];
	int pos[2];

	pos[0] = d->player->y;
	pos[1] = d->player->x;
	zoomed[0] = pos[0] - 13;
	zoomed[1] = pos[1] - 13;
	if (zoomed[0] < 0)
		zoomed[0] = 0;
	if (zoomed[1] < 0)
		zoomed[1] = 0;
	if (zoomed[0] > d->sizex - 26)
		zoomed[0] = d->sizex - 26;
	if (zoomed[1] > d->sizey - 26)
		zoomed[1] = d->sizey - 26;
	color = 0;
	dis_map(d, color, zoomed, pos);
}
