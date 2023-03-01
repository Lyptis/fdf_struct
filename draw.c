/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:37:53 by svanmeen          #+#    #+#             */
/*   Updated: 2023/03/01 15:21:03 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	draw_lines(t_parse *curr, t_param *set, t_parse *prev)
{
	int	line_s;

	line_s = prev->y;
	if (curr && curr->y == line_s)
		put_pts(*prev, *curr, set);
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

int	draw_pts(t_parse **tab, t_param *set)
{
	t_parse	*col;
	t_parse	*curr;
	t_parse	*tmp;

	col = *tab;
	curr = col->next;
	tmp = col;
	while (curr)
	{
		draw_lines(curr, set, tmp);
		col = draw_cols(curr, set, col);
		tmp = curr;
		curr = curr->next;
	}
}

void	ft_draw(t_parse **points, t_param *set)
{
	ft_setpoints(points, set);
	draw_pts(points, set);
	mlx_put_image_to_window(set->ptr, set->win, set->img->i_ptr, set->x_size / 2 - (set->mid_x) * 2, set->y_size / 2 - (set->mid_y));
}
