/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:50:55 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/03 20:27:33 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	*fill_keys(t_data *d, char *gnl)
{
	char	**tab;
	static char	*keys[6] = {"NO ", "SO ", "WE ", "EA ", "F ", "C "};
	int		i;

	i = -1;
	while (*gnl == ' ')
		gnl++;
	while (++i < 6)
	{
		if (!ft_strncmp(gnl, keys[i], ft_strlen(keys[i])))
		{
			tab = ft_split_set(gnl, " \n");
			if (!tab)
				return (error(MALLOC_ERR));
			if (ft_arrlen(tab) != 2)
				return (ft_free_arr(tab), error(NB_IDS));
			if (search_dico(tab[0], d))
				return (ft_free_arr(tab), error(TOO_MANY_IDS));
			if (!add_dico(&d->h_dico, tab[0], tab[1]))
				return (error(MALLOC_ERR));
		}
	}
	return ("");
}

void	*get_keys(t_data *d)
{
	char	*gnl;

	gnl = get_next_line(d->fd_map);
	while (gnl)
	{
		if (gnl && gnl[0] != '\n')
			if (!fill_keys(d, gnl))
				return (free(gnl), NULL);
		free(gnl);
		if (ft_lstsize(d->h_dico) != 6)
			gnl = get_next_line(d->fd_map);
		else
			break ;
	}
	if (gnl)
		free(gnl);
	return ("");
}
