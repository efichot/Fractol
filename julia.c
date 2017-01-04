/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 18:12:02 by efichot           #+#    #+#             */
/*   Updated: 2016/12/12 13:20:08 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int		ft_julia_iter(t_env *e)
{
	int		i;

	i = 0;
	while (i < e->imax)
	{
		e->jul->tmp = e->jul->zr;
		e->jul->zr = e->jul->zr * e->jul->zr - e->jul->zi * e->jul->zi +
			e->jul->cr;
		e->jul->zi = 2 * e->jul->zi * e->jul->tmp + e->jul->ci;
		if (e->jul->zr * e->jul->zr + e->jul->zi * e->jul->zi >= 4)
			return (i);
		i++;
	}
	return (i);
}

void	julia(t_env *e)
{
	int		x;
	int		y;

	x = e->x;
	while (x < e->width + e->x)
	{
		y = e->y;
		while (y < e->height + e->y)
		{
			e->jul->zr = (float)x / e->z + e->jul->x1;
			e->jul->zi = (float)y / e->z + e->jul->y1;
			e->jul->cr = 0.285;
			e->jul->ci = 0.52;
			ft_put_pxl(e, x - e->x, y - e->y,
				ft_get_color(ft_julia_iter(e), e));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
