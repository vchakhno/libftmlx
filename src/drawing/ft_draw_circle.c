/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:43:43 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 05:15:54 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxft/mlxft.h"
#include "mlxft/math.h"
#include <math.h>
#include <libft/arithmetic/bounds.h>
#include <stdio.h>

void	ft_fill_circle(t_renderer *renderer,
	t_circle circle, t_color color, float opacity)
{
	t_i32	i;
	t_i32	j;
	float	dst;
	float	edge_opacity;

	i = ft_i32_max(-circle.r - ceilf(EDGE), -circle.y);
	while (i < ft_i32_min(+circle.r + ceilf(EDGE), renderer->height - circle.y))
	{
		j = ft_i32_max(-circle.r - ceilf(EDGE), -circle.x);
		dst = i * i + j * j;
		while (j < ft_i32_min(
				+circle.r + ceilf(EDGE), renderer->width - circle.x))
		{
			edge_opacity = (float) ft_lerp(sqrt(dst),
					(t_drange){circle.r - EDGE, circle.r + EDGE},
					(t_drange){1., 0.});
			ft_draw_opaque_point(renderer,
				(t_point){circle.x + j, circle.y + i}, color,
				edge_opacity * opacity);
			dst += 2 * j + 1;
			j++;
		}
		i++;
	}
}
