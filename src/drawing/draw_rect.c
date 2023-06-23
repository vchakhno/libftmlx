/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_rect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:43:43 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 05:55:09 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/libftmlx.h"
#include <math.h>
#include <stdio.h>

void	ft_fill_rect(t_renderer *renderer,
	t_rect rect, t_color color, float opacity)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.h)
	{
		j = rect.x;
		while (j < rect.x + rect.w)
		{
			ft_draw_opaque_point(renderer,
				(t_point){j, i}, color, opacity);
			j++;
		}
		i++;
	}
}
