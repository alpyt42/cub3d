/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:47:16 by amontalb          #+#    #+#             */
/*   Updated: 2023/04/12 14:21:15 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_step(t_data *d)
{
    if (d->ray->raydirx < 0)
    {
        d->ray->stepx = -1;
        d->ray->sidedistx = ((d->player->x - d->ray->mapx) * d->ray->deltadistx);
    }
    else
    {
        d->ray->stepx = 1;
        d->ray->sidedistx = ((1 + d->ray->mapx - d->player->x) * d->ray->deltadistx);
    }
    if (d->ray->raydiry < 0)
    {
        d->ray->stepy = -1;
        d->ray->sidedisty = ((d->player->y - d->ray->mapy) * d->ray->deltadisty);
    }
    else
    {
        d->ray->stepy = 1;
        d->ray->sidedisty = ((1 + d->ray->mapy - d->player->y) * d->ray->deltadisty);
    }  
}


void    ray_to_wall(t_data *d)
{
    // printf("%c\n", )
    while (d->ray->hit == 0)
    {
        // printf("sidedistx :%f -----sidedisty : %f\n", d->ray->sidedistx, d->ray->sidedisty);
        if (d->ray->sidedistx < d->ray->sidedisty)
        {
            d->ray->sidedistx += d->ray->deltadistx;
            d->ray->mapx += d->ray->stepx;
            d->ray->side = 0;
        }
        else
        {
            d->ray->sidedisty += d->ray->deltadisty;
            d->ray->mapy += d->ray->stepy;
            d->ray->side = 1;
        }
        if (d->map[d->ray->mapx][d->ray->mapy] == '1')
            d->ray->hit = 1;
    }
    if (d->ray->side == 0)
        d->ray->p_to_wall_dist = (d->ray->sidedistx - d->ray->deltadistx);
    else
        d->ray->p_to_wall_dist = (d->ray->sidedisty - d->ray->deltadisty);
}

void    size_wall(t_data *d)
{
    d->ray->height = (int)(d->mlx->height / d->ray->p_to_wall_dist);
    d->ray->draw_start = (d->ray->height / 2) + (d->mlx->height/ 2);
    d->ray->draw_end = -(d->ray->height / 2) + (d->mlx->height / 2);
    if (d->ray->draw_start < 0)
        d->ray->draw_start = 0;
    if (d->ray->draw_end >= d->mlx->height)
        d->ray->draw_end = d->mlx->height- 1;
}

int init_ray(t_data *d, float i)
{
    t_ray   *ray;

    ray = (t_ray *)malloc(sizeof(t_ray));
    d->ray = ray;
    d->ray->hit = 0;
    d->ray->mapx = (int)d->player->x;
    d->ray->mapy = (int)d->player->y;
    // printf("mapx : %d--- mapy :%d\n", d->ray->mapx, d->ray->mapy);
    d->ray->camerax = 2 * i / d->mlx->width - 1;
    // printf("camerax : %f\n", d->ray->camerax);
    // printf("dirx : %f------diry :%f\n", d->player->dirx, d->player->diry);
    d->ray->raydirx = d->player->dirx + d->player->planx * d->ray->camerax;
    d->ray->raydiry = d->player->diry + d->player->plany * d->ray->camerax;
    // printf("raydirx : %f ---- raydiry : %f\n", d->ray->raydirx, d->ray->raydiry);
    d->ray->deltadistx = sqrt(1 + (d->ray->raydiry * d->ray->raydiry) / (d->ray->raydirx * d->ray->raydirx));
    d->ray->deltadisty = sqrt(1 + (d->ray->raydirx * d->ray->raydirx) / (d->ray->raydiry * d->ray->raydiry)); // possible de opti
    // printf("deltadistx : %f---deltadisty : %f\n", d->ray->deltadistx, d->ray->deltadisty);
    
    return (0);
}

void draw_wall(t_data *d, int x)
{
    int y;
    int j = 0;
    int y2;
    int x2;
    char *color;
    // printf("ds : %d\n", d->ray->draw_start);
    y = d->ray->draw_end;
    // if (d->ray->side == 0)
    //     x2 = fmod(d->ray->wally , 1) * d->imgs[2].width;
    // else
    //     x2 = fmod(d->ray->wallx , 1) * d->imgs[2].width;
    while(j < d->ray->height)
    {
        if (d->ray->side == 0 && d->ray->raydirx > 0)
        {
            x2 = fmod(d->ray->wally , 1) * d->imgs[0].width;
           
    // printf("_______________________________________\n");
            // printf("x1 : %f\n", x1);
            // my_mlx_pixel_put(d, x, y, 0x000000FF);
            y2 = j * d->imgs[0].height / d->ray->height;
            // dprintf(2, "ttt :%d\n", y * d->imgs[0].len_line + (int)x2 * (d->imgs[0].bpp / 8));
			if (x2 < 0)
			{
            dprintf(2,"width : %d, height : %d\n", d->imgs[0].width, d->imgs[0].height);
            dprintf(2,"y : %f --- x2 : %d ----y : %d ----  y2 : %d\n", d->ray->wally, x2, y, y2);
			}
            color = (d->imgs[0].add + (int)(y2 * d->imgs[0].len_line + x2 * (d->imgs[0].bpp / 8)));
            // dprintf(2, "color : %0x --- len_lign : %d\n", *color, d->imgs[1].len_line);
            my_mlx_pixel_put(d, x, y, *(int *)color);
        }
        else if (d->ray->side == 0)
        {
            x2 = fmod(d->ray->wally , 1) * d->imgs[1].width;
            y2 = j * d->imgs[1].height / d->ray->height;
            color = (d->imgs[1].add + (int)(y2 * d->imgs[1].len_line + x2 * (d->imgs[1].bpp / 8)));
			
			if (x2 < 0)
			{
            dprintf(2,"width : %d, height : %d\n", d->imgs[0].width, d->imgs[0].height);
            dprintf(2,"y : %f --- x2 : %d ----y : %d ----  y2 : %d\n", d->ray->wally, x2, y, y2);
						}
            my_mlx_pixel_put(d, x, y, *(int *)color);
            
            // my_mlx_pixel_put(d, x, y, 0x0000FF00);
        }
        else if (d->ray->raydiry > 0)
        {
            x2 = fmod(d->ray->wallx , 1) * d->imgs[2].width;
            y2 = j * d->imgs[2].height / d->ray->height;
            color = (d->imgs[2].add + (int)(y2 * d->imgs[2].len_line + x2 * (d->imgs[2].bpp / 8)));
			if (x2 < 0)
			{
            dprintf(2,"width : %d, height : %d\n", d->imgs[0].width, d->imgs[0].height);
            dprintf(2,"x : %f --- x2 : %d ----y : %d ----  y2 : %d\n", d->ray->wallx, x2, y, y2);
						}
            my_mlx_pixel_put(d, x, y, *(int *)color);
            
            // my_mlx_pixel_put(d, x, y, 0xFFC0CB);
        }
        else
        {
            x2 = fmod(d->ray->wallx , 1) * d->imgs[3].width;
            y2 = j * d->imgs[3].height / d->ray->height;
            color = (d->imgs[3].add + (int)(y2 * d->imgs[3].len_line + x2 * (d->imgs[3].bpp / 8)));
			if (x2 < 0)
			{
            dprintf(2,"width : %d, height : %d\n", d->imgs[0].width, d->imgs[0].height);
            dprintf(2,"x : %f --- x2 : %d ----y : %d ----  y2 : %d\n", d->ray->wallx, x2, y, y2);
						}
            my_mlx_pixel_put(d, x, y, *(int *)color);
            
            // my_mlx_pixel_put(d, x, y, 0x800080);
        }
        y++;
        j++;
    } 
}

void    hit_point(t_data *d)
{
    float   magnitudevector;
    
    magnitudevector = sqrt(pow(d->ray->raydirx, 2) + pow(d->ray->raydiry, 2));

    if (d->ray->side == 0)
    {
        d->ray->wallx = d->player->x + ((fabs(d->ray->sidedistx) * d->ray->raydirx / magnitudevector));
        d->ray->wally = d->player->y + ((fabs(d->ray->sidedistx) * d->ray->raydiry / magnitudevector));
    }
    else
    {
        d->ray->wallx = d->player->x + ((fabs(d->ray->sidedisty) * d->ray->raydirx / magnitudevector));
        d->ray->wally = d->player->y + ((fabs(d->ray->sidedisty) * d->ray->raydiry / magnitudevector));
    }
	if (d->ray->wallx < 0)
		d->ray->wallx *= -1;
	if (d->ray->wally < 0)
		d->ray->wally *= -1;
   		// printf("x : %f --- y : %f\n", d->ray->wallx, d->ray->wally);
}

int raycasting(t_data *d)
{
    int x;
    x = 0;
    floor_ceiling(d);
    while (x < d->mlx->width)
    {
        // printf("rayon : %d----------------------------------------------\n", x);
        init_ray(d, x);
        init_step(d);
        ray_to_wall(d);
        size_wall(d);
        hit_point(d);
        draw_wall(d, x);
        free(d->ray);
        x++;
    }
    return(0);
}   