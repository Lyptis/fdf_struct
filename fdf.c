/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:52:45 by svanmeen          #+#    #+#             */
/*   Updated: 2023/03/30 14:30:49 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_set_image(t_param *set)
{
	int	*bpp;
	int	*lnl;
	int	*end;

	bpp = &set->img->bpp;
	lnl = &set->img->lnl;
	end = &set->img->endian;
	set->img->i_ptr = mlx_new_image(set->ptr, set->x_size * 3, set->y_size * 3);
	set->img->addr = mlx_get_data_addr(set->img->i_ptr, bpp, lnl, end);
}

static void	destroy_fdf(t_parse **points, t_param *set)
{
	mlx_destroy_image(set->ptr, set->img->i_ptr);
	///mlx_clear_window(set->ptr, set->win);
	mlx_destroy_window(set->ptr, set->win);
	mlx_destroy_display(set->ptr);
	free(set->ptr);
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
		set->y_tr = 0;
		set->x_tr = 1;
		mlx_clear_window(set->ptr, set->win);
		mlx_destroy_image(set->ptr, set->img->i_ptr);
		mlx_set_image(set);
		draw_pts(set->points, set);
		mlx_put_image_to_window(set->ptr, set->win, set->img->i_ptr, - set->x_size + set->mid_x, - set->y_size + set->mid_y);
	}
	if (keycode == 0xff56)
	{
		set->z_factor = set->z_factor * 0.5;
		mlx_clear_window(set->ptr, set->win);
		mlx_destroy_image(set->ptr, set->img->i_ptr);
		mlx_set_image(set);
		draw_pts(set->points, set);
		mlx_put_image_to_window(set->ptr, set->win, set->img->i_ptr, - set->x_size + set->mid_x, - set->y_size + set->mid_y);
	}
	if (keycode == 0xff53)
	{
		mlx_clear_window(set->ptr, set->win);
		set->mid_x = set->mid_x + 5;
		mlx_put_image_to_window(set->ptr, set->win, set->img->i_ptr, - set->x_size + set->mid_x, - set->y_size + set->mid_y);
	}
	if (keycode == 0xff54)
	{
		mlx_clear_window(set->ptr, set->win);
		set->mid_y = set->mid_y + 5;
		mlx_put_image_to_window(set->ptr, set->win, set->img->i_ptr, - set->x_size + set->mid_x, - set->y_size + set->mid_y);
	}
	if (keycode == 0xff52)
	{
		mlx_clear_window(set->ptr, set->win);
		set->mid_y = set->mid_y - 5;
		mlx_put_image_to_window(set->ptr, set->win, set->img->i_ptr, - set->x_size + set->mid_x, - set->y_size + set->mid_y);
	}
	if (keycode == 0xff51)
	{
		mlx_clear_window(set->ptr, set->win);
		set->mid_x = set->mid_x - 5;
		mlx_put_image_to_window(set->ptr, set->win, set->img->i_ptr, - set->x_size + set->mid_x, - set->y_size + set->mid_y);
	}
	if (keycode == 0xffab)
	{
		set->lenght = set->lenght * 1.5;
		set->y_tr = 1;
		set->x_tr = 0;
		mlx_clear_window(set->ptr, set->win);
		mlx_destroy_image(set->ptr, set->img->i_ptr);
		mlx_set_image(set);
		get_points(set->points, set);
		draw_pts(set->points, set);
		mlx_put_image_to_window(set->ptr, set->win, set->img->i_ptr, - set->x_size + set->mid_x, - set->y_size + set->mid_y);
	}
	if (keycode == 0xffad)
	{
		set->lenght = set->lenght * 0.5;
		mlx_clear_window(set->ptr, set->win);
		mlx_destroy_image(set->ptr, set->img->i_ptr);
		mlx_set_image(set);
		get_points(set->points, set);
		draw_pts(set->points, set);
		mlx_put_image_to_window(set->ptr, set->win, set->img->i_ptr, - set->x_size + set->mid_x, - set->y_size + set->mid_y);
	}
	return (0);
}

int	exit_hook(t_param *set)
{
	mlx_loop_end(set->ptr);
	return (0);
}

static void	mlx_initiate_hook(t_param *set)
{
	mlx_hook(set->win, 2, 1L << 0, keyhooks, set);
	mlx_hook(set->win, 17, 1L << 19, exit_hook, set);
}

static void	mlx_initiate(t_param *set)
{
	set->x_size = 2160;
	set->y_size = 1840;
	set->ptr = mlx_init();
	set->win = mlx_new_window(set->ptr, set->x_size, set->y_size, "./fdf");
	mlx_set_image(set);
}

int	run_fdf(t_parse **points, t_param *set)
{
	set->img = malloc(sizeof(t_img));
	if (!(set->img))
		return (EXIT_FAILURE);
	mlx_initiate(set);
	mlx_initiate_hook(set);
	ft_draw(points, set);
	set->points = points;
	mlx_loop(set->ptr);
	destroy_fdf(points, set);
	return (0);
}
