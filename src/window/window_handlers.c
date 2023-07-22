/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:55:56 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/22 16:06:11 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/libftmlx.h"
#include <libft/data/mem.h>
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>

void	ft_window_handlers_init(t_window_handlers *window_handlers)
{
	ft_mem_zero(window_handlers, sizeof(t_window_handlers));
}

int	ft_window_cross_handler(t_window *window)
{
	ft_window_close(window);
	return (0);
}

int	ft_window_loop_adaptator(t_window *window)
{
	if (!window->open)
		return (0);
	if (window->handlers.loop_handler)
		window->handlers.loop_handler(
			window, window->handlers.loop_handler_data);
	ft_input_update(&window->input);
	return (0);
}

void	ft_window_handlers_setup(t_window *window)
{
	mlx_loop_hook(window->mlx_context, ft_window_loop_adaptator, window);
	mlx_hook(window->mlx_window,
		DestroyNotify, NoEventMask, ft_window_cross_handler, window);
	mlx_hook(window->mlx_window,
		ButtonPress, ButtonPressMask,
		ft_mouse_press_adaptator, window);
	mlx_hook(window->mlx_window,
		ButtonRelease, ButtonReleaseMask,
		ft_mouse_release_adaptator, window);
	mlx_hook(window->mlx_window,
		MotionNotify, PointerMotionMask,
		&ft_mouse_move_adaptator, window);
	mlx_hook(window->mlx_window,
		KeyPress, KeyPressMask, ft_key_press_adaptator, window);
	mlx_hook(window->mlx_window,
		KeyRelease, KeyReleaseMask, ft_key_release_adaptator, window);
}
