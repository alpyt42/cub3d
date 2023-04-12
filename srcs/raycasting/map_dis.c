/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:35:39 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/12 18:34:32 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	dis_player(t_data *d)
// {
// 	int	x;
// 	int	y;

// 	y = -1;
// 	while (++y < 250)
// 	{
// 		x = -1;
// 		while (++x < 300)
// 			my_mlx_pixel_put(d, x + 20, y + 20, 0x000000);
// 	}
// }

// static void dis_map(t_data *d, int px, int py)
// {
//     float x;
//     float y;

//     float scale_factor = 5.0; // scale factor to make the map larger

//     y = 0;
//     while ((int)y < d->sizey)
//     {
//         x = 0;
//         while ((int)x < d->sizex)
//         {
//             if (!d->map[(int)y][(int)x])
//                 break ;
//             if (ft_strchr("NSWE0", d->map[(int)y][(int)x]))
//                 my_mlx_pixel_put(d, (int)(x * scale_factor) + 20, (int)(y * scale_factor) + 20, 0xFFFFFF);
//             x += 1;
//         }
//         y += 1;
//     }
// }

void dis_map(t_data *d, int player_x, int player_y) {
    // calculate the top-left corner of the zoomed display
    int zoomed_x = player_x - 5;
    int zoomed_y = player_y - 13;
    if (zoomed_x < 0) zoomed_x = 0;
    if (zoomed_y < 0) zoomed_y = 0;
    if (zoomed_x > d->sizex - 10) zoomed_x = d->sizex - 10;
    if (zoomed_y > d->sizey - 26) zoomed_y = d->sizey - 26;
    
    // loop over the tiles in the zoomed display
    for (int y = 0; y < 26; y++) {
        for (int x = 0; x < 10; x++) {
            // calculate the coordinates of the tile in the original map
            int tile_x = zoomed_x + x;
            int tile_y = zoomed_y + y;
            // calculate the color of the tile based on the character in the map
            int color;
			if (!d->map[tile_y][tile_x])
				break ;
            if (ft_strchr("NSWE", d->map[tile_y][tile_x])) 
                color = 0xFFFFFF; // white
			else if (ft_strchr("0", d->map[tile_y][tile_x]))
				color = 0x888888; // white
                // add more cases for different tile type
            // draw the tile at the correct position and size
            for (int dy = 0; dy < 10; dy++) {
                for (int dx = 0; dx < 10; dx++) {
                    int pixel_x = x * 10 + dx + 20;
                    int pixel_y = y * 10 + dy + 20;
                    my_mlx_pixel_put(d, pixel_x, pixel_y, color);
                }
            }
        }
    }
}

static void	dis_square(t_data *d)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 260)
	{
		x = -1;
		while (++x < 300)
			my_mlx_pixel_put(d, x + 20, y + 20, 0x000000);
	}
}

void	display_map(t_data *d)
{
	dis_square(d);
	dis_map(d, d->player->x, d->player->y);
	// dis_player(d);
}
