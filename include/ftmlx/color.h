/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 03:58:02 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/31 16:09:29 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef union u_color
{
	struct {
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
	};
	int	hex;
}	t_color;

t_color	ft_color_from_char_rgb(char red, char green, char blue);
t_color	ft_color_from_float_rgb(float red, float green, float blue);
t_color	ft_color_from_float_hsv(float hue, float saturation, float value);
t_color	ft_color_blend(t_color a, t_color b, float factor);

#endif