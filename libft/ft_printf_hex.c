/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:57:36 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/18 15:24:42 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_hexc_nbr_fd(unsigned int nb, int fd, int len)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		len = ft_put_hexc_nbr_fd(nb / 16, fd, len);
		if (len < 0 || ft_putchar_fd_printf(base[(nb % 16)], fd) < 0)
			return (-1);
		return (len + 1);
	}
	else
	{
		if (len < 0 || ft_putchar_fd_printf(base[nb], fd) < 0)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_put_hexm_nbr_fd(unsigned int nb, int fd, int len)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		len = ft_put_hexm_nbr_fd(nb / 16, fd, len);
		if (len < 0 || ft_putchar_fd_printf(base[(nb % 16)], fd) < 0)
			return (-1);
		return (len + 1);
	}
	else
	{
		if (len < 0 || ft_putchar_fd_printf(base[nb], fd) < 0)
			return (-1);
		len++;
	}
	return (len);
}

static int	ft_put_hex_ptr_fd(uintptr_t nb, int fd, int len)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		len = ft_put_hex_ptr_fd(nb / 16, fd, len);
		if (len < 0 || ft_putchar_fd_printf(base[(nb % 16)], fd) < 0)
			return (-1);
		return (len + 1);
	}
	else
	{
		if (len < 0 || ft_putchar_fd_printf(base[nb], fd) < 0)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_putptr(uintptr_t val)
{
	int	len;

	len = write(1, "0x", 2);
	if (len < 0)
		return (-1);
	len += ft_put_hex_ptr_fd(val, 1, 0);
	return (len);
}
