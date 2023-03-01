/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:42:58 by svanmeen          #+#    #+#             */
/*   Updated: 2023/02/28 13:47:36 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_list(t_parse **list)
{
	t_parse	*tmp;
	int		i;

	tmp = *list;
	if (!(*list))
		ft_printf("Empty\n");
	else
	{
		while (tmp)
		{
			ft_printf("x :%d y:%d z:%d\n", tmp->graph_x, tmp->graph_y, tmp->z);
			tmp = tmp->next;
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_parse	**points;
	t_param	*set;

	points = malloc(sizeof(t_parse *));
	if (input(argc, argv) || !points)
		return (EXIT_FAILURE);
	*points = 0;
	set = malloc(sizeof(t_param));
	if (!set)
		return (free_points(points));
	if (ft_get_tab(argv[1], points, set))
	{
		free(set);
		return (free_points(points));
	}
	if (run_fdf(points, set) == 1)
	{
		free(set->img);
		free(set);
		free_points(points);
	}
	return (EXIT_SUCCESS);
}
