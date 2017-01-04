/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:37:20 by efichot           #+#    #+#             */
/*   Updated: 2016/12/15 14:01:40 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int		main(int ac, char **av)
{
	t_env	*e;

	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))) || !ft_arg(ac, av, e))
		return (0);
	if (!(ft_init_env(e)))
	{
		free(e);
		exit(0);
		return (0);
	}
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_hook(e->win, MOTION_NOTIFY, PTR_MOTION_MASK, mouse_move_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
