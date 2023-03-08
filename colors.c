/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:49:05 by svanmeen          #+#    #+#             */
/*   Updated: 2023/03/08 16:13:37 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	colors(char *str, char color)
{
	if (color == 'r')
	{
		ft_printf(KRED);
		ft_printf("%s", str);
		ft_printf(KNORMAL);
	}
	return (1);
}

static int	ft_isspace_n_minus(char *str, int *sign)
{
	int	i;
	int	minus;

	minus = 0;
	i = 0;
	while (!(str[i] >= 33 && str[i] <= 126) || str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			minus++;
		i++;
	}
	*sign = minus;
	return (i);
}

static int	ft_rank_val(char *str, int start)
{
	int	num;

	num = 0;
	while (str[start + num])
		num++;
	return (num - 1);
}

static int	ft_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j] || str[i] == '-' || str[i] == '+')
				return (0);
			j++;
		}
		if (!(str[i] >= '!' && str[i] <= '~'))
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

static int	ft_pow(int base, int rank)
{
	if (rank <= 0)
		return (1);
	else
		return (base * ft_pow(base, rank - 1));
}

int	ft_atoi_base(char *str, char *base)
{
	int	start;
	int	i;
	int	result;
	int	sign;

	i = 0;
	sign = 0;
	result = 0;
	start = ft_isspace_n_minus(str, &sign);
	while (base[i])
	{
		if (base[i] == str[start])
		{
			result += i * ft_pow(ft_base(base), ft_rank_val(str, start));
			i = 0;
			start++;
		}
		else
			i++;
	}
	if (sign % 2 != 0)
		return (-result);
	else
		return (result);
}
