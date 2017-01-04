/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 18:13:31 by efichot           #+#    #+#             */
/*   Updated: 2016/12/13 14:24:33 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int		ft_mandelbrot_iter(t_env *e)
{
	int		i;

	i = 0;
	while (i < e->imax)
	{
		e->mand->tmp = e->mand->zr;
		e->mand->zr = e->mand->zr * e->mand->zr - e->mand->zi * e->mand->zi +
			e->mand->cr;
		e->mand->zi = 2 * e->mand->zi * e->mand->tmp + e->mand->ci;
		if (e->mand->zr * e->mand->zr + e->mand->zi * e->mand->zi >= 4)
			return (i);
		i++;
	}
	return (i);
}

void	mandelbrot(t_env *e)
{
	int		x;
	int		y;

	x = e->x;
	while (x < e->width + e->x)
	{
		y = e->y;
		while (y < e->height + e->y)
		{
			e->mand->zr = 0;
			e->mand->zi = 0;
			e->mand->cr = (float)x / e->z + e->mand->x1;
			e->mand->ci = (float)y / e->z + e->mand->y1;
			ft_put_pxl(e, x - e->x, y - e->y,
				ft_get_color(ft_mandelbrot_iter(e), e));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
