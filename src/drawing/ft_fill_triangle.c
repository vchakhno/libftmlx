/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line copy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:43:43 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/02 06:40:12 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxft/mlxft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_draw_solid_line(t_renderer *renderer,
	t_line line, t_color color)
{
	int		i;
	int		dy;
	float	slope;

	if (line.end.y < line.start.y)
	{
		ft_swap(&line.start.x, &line.end.x);
		ft_swap(&line.start.y, &line.end.y);
	}
	dy = line.end.y - line.start.y;
	if (!dy)
	{
		ft_draw_horizontal_line(renderer,
			(t_hor_line){line.start.x, line.end.x, line.start.y}, color);
		return ;
	}
	slope = (float)(line.end.x - line.start.x) / dy;
	i = 0;
	while (i <= dy)
	{
		ft_draw_horizontal_line(renderer, (t_hor_line){
			fmax(i - 0.5, 0) * slope + 0.5f + line.start.x,
			fmin(i + 0.5, dy) * slope + 0.5f + line.start.x,
			i + fmin(line.start.y, line.end.y)},
			color);
		i++;
	}
}
