/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:18:11 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/28 11:45:37 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (0);
		nb = nb * 10 + str[i++] - 48;
	}
	if (nb == 0 && str[0] != '0' && str[1] == '\0')
		return (0);
	return (sign * nb);
}

static int	after_space(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[0] && str[0] == ' ')
		while (str[i++])
			if (str[i] && str[i] != ' ')
				return (1);
	return (0);
}

static size_t	check_sign(char **str, unsigned long long *sign)
{
	size_t	i;

	i = 0;
	while (*str[i] && *str[i] == ' ')
		i++;
	if (*str[i] == '-' || *str[i] == '+')
	{
		if (*str[i] == '-')
			*sign *= -1;
		else
			*str[i] = '0';
		i++;
	}
	return (i);
}

long	ft_atoi_long(char *str)
{
	size_t				i;
	unsigned long long	nb;
	unsigned long long	sign;

	nb = 0;
	sign = 1;
	if (!str)
		return (-1);
	i = check_sign(&str, &sign);
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
			return (-1);
		if (str[i] == ' ' && after_space(&str[i]))
			return (-1);
		else if (str[i] == ' ' && !after_space(&str[i]))
			break ;
		nb = nb * 10 + str[i++] - 48;
	}
	if (sign * nb == (unsigned long long)-1)
		return (255);
	if (nb > 9223372036854775807)
		return (-1);
	return (sign * nb);
}
