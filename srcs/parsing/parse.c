/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:20:20 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/06 18:51:29 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t trgb_to_hex(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	uint32_t	value;

	value = 0;
	value |= (t << 24);
	value |= (r << 16);
	value |= (g << 8);
	value |= b;
	return (value);
}

void	*parse(t_data *d)
{
	if (d->ac != 2 || !(d->av[1]) || !(d->av[1][0]))
		return (error(NB_ARG));
	if (!ft_strstr(d->av[1], ".cub")
	|| ft_strstr(d->av[1], ".cub")[4])
		return (error(MAP_EXT));
	d->fd_map = open(d->av[1], O_RDONLY);
	if (d->fd_map == -1)
		return (error(strerror(errno)));
	if (!get_keys(d))
		return (NULL);
	if (!check_keys(d))
		return (NULL);
	if (!get_map(d))
		return (NULL);
	if (!check_map(d, -1, -1, 0))
		return (NULL);
	return ("");
}

void	*set_all(t_data *d)
{
	if (!parse(d))
		return (NULL);
	get_size_map(d);
	d->floor = trgb_to_hex(255, d->col[F][0], d->col[F][1], d->col[F][2]);
	d->ceiling = trgb_to_hex(255, d->col[C][0], d->col[C][1], d->col[C][2]);
	// printf("The hexadecimal value of RGBA(%d, %d, %d, %d) is 0x%08X\n", d->col[C][0], d->col[C][1], d->col[C][2], 255, d->ceiling);
	// printf("The hexadecimal value of RGBA(%d, %d, %d, %d) is 0x%08X\n", d->col[F][0], d->col[F][1], d->col[F][2], 255, d->floor);
	d->imgback = create_img(d->mlx, d->mlx->width, d->mlx->height);
	d->imgwall = create_img(d->mlx, d->mlx->width, d->mlx->height);
	if (!d->imgback || !d->imgwall)
		return (NULL);
	set_img_mlx(d);
	return ("");
}
