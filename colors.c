/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:49:05 by svanmeen          #+#    #+#             */
/*   Updated: 2023/02/23 15:56:46 by svanmeen         ###   ########.fr       */
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
