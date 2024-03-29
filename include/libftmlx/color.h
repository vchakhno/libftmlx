/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 03:58:02 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 07:30:55 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <libft/arithmetic/fixed_types.h>

typedef union u_color
{
	struct {
		t_u8	b;
		t_u8	g;
		t_u8	r;
		t_u8	a;
	};
	t_u32	hex;
}	t_color;

t_color	ft_color_from_f32_hsv(t_f32 hue, t_f32 saturation, t_f32 value);
t_color	ft_color_blend(t_color background, t_color overlay);

#endif