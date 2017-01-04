/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 18:14:32 by efichot           #+#    #+#             */
/*   Updated: 2016/12/15 14:21:46 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int		ft_cus_iter(t_env *e)
{
	int		i;

	i = 0;
	while (i < e->imax)
	{
		e->cus->tmp = e->cus->zr;
		e->cus->zr = e->cus->zr * e->cus->zr - e->cus->zi * e->cus->zi - 0.8 +
			(0.6 / ((float)e->option_x / (float)e->width));
		e->cus->zi = 2 * e->cus->zi * e->cus->tmp + 0.27015 /
			((float)e->option_y / (float)e->height);
		if (e->cus->zr * e->cus->zr + e->cus->zi * e->cus->zi >= 4)
			return (i);
		i++;
	}
	return (i);
}

void	custom(t_env *e)
{
	int		x;
	int		y;

	x = e->x;
	while (x < e->width + e->x)
	{
		y = e->y;
		while (y < e->height + e->y)
		{
			e->cus->zr = (float)x / e->z + e->cus->x1;
			e->cus->zi = (float)y / e->z + e->cus->y1;
			ft_put_pxl(e, x - e->x, y - e->y, ft_get_color(ft_cus_iter(e), e));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
