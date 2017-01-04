/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:20:53 by efichot           #+#    #+#             */
/*   Updated: 2016/12/12 18:21:57 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int		ft_bur_iter(t_env *e)
{
	int		i;

	i = 0;
	while (i < e->imax)
	{
		e->bur->tmp = e->bur->zr;
		e->bur->zr = e->bur->zr * e->bur->zr - e->bur->zi * e->bur->zi +
			e->bur->cr;
		e->bur->zi = 2 * fabsf(e->bur->zi * e->bur->tmp) + e->bur->ci;
		if (e->bur->zr * e->bur->zr + e->bur->zi * e->bur->zi >= 4)
			return (i);
		i++;
	}
	return (i);
}

void	burningship(t_env *e)
{
	int		x;
	int		y;

	x = e->x;
	while (x < e->width + e->x)
	{
		y = e->y;
		while (y < e->height + e->y)
		{
			e->bur->zr = 0;
			e->bur->zi = 0;
			e->bur->cr = (float)x / e->z + e->bur->x1;
			e->bur->ci = (float)y / e->z + e->bur->y1;
			ft_put_pxl(e, x - e->x, y - e->y,
				ft_get_color(ft_bur_iter(e), e));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
