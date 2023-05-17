/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:52:45 by svanmeen          #+#    #+#             */
/*   Updated: 2023/05/17 12:19:50 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_set_image(t_param *set, t_mlx *mlx)
{
	int	*bpp;
	int	*lnl;
	int	*end;

	bpp = &set->img->bpp;
	lnl = &set->img->lnl;
	end = &set->img->endian;
	set->img->i_ptr = mlx_new_image(mlx->ptr, set->info.x_size * 3, \
		set->info.y_size * 3);
	set->img->addr = mlx_get_data_addr(set->img->i_ptr, bpp, lnl, end);
}

static void	destroy_fdf(t_parse **points, t_param *set)
{
	t_mlx	*mlx;

	mlx = set->mlx;
	mlx_destroy_image(mlx->ptr, set->img->i_ptr);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	free(set->img);
	free(mlx);
	free_points(points);
	free(set);
	exit(0);
}

static void	mlx_initiate_hook(t_param *set)
{
	mlx_hook(set->mlx->win, 2, 1L << 0, keyhooks, set);
	mlx_hook(set->mlx->win, 17, 1L << 19, exit_hook, set);
}

static t_mlx	*mlx_initiate(t_param *set)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	set->info.x_size = 1920;
	set->info.y_size = 1080;
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		return (NULL);
	mlx->win = mlx_new_window(mlx->ptr, set->info.x_size, \
		set->info.y_size, "fdf");
	if (mlx->win == NULL)
		return (NULL);
	mlx_set_image(set, mlx);
	return (mlx);
}

int	run_fdf(t_parse **points, t_param *set)
{
	set->img = malloc(sizeof(t_imag));
	if (!(set->img))
		return (EXIT_FAILURE);
	set->mlx = mlx_initiate(set);
	if (set->mlx == NULL)
		return (1);
	mlx_initiate_hook(set);
	ft_draw(points, set);
	set->points = points;
	mlx_loop(set->mlx->ptr);
	destroy_fdf(points, set);
	return (0);
}
