/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 06:09:51 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 05:55:09 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/libftmlx.h"
#include <mlx.h>
#include <X11/X.h>
#include <stddef.h>

void	ft_mouse_attach_handlers(t_mouse *mouse)
{
	t_window	*window;

	window = (void *)mouse \
			- ((ptrdiff_t) &((t_window *)0)->input.mouse);
	mlx_hook(window->mlx_window,
		ButtonPress, ButtonPressMask,
		&ft_mouse_press_handler, mouse);
	mlx_hook(window->mlx_window,
		ButtonRelease, ButtonReleaseMask,
		&ft_mouse_release_handler, mouse);
	mlx_hook(window->mlx_window,
		MotionNotify, PointerMotionMask,
		&ft_mouse_move_handler, mouse);
}

int	ft_mouse_press_handler(int button, int x, int y, t_mouse *mouse)
{
	t_window	*window;

	window = (void *)mouse \
			- ((ptrdiff_t) &((t_window *)0)->input.mouse);
	if (button <= 3)
	{
		mouse->buttons[button - 1] = true;
		mouse->drag_start_positions[button - 1] = (t_point){x, y};
	}
	else if (button == 4)
		mouse->scroll++;
	else if (button == 5)
		mouse->scroll--;
	if (window->on_mouse_button_press)
		window->on_mouse_button_press(window,
			button, window->mouse_button_data);
	return (0);
}

int	ft_mouse_release_handler(int button, int x, int y, t_mouse *mouse)
{
	t_window	*window;

	(void) x;
	(void) y;
	window = (void *)mouse \
			- ((ptrdiff_t) &((t_window *)0)->input.mouse);
	mouse->buttons[button - 1] = false;
	if (window->on_mouse_button_release)
		window->on_mouse_button_release(window,
			button, window->mouse_button_data);
	return (0);
}

int	ft_mouse_move_handler(int x, int y, t_mouse *mouse)
{
	t_window	*window;

	window = (void *)mouse \
			- ((ptrdiff_t) &((t_window *)0)->input.mouse);
	mouse->pos.x = x;
	mouse->pos.y = y;
	if (window->on_mouse_move)
		window->on_mouse_move(window,
			x, y, window->mouse_button_data);
	return (0);
}
