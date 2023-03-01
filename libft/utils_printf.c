/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:48:13 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/18 15:23:45 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd_printf(char c, int fd)
{
	return (write(fd, &c, sizeof(char)));
}

int	ft_putstr_fd_printf(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr_fd_printf("(null)", 1));
	while (s[i])
	{
		if (ft_putchar_fd_printf(s[i], fd) > 0)
			i++;
		else
			return (-1);
	}
	return (i);
}

int	ft_putnbr_fd_printf(long nb, int fd, int len)
{
	if (nb < 0)
	{
		if (ft_putchar_fd_printf('-', fd) < 0)
			return (-1);
		len++;
		nb *= -1;
		len = ft_putnbr_fd_printf(nb, fd, len);
		if (len < 0)
			return (-1);
		return (len);
	}
	if (nb >= 10)
	{
		len = ft_putnbr_fd_printf(nb / 10, fd, len);
		if (len < 0 || ft_putchar_fd_printf((nb % 10) + '0', fd) < 0)
			return (-1);
		return (len + 1);
	}
	else
	{
		if (len < 0 || ft_putchar_fd_printf(nb + '0', fd) < 0)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_putunbr_fd(unsigned int nb, int fd, int len)
{
	if (nb >= 10)
	{
		len = ft_putunbr_fd(nb / 10, fd, len);
		if (len < 0 || ft_putchar_fd_printf((nb % 10) + '0', fd) < 0)
			return (-1);
		return (len + 1);
	}
	else
	{
		if (len < 0 || ft_putchar_fd_printf(nb + '0', fd) < 0)
			return (-1);
		len++;
	}
	return (len);
}
