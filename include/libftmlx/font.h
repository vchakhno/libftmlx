/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 08:55:42 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/27 17:34:19 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONT_H
# define FONT_H
# include "libftmlx/font.h"
# undef FONT_H
#else
# ifndef LIBFTMLX_FONT_H
#  define LIBFTMLX_FONT_H

#  include <stdbool.h>
#  include <libft/arithmetic/fixed_types.h>
#  include <libft/data/str.h>
#  include "libftmlx/color.h"
#  include "libftmlx/image.h"

typedef struct s_font
{
	t_u8	*alpha;
	t_u32	size;
	t_u32	letter_w;
	t_u32	letter_h;
}	t_font;

bool		ft_font_alloc(t_font *font, char *filename);
t_u8		ft_font_get_alpha__unchecked(t_font *font, char c,
				t_u32 x, t_u32 y);
t_u8		ft_font_get_alpha(t_font *font, char c, t_u32 x, t_u32 y);
void		ft_font_free(t_font *font);

typedef struct s_paragraph
{
	t_str	message;
	t_font	font;
	t_u32	dst_letter_w;
	t_u32	dst_letter_h;
	t_color	color;
}	t_paragraph;

t_paragraph	ft_paragraph_from(t_str message, t_font font,
				t_u32 font_size, t_color color);
void		ft_paragraph_render(t_paragraph paragraph, t_image *image,
				t_point point);

# endif
#endif