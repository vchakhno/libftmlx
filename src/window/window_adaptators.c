/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_adaptators.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:55:56 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 15:48:56 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/libftmlx.h"
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>

int	ft_mouse_press_adaptator(
	int button, int x, int y, t_window *window
) {
	t_mouse	*mouse;

	mouse = &window->input.mouse;
	if (button <= 3)
	{
		mouse->buttons[button - 1] = true;
		mouse->drag_start_positions[button - 1] = (t_point){x, y};
	}
	else if (button == 4)
		mouse->scroll++;
	else if (button == 5)
		mouse->scroll--;
	if (window->handlers.mouse_button_press_handler)
		window->handlers.mouse_button_press_handler(window,
			button, window->handlers.mouse_button_handlers_data);
	return (0);
}

int	ft_mouse_release_adaptator(int button, int x, int y, t_window *window)
{
	(void) x;
	(void) y;
	window->input.mouse.buttons[button - 1] = false;
	if (window->handlers.mouse_button_release_handler)
		window->handlers.mouse_button_release_handler(window,
			button, window->handlers.mouse_button_handlers_data);
	return (0);
}

int	ft_mouse_move_adaptator(int x, int y, t_window *window)
{
	window->input.mouse.pos.x = x;
	window->input.mouse.pos.y = y;
	if (window->handlers.mouse_move_handler)
		window->handlers.mouse_move_handler(window,
			x, y, window->handlers.mouse_move_handler_data);
	return (0);
}

int	ft_key_press_adaptator(int key, t_window *window)
{
	if (window->handlers.key_press_handler)
		window->handlers.key_press_handler(
			window, key, window->handlers.key_handlers_data);
	return (0);
}

int	ft_key_release_adaptator(int key, t_window *window)
{
	if (window->handlers.key_release_handler)
		window->handlers.key_release_handler(
			window, key, window->handlers.key_handlers_data);
	return (0);
}
