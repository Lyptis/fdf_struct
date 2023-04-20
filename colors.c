/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:49:05 by svanmeen          #+#    #+#             */
/*   Updated: 2023/04/19 14:50:12 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static int	capital(char b, char n)
{
	if (b - 32 == n && ((b - 32) >= 65 && (b - 32) <= 90))
		return (1);
	else if (b + 32 == n && ((b + 32) >= 97 && (b + 32) <= 122))
		return (1);
	else
		return (0);
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
	start = 0;
	while (base[i])
	{
		if (capital(base[i], str[start]) || base[i] == str[start])
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
