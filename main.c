/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:42:58 by svanmeen          #+#    #+#             */
/*   Updated: 2023/06/14 14:13:35 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_parse	**points;
	t_param	*set;

	points = malloc(sizeof(t_parse *));
	if (input(argc, argv) || !points)
	{
		free(points);
		return (EXIT_FAILURE);
	}
	*points = 0;
	set = malloc(sizeof(t_param));
	if (!set)
		return (free_points(points));
	if (ft_get_tab(argv[1], points, &(set->info)))
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
