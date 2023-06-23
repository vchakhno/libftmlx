/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:55:56 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 05:55:09 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/libftmlx.h"
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>

int	ft_window_loop(t_window *window)
{
	if (!window->open)
	{
		mlx_destroy_window(window->mlx_context, window->mlx_window);
		mlx_loop_end(window->mlx_context);
		return (0);
	}
	if (window->loop_callback)
		window->loop_callback(window, window->loop_data);
	ft_input_update(&window->input);
	return (0);
}

int	ft_window_cross_clicked(t_window *window)
{
	ft_window_close(window);
	return (0);
}

int	ft_key_pressed_handler(int key, t_window *window)
{
	if (window->on_key_press)
		window->on_key_press(window, key, window->key_data);
	return (0);
}

int	ft_key_released_handler(int key, t_window *window)
{
	if (window->on_key_release)
		window->on_key_release(window, key, window->key_data);
	return (0);
}
