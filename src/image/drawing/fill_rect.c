/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:43:43 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/26 04:19:44 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/libftmlx.h"

void	ft_image_fill_rect__unchecked(
	t_image *image, t_drect rect, t_color color
) {
	t_u32	i;
	t_u32	j;

	i = rect.y;
	while (i < rect.y + rect.h)
	{
		j = rect.x;
		while (j < rect.x + rect.w)
		{
			(*ft_image_get_pixel(image, j, i)) = color;
			j++;
		}
		i++;
	}
}

void	ft_image_fill_rect(t_image *image, t_drect rect, t_color color)
{
	if (ft_rect_overlap(
			rect, (t_drect){0, 0, image->width, image->height}, &rect
	))
		ft_image_fill_rect__unchecked(image, rect, color);
}
