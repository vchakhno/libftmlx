/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:07:48 by vchakhno          #+#    #+#             */
/*   Updated: 2023/03/06 23:10:39 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxft/math.h"
#include <math.h>

bool	ft_circle_contains(t_circle circle, t_point point)
{
	return (
		(point.x - circle.x) * (point.x - circle.x)
		+ (point.y - circle.y) * (point.y - circle.y)
		< circle.r * circle.r
	);
}

bool	ft_rect_contains_point(t_rect rect, t_point point)
{
	return (
		(rect.x <= point.x) && (point.x <= rect.x + rect.w)
		&& (rect.y <= point.y) && (point.y <= rect.y + rect.h)
	);
}
