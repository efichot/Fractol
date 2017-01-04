/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:27:35 by efichot           #+#    #+#             */
/*   Updated: 2016/12/15 14:25:31 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>

# define WIDTH 900
# define HEIGHT 600
# define TEXT_COLOR 0xCCCCCC
# define PTR_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6

typedef struct	s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*pxl;
	int					bpp;
	int					s_line;
	int					ed;
	int					width;
	int					height;
	void				(*fractal)();
	int					z;
	int					x;
	int					y;
	int					imax;
	int					psy;
	struct s_fractol	*mand;
	struct s_fractol	*jul;
	struct s_fractol	*axone;
	struct s_fractol	*cus;
	struct s_fractol	*bur;
	struct s_fractol	*new;
	int					zoom_auto;
	unsigned int		color_value;
	unsigned int		color_max;
	int					cr;
	int					cg;
	int					cb;
	int					option_x;
	int					option_y;
}				t_env;

typedef struct	s_fractol
{
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	float		zr;
	float		zi;
	float		cr;
	float		ci;
	float		tmp;
}				t_fractol;

typedef struct	s_new
{
	float		cte1;
	float		cte2;
	float		cte3;
	float		cte4;
}				t_new;

int				ft_arg(int ac, char **av, t_env *e);
void			*ft_init_env(t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
t_fractol		*ft_init_mandelbrot(void);
void			julia(t_env *e);
void			mandelbrot(t_env *e);
void			ft_put_pxl(t_env *e, int x, int y, int color);
void			ft_string_put(t_env *e);
unsigned int	ft_get_color(int i, t_env *e);
int				ft_mandelbrot_iter(t_env *e);
t_fractol		*ft_init_julia(void);
int				ft_julia_iter(t_env *e);
void			axone(t_env *e);
int				ft_axone_iter(t_env *e);
void			custom(t_env *e);
int				ft_cus_iter(t_env *e);
int				key_hook(int keycode, t_env *e);
int				key_hook_2(int keycode, t_env *e);
int				key_hook_3(int keycode, t_env *e);
int				key_hook_4(int keycode, t_env *e);
int				key_hook_5(int keycode, t_env *e);
void			burningship(t_env *e);
int				ft_bur_iter(t_env *e);
int				loop_hook(t_env *e);
void			newton(t_env *e);
int				ft_new_iter(t_env *e, t_new *n);
int				mouse_move_hook(int x, int y, t_env *e);

#endif
