/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:48:19 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/22 16:07:15 by vchakhno         ###   ########.fr       */
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
	if (!ft_image_alloc(&window->back_buffer, width, height))
		return (false);
	window->title = title;
	window->open = false;
	ft_window_handlers_init(&window->handlers);
	return (true);
}

bool	ft_window_open(t_window *window)
{
	window->mlx_context = mlx_init();
	if (!window->mlx_context)
		return (false);
	window->mlx_window = mlx_new_window(window->mlx_context,
			window->width, window->height, window->title);
	if (!window->mlx_window)
	{
		mlx_destroy_display(window->mlx_context);
		free(window->mlx_context);
		return (false);
	}
	ft_mouse_init(&window->input.mouse);
	window->open = true;
	ft_window_handlers_setup(window);
	ft_window_render_backbuffer(window);
	mlx_loop(window->mlx_context);
	mlx_destroy_window(window->mlx_context, window->mlx_window);
	mlx_destroy_display(window->mlx_context);
	free(window->mlx_context);
	return (true);
}

void	ft_window_close(t_window *window)
{
	window->open = false;
	mlx_loop_end(window->mlx_context);
}

void	ft_window_free(t_window *window)
{
	ft_image_free(&window->back_buffer);
}

void	ft_window_render_backbuffer(t_window *window)
{
	if (window->open)
		mlx_put_image_to_window(
			window->mlx_context, window->mlx_window,
			window->back_buffer.mlx_image, 0, 0);
}
