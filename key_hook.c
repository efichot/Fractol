/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 18:53:24 by efichot           #+#    #+#             */
/*   Updated: 2016/12/15 14:24:15 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int		key_hook_5(int keycode, t_env *e)
{
	if (keycode == 15)
	{
		e->imax = 75;
		e->color_value = 1;
		e->psy = 1;
		e->cr = 5;
		e->cg = 10;
		e->cb = 2;
		e->x = 1;
		e->y = 1;
		e->z = 250;
		e->color_max = 0x000000;
	}
	if (keycode == 87)
		e->fractal = newton;
	return (1);
}

int		key_hook_4(int keycode, t_env *e)
{
	if (keycode == 83)
		e->psy = (e->psy < 255) ? e->psy + 1 : 1;
	if (keycode == 84)
		e->psy = (e->psy > 1) ? e->psy - 1 : 255;
	if (keycode == 86)
	{
		e->cr = 10;
		e->cg = 2;
		e->cb = 5;
	}
	if (keycode == 88)
	{
		e->cr = 2;
		e->cg = 5;
		e->cb = 10;
	}
	return (1);
}

int		key_hook_3(int keycode, t_env *e)
{
	if (keycode == 123)
		e->x -= 60;
	if (keycode == 124)
		e->x += 60;
	if (keycode == 126)
		e->y -= 60;
	if (keycode == 125)
		e->y += 60;
	if (keycode == 69)
	{
		e->z = e->z * 1.2;
		e->y = e->y * 1.2;
		e->x = e->x * 1.2;
	}
	if (keycode == 78)
	{
		if (e->z > 100)
		{
			e->z = e->z / 1.2;
			e->y = e->y / 1.2;
			e->x = e->x / 1.2;
		}
	}
	return (1);
}

int		key_hook_2(int keycode, t_env *e)
{
	if (keycode == 67)
		e->imax += 10;
	if (keycode == 75)
		e->imax -= 10;
	if (keycode == 89)
		e->fractal = mandelbrot;
	if (keycode == 91)
		e->fractal = julia;
	if (keycode == 92)
		e->fractal = axone;
	if (keycode == 8)
		e->fractal = custom;
	return (1);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		free(e);
		exit(0);
	}
	if (keycode == 11)
		e->fractal = burningship;
	if (keycode == 6)
		e->zoom_auto = (!(e->zoom_auto)) ? 1 : 0;
	key_hook_5(keycode, e);
	key_hook_4(keycode, e);
	key_hook_3(keycode, e);
	key_hook_2(keycode, e);
	ft_string_put(e);
	loop_hook(e);
	return (1);
}
