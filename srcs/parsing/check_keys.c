/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:51:44 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/04 18:05:07 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	*fill_colors(t_data *d, int i, char *val)
{
	static char	*keys[6] = {"F", "C"};
	char		**sp_col;
	int			j;

	j = -1;
	while (++i <= 1)
	{
		val = search_dico(keys[i], d);
		if (val || val[0] || !ft_isdigit(val[0])
			|| !ft_isdigit(ft_strlen(val) - 1))
			return (error(COL_ERROR));
		sp_col = ft_split(val, ',');
		if (!sp_col)
			return (MALLOC_ERR);
		if (ft_arrlen(sp_col) != 3 || !check_arr_type(sp_col))
			return (ft_free_arr(sp_col), error(COL_ERROR));
		else
			while (++j < 3)
				d->col[i][j] = ft_atoi(sp_col[j]);
	}
	return ("");
}

static void	*fill_ids(t_data *d)
{
	static char	*keys[6] = {"NO", "SO", "WE", "EA"};
	char		*val;
	int			i;

	i = -1;
	while (++i <= 3)
	{
		val = search_dico(keys[i], d);
		d->imgs[i].ptr = mlx_xpm_file_to_image(d->mlx->mlx, \
			val, &d->imgs[i].width, &d->imgs[i].height);
		if (!d->imgs[i].ptr)
			return (error(MLX_IMG_ERR));
	}
	return ("");
}

void	*check_keys(t_data *d)
{
	if (ft_lstsize(d->h_dico) != 6)
		return (error(TOO_LOW_IDS));
	if (!set_color_img(d, -1))
		return (NULL);
	if (!fill_ids(d))
		return (NULL);
	if (!fill_colors(d, -1, NULL))
		return (NULL);
	return ("");
}
