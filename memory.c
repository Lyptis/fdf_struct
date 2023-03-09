/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:35:36 by svanmeen          #+#    #+#             */
/*   Updated: 2023/03/09 12:08:16 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_points(t_parse **list)
{
	t_parse	*tmp;

	while ((*list))
	{
		tmp = *list;
		(*list) = (*list)->next;
		free(tmp);
	}
	free(list);
	return (1);
}
