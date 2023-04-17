/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:42:37 by svanmeen          #+#    #+#             */
/*   Updated: 2023/04/17 12:48:19 by svanmeen         ###   ########.fr       */
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

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*put;

	put = img->addr + (y * img->lnl + x *(img->bpp / 8));
	*(unsigned int *)put = color;
}

void	img_pixel_puts(t_img *img, int x, int y, int color)
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

int	put_pts(t_parse p1, t_parse p2, t_param *set)
{
	int	diff;
	int	dx;
	int	dy;
	t_info	info;

	info = set->info;
	p1.graph_y = p1.graph_y - (p1.z * info.lenght) * info.z_factor;
	p2.graph_y = p2.graph_y - (p2.z * info.lenght) * info.z_factor;
	diff = ft_get(p2.graph_x, p1.graph_x);
	dx = diff;
	dy = ft_get(p2.graph_y, p1.graph_y);
	if (diff > dy)
	{
		while (!(p2.graph_x == p1.graph_x && p2.graph_y == p1.graph_y))
		{
			img_pixel_put(set->img, p1.graph_x, p1.graph_y, p2.color);
			p1.graph_x += ft_inc(p2.graph_x, p1.graph_x);
			diff = diff - dy;
			if (diff < 0)
			{
				p1.graph_y += ft_inc(p2.graph_y, p1.graph_y);
				diff = diff + dx;
			}
		}
	}
	else
	{
		diff = ft_get(p2.graph_y, p1.graph_y);
		dy = diff;
		dx = ft_get(p2.graph_x, p1.graph_x);
		while (!(p2.graph_x == p1.graph_x && p2.graph_y == p1.graph_y))
		{
			img_pixel_puts(set->img, p1.graph_x, p1.graph_y, p2.color);
			p1.graph_y += ft_inc(p2.graph_y, p1.graph_y);
			diff = diff - dx;
			if (diff < 0)
			{
				p1.graph_x += ft_inc(p2.graph_x, p1.graph_x);
				diff = diff + dy;
			}
		}
	}
	return (0);
}
