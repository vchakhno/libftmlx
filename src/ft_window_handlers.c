/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:55:56 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/15 12:58:31 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>

void	ft_window_attach_handlers(t_window *window)
{
	void *const	context = ft_mlx_context_get();

	mlx_hook(window->mlx_window,
		DestroyNotify, NoEventMask, &ft_window_quit_handler, context);
	mlx_hook(window->mlx_window,
		KeyPress, KeyPressMask, &ft_window_keypress_handler, context);
}

int	ft_window_keypress_handler(int keysym, void *context)
{
	if (keysym == XK_Escape)
		mlx_loop_end(context);
	return (0);
}

int	ft_window_loop_handler(t_window_loop_callback *callback)
{
	void *const	context = ft_mlx_context_get();

	if ((
			callback->tick && !callback->tick(
				callback->user_data, &callback->window->input)
		) || (
			callback->render && !callback->render(
				callback->user_data, &callback->window->renderer)
		))
	{
		mlx_loop_end(context);
		return (0);
	}
	ft_input_update(&callback->window->input);
	return (0);
}

int	ft_window_quit_handler(void *context)
{
	mlx_loop_end(context);
	return (0);
}
