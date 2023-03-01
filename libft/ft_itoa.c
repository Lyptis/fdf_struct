/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:11:40 by svanmeen          #+#    #+#             */
/*   Updated: 2022/11/15 12:12:14 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoacount(int nb, int *sign)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count++;
		*sign *= -1;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static char	*ft_itoaspe(int n)
{
	char	*tab;

	if (n == 0)
	{
		tab = malloc(2 * sizeof(char));
		if (!tab)
			return (NULL);
		ft_strlcpy(tab, "0", 2);
		return (tab);
	}
	else
	{
		tab = malloc(12 * sizeof(char));
		if (tab == NULL)
			return (NULL);
		ft_strlcpy(tab, "-2147483648", 12);
		return (tab);
	}
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		i;
	int		count;
	int		sign;

	i = 0;
	sign = 1;
	if (n == -2147483648 || n == 0)
		return (ft_itoaspe(n));
	count = ft_itoacount(n, &sign);
	tab = malloc((count + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	tab[count] = '\0';
	if (sign < 0)
		tab[i++] = 45;
	n = n * sign;
	while (i < count)
	{
		tab[count - 1] = (n % 10) + 48;
		n = n / 10;
		count--;
	}
	return (tab);
}
