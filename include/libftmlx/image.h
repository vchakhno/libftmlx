/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 05:52:38 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 14:06:48 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include "libftmlx/image.h"
# undef IMAGE_H
#else
# ifndef LIBFTMLX_IMAGE_H
#  define LIBFTMLX_IMAGE_H

#  include <libft/arithmetic/fixed_types.h>
#  include "libftmlx/color.h"
#  include "libftmlx/math.h"
#  include <stdbool.h>

typedef struct s_image
{
	t_u32	width;
	t_u32	height;
	void	*mlx_image;
	t_color	*pixels;
}	t_image;

// image.c
bool			ft_image_alloc(t_image *image, t_u32 width, t_u32 height);
bool			ft_image_alloc_from_xpm(t_image *image, char *filename);
t_color			*ft_image_get_pixel(t_image *image, t_u32 x, t_u32 y);
void			ft_image_free(t_image *image);

// manip/*.c
void			ft_image_draw_pixel(
					t_image *image, t_u32 x, t_u32 y, t_color color);
void			ft_image_draw_pixel__unchecked(
					t_image *image, t_u32 x, t_u32 y, t_color color);
void			ft_image_copy_image(
					t_image *dst, t_drect dst_rect,
					t_image *src, t_drect src_rect);
void			ft_image_copy_image__unchecked(
					t_image *dst, t_drect dst_rect,
					t_image *src, t_drect src_rect);
void			ft_image_replace_image(
					t_image *dst, t_drect dst_rect,
					t_image *src, t_drect src_rect);
void			ft_image_replace_image__unchecked(
					t_image *dst, t_drect dst_rect,
					t_image *src, t_drect src_rect);
void			ft_image_clear(t_image *image, t_color color);
void			ft_image_cover(t_image *image, t_color color);

// TODO
void			ft_image_draw_line(
					t_image *image, t_line line, t_color color);
void			ft_image_fill_rect(
					t_image *image, t_rect rect, t_color color);
void			ft_image_draw_rect(
					t_image *image, t_rect rect, t_color color);
void			ft_image_fill_triangle(
					t_image *image, t_triangle triangle, t_color color);
void			ft_image_draw_triangle(
					t_image *image, t_triangle triangle, t_color color);
void			ft_image_fill_circle(
					t_image *image, t_circle circle, t_color color);
void			ft_image_draw_circle(
					t_image *image, t_circle circle, t_color color);

/******************************************************************************/
/* 	IMAGE CONTEXT															  */
/******************************************************************************/

typedef struct s_image_context
{
	void	*mlx_context;
	t_u32	image_count;
}	t_image_context;

t_image_context	*ft_image_context(void);
bool			ft_image_context_increment(void **mlx_context);
void			ft_image_context_decrement(void);

# endif
#endif