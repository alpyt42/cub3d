/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dico.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:55:32 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/03 13:50:02 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_dico	*init_dico(void)
{
	t_dico	*dico;

	dico = malloc(sizeof(t_dico));
	if (!dico)
		return (NULL);
	dico->key = NULL;
	dico->val = NULL;
	return (dico);
}