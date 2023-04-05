/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:20:20 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/05 14:15:06 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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