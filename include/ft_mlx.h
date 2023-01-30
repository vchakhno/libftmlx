/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:54:50 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 04:45:21 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# include "ft_math.h"
# include "ft_color.h"
# include <stdbool.h>
# include <time.h>

typedef struct s_window	t_window;

/******************************************************************************/
/* INPUT																	  */
/******************************************************************************/

typedef enum e_button_id {
	FT_MOUSE_LEFT = 0,
	FT_MOUSE_MIDDLE = 2,
	FT_MOUSE_RIGHT = 1
}	t_button_id;

typedef struct s_mouse
{
	t_point	pos;
	t_point	previous_pos;
	bool	buttons[3];
	bool	previous_buttons[3];
	t_point	drag_start_positions[3];
	int		scroll;
}	t_mouse;

// ft_mouse.c
void			ft_mouse_init(t_mouse *mouse, void *mlx_window);
void			ft_mouse_update(t_mouse *mouse);
bool			ft_mouse_moved(t_mouse *mouse);

// ft_mouse_buttons.c
bool			ft_mouse_button_down(t_mouse *mouse, t_button_id button);
bool			ft_mouse_button_pressed(t_mouse *mouse, t_button_id button);
bool			ft_mouse_button_released(t_mouse *mouse, t_button_id button);
bool			ft_mouse_zone_clicked(t_mouse *mouse,
					t_rect rect, t_button_id button);

// ft_mouse_handlers.c
void			ft_mouse_attach_handlers(t_mouse *mouse, void *mlx_window);
int				ft_mouse_press_handler(
					int button, int x, int y, t_mouse *mouse);
int				ft_mouse_release_handler(
					int button, int x, int y, t_mouse *mouse);
int				ft_mouse_move_handler(int x, int y, t_mouse *mouse);

typedef struct s_input
{
	t_mouse	mouse;
}	t_input;

// ft_input.c
void			ft_input_init(t_input *input, void *mlx_window);
void			ft_input_update(t_input *input);

/******************************************************************************/
/* 	OUTPUT																	  */
/******************************************************************************/

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

// ft_image.c
bool			ft_image_alloc(t_img *img, int width, int height);
t_color			*ft_image_get_pixel(t_img *img, t_point pos);
void			ft_image_free(t_img *img);

typedef struct s_renderer
{
	void	*mlx_window;
	int		width;
	int		height;
	t_img	back_buffer;
}	t_renderer;

// ft_renderer.c
bool			ft_renderer_alloc(t_renderer *renderer,
					void *mlx_window, int width, int height);
void			ft_renderer_free(t_renderer *renderer);
void			ft_renderer_display(t_renderer *renderer);

// ft_renderer_draw.c
void			ft_renderer_draw_solid_point(t_renderer *renderer,
					t_point point, t_color color);
void			ft_renderer_draw_opaque_point(t_renderer *renderer,
					t_point point, t_color color, float opacity);

// ft_renderer_fill.c
void			ft_renderer_fill_rect(t_renderer *renderer,
					t_rect rect, t_color color, float opacity);
void			ft_renderer_fill_circle(t_renderer *renderer,
					t_circle circle, t_color color, float opacity);
void			ft_renderer_clear(t_renderer *renderer, t_color color);

/******************************************************************************/
/* 	WINDOW																	  */
/******************************************************************************/

typedef struct s_window_loop_callback
{
	bool		(*tick)();
	bool		(*render)();
	t_window	*window;
	void		*user_data;
}	t_window_loop_callback;

typedef struct s_window
{
	void		*mlx_window;
	t_input		input;
	t_renderer	renderer;
}	t_window;

// ft_window.c
bool			ft_window_alloc(t_window *window,
					int width, int height, char *title);
void			ft_window_init(t_window *window);
void			ft_window_loop(t_window *window,
					bool (*tick)(), bool (*render)(), void *user_data);
void			ft_window_free(t_window *window);

// ft_window_handlers.c
void			ft_window_attach_handlers(t_window *window);
int				ft_window_keypress_handler(int keysym, void *context);
int				ft_window_loop_handler(t_window_loop_callback *callback);
int				ft_window_quit_handler(void *context);

/******************************************************************************/
/* 	CONTEXT																	  */
/******************************************************************************/

// ft_context.c
bool			ft_mlx_context_add_window(void);
void			*ft_mlx_context_get(void);
void			ft_mlx_context_remove_window(void);

#endif