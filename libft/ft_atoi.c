/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:32:55 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/26 13:47:00 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	*s;
	int		i;
	int		sign;
	long	result;

	s = (char *)str;
	i = 0;
	result = 0;
	sign = 1;
	while ((s[i] > 8 && s[i] < 14) || s[i] == 32)
		i++;
	if (s[i] == 43 || s[i] == 45)
	{
		if (s[i] == 45)
			sign = sign * -1;
		i++;
	}
	while (s[i] > 47 && s[i] < 58)
	{
		result = result * 10 + (s[i] - 48);
		i++;
	}
	if ((result > 2147483648 && sign < 0) || (result > 2147483647 && sign > 0))
		return (-1);
	return (result * sign);
}
