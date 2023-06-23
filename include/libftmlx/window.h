/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:54:50 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 08:16:55 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# include "libftmlx/window.h"
# undef WINDOW_H
#else
# ifndef LIBFTMLX_WINDOW_H
#  define LIBFTMLX_WINDOW_H

#  include <libft/arithmetic/fixed_types.h>
#  include "libftmlx/image.h"
#  include "libftmlx/input.h"
#  include <stdbool.h>

/*
	Loop callback
		(t_window *window, void *data)
		
	Key press callback
		(t_window *window, int key, void *data)
	
	Key release callback
		(t_window *window, int key, void *data)

	Mouse move callback
		(t_window *window, int mouse_x, int mouse_y, void *data)
		Note:
			you can get the new mouse pos from window->input
			so I'm not certain whether to include it

	Mouse button press:
		(t_window *window, int button, void *data)
		
	Mouse button release:
		(t_window *window, int button, void *data)

	The prototypes are hidden in this way so that the void *data coerces without
	warning into any type, which is a bit more comfortable to use (no cast).
*/

typedef struct s_window
{
	void			*mlx_context;
	void			*mlx_window;
	char			*title;
	bool			open;
	t_input			input;
	union {
		t_image		back_buffer;
		struct {
			t_u32	width;
			t_u32	height;
		};
	};
	void			(*loop_callback)();
	void			*loop_data;
	void			(*on_key_press)();
	void			(*on_key_release)();
	void			*key_data;
	void			(*on_mouse_move)();
	void			*mouse_move_data;
	void			(*on_mouse_button_press)();
	void			(*on_mouse_button_release)();
	void			*mouse_button_data;
}	t_window;

// ft_window.c
bool			ft_window_alloc(t_window *window,
					t_u32 width, t_u32 height, char *title);
bool			ft_window_open(t_window *window);
void			ft_window_close(t_window *window);
void			ft_window_free(t_window *window);

void			ft_window_render_backbuffer(t_window *window);

// ft_window_handlers.c
int				ft_window_loop(t_window *window);
int				ft_window_cross_clicked(t_window *window);
int				ft_key_pressed_handler(int key, t_window *window);
int				ft_key_released_handler(int key, t_window *window);

// ft_window_hooks.c
void			ft_window_loop_hook(t_window *window,
					void (*loop_callback), void *loop_data);
void			ft_window_key_hook(t_window *window,
					void (*on_key_press), void (*on_key_release),
					void *key_data);
void			ft_window_mouse_button_hook(t_window *window,
					void (*on_mouse_button_press),
					void (*on_mouse_button_release),
					void *mouse_button_data);
void			ft_window_mouse_move_hook(t_window *window,
					void (*on_mouse_move), void *mouse_move_data);

# endif
#endif