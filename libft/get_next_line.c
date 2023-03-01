/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:19:31 by svanmeen          #+#    #+#             */
/*   Updated: 2022/12/12 13:41:57 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_line(char *mem)
{
	size_t	index;

	index = 0;
	if (!mem)
		return (0);
	while (mem[index])
	{
		if (mem[index] == '\n')
			return (index);
		index++;
	}
	return (index);
}

static char	*ft_new(char *mem, char *buf)
{
	static char		*new_mem;
	char			*temp;
	size_t			max_size;

	if (!mem)
	{
		temp = ft_gstrdup(buf);
		if (!temp)
			return (NULL);
		return (temp);
	}
	max_size = ft_gstrlen(mem) + BUFFER_SIZE + 1;
	new_mem = malloc((max_size) * sizeof(char));
	if (!new_mem)
	{
		if (mem)
			free(mem);
		mem = NULL;
		return (NULL);
	}
	new_mem = ft_gstrncpy(new_mem, mem, ft_gstrlen(mem) + 1);
	ft_gstrlcat(new_mem, buf, max_size);
	free(mem);
	return (new_mem);
}

static char	*ft_save(char *mem, int gnl_index)
{
	static char	*new_mem;
	size_t		size;

	if (!mem[gnl_index])
	{
		free(mem);
		return (NULL);
	}
	size = ft_gstrlen(mem);
	new_mem = malloc((size - gnl_index + 2) * sizeof(char));
	if (!new_mem)
	{
		if (mem)
			free(mem);
		mem = NULL;
		return (NULL);
	}
	new_mem = ft_gstrncpy(new_mem, &mem[gnl_index], size - gnl_index + 1);
	free(mem);
	return (new_mem);
}

static char	*ft_check(char **mem, int read_val)
{
	char	*str;
	int		gnl_index;

	if (!*mem || read_val < 0)
	{
		if (*mem)
			free(*mem);
		*mem = NULL;
		return (NULL);
	}
	gnl_index = ft_get_line(*mem);
	str = malloc((gnl_index + 1) * sizeof(char));
	if (!str)
	{
		if (*mem)
			free(*mem);
		*mem = NULL;
		return (NULL);
	}
	ft_gstrlcpy(str, *mem, gnl_index + 2);
	*mem = ft_save(*mem, gnl_index);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*mem;
	char		buf[BUFFER_SIZE + 1];
	size_t		gnl_index;
	int			read_val;

	gnl_index = ft_get_line(mem);
	while (!mem || mem[gnl_index] != '\n')
	{
		read_val = read(fd, buf, BUFFER_SIZE);
		if (read_val <= 0)
			return (ft_check(&mem, read_val));
		buf[read_val] = '\0';
		mem = ft_new(mem, buf);
		gnl_index = ft_get_line(mem);
	}
	str = malloc((gnl_index + 2) * sizeof(char));
	if (!str)
	{
		free(mem);
		return (mem = NULL, NULL);
	}
	ft_gstrlcpy(str, mem, gnl_index + 2);
	mem = ft_save(mem, gnl_index + 1);
	return (str);
}
