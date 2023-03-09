/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:54:13 by svanmeen          #+#    #+#             */
/*   Updated: 2023/03/09 12:33:41 by svanmeen         ###   ########.fr       */
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
	struct s_parse	*next;
}					t_parse;

typedef struct s_img
{
	void	*i_ptr;
	char	*addr;
	int		bpp;
	int		lnl;
	int		endian;
}			t_img;

typedef struct s_param
{
	void	*ptr;
	void	*win;
	t_img	*img;
	t_parse	**points;
	double		lenght;
	int		max_x;
	int		max_y;
	double		z_factor;
	int		y_size;
	int		x_size;
	int		mid_x;
	int		mid_y;
	int		x_tr;
	int		y_tr;
}			t_param;

//	Check_inputs
int		input(int argc, char **argv);

//	Parse Map
int		ft_get_tab(char *file, t_parse **tab, t_param *set);

void	print_list(t_parse **list);

//	Main function
int		run_fdf(t_parse **points, t_param *set);
void	ft_draw(t_parse **points, t_param *set);
void	ft_setpoints(t_parse **pts, t_param *set);
void	get_points(t_parse	**tab, t_param *set);

//	Utils
//parse
t_parse	*get_last(t_parse **list);
//draw
void	img_pixel_put(t_img *img, int x, int y, int color);
int		ft_inc(int x, int y);
int		ft_get(int x, int y);
int		put_pts(t_parse p1, t_parse p2, t_param *img);
int		draw_pts(t_parse **tab, t_param *set);
int		ft_atoi_base(char *str, char *base);
//output
int		colors(char *str, char color);
//memory protection
int		free_points(t_parse **list);

#endif
