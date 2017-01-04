/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 18:32:03 by efichot           #+#    #+#             */
/*   Updated: 2016/12/15 14:26:10 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

t_fractol	*ft_init_fract(void)
{
	t_fractol	*fract;

	if (!(fract = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
		return (NULL);
	fract->x1 = -2.1;
	fract->x2 = 0.6;
	fract->y1 = -1.2;
	fract->y2 = 1.2;
	fract->zr = 0;
	fract->zi = 0;
	fract->cr = 0;
	fract->ci = 0;
	fract->tmp = 0;
	return (fract);
}

int			ft_init_env_fract(t_env *e)
{
	if (!(e->mand = ft_init_fract()))
		return (0);
	if (!(e->axone = ft_init_fract()))
		return (0);
	if (!(e->jul = ft_init_fract()))
		return (0);
	if (!(e->cus = ft_init_fract()))
		return (0);
	if (!(e->bur = ft_init_fract()))
		return (0);
	if (!(e->new = ft_init_fract()))
		return (0);
	return (1);
}

void		*ft_init_env(t_env *e)
{
	e->width = WIDTH;
	e->height = HEIGHT;
	e->x = 1;
	e->y = 1;
	e->z = 250;
	e->color_max = 0x000000;
	e->mlx = mlx_init();
	e->imax = 75;
	e->color_value = 1;
	e->psy = 1;
	e->cr = 5;
	e->cg = 10;
	e->cb = 2;
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	e->pxl = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->ed));
	if (!(ft_init_env_fract(e)))
		return (NULL);
	e->win = mlx_new_window(e->mlx, e->width, e->height, "Fract'ol");
	return (e);
}
