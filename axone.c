/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 18:09:19 by efichot           #+#    #+#             */
/*   Updated: 2016/12/12 13:20:11 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int		ft_axone_iter(t_env *e)
{
	int		i;

	i = 0;
	while (i < e->imax)
	{
		e->axone->tmp = e->axone->zr;
		e->axone->zr = e->axone->zr * e->axone->zr - e->axone->zi *
		e->axone->zi + e->axone->cr;
		e->axone->zi = 2 * e->axone->zi * e->axone->tmp + e->axone->ci;
		if (e->axone->zr * e->axone->zr + e->axone->zi * e->axone->zi >= 4)
			return (i);
		i++;
	}
	return (i);
}

void	axone(t_env *e)
{
	int		x;
	int		y;

	x = e->x;
	while (x < e->width + e->x)
	{
		y = e->y;
		while (y < e->height + e->y)
		{
			e->axone->zr = (float)x / e->z + e->axone->x1;
			e->axone->zi = (float)y / e->z + e->axone->y1;
			e->axone->cr = 0;
			e->axone->ci = 1;
			ft_put_pxl(e, x - e->x, y - e->y,
				ft_get_color(ft_axone_iter(e), e));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
