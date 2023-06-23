/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 08:41:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 08:53:31 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/math.h"
#include <libft/arithmetic/bounds.h>

bool	ft_rect_overlap(t_drect a, t_drect b, t_drect *dest)
{
	*dest = (t_drect){
		ft_f64_max(a.x, b.x),
		ft_f64_max(a.y, b.y),
		ft_f64_min(a.x + a.w, b.x + b.w) - ft_f64_max(a.x, b.x),
		ft_f64_min(a.y + a.h, b.y + b.h) - ft_f64_max(a.y, b.y),
	};
	return (dest->w >= 0 && dest->h >= 0);
}

t_drect	ft_rect_divide(t_drect a, t_drect b)
{
	return ((t_drect){
		(a.x - b.x) / b.w,
		(a.y - b.y) / b.h,
		a.w / b.w,
		a.h / b.h,
	});
}

t_drect	ft_rect_multiply(t_drect a, t_drect b)
{
	return ((t_drect){
		a.x * b.w + b.x,
		a.y * b.h + b.y,
		a.w * b.w,
		a.h * b.h,
	});
}
