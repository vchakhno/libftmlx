/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:43:43 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 05:55:09 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/libftmlx.h"
#include <math.h>
#include <stdio.h>

void	ft_draw_solid_point(t_renderer *renderer,
	t_point point, t_color color)
{
	if (point.x < 0 || point.x >= (int) renderer->width)
		return ;
	if (point.y < 0 || point.y >= (int) renderer->height)
		return ;
	*ft_image_get_pixel(&renderer->back_buffer, point) = color;
}

void	ft_draw_solid_point__unchecked(t_renderer *renderer,
	t_point point, t_color color)
{
	*ft_image_get_pixel(&renderer->back_buffer, point) = color;
}

void	ft_draw_opaque_point(t_renderer *renderer,
	t_point point, t_color color, float opacity)
{
	if (point.x < 0 || point.x >= (int) renderer->width)
		return ;
	if (point.y < 0 || point.y >= (int) renderer->height)
		return ;
	ft_draw_opaque_point__unchecked(renderer, point, color, opacity);
}

void	ft_draw_opaque_point__unchecked(t_renderer *renderer,
	t_point point, t_color color, float opacity)
{
	t_color	*old_pixel;

	old_pixel = ft_image_get_pixel(&renderer->back_buffer, point);
	old_pixel->r += (char)((float)(color.r - old_pixel->r) * opacity);
	old_pixel->g += (char)((float)(color.g - old_pixel->g) * opacity);
	old_pixel->b += (char)((float)(color.b - old_pixel->b) * opacity);
}
