/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:37:10 by svanmeen          #+#    #+#             */
/*   Updated: 2023/04/19 14:48:34 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	ft_rad(int angle)
{
	double	ret;

	ret = angle * 3.1415 / 180;
	return (ret);
}

t_parse	*ft_calc(t_parse *curr, t_parse *prev, t_info *set, int angle)
{
	int	lenght;

	lenght = set->lenght;
	curr->graph_x = prev->graph_x + lenght * cos(ft_rad(angle));
	curr->graph_y = (prev->graph_y) + lenght * sin(ft_rad(angle));
	return (curr);
}

void	get_points(t_parse	**tab, t_info *set)
{
	t_parse	*first;
	t_parse	*curr;
	t_parse	*tmp;

	first = *tab;
	curr = first->next;
	tmp = first;
	while (curr)
	{
		if (curr->y == first->y)
		{
			curr = ft_calc(curr, tmp, set, 30);
			curr = curr->next;
			tmp = tmp->next;
		}
		else
		{
			ft_calc(curr, first, set, 150);
			first = curr;
			curr = curr->next;
			tmp = tmp->next;
		}
	}
}

void	set_win(t_parse **tab, t_info *setup)
{
	t_parse	*curr;

	curr = *tab;
	while (curr->x != setup->max_x / 2)
		curr = curr->next;
	while (curr->y != setup->max_y / 2)
		curr = curr->next;
	setup->mid_x = 0;
	setup->mid_y = 0;
}

void	ft_setpoints(t_parse **pts, t_info *set)
{
	int	x;
	int	y;

	x = set->x_size;
	y = set->y_size;
	(*pts)->graph_x = x * 3 / 2;
	(*pts)->graph_y = y * 3 / 2;
	(*pts)->graph_x += (x / set->max_x) / 2;
	(*pts)->graph_y += (y / set->max_y) / 2;
	set->lenght = ((x / (set->max_y) + (y / (set->max_x)) / 2) / 3);
	get_points(pts, set);
	set_win(pts, set);
}
