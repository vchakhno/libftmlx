/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:42:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 13:45:40 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/image.h"

void	ft_image_draw_pixel(
	t_image *image, t_u32 x, t_u32 y, t_color color
) {
	if (x < image->width && y < image->height)
		ft_image_draw_pixel__unchecked(image, x, y, color);
}

void	ft_image_draw_pixel__unchecked(
	t_image *image, t_u32 x, t_u32 y, t_color color
) {
	t_color	*pixel;

	pixel = ft_image_get_pixel(image, x, y);
	*pixel = ft_color_blend(*pixel, color);
}
