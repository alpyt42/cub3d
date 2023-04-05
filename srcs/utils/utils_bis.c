/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:50:44 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/05 13:53:04 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*rm_ret_gnl(int fd)
{
	char	*gnl;

	gnl = get_next_line(fd);
	while (gnl && gnl[0] && gnl[0] == '\n')
	{
		free(gnl);
		gnl = get_next_line(fd);
	}
	return (gnl);
}