/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paragraph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 05:52:49 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/25 09:02:40 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/font.h"

t_paragraph	ft_paragraph_from(
	char *message, t_font font, t_u32 font_size, t_color color
) {
	return ((t_paragraph){
		.message = message,
		.font = font,
		.dst_letter_w = font_size * font.letter_w / font.size,
		.dst_letter_h = font_size * font.letter_h / font.size,
		.color = color,
	});
}

// Could be optimized with rect_overlap and draw_pixel_unchecked
void	ft_paragraph_render_letter(
	t_paragraph paragraph, t_image *image, t_point point, char c
) {
	t_color	color;
	t_u32	i;
	t_u32	j;

	i = 0;
	while (i < paragraph.dst_letter_h)
	{
		j = 0;
		while (j < paragraph.dst_letter_w)
		{
			color = paragraph.color;
			color.a *= (t_f32)ft_font_get_alpha(&paragraph.font, c,
					j * paragraph.font.letter_w / paragraph.dst_letter_w,
					i * paragraph.font.letter_h / paragraph.dst_letter_h) / 255;
			ft_image_draw_pixel(image,
				point.x + j, point.y - paragraph.dst_letter_h + i, color);
			j++;
		}
		i++;
	}
}

// Only supports one line paragraphs... for now
void	ft_paragraph_render(
	t_paragraph paragraph, t_image *image, t_point point
) {
	t_u32	i;

	i = 0;
	while (paragraph.message[i]
		&& point.x + i * paragraph.dst_letter_w < image->width)
	{
		ft_paragraph_render_letter(paragraph, image,
			(t_point){.x = point.x + i * paragraph.dst_letter_w, .y = point.y},
			paragraph.message[i]);
		i++;
	}
}
