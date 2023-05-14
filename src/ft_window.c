/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:48:19 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/14 20:36:27 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxft/mlxft.h"
#include <mlx.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>

bool	ft_window_alloc(
	t_window *window, t_u32 width, t_u32 height, char *title
) {
	window->mlx_context = mlx_init();
	if (!window->mlx_context)
		return (false);
	if (!ft_renderer_alloc(&window->renderer, width, height))
	{
		mlx_destroy_display(window->mlx_context);
		free(window->mlx_context);
		return (false);
	}
	window->title = title;
	window->open = false;
	window->loop_callback = NULL;
	window->on_key_press = NULL;
	window->on_key_release = NULL;
	window->on_mouse_button_press = NULL;
	window->on_mouse_button_release = NULL;
	window->on_mouse_move = NULL;
	return (true);
}

bool	ft_window_open(t_window *window)
{
	window->mlx_window = mlx_new_window(window->mlx_context,
			window->width, window->height, window->title);
	if (!window->mlx_window)
		return (false);
	mlx_hook(window->mlx_window,
		DestroyNotify, NoEventMask, &ft_window_cross_clicked, window);
	mlx_loop_hook(window->mlx_context, ft_window_loop, window);
	window->open = true;
	mlx_loop(window->mlx_context);
	return (true);
}

void	ft_window_close(t_window *window)
{
	window->open = false;
}

void	ft_window_free(t_window *window)
{
	ft_renderer_free(&window->renderer);
	mlx_destroy_display(window->mlx_context);
	free(window->mlx_context);
}
