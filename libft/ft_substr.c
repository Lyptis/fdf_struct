/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:15:24 by svanmeen          #+#    #+#             */
/*   Updated: 2022/12/14 12:48:40 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	else if (len > ft_strlen(s))
		len = ft_strlen(s);
	dst = ft_calloc(len + 1, sizeof(char));
	if (!dst)
		return (dst);
	while ((char)s[start + i] && i < len && start <= ft_strlen(s))
	{
		dst[i] = (char)s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
