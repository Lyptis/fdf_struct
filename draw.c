/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:37:53 by svanmeen          #+#    #+#             */
/*   Updated: 2023/04/19 14:55:10 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	draw_lines(t_parse *curr, t_param *set, t_parse *prev)
{
	int	line_s;

	line_s = prev->y;
	if (curr && curr->y == line_s)
		put_pts(*prev, *curr, set);
	return (0);
}

static t_parse	*draw_cols(t_parse *curr, t_param *set, t_parse *prev)
{
	int	line_s;

	line_s = prev->x;
	if (curr->x == line_s)
	{
		put_pts(*prev, *curr, set);
		prev = prev->next;
	}
	return (prev);
}

int	ft_overflow(t_parse **pts, t_info *set)
{
	t_parse	*tmp;

	tmp = (*pts);
	while (tmp)
	{
		if ((tmp->graph_x > set->x_size * 3 || tmp->graph_y - \
			(tmp->z * set->lenght) * set->z_factor > set->y_size * 3) || \
			(tmp->graph_x < 0 || tmp->graph_y - (tmp->z * set->lenght) * \
			set->z_factor < 0))
			return (1);
		else
			tmp = tmp->next;
	}
	return (0);
}

int	draw_pts(t_parse **tab, t_param *set)
{
	t_parse	*col;
	t_parse	*curr;
	t_parse	*tmp;
	t_info	*info;

	info = &(set->info);
	col = *tab;
	curr = col->next;
	tmp = col;
	if (ft_overflow(tab, info))
	{
		if (info->y_tr == 1)
			info->lenght = info->lenght * 0.5;
		else if (info->x_tr == 1)
			info->z_factor = info->z_factor * 0.5;
		get_points(tab, info);
	}
	while (curr)
	{
		draw_lines(curr, set, tmp);
		col = draw_cols(curr, set, col);
		tmp = curr;
		curr = curr->next;
	}
	return (0);
}

void	ft_draw(t_parse **points, t_param *set)
{
	t_mlx	*mlx;
	t_info	info;
	t_img	*img;

	mlx = set->mlx;
	info = set->info;
	img = set->img;
	ft_setpoints(points, &(set->info));
	draw_pts(points, set);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->i_ptr, \
		-info.x_size, -info.y_size);
}
