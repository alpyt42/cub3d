/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:20:20 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/12 10:18:03 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_pos_player(t_data *d)
{
	int		i;
	int		j;

	i = -1;
	while (d->map[++i])
	{
		j = -1;
		while (d->map[i][++j])
		{
			if (ft_strchr("NSWE", d->map[i][j]))
			{
				d->player->x = i + 0.5;
				d->player->y = j + 0.5;
				d->player->orientation = d->map[i][j];
			}
			if (d->map[i][j] == ' ')
				d->map[i][j] = '1';
		}
	}
}

uint32_t	trgb_to_hex(char t, char r, char g, char b)
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
	d->imgback = create_img(d->mlx, d->mlx->width, d->mlx->height);
	d->imgwall = create_img(d->mlx, d->mlx->width, d->mlx->height);
	get_pos_player(d);
	// display_arr(d->map, "d->map ");
	start_player_orientation(d);
	start_plan_vector(d);
	if (!d->imgback || !d->imgwall)
		return (NULL);
	set_img_mlx(d);
	// printf("d->imgback->bpp : %d\n", d->imgback->bpp);
	return ("");
}
