/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_hsv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 03:59:30 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/26 06:46:01 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/color.h"
#include <libft/arithmetic/float_math.h>
#include <math.h>

static t_color	ft_color_from_hsv__rotate(t_color color, t_f32 hue)
{
	int	rotation;

	rotation = (int)(hue * 3) % 3;
	if (rotation < 1)
		return (color);
	if (rotation < 2)
		return ((t_color){.r = color.b, .g = color.r, .b = color.g});
	return ((t_color){.r = color.g, .g = color.b, .b = color.r});
}

static t_color	ft_color_from_hsv__swap(t_color color, t_f32 hue)
{
	if ((int)(hue * 6) % 2)
		return ((t_color){.r = color.g, .g = color.r, .b = color.b});
	return (color);
}

static t_color	ft_color_from_hsv__color(
	t_f32 hue, t_f32 saturation, t_f32 value)
{
	t_f32	chroma;

	chroma = value * saturation;
	return ((t_color){
		.r = (t_u8)(value * 255),
		.g = (t_u8)(255 * (
			value + chroma * -fabsf(ft_f32_mod(hue * 6, 2.f) - 1))),
		.b = (t_u8)((value - chroma) * 255)
	});
}

t_color	ft_color_from_f32_hsv(t_f32 hue, t_f32 saturation, t_f32 value)
{
	t_color	color;

	color = ft_color_from_hsv__color(hue, saturation, value);
	color = ft_color_from_hsv__swap(color, hue);
	color = ft_color_from_hsv__rotate(color, hue);
	return (color);
}
