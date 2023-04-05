/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:15:29 by amontalb          #+#    #+#             */
/*   Updated: 2023/04/05 13:40:48 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_input(int keysym, t_data *d)
{
    (void)d;
    printf("toto----------------------------\n");
	if (keysym == KEY_W)
	{
        printf("-------------yees--------------\n");
		exit(0);
	}
	// if (keysym == 13)
	// 	move_up(d);
	// if (keysym == 0)
	// 	move_left(d);
	// if (keysym == 1)
	// 	move_down(d);
	// if (keysym == 2)
	// 	move_right(d);
	return (0);
}