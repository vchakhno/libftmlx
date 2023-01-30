/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:07:48 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/11 11:31:30 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include <math.h>

bool	ft_circle_contains(t_circle circle, t_point point)
{
	return (
		(point.x - circle.x) * (point.x - circle.x)
		+ (point.y - circle.y) * (point.y - circle.y)
		< circle.r * circle.r
	);
}

double	ft_squared_dist(t_complex a, t_complex b)
{
	return (
		(a.x - b.x) * (a.x - b.x)
		+ (a.y - b.y) * (a.y - b.y)
	);
}

bool	ft_rect_contains_point(t_rect rect, t_point point)
{
	return (
		(rect.x <= point.x) && (point.x <= rect.x + rect.w)
		&& (rect.y <= point.y) && (point.y <= rect.y + rect.h)
	);
}
