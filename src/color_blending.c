/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_blend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 03:59:30 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 08:05:10 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/color.h"
#include <math.h>

t_color	ft_color_blend(t_color background, t_color overlay)
{
	t_f32	background_opacity;
	t_f32	overlay_opacity;

	background_opacity = (t_f32) background.a / 255;
	overlay_opacity = (t_f32) overlay.a / 255;
	return ((t_color){
		.r = (t_u8)(overlay.r * overlay_opacity
		+ background.r * background_opacity * (1 - overlay_opacity)),
		.g = (t_u8)(overlay.g * overlay_opacity
		+ background.g * background_opacity * (1 - overlay_opacity)),
		.b = (t_u8)(overlay.b * overlay_opacity
		+ background.b * background_opacity * (1 - overlay_opacity)),
		.a = (t_u8)(255 * (
			overlay_opacity + background_opacity * (1 - overlay_opacity)
		))
	});
}
