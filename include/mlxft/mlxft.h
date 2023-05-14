/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:54:50 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/14 19:04:41 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXFT_H
# define MLXFT_H

# include <libft/fixed_types.h>
# include "math.h"
# include "color.h"
# include "input.h"
# include <stdbool.h>
# include <time.h>

typedef struct s_window	t_window;

/******************************************************************************/
/* 	OUTPUT																	  */
/******************************************************************************/

typedef struct s_img
{
	t_u32	width;
	t_u32	height;
	void	*mlx_img;
	char	*addr;
	t_u32	line_len;
}	t_img;

// ft_image.c
bool			ft_image_alloc(t_img *img,
					void *mlx_context, int width, int height);
bool			ft_image_alloc_from_xpm(t_img *img,
					void *mlx_context, char *filename);
t_color			*ft_image_get_pixel(t_img *img, t_point pos);
void			ft_image_free(t_img *img, void *mlx_context);

typedef struct s_renderer
{
	union {
		t_img	back_buffer;
		struct {
			t_u32	width;
			t_u32	height;
		};
	};
}	t_renderer;

# define EDGE 1.f

// ft_renderer.c
bool			ft_renderer_alloc(t_renderer *renderer,
					int width, int height);
void			ft_renderer_free(t_renderer *renderer);
void			ft_renderer_display(t_renderer *renderer);

// ft_draw.c
void			ft_draw_solid_point(t_renderer *renderer,
					t_point point, t_color color);
void			ft_draw_solid_point__unchecked(t_renderer *renderer,
					t_point point, t_color color);
void			ft_draw_opaque_point(t_renderer *renderer,
					t_point point, t_color color, float opacity);
void			ft_draw_opaque_point__unchecked(t_renderer *renderer,
					t_point point, t_color color, float opacity);
void			ft_draw_solid_line(t_renderer *renderer,
					t_line line, t_color color);
void			ft_render_image(
					t_renderer *renderer, t_drect dst_rect,
					t_img *img, t_drect src_rect);
void			ft_render_image__unchecked(
					t_renderer *renderer, t_drect dst_rect,
					t_img *img, t_drect src_rect);

// ft_fill.c
void			ft_fill_rect(t_renderer *renderer,
					t_rect rect, t_color color, float opacity);
void			ft_fill_circle(t_renderer *renderer,
					t_circle circle, t_color color, float opacity);
void			ft_renderer_clear(t_renderer *renderer, t_color color);

/******************************************************************************/
/* 	WINDOW																	  */
/******************************************************************************/

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
	warning into any type, which these a bit more comfortable to use (no cast).
*/

typedef struct s_window
{
	void			*mlx_context;
	void			*mlx_window;
	char			*title;
	bool			open;
	t_input			input;
	union {
		t_renderer	renderer;
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

// ft_window_handlers.c
int				ft_window_loop(t_window *window);
int				ft_window_cross_clicked(t_window *window);

#endif