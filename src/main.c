/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 05:33:55 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 06:55:59 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <complex.h>

typedef struct s_app
{
	int		slider_offset;
	t_point	color_pos;
}	t_app;

void	ft_app_init(t_app *app)
{
	app->color_pos = (t_point){0};
	app->slider_offset = 0;
}

static int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	ft_clamp(int floor, int val, int ceil)
{
	return (ft_min(ft_max(floor, val), ceil));
}

bool	tick(t_app *app, t_input *input)
{
	t_rect	color_bar;

	color_bar = (t_rect){525, 25, 50, 450};
	if (ft_mouse_button_down(&input->mouse, FT_MOUSE_LEFT)
		&& ft_rect_contains_point(color_bar,
			input->mouse.drag_start_positions[FT_MOUSE_LEFT]))
		app->slider_offset = ft_clamp(25, input->mouse.pos.y, 475) - 25;
	return (true);
}

void	ft_render_color_plan(t_app *app, t_renderer *renderer)
{
	int		i;
	int		j;
	float	hue;

	hue = app->slider_offset / 450.f;
	i = 0;
	while (i < 500)
	{
		j = 0;
		while (j < 500)
		{
			ft_renderer_draw_solid_point(renderer, (t_point){j, i},
				ft_color_from_float_hsv(hue, j / 500.f, 1 - (i / 500.f)));
			j++;
		}
		i++;
	}
}

void	ft_render_color_bar(t_app *app, t_renderer *renderer)
{
	int	i;
	int	j;

	(void) app;
	i = 0;
	while (i < 450)
	{
		j = 0;
		while (j < 50)
		{
			ft_renderer_draw_solid_point(renderer, (t_point){525 + j, 25 + i},
				ft_color_from_float_hsv(i / 450.f, 1, 1));
			j++;
		}
		i++;
	}
}

static int ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	ft_render_slider(t_app *app, t_renderer *renderer)
{
	int	i;
	int	j;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 10 - ft_abs(i - 10))
		{
			ft_renderer_draw_solid_point(renderer, (t_point){
				522 + j, i + app->slider_offset + 15},
				(t_color)(0xFFFFFF * (j < 7 - ft_abs(i - 10))));
			ft_renderer_draw_solid_point(renderer, (t_point){
				578 - j, i + app->slider_offset + 15},
				(t_color)(0xFFFFFF * (j < 7 - ft_abs(i - 10))));
			j++;
		}
		i++;
	}
}

bool	render(t_app *app, t_renderer *renderer)
{
	ft_renderer_clear(renderer, (t_color) 0);
	ft_render_color_plan(app, renderer);
	ft_render_color_bar(app, renderer);
	ft_render_slider(app, renderer);
	ft_renderer_display(renderer);
	return (true);
}

int	main(void)
{
	t_window	window;
	t_app		app;

	if (!ft_window_alloc(&window, 600, 500, "Color picker"))
		return (1);
	ft_app_init(&app);
	ft_window_loop(&window, tick, render, &app);
	ft_window_free(&window);
}
