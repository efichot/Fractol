/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_and_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 18:15:49 by efichot           #+#    #+#             */
/*   Updated: 2016/12/15 14:35:46 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void			ft_put_pxl(t_env *e, int x, int y, int color)
{
	int		i;

	i = (x * 4) + (y * e->s_line);
	e->pxl[i] = color;
	e->pxl[++i] = color >> 8;
	e->pxl[++i] = color >> 16;
}

unsigned int	ft_get_color(int i, t_env *e)
{
	unsigned int	color;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (i == e->imax)
		return (e->color_max);
	r = e->psy * i * e->cr;
	g = e->psy * i * e->cg;
	b = e->psy * i * e->cb;
	color = (r << 16) + (g << 8) + b;
	return (color);
}

void			ft_string_put(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 0, TEXT_COLOR, "Quit = ESC");
	mlx_string_put(e->mlx, e->win, 10, 15, TEXT_COLOR, "Psy mode = 1 or 2");
	mlx_string_put(e->mlx, e->win, 10, 35, TEXT_COLOR, "Pink mode = 4");
	mlx_string_put(e->mlx, e->win, 10, 55, TEXT_COLOR, "Newton = 5");
	mlx_string_put(e->mlx, e->win, 10, 75, TEXT_COLOR, "Blue mode = 6");
	mlx_string_put(e->mlx, e->win, 10, 95,
		TEXT_COLOR, "Zoom = - or + or scrolling");
	mlx_string_put(e->mlx, e->win, 10, 115, TEXT_COLOR, "Iteration = / or *");
	mlx_string_put(e->mlx, e->win, 10, 135, TEXT_COLOR, "Mandelbrot = 7");
	mlx_string_put(e->mlx, e->win, 10, 155, TEXT_COLOR, "Julia = 8");
	mlx_string_put(e->mlx, e->win, 10, 175, TEXT_COLOR, "Axone = 9");
	mlx_string_put(e->mlx, e->win, 10, 195, TEXT_COLOR, "Custom = c");
	mlx_string_put(e->mlx, e->win, 10, 215, TEXT_COLOR, "Burningship = b");
	mlx_string_put(e->mlx, e->win, 10, 235, TEXT_COLOR, "Zoom auto = z");
	mlx_string_put(e->mlx, e->win, 10, 255, TEXT_COLOR, "Reset = r");
}

int				mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 5)
	{
		e->x += x / 5;
		e->y += y / 5;
		e->z = e->z * 1.2;
		e->y = e->y * 1.2;
		e->x = e->x * 1.2;
		e->imax += 1;
	}
	if (button == 4)
	{
		if (e->z > 100)
		{
			e->x -= x / 5;
			e->y -= y / 5;
			e->z = e->z / 1.2;
			e->y = e->y / 1.2;
			e->x = e->x / 1.2;
			e->imax -= 1;
		}
	}
	loop_hook(e);
	return (1);
}

int				mouse_move_hook(int x, int y, t_env *e)
{
	if (x < 0 || x >= e->width || y < 0 || y >= e->height)
		return (0);
	e->option_x = x;
	e->option_y = y;
	e->fractal(e);
	ft_string_put(e);
	return (1);
}
