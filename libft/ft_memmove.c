/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:24:53 by svanmeen          #+#    #+#             */
/*   Updated: 2022/11/14 13:39:50 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*sstr;
	unsigned char	*dstr;
	size_t			i;

	dstr = (unsigned char *)dst;
	sstr = (unsigned char *)src;
	if ((dstr < sstr) && ((dst != NULL) || (src != NULL)))
	{
		i = 0;
		while (i < len)
		{
			dstr[i] = sstr[i];
			i++;
		}
	}
	else if ((dst != NULL) || (src != NULL))
	{
		i = 0;
		while (len > i)
		{
			dstr[len - 1] = sstr[len - 1];
			len--;
		}
	}
	return (dstr);
}
