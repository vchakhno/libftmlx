/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:55:56 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/14 21:11:10 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxft/mlxft.h"
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>

void	ft_window_loop_hook(
	t_window *window, void (*loop_callback), void *loop_data
) {
	window->loop_callback = loop_callback;
	window->loop_data = loop_data;
}

void	ft_window_key_hook(
	t_window *window,
	void (*on_key_press), void (*on_key_release), void *key_data
) {
	window->on_key_press = on_key_press;
	window->on_key_release = on_key_release;
	window->key_data = key_data;
}

void	ft_window_mouse_button_hook(
	t_window *window,
	void (*on_mouse_button_press), void (*on_mouse_button_release),
	void *mouse_button_data
) {
	window->on_mouse_button_press = on_mouse_button_press;
	window->on_mouse_button_release = on_mouse_button_release;
	window->mouse_button_data = mouse_button_data;
}

void	ft_window_mouse_move_hook(
	t_window *window, void (*on_mouse_move), void *mouse_move_data
) {
	window->on_mouse_move = on_mouse_move;
	window->mouse_move_data = mouse_move_data;
}
