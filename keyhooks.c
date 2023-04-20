/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:58:15 by svanmeen          #+#    #+#             */
/*   Updated: 2023/04/19 15:35:21 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keyhooks_height(int keycode, t_param *set)
{
	t_mlx	*mlx;
	t_info	*info;

	info = &(set->info);
	mlx = set->mlx;
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_image(mlx->ptr, set->img->i_ptr);
	if (keycode == 0xff55)
	{
		info->z_factor = info->z_factor * 1.5;
		info->y_tr = 0;
		info->x_tr = 1;
	}
	if (keycode == 0xff56)
		info->z_factor = info->z_factor * 0.5;
	mlx_set_image(set, mlx);
	draw_pts(set->points, set);
	mlx_put_image_to_window(mlx->ptr, mlx->win, set->img->i_ptr, \
		-info->x_size + info->mid_x, -info->y_size + info->mid_y);
	return (0);
}

int	keyhooks_trans(int keycode, t_param *set)
{
	t_mlx	*mlx;
	t_info	*info;

	info = &(set->info);
	mlx = set->mlx;
	mlx_clear_window(mlx->ptr, mlx->win);
	if (keycode == 0xff53)
		info->mid_x = info->mid_x + 5;
	if (keycode == 0xff54)
		info->mid_y = info->mid_y + 5;
	if (keycode == 0xff52)
		info->mid_y = info->mid_y - 5;
	if (keycode == 0xff51)
		info->mid_x = info->mid_x - 5;
	mlx_put_image_to_window(mlx->ptr, mlx->win, set->img->i_ptr, \
			-info->x_size + info->mid_x, -info->y_size + info->mid_y);
	return (0);
}

int	keyhooks_zoom(int keycode, t_param *set)
{
	t_mlx	*mlx;
	t_info	*info;

	info = &(set->info);
	mlx = set->mlx;
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_image(mlx->ptr, set->img->i_ptr);
	if (keycode == 0xffab)
	{
		info->lenght = info->lenght * 1.5;
		info->y_tr = 1;
		info->x_tr = 0;
	}
	if (keycode == 0xffad)
		info->lenght = info->lenght * 0.5;
	mlx_set_image(set, mlx);
	get_points(set->points, info);
	draw_pts(set->points, set);
	mlx_put_image_to_window(mlx->ptr, mlx->win, set->img->i_ptr, \
		-info->x_size + info->mid_x, -info->y_size + info->mid_y);
	return (0);
}

int	keyhooks(int keycode, t_param *set)
{
	t_mlx	*mlx;

	mlx = set->mlx;
	if (keycode == 0xff1b || !keycode)
		mlx_loop_end(mlx->ptr);
	if (keycode == 0xff55 || keycode == 0xff56)
		keyhooks_height(keycode, set);
	if (keycode == 0xff53 || keycode == 0xff54 || \
		keycode == 0xff52 || keycode == 0xff51)
		keyhooks_trans(keycode, set);
	if (keycode == 0xffab || 0xffad)
		keyhooks_zoom(keycode, set);
	return (0);
}

int	exit_hook(t_param *set)
{
	mlx_loop_end(set->mlx->ptr);
	return (0);
}
