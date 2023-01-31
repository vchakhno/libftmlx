/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:48:19 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 11:52:19 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxft/mlxft.h"
#include <mlx.h>

bool	ft_window_alloc(t_window *window, int width, int height, char *title)
{
	if (!ft_mlx_context_add_window())
		return (false);
	window->mlx_window = mlx_new_window(ft_mlx_context_get(),
			width, height, title);
	if (!window->mlx_window)
	{
		ft_mlx_context_remove_window();
		return (false);
	}
	if (!ft_renderer_alloc(&window->renderer,
			window->mlx_window, width, height))
	{
		mlx_destroy_window(ft_mlx_context_get(), window->mlx_window);
		ft_mlx_context_remove_window();
		return (false);
	}
	ft_window_init(window);
	return (true);
}

void	ft_window_init(t_window *window)
{
	ft_window_attach_handlers(window);
	ft_input_init(&window->input, window->mlx_window);
}

void	ft_window_loop(t_window *window,
	bool (*tick)(), bool (*render)(), void *user_data)
{
	void *const				context = ft_mlx_context_get();
	t_window_loop_callback	lambda;

	lambda.tick = tick;
	lambda.render = render;
	lambda.window = window;
	lambda.user_data = user_data;
	mlx_loop_hook(context, ft_window_loop_handler, &lambda);
	mlx_loop(context);
}

void	ft_window_free(t_window *window)
{
	ft_renderer_free(&window->renderer);
	mlx_destroy_window(ft_mlx_context_get(), window->mlx_window);
	ft_mlx_context_remove_window();
}
