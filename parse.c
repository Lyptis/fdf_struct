/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:26:21 by svanmeen          #+#    #+#             */
/*   Updated: 2023/03/30 12:16:09 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	*ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

t_parse	*ft_create(char *str, int k, int i)
{
	t_parse	*nb;
	char	**strs;

	nb = malloc(sizeof(t_parse));
	if (!nb)
		return (NULL);
	else
	{
		strs = ft_split(str, ',');
		if (!strs)
		{
			free(nb);
			return (NULL);
		}
		nb->x = i;
		nb->y = k;
		nb->z = ft_atoi(strs[0]);
		if (strs[1])
			nb->color = ft_atoi_base(strs[1] + 2, "0123456789abcdef");
		else
			nb->color = 16777215;
		nb->graph_x = 0;
		nb->graph_y = 0;
		free(strs[0]);
		if (strs[1])
			free(strs[1]);
		free(strs);
	}
	nb->next = 0;
	return (nb);
}

t_parse	*ft_parse_line(char *line, t_parse **tab, int k, t_param *setup)
{
	t_parse	*tmp;
	t_parse	*last;
	char	**tab_a;
	int		i;

	i = 0;
	tab_a = ft_split(line, ' ');
	if (!tab_a)
		return (NULL);
	while (tab_a[i])
	{
		tmp = ft_create(tab_a[i], k, i);
		if (!tmp)
			return (ft_free(tab_a, i));
		last = get_last(tab);
		if (!last)
			*tab = tmp;
		else
			last->next = tmp;
		i++;
	}
	ft_free(tab_a, i);
	setup->max_x = i;
	return (tmp);
}

int	ft_get_tab(char *file, t_parse **tab, t_param *set)
{
	int		fd;
	int		i;
	char	*linetmp;

	fd = open(file, O_RDONLY);
	linetmp = get_next_line(fd);
	i = 0;
	set->z_factor = 0.2;
	if (linetmp)
	{
		while (linetmp)
		{
			if (!(ft_parse_line(linetmp, tab, i, set)))
				return (colors("Malloc: Error\n", 'r'));
			free(linetmp);
			linetmp = get_next_line(fd);
			i++;
		}
		free(linetmp);
	}
	else
		return (colors("File empty", 'r'));
	close(fd);
	set->max_y = i;
	return (0);
}
