/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:24:14 by amontalb          #+#    #+#             */
/*   Updated: 2023/04/03 09:57:18 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long long int   ft_get_time(void)
{
    struct timeval  time;
    
    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));   
}