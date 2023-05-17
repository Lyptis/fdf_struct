/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:56:20 by svanmeen          #+#    #+#             */
/*   Updated: 2023/05/17 12:05:48 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_ptspos(t_parse p1, t_parse p2, t_param *set)
{
	int		diff;
	int		dx;
	int		dy;

	diff = ft_get(p2.graph_x, p1.graph_x);
	dx = diff;
	dy = ft_get(p2.graph_y, p1.graph_y);
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

static void	put_ptsneg(t_parse p1, t_parse p2, t_param *set)
{
	int		diff;
	int		dx;
	int		dy;

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

int	put_pts(t_parse p1, t_parse p2, t_param *set)
{
	int		diff;
	int		dy;
	t_info	info;

	info = set->info;
	p1.graph_y = p1.graph_y - (p1.z * info.lenght) * info.z_factor;
	p2.graph_y = p2.graph_y - (p2.z * info.lenght) * info.z_factor;
	diff = ft_get(p2.graph_x, p1.graph_x);
	dy = ft_get(p2.graph_y, p1.graph_y);
	if (diff > dy)
		put_ptspos(p1, p2, set);
	else
		put_ptsneg(p1, p2, set);
	return (0);
}
