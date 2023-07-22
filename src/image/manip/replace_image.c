/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:43:43 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/22 14:10:39 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/libftmlx.h"
#include "libftmlx/math.h"
#include <math.h>
#include <stdio.h>

void	ft_image_replace_image(
	t_image *dst, t_drect dst_rect, t_image *src, t_drect src_rect
) {
	t_drect	dst_overlap;
	t_drect	src_overlap;
	t_drect	total_normalized;

	ft_rect_overlap((t_drect){
		0, 0, dst->width, dst->height
	}, dst_rect, &dst_overlap);
	ft_rect_overlap((t_drect){
		0, 0, src->width, src->height
	}, src_rect, &src_overlap);
	ft_rect_overlap(
		ft_rect_divide(dst_overlap, dst_rect),
		ft_rect_divide(src_overlap, src_rect),
		&total_normalized);
	ft_image_replace_image__unchecked(
		dst, ft_rect_multiply(total_normalized, dst_rect),
		src, ft_rect_multiply(total_normalized, src_rect));
}

void	ft_image_replace_image__unchecked(
	t_image *dst, t_drect dst_rect, t_image *src, t_drect src_rect
) {
	t_u32	dst_i;
	t_u32	dst_j;
	t_u32	src_i;
	t_u32	src_j;

	dst_i = 0;
	while ((t_i32) dst_i < dst_rect.h)
	{
		src_i = (double) dst_i / dst_rect.h
			* src_rect.h + src_rect.y;
		dst_j = 0;
		while ((t_i32) dst_j < dst_rect.w)
		{
			src_j = (double) dst_j / dst_rect.w
				* src_rect.w + src_rect.x;
			(*ft_image_get_pixel(dst,
					dst_j + (t_u32) dst_rect.x, dst_i + (t_u32) dst_rect.y
				)) = *ft_image_get_pixel(src, src_j, src_i);
			dst_j++;
		}
		dst_i++;
	}
}
