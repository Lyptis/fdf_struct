/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:54:13 by svanmeen          #+#    #+#             */
/*   Updated: 2023/05/17 12:26:57 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "fcntl.h"
# include "stdio.h"
# include "math.h"

# define KNORMAL "\x1B[0m"
# define KRED "\x1B[31m"
# define KGREEN "\x1B[32m"
# define KYELLOW "\x1B[33m"
# define KBLUE "\x1B[34m"
# define KWHITE "\x1B[37m"

typedef struct s_parse
{
	long				x;
	long				y;
	long				z;
	int					color;
	long				graph_x;
	long				graph_y;
	struct s_parse		*next;
}						t_parse;

typedef struct s_imag
{
	void	*i_ptr;
	char	*addr;
	int		bpp;
	int		lnl;
	int		endian;
}			t_imag;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}			t_mlx;

typedef struct s_info
{
	double	lenght;
	long	max_x;
	long	max_y;
	double	z_factor;
	long	y_size;
	long	x_size;
	long	mid_x;
	long	mid_y;
	int		x_tr;
	int		y_tr;
}			t_info;

typedef struct s_param
{
	t_mlx	*mlx;
	t_imag	*img;
	t_parse	**points;
	t_parse	**save;
	t_info	info;
}			t_param;

//	Check_inputs
int		input(int argc, char **argv);

//	Parse Map
int		ft_get_tab(char *file, t_parse **tab, t_info *set);

void	print_list(t_parse **list);

//	Main function
int		run_fdf(t_parse **points, t_param *set);
void	ft_draw(t_parse **points, t_param *set);
void	ft_setpoints(t_parse **pts, t_info *set);
void	get_points(t_parse	**tab, t_info *set);
//	Hooks
int		keyhooks(int keycode, t_param *set);
int		exit_hook(t_param *set);

//	Utils
//parse
t_parse	*get_last(t_parse **list);
//draw
void	img_pixel_put(t_imag *img, int x, int y, int color);
void	img_pixel_put(t_imag *img, int x, int y, int color);
void	img_pixel_puts(t_imag *img, int x, int y, int color);
int		ft_inc(int x, int y);
int		ft_get(int x, int y);
int		ft_inc(int x, int y);
int		ft_get(int x, int y);
int		put_pts(t_parse p1, t_parse p2, t_param *img);
int		draw_pts(t_parse **tab, t_param *set);
int		ft_atoi_base(char *str, char *base);
void	mlx_set_image(t_param *set, t_mlx *mlx);
//output
int		colors(char *str, char color);
//memory protection
int		free_points(t_parse **list);

#endif
