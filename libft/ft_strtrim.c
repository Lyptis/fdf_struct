/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:14:06 by svanmeen          #+#    #+#             */
/*   Updated: 2022/11/15 15:12:06 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getstart(char *s1, char *set)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (ft_strlen(set) > 1)
	{
		while (s1[i] && set[j])
		{
			if (set[j] == s1[i])
			{
				i++;
				j = 0;
			}
			else
				j++;
		}
	}
	else
	{
		while (s1[i] && s1[i] == set[j])
			i++;
	}
	return (i);
}

static int	ft_getend(char *s1, char *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	if (ft_strlen(set) > 1)
	{
		while (s1[i] && set[j])
		{
			if (set[j] == s1[i])
			{
				i--;
				j = 0;
			}
			else
				j++;
		}
	}
	else
	{
		while (s1[i] && s1[i] == set[j])
			i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = ft_getstart((char *)s1, (char *)set);
	end = ft_getend((char *)s1, (char *)set);
	if (start > end)
		return (ft_strdup(""));
	str = malloc((end - start + 2) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)&s1[start], end - start + 2);
	return (str);
}
