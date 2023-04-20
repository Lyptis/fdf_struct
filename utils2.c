/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:49:38 by svanmeen          #+#    #+#             */
/*   Updated: 2023/04/19 14:49:53 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	colors(char *str, char color)
{
	if (color == 'r')
	{
		ft_printf(KRED);
		ft_printf("%s", str);
		ft_printf(KNORMAL);
	}
	return (1);
}
