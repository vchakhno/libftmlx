/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_blending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 03:59:30 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/25 07:20:39 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/color.h"
#include <math.h>

static t_u8	color_component_blend(
	t_u8 background_component, t_f32 background_blocking,
	t_u8 foreground_component, t_f32 foreground_alpha
) {
	return ((t_f32)
		(
			(t_f32) foreground_component / 255 * foreground_alpha
			+ (t_f32) background_component / 255 * background_blocking
		) / (foreground_alpha + background_blocking) * 255
	);
}

t_color	ft_color_blend(t_color background, t_color foreground)
{
	t_f32	foreground_alpha;
	t_f32	background_blocking;

	foreground_alpha = (t_f32) foreground.a / 255;
	background_blocking = (t_f32) background.a / 255 * (1 - foreground_alpha);
	return ((t_color){
		.r = color_component_blend(background.r, background_blocking,
			foreground.r, foreground_alpha),
		.g = color_component_blend(background.g, background_blocking,
			foreground.g, foreground_alpha),
		.b = color_component_blend(background.b, background_blocking,
			foreground.b, foreground_alpha),
		.a = 255 * (foreground_alpha + background_blocking)
	});
}
