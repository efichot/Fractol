/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:33:23 by efichot           #+#    #+#             */
/*   Updated: 2016/12/14 15:56:57 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int			ft_new_iter(t_env *e, t_new *n)
{
	int			i;
	float		tmp;

	i = 0;
	while (i < e->imax && ((e->new->zr - 1) * (e->new->zr - 1) + e->new->zi *
	e->new->zi) >= 0.000001 && ((e->new->zr + 0.5) * (e->new->zr + 0.5) +
	(e->new->zi - 0.866025) * (e->new->zi - 0.866025)) >= 0.000001 &&
	((e->new->zr + 0.5) * (e->new->zr + 0.5) + (e->new->zi + 0.866025) *
	(e->new->zi + 0.866025)) >= 0.000001)
	{
		tmp = e->new->zr;
		n->cte1 = tmp * tmp - e->new->zi * e->new->zi;
		n->cte2 = 36 * tmp * tmp * e->new->zi * e->new->zi;
		n->cte3 = tmp * tmp * tmp - 3 * tmp * e->new->zi * e->new->zi - 1;
		n->cte4 = 3 * tmp * tmp * e->new->zi - e->new->zi * e->new->zi *
		e->new->zi;
		e->new->zr = (9 * tmp * n->cte1 * n->cte1 + n->cte2 * tmp - 3 * n->cte1
			* n->cte3 - 6 * tmp * e->new->zi * n->cte4) / (9 * n->cte1 *
				n->cte1 + n->cte2);
		e->new->zi = (9 * e->new->zi * n->cte1 * n->cte1 + n->cte2 * e->new->zi
			- 3 * n->cte1 * n->cte4 + 6 * tmp * e->new->zi * n->cte3) /
			(9 * n->cte1 * n->cte1 + n->cte2);
		i++;
	}
	return (i);
}

void		newton(t_env *e)
{
	int			x;
	int			y;
	t_new		*n;

	if (!(n = (t_new *)ft_memalloc(sizeof(t_new))))
		return ;
	x = e->x;
	while (x < e->width + e->x)
	{
		y = e->y;
		while (y < e->height + e->y)
		{
			e->new->zr = (float)x / e->z + e->new->x1;
			e->new->zi = (float)y / e->z + e->new->y1;
			ft_put_pxl(e, x - e->x, y - e->y,
				ft_get_color(ft_new_iter(e, n), e));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
