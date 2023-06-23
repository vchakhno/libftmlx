/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:48:19 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 08:30:16 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/libftmlx.h"
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
	if (!ft_image_alloc(&window->back_buffer, width, height))
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
	ft_mouse_init(&window->input.mouse);
	ft_mouse_attach_handlers(&window->input.mouse);
	mlx_hook(window->mlx_window,
		KeyPress, KeyPressMask, &ft_key_pressed_handler, window);
	mlx_hook(window->mlx_window,
		KeyRelease, KeyReleaseMask, &ft_key_released_handler, window);
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
	ft_image_free(&window->back_buffer);
	mlx_destroy_display(window->mlx_context);
	free(window->mlx_context);
}

void	ft_window_render_backbuffer(t_window *window)
{
	mlx_put_image_to_window(
		window->mlx_context, window->mlx_window,
		window->back_buffer.mlx_image, 0, 0);
}
