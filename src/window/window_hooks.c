/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:55:56 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 17:47:41 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/libftmlx.h"
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>

void	ft_window_loop_hook(
	t_window *window, void (*loop_handler)(), void *loop_handler_data
) {
	window->handlers.loop_handler = loop_handler;
	window->handlers.loop_handler_data = loop_handler_data;
}

void	ft_window_key_hook(
	t_window *window,
	void (*key_press_handler)(), void (*key_release_handler)(),
	void *key_handlers_data
) {
	window->handlers.key_press_handler = key_press_handler;
	window->handlers.key_release_handler = key_release_handler;
	window->handlers.key_handlers_data = key_handlers_data;
}

void	ft_window_mouse_button_hook(
	t_window *window,
	void (*mouse_button_press_handler)(),
	void (*mouse_button_release_handler)(),
	void *mouse_button_handlers_data
) {
	window->handlers.mouse_button_press_handler = mouse_button_press_handler;
	window->handlers.mouse_button_release_handler = \
		mouse_button_release_handler;
	window->handlers.mouse_button_handlers_data = mouse_button_handlers_data;
}

void	ft_window_mouse_move_hook(
	t_window *window,
	void (*mouse_move_handler)(), void *mouse_move_handler_data
) {
	window->handlers.mouse_move_handler = mouse_move_handler;
	window->handlers.mouse_move_handler_data = mouse_move_handler_data;
}
