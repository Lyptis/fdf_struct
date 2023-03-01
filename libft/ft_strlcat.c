/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:08:28 by svanmeen          #+#    #+#             */
/*   Updated: 2022/11/14 13:59:52 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = 0;
	if ((dst == NULL && dstsize == 0) || dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	else
	{
		i = ft_strlen(dst);
		while (src[j] && (i + j) < dstsize - 1)
		{
			dst[i + j] = src[j];
			j++;
		}
		if (i + j < dstsize)
			dst[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}
