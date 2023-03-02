/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:54:50 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/02 06:34:09 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXFT_H
# define MLXFT_H

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

# define EDGE 1.f

// ft_renderer.c
bool			ft_renderer_alloc(t_renderer *renderer,
					void *mlx_window, int width, int height);
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

// ft_fill.c
void			ft_fill_rect(t_renderer *renderer,
					t_rect rect, t_color color, float opacity);
void			ft_fill_circle(t_renderer *renderer,
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