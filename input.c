/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:46:22 by svanmeen          #+#    #+#             */
/*   Updated: 2023/02/23 16:37:47 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	input(int argc, char **argv)
{
	char	*ext;
	int		fd;

	if (argc != 2)
		return (colors("Invalid Args\n", 'r'));
	fd = open(argv[1], O_RDONLY);
	ext = ft_strrchr(argv[1], '.');
	if (ft_strncmp(ext, ".fdf", 4))
		return (colors("File not .fdf\n", 'r'));
	if (fd == -1)
		return (colors("File does not exist or can not be read\n", 'r'));
	close(fd);
	return (0);
}
