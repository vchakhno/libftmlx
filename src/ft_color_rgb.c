/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 03:59:30 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/31 16:09:41 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxft/color.h"
#include <math.h>

t_color	ft_color_from_char_rgb(char red, char green, char blue)
{
	return ((t_color){
		.r = red,
		.g = green,
		.b = blue,
	});
}

t_color	ft_color_from_float_rgb(float red, float green, float blue)
{
	return ((t_color){
		.r = (char)(red * 255),
		.g = (char)(green * 255),
		.b = (char)(blue * 255),
	});
}

t_color	ft_color_blend(t_color background, t_color added, float factor)
{
	float	inverse;

	inverse = 1 - factor;
	return ((t_color){
		.r = (char)(background.r * inverse + added.r * factor),
		.g = (char)(background.g * inverse + added.g * factor),
		.b = (char)(background.b * inverse + added.b * factor)
	});
}
