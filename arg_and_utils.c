/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_and_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 18:33:30 by efichot           #+#    #+#             */
/*   Updated: 2016/12/15 14:25:53 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int		ft_arg(int ac, char **av, t_env *e)
{
	if (ac != 2)
	{
		ft_putstr_fd("Usage <filename> [mandelbrot/julia/axone", 2);
		ft_putstr_fd("/custom/burningship/newton]\n", 2);
		return (0);
	}
	if (ft_strcmp(av[1], "axone") == 0)
		e->fractal = axone;
	if (ft_strcmp(av[1], "julia") == 0)
		e->fractal = julia;
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		e->fractal = mandelbrot;
	if (ft_strcmp(av[1], "custom") == 0)
		e->fractal = custom;
	if (ft_strcmp(av[1], "burningship") == 0)
		e->fractal = burningship;
	if (ft_strcmp(av[1], "newton") == 0)
		e->fractal = newton;
	if (e->fractal)
		return (1);
	ft_putstr_fd("Sorry <filename> can only be [mandelbrot/julia/axone", 2);
	ft_putstr_fd("/custom/burningship/newton]\n", 2);
	return (0);
}

void	zoom_auto(t_env *e)
{
	e->z = e->z * 1.025;
	e->y = e->y * 1.025;
	e->x = e->x * 1.025;
	e->x += e->width / 80;
	e->y += e->height / 80;
	e->imax += 1;
}

int		loop_hook(t_env *e)
{
	if (e->zoom_auto)
		zoom_auto(e);
	e->fractal(e);
	ft_string_put(e);
	return (1);
}
