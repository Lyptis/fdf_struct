/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:52:45 by svanmeen          #+#    #+#             */
/*   Updated: 2023/04/17 12:47:24 by svanmeen         ###   ########.fr       */
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
	set->img->i_ptr = mlx_new_image(mlx->ptr, set->info.x_size * 3, set->info.y_size * 3);
	set->img->addr = mlx_get_data_addr(set->img->i_ptr, bpp, lnl, end);
}

static void	destroy_fdf(t_parse **points, t_param *set)
{
	t_mlx	*mlx;

	mlx = set->mlx;
	mlx_destroy_image(mlx->ptr, set->img->i_ptr);
	///mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	free(set->img);
	free(mlx);
	free_points(points);
	free(set);
}

int	keyhooks(int keycode, t_param *set)
{
	t_mlx	*mlx;
	t_info	*info;

	info = &(set->info);
	mlx = set->mlx;
	if (keycode == 0xff1b || !keycode)
		mlx_loop_end(mlx->ptr);
	if (keycode == 0xff55)
	{
		info->z_factor = info->z_factor * 1.5;
		info->y_tr = 0;
		info->x_tr = 1;
		mlx_clear_window(mlx->ptr, mlx->win);
		mlx_destroy_image(mlx->ptr, set->img->i_ptr);
		mlx_set_image(set, mlx);
		draw_pts(set->points, set);
		mlx_put_image_to_window(mlx->ptr, mlx->win, set->img->i_ptr, - info->x_size + info->mid_x, - info->y_size + info->mid_y);
	}
	if (keycode == 0xff56)
	{
		info->z_factor = info->z_factor * 0.5;
		mlx_clear_window(mlx->ptr, mlx->win);
		mlx_destroy_image(mlx->ptr, set->img->i_ptr);
		mlx_set_image(set, mlx);
		draw_pts(set->points, set);
		mlx_put_image_to_window(mlx->ptr, mlx->win, set->img->i_ptr, - info->x_size + info->mid_x, - info->y_size + info->mid_y);
	}
	if (keycode == 0xff53)
	{
		mlx_clear_window(mlx->ptr, mlx->win);
		info->mid_x = info->mid_x + 5;
		mlx_put_image_to_window(mlx->ptr, mlx->win, set->img->i_ptr, - info->x_size + info->mid_x, - info->y_size + info->mid_y);
	}
	if (keycode == 0xff54)
	{
		mlx_clear_window(mlx->ptr, mlx->win);
		info->mid_y = info->mid_y + 5;
		mlx_put_image_to_window(mlx->ptr, mlx->win, set->img->i_ptr, - info->x_size + info->mid_x, - info->y_size + info->mid_y);
	}
	if (keycode == 0xff52)
	{
		mlx_clear_window(mlx->ptr, mlx->win);
		info->mid_y = info->mid_y - 5;
		mlx_put_image_to_window(mlx->ptr, mlx->win, set->img->i_ptr, - info->x_size + info->mid_x, - info->y_size + info->mid_y);
	}
	if (keycode == 0xff51)
	{
		mlx_clear_window(mlx->ptr, mlx->win);
		info->mid_x = info->mid_x - 5;
		mlx_put_image_to_window(mlx->ptr, mlx->win, set->img->i_ptr, - info->x_size + info->mid_x, - info->y_size + info->mid_y);
	}
	if (keycode == 0xffab)
	{
		info->lenght = info->lenght * 1.5;
		info->y_tr = 1;
		info->x_tr = 0;
		mlx_clear_window(mlx->ptr, mlx->win);
		mlx_destroy_image(mlx->ptr, set->img->i_ptr);
		mlx_set_image(set, mlx);
		get_points(set->points, info);
		draw_pts(set->points, set);
		mlx_put_image_to_window(mlx->ptr, mlx->win, set->img->i_ptr, - info->x_size + info->mid_x, - info->y_size + info->mid_y);
	}
	if (keycode == 0xffad)
	{
		info->lenght = info->lenght * 0.5;
		mlx_clear_window(mlx->ptr, mlx->win);
		mlx_destroy_image(mlx->ptr, set->img->i_ptr);
		mlx_set_image(set, mlx);
		get_points(set->points, info);
		draw_pts(set->points, set);
		mlx_put_image_to_window(mlx->ptr, mlx->win, set->img->i_ptr, - info->x_size + info->mid_x, - info->y_size + info->mid_y);
	}
	return (0);
}

int	exit_hook(t_param *set)
{
	mlx_loop_end(set->mlx->ptr);
	return (0);
}

static void	mlx_initiate_hook(t_param *set)
{
	mlx_hook(set->mlx->win, 2, 1L << 0, keyhooks, set);
	mlx_hook(set->mlx->win, 17, 1L << 19, exit_hook, set);
}

static t_mlx *	mlx_initiate(t_param *set)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	set->info.x_size = 800;
	set->info.y_size = 800;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, set->info.x_size, set->info.y_size, "fdf");
	mlx_set_image(set, mlx);
	return (mlx);
}

int	run_fdf(t_parse **points, t_param *set)
{
	set->img = malloc(sizeof(t_img));
	if (!(set->img))
		return (EXIT_FAILURE);
	set->mlx = mlx_initiate(set);
	mlx_initiate_hook(set);
	ft_draw(points, set);
	set->points = points;
	mlx_loop(set->mlx->ptr);
	destroy_fdf(points, set);
	return (0);
}
