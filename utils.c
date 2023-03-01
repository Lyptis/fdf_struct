/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:42:37 by svanmeen          #+#    #+#             */
/*   Updated: 2023/02/28 14:02:17 by svanmeen         ###   ########.fr       */
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

int	put_pts(t_parse p1, t_parse p2, t_param *img)
{
	int	diff;
	int	dx;
	int	dy;
	int	y1;
	int	y2;

	y1 = p1.graph_y;//- (p1.z * img->lenght) * img->z_factor;
	y2 = p2.graph_y;//- (p2.z * img->lenght) * img->z_factor;
	diff = ft_get(p2.graph_x, p1.graph_x);
	dx = diff;
	dy = ft_get(y2, y1);
	if (diff > dy)
	{
		while (!(p2.graph_x == p1.graph_x && y2 == y1))
		{
			img_pixel_put(img->img->i_ptr, p1.graph_x, y1, 16711935);
			p1.graph_x += ft_inc(p2.graph_x, p1.graph_x);
			diff = diff - dy;
			if (diff < 0)
			{
				y1 += ft_inc(y2, y1);
				diff = diff + dx;
			}
		}
	}
	else
	{
		diff = ft_get(y2, y1);
		dy = diff;
		dx = ft_get(p2.graph_x, p1.graph_x);
		while (!(p2.graph_x == p1.graph_x && y2 == y1))
		{
			img_pixel_put(img->img->i_ptr, p1.graph_x, y1, 16711935);
			y1 += ft_inc(y2, y1);
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
