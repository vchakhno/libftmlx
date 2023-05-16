/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:58:42 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/14 21:48:10 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxft/mlxft.h>
#include <stdio.h>
#include <X11/keysym.h>
#include <mlx.h>

typedef struct s_app
{
	t_img	image;
	float	offx;
	float	offy;
}	t_app;

bool	app_alloc(t_app *app)
{
	if (!ft_image_alloc_from_xpm(&app->image, "assets/katana_zero.xpm"))
		return (false);
	app->offx = 0;
	app->offy = 0;
	return (true);
}

void	app_free(t_app *app)
{
	ft_image_free(&app->image);
}

void	loop(t_window *window, t_app *app)
{
	mlx_do_sync(window->mlx_context);
	ft_renderer_clear(&window->renderer, (t_color) 0);
	ft_render_image(
		&window->renderer, (t_drect){app->offx, app->offy,
		window->width, window->height},
		&app->image, (t_drect){0, 0, app->image.width, app->image.height});
	ft_renderer_display(&window->renderer);
	mlx_do_sync(window->mlx_context);
}

void	keys(t_window *window, int key, t_app *app)
{
	(void) window;
	if (key == XK_Up)
	{
		app->offy -= 10;
	}
	else if (key == XK_Down)
	{
		app->offy += 10;
	}
	else if (key == XK_Left)
	{
		app->offx -= 10;
	}
	else if (key == XK_Right)
	{
		app->offx += 10;
	}
	else if (key == XK_Escape)
	{
		ft_window_close(window);
	}
}

int	main(void)
{
	t_app		app;
	t_window	window;

	setbuf(stdout, NULL);
	if (!ft_window_alloc(&window, 800, 600, "Test window"))
		return (1);
	if (!app_alloc(&app))
	{
		ft_window_free(&window);
		return (1);
	}
	ft_window_loop_hook(&window, loop, &app);
	ft_window_key_hook(&window, keys, NULL, &app);
	if (!ft_window_open(&window))
	{
		app_free(&app);
		ft_window_free(&window);
		return (1);
	}
	app_free(&app);
	ft_window_free(&window);
	return (0);
}
