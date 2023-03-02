/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:47:19 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/27 05:44:03 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxft/mlxft.h"
#include <mlx.h>
#include <stdio.h>

typedef struct s_app
{

}	t_app;

bool	tick(t_app *app, t_input *input)
{
	(void) app;
	(void) input;
	return (true);
}

bool	render(t_app *app, t_renderer *renderer)
{
	(void) app;
	(void) renderer;
	ft_fill_rect(renderer, (t_rect){0, 0, 500, 60}, (t_color) 0x303030, 1);
	ft_renderer_display(renderer);
	mlx_string_put(ft_mlx_context_get(), renderer->mlx_window,
		0, 60, 0xFFFFFF, "Bonjour Ulysse");
	return (true);
}

int	main(void)
{
	t_window	window;

	if (!ft_window_alloc(&window, 1200, 800, "Text example"))
		return (1);
	mlx_set_font(ft_mlx_context_get(), window.mlx_window, "roboto");
	ft_window_loop(&window, tick, render, &(t_app){});
	ft_window_free(&window);
}
