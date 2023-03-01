/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:13:37 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/20 12:25:49 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_nb_w(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_malloc(char *s, char c, int *count)
{
	char	**tab;
	int		count_m;

	*count = ft_get_nb_w(s, c);
	count_m = *count;
	tab = malloc((count_m + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	return (tab);
}

static char	**ft_free_all(char **tab, int i)
{
	while (i > 0)
		free(tab[i--]);
	free(tab);
	return (NULL);
}

static int	ft_get_size(char *s, char c, int *i)
{
	int	save;

	save = *i;
	while (s[*i] != c && s[*i])
		*i = *i + 1;
	return (save);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		save;
	int		count;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	tab = ft_malloc((char *)s, c, &count);
	if (!tab)
		return (NULL);
	while (++i < count)
	{
		while (s[j] == c)
			j++;
		save = ft_get_size((char *)s, c, &j);
		tab[i] = ft_substr(s, save, j - save);
		if (!tab[i])
			return (ft_free_all(tab, i));
		j++;
	}
	tab[count] = NULL;
	return (tab);
}
