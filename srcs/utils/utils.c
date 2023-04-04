/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:24:14 by amontalb          #+#    #+#             */
/*   Updated: 2023/04/04 19:21:44 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long long	ft_get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	*error(char *str)
{
	ft_dprintf(2, "ERROR\n");
	if (!str)
		return (NULL);
	else
		ft_dprintf(2, "%s\n", str);
	return (NULL);
}

void	display_dico(t_list *h_dico)
{
	t_dico	*d;
	void	*tmp;

	tmp = h_dico;
	while (h_dico)
	{
		d = h_dico->content;
		dprintf(2, "keys : $%s$ && val : $%s$\n", d->key, d->val);
		h_dico = h_dico->next;
	}
	h_dico = tmp;
}

void	*check_arr_type(char **str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
			if (!ft_isdigit(str[i][j]))
				return (NULL);
	}
	return ("");
}