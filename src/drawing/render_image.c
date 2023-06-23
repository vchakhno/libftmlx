/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:43:43 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 05:55:09 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/libftmlx.h"
#include "libftmlx/math.h"
#include <math.h>
#include <stdio.h>

bool	ft_rect_overlap(t_drect a, t_drect b, t_drect *dest)
{
	*dest = (t_drect){
		fmax(a.x, b.x),
		fmax(a.y, b.y),
		fmin(a.x + a.w, b.x + b.w) - fmax(a.x, b.x),
		fmin(a.y + a.h, b.y + b.h) - fmax(a.y, b.y),
	};
	return (dest->w >= 0 && dest->h >= 0);
}

t_drect	ft_rect_divide(t_drect a, t_drect b)
{
	return ((t_drect){
		(a.x - b.x) / b.w,
		(a.y - b.y) / b.h,
		a.w / b.w,
		a.h / b.h,
	});
}

t_drect	ft_rect_multiply(t_drect a, t_drect b)
{
	return ((t_drect){
		a.x * b.w + b.x,
		a.y * b.h + b.y,
		a.w * b.w,
		a.h * b.h,
	});
}

void	ft_render_image(
	t_renderer *renderer, t_drect dst_rect,
	t_img *img, t_drect src_rect
) {
	t_drect	dst_overlap;
	t_drect	src_overlap;
	t_drect	total_normalized;

	ft_rect_overlap((t_drect){
		0, 0, renderer->width, renderer->height
	}, dst_rect, &dst_overlap);
	ft_rect_overlap((t_drect){
		0, 0, img->width, img->height
	}, src_rect, &src_overlap);
	ft_rect_overlap(
		ft_rect_divide(dst_overlap, dst_rect),
		ft_rect_divide(src_overlap, src_rect),
		&total_normalized);
	ft_render_image__unchecked(
		renderer, ft_rect_multiply(total_normalized, dst_rect),
		img, ft_rect_multiply(total_normalized, src_rect));
}

void	ft_render_image__unchecked(
	t_renderer *renderer, t_drect dst_rect,
	t_img *img, t_drect src_rect
) {
	int		i;
	int		j;
	t_color	pixel_color;
	t_point	src_pos;

	i = 0;
	while (i < (int) dst_rect.h)
	{
		src_pos.y = (double) i / dst_rect.h
			* src_rect.h + src_rect.y;
		j = 0;
		while (j < (int) dst_rect.w)
		{
			src_pos.x = (double) j / dst_rect.w
				* src_rect.w + src_rect.x;
			pixel_color = *ft_image_get_pixel(img, src_pos);
			*ft_image_get_pixel(&renderer->back_buffer,
				(t_point){j + (int) dst_rect.x, i + (int) dst_rect.y}
				) = pixel_color;
			j++;
		}
		i++;
	}
}