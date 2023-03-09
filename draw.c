/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:37:53 by svanmeen          #+#    #+#             */
/*   Updated: 2023/03/09 12:33:32 by svanmeen         ###   ########.fr       */
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

int	ft_overflow(t_parse **pts, t_param *set)
{
	t_parse	*tmp;

	tmp = (*pts);
	while (tmp)
	{
		if ((tmp->graph_x > set->x_size * 3 || tmp->graph_y - (tmp->z * set->lenght) * set->z_factor > set->y_size * 3) || (tmp->graph_x < 0 || tmp->graph_y - (tmp->z * set->lenght) * set->z_factor < 0))
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

	col = *tab;
	curr = col->next;
	tmp = col;
	//print_list(tab);
	if (ft_overflow(tab, set))
	{
		if (set->y_tr == 1)
			set->lenght = set->lenght * 0.5;
		else if (set->x_tr == 1)
			set->z_factor = set->z_factor * 0.5;
		get_points(tab, set); 
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
	ft_setpoints(points, set);
	draw_pts(points, set);
	mlx_put_image_to_window(set->ptr, set->win, set->img->i_ptr, - set->x_size, - set->y_size);
}
