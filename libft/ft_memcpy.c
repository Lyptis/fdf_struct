/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:09:47 by svanmeen          #+#    #+#             */
/*   Updated: 2022/11/14 13:35:04 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*strdst;
	char	*strsrc;

	i = 0;
	strdst = dst;
	strsrc = (char *)src;
	while (i < n && ((dst != NULL) || (src != NULL)))
	{
		strdst[i] = strsrc[i];
		i++;
	}
	return (strdst);
}
