/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:47:19 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/31 21:26:54 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxft/mlxft.h"
#include <stdio.h>

typedef struct s_app
{
	bool	once_hold;
	t_line	line;
}	t_app;

bool	tick(t_app *app, t_input *input)
{
	if (ft_mouse_button_down(&input->mouse, FT_MOUSE_LEFT))
	{
		if (!app->once_hold)
			app->once_hold = true;
		app->line = (t_line){
			input->mouse.pos,
			input->mouse.drag_start_positions[FT_MOUSE_LEFT]
		};
	}
	return (true);
}

bool	render(t_app *app, t_renderer *renderer)
{
	ft_renderer_clear(renderer, (t_color) 0);
	if (app->once_hold)
	{
		ft_fill_circle(renderer,
			(t_circle){app->line.start.x, app->line.start.y, 10},
			(t_color) 0x303030, 1);
		ft_fill_circle(renderer,
			(t_circle){app->line.end.x, app->line.end.y, 10},
			(t_color) 0x303030, 1);
		ft_draw_solid_line(renderer,
			app->line, (t_color) 0xFFFFFF);
		ft_draw_solid_point(renderer,
			(t_point){app->line.start.x, app->line.start.y},
			(t_color) 0xFF0000);
		ft_draw_solid_point(renderer,
			(t_point){app->line.end.x, app->line.end.y}, (t_color) 0xFF0000);
	}
	ft_renderer_display(renderer);
	return (true);
}

int	main(void)
{
	t_window	window;

	if (!ft_window_alloc(&window, 1200, 800, "Hello Window"))
		return (1);
	ft_window_loop(&window, tick, render, &(t_app){0});
	ft_window_free(&window);
}
