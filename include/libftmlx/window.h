/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:54:50 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 15:48:45 by vchakhno         ###   ########.fr       */
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
	Loop handler
		(t_window *window, void *data)
		
	Mouse move handler
		(t_window *window, int mouse_x, int mouse_y, void *data)
		Note:
			you can get the new mouse pos from window->input
			so I'm not certain whether to include it

	Mouse button press handler:
		(t_window *window, int button, void *data)
		
	Mouse button release handler:
		(t_window *window, int button, void *data)

	Key press handler
		(t_window *window, int key, void *data)
	
	Key release handler
		(t_window *window, int key, void *data)

	The prototypes are hidden in this way so that the void *data coerces without
	warning into any type, which is a bit more comfortable to use (no cast).
*/

typedef struct s_window_handlers
{
	void	(*loop_handler)();
	void	*loop_handler_data;
	void	(*mouse_move_handler)();
	void	*mouse_move_handler_data;
	void	(*mouse_button_press_handler)();
	void	(*mouse_button_release_handler)();
	void	*mouse_button_handlers_data;
	void	(*key_press_handler)();
	void	(*key_release_handler)();
	void	*key_handlers_data;
}	t_window_handlers;

typedef struct s_window
{
	void				*mlx_context;
	void				*mlx_window;
	char				*title;
	bool				open;
	t_input				input;
	union {
		t_image			back_buffer;
		struct {
			t_u32		width;
			t_u32		height;
		};
	};
	t_window_handlers	handlers;
}	t_window;

// window.c
bool	ft_window_alloc(t_window *window,
			t_u32 width, t_u32 height, char *title);
bool	ft_window_open(t_window *window);
void	ft_window_close(t_window *window);
void	ft_window_free(t_window *window);

void	ft_window_render_backbuffer(t_window *window);

// window_adaptators.c
int		ft_mouse_press_adaptator(int button, int x, int y, t_window *window);
int		ft_mouse_release_adaptator(int button, int x, int y, t_window *window);
int		ft_mouse_move_adaptator(int x, int y, t_window *window);
int		ft_key_press_adaptator(int key, t_window *window);
int		ft_key_release_adaptator(int key, t_window *window);

// window_handlers.c
void	ft_window_handlers_init(t_window_handlers *window_handlers);
int		ft_window_cross_handler(t_window *window);
int		ft_window_loop_adaptator(t_window *window);
void	ft_window_handlers_setup(t_window *window);

// window_hooks.c
void	ft_window_loop_hook(t_window *window,
			void *loop_handler, void *loop_handler_data);
void	ft_window_key_hook(t_window *window,
			void *key_press_handler, void *key_release_handler,
			void *key_handlers_data);
void	ft_window_mouse_button_hook(t_window *window,
			void *mouse_button_press_handler,
			void *mouse_button_release_handler,
			void *mouse_button_handlers_data);
void	ft_window_mouse_move_hook(t_window *window,
			void *mouse_move_handler, void *mouse_move_handler_data);

# endif
#endif