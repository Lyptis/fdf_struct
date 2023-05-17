/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:42:37 by svanmeen          #+#    #+#             */
/*   Updated: 2023/05/17 12:00:21 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_parse	*get_last(t_parse **list)
{
	t_parse	*current;

	if (!*list)
		return (NULL);
	current = *list;
	while (current->next)
		current = current->next;
	return (current);
}

void	img_pixel_put(t_imag *img, int x, int y, int color)
{
	char	*put;

	put = img->addr + (y * img->lnl + x *(img->bpp / 8));
	*(unsigned int *)put = color;
}

void	img_pixel_puts(t_imag *img, int x, int y, int color)
{
	char	*put;

	put = img->addr + (y * img->lnl + x *(img->bpp / 8));
	*(unsigned int *)put = color;
}

int	ft_inc(int x, int y)
{
	if (x > y)
		return (1);
	else if (x == y)
		return (0);
	else
		return (-1);
}

int	ft_get(int x, int y)
{
	if (x > y)
		return (x - y);
	else
		return (y - x);
}
