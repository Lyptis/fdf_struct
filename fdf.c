/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:52:45 by svanmeen          #+#    #+#             */
/*   Updated: 2023/02/28 13:47:16 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	destroy_fdf(t_parse **points, t_param *set)
{
	mlx_destroy_image(set->ptr, set->img->i_ptr);
	mlx_clear_window(set->ptr, set->win);
	mlx_destroy_window(set->ptr, set->win);
	mlx_destroy_display(set->ptr);
	free(set->img);
	free(set);
	free_points(points);
}

int	keyhooks(int keycode, t_param *set)
{
	if (keycode == 0xff1b || !keycode)
		mlx_loop_end(set->ptr);
	if (keycode == 0xff55)
	{
		set->z_factor = set->z_factor * 1.5;
	}
	if (keycode == 0xff56)
		set->z_factor = set->z_factor * 0.5;
	return (0);
}

int	exit_hook(t_param *set)
{
	mlx_loop_end(set->ptr);
}

static void	mlx_initiate(t_param *set)
{
	int	*bpp;
	int	*lnl;
	int	*end;

	bpp = &set->img->bpp;
	lnl = &set->img->lnl;
	end = &set->img->endian;
	set->x_size = 1080;
	set->y_size = 920;
	set->ptr = mlx_init();
	set->win = mlx_new_window(set->ptr, set->x_size, set->y_size, "./fdf");
	set->img->i_ptr = mlx_new_image(set->ptr, set->x_size, set->y_size);
	set->img->addr = mlx_get_data_addr(set->img->i_ptr, bpp, lnl, end);
}

static void	mlx_initiate_hook(t_param *set)
{
	mlx_hook(set->win, 2, 1L << 0, keyhooks, set);
	mlx_hook(set->win, 17, 1L << 19, exit_hook, set);
}

int	run_fdf(t_parse **points, t_param *set)
{
	set->img = malloc(sizeof(t_img));
	if (!(set->img))
		return (EXIT_FAILURE);
	mlx_initiate(set);
	mlx_initiate_hook(set);
	ft_draw(points, set);
	print_list(points);
	mlx_loop(set->ptr);
	destroy_fdf(points, set);
	return (0);
}
