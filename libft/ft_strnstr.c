/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:21:44 by svanmeen          #+#    #+#             */
/*   Updated: 2022/11/14 14:00:54 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)haystack;
	i = 0;
	j = 0;
	if ((haystack == NULL && len == 0) || (needle[i] == '\0'))
		return (str);
	while (str[i] != '\0' && i < len)
	{
		while (str[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] != '\0')
				j++;
			else
				return (&str[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}
