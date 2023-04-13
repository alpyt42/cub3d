/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:11:29 by amontalb          #+#    #+#             */
/*   Updated: 2023/04/13 13:30:34 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    move(t_data *d)
{
    // mlx_destroy_image(d->mlx->mlx, d->mlx->img);
    // printf("img : %p\n", d->mlx->img);
    // d->mlx->img = mlx_new_image(d->mlx->mlx, d->mlx->width, d->mlx->height);
	raycasting(d);
	display_map(d);
    mlx_put_image_to_window(d->mlx->mlx, d->mlx->win, d->mlx->img, 0, 0);
    // d->mlx->addr = mlx_get_data_addr(d->mlx->img, &d->mlx->bpp, &d->mlx->size_line, &d->mlx->endian);
}

void look_left(t_data *d)
{
    // float   magnitude;
    // float   angle;
    
    // magnitude = sqrt(pow(d->player->dirx, 2) + pow(d->player->diry, 2));
    // angle = atan2(d->player->diry, d->player->dirx);
    // angle += 3.14 * -10 / 180;
    // d->player->dirx = magnitude * cos(angle);
    // d->player->diry = magnitude * sin(angle);
    if (d->player->orientation == 'N')
        d->player->orientation = 'W';
    else if (d->player->orientation == 'W')
        d->player->orientation = 'S';
    else if (d->player->orientation == 'S')
        d->player->orientation = 'E';
    else if (d->player->orientation == 'E')
        d->player->orientation = 'N';
    start_player_orientation(d);
    start_plan_vector(d);
	move (d);
    printf("new dirx : %f, diry : %f\n",  d->player->dirx,  d->player->diry);
	printf("planx : %f, plany : %f\n", d->player->planx, d->player->plany );
}


void look_right(t_data *d)
{
    // float   magnitude;
    // float   angle;

    // magnitude = sqrt(pow(d->player->dirx, 2) + pow(d->player->diry, 2));
    // angle = atan2(d->player->diry, d->player->dirx);
    // angle += 3.14 * 10 / 180;
    // d->player->dirx = magnitude * cos(angle);
    // d->player->diry = magnitude * sin(angle);
    // printf("new dirx : %f, diry : %f\n",  d->player->dirx,  d->player->diry);
    printf("%c\n", d->player->orientation);
    if (d->player->orientation == 'N')
        d->player->orientation = 'E';
    else if (d->player->orientation == 'E')
        d->player->orientation = 'S';
    else if (d->player->orientation == 'S')
        d->player->orientation = 'W';
    else if (d->player->orientation == 'W')
        d->player->orientation = 'N';
    printf("%c\n", d->player->orientation);
    start_player_orientation(d);
    start_plan_vector(d);
	move (d);
    printf("new dirx : %f, diry : %f\n",  d->player->dirx,  d->player->diry);
	printf("planx : %f, plany : %f\n", d->player->planx, d->player->plany );
}


int avoid_wall(int keysym, t_data *d)
{
    if (keysym == KEY_W)
    {
        if (d->map[(int)(d->player->x )][(int)(d->player->y )] == '1')
        {
            d->player->x -= d->player->dirx;
            d->player->y -= d->player->diry;
            return (1);
        }
    }
    if (keysym == KEY_S)
    {
        printf("%c\n", d->map[(int)(d->player->x + d->player->dirx)][(int)(d->player->y + d->player->diry)]);
        if (d->map[(int)(d->player->x - d->player->dirx)][(int)(d->player->y - d->player->diry)] == '1')
        {
            d->player->x += d->player->dirx;
            d->player->y += d->player->diry;
            return (1);
        }
    }
    return (0);
}

void	move_left(t_data *d)
{
	
		if (d->player->orientation == 'N' && d->map[(int)(d->player->x + 1)][(int)(d->player->y)] != '1')
        	d->player->x += 1;
    	else if (d->player->orientation == 'E' && d->map[(int)(d->player->x)][(int)(d->player->y - 1)] != '1')
      	 	d->player->y -= 1;
   	 	else if (d->player->orientation == 'S' && d->map[(int)(d->player->x - 1)][(int)(d->player->y)] != '1')
        	d->player->x -= 1;
   		 else if (d->player->orientation == 'W' && d->map[(int)(d->player->x)][(int)(d->player->y + 1)] != '1') 
      		d->player->y += 1;
		// d->player->x -= d->player->planx;
		// d->player->x -= d->player->plany;
		move(d);
}

void	move_right(t_data *d)
{
	
		if (d->player->orientation == 'N' && d->map[(int)(d->player->x - 1)][(int)(d->player->y)] != '1')
        	d->player->x -= 1;
    	else if (d->player->orientation == 'E' && d->map[(int)(d->player->x)][(int)(d->player->y + 1)] != '1')
      	 	d->player->y += 1;
   	 	else if (d->player->orientation == 'S'&& d->map[(int)(d->player->x + 1)][(int)(d->player->y)] != '1')
        	d->player->x += 1;
   		 else if (d->player->orientation == 'W' && d->map[(int)(d->player->x)][(int)(d->player->y - 1)] != '1')
      		d->player->y -= 1;
		// d->player->x += d->player->planx;
		// d->player->x += d->player->plany;
		move(d);

}

int	handle_input(int keysym, t_data *d)
{
	if (keysym == KEY_W  || keysym == 13)
	{
        d->player->x += d->player->dirx;
        d->player->y += d->player->diry;
        if (avoid_wall(keysym, d))
            return (0) ;
        move (d);
	}
    if (keysym == KEY_S || keysym == 1)
	{
        d->player->x -= d->player->dirx;
        d->player->y -= d->player->diry;
        if (avoid_wall(keysym, d))
            return (0) ;
        move (d);
	}
	if (keysym == 65363 )
        look_right(d);
	if (keysym == 65361)
		look_left(d);
	if (keysym == KEY_A)
		move_left(d);
	if (keysym == KEY_D)
		move_right(d);
	return (0);
}