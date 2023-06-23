/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:43:43 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 05:43:21 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx/ftmlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <libft/data/mem.h>

void	ft_draw_solid_line2(t_renderer *renderer,
	t_line line, t_color color)
{
	float	dx;
	float	dy;
	int		i;
	float	j;

	dx = line.end.x - line.start.x;
	dy = line.end.y - line.start.y;
	i = 0;
	if (!dx && !dy)
		return ;
	if (fabs(dx) > fabs(dy))
	{
		while (i <= fabs(dx))
		{
			j = i / fabs(dx) * dy + 0.5f;
			if (dx > 0)
				ft_draw_solid_point(renderer,
					(t_point){i + line.start.x, j + line.start.y}, color);
			else
				ft_draw_solid_point(renderer,
					(t_point){-i + line.start.x, j + line.start.y}, color);
			i++;
		}
	}
	else
	{
		while (i <= fabs(dy))
		{
			j = i / fabs(dy) * dx + 0.5f;
			if (dy > 0)
				ft_draw_solid_point(renderer,
					(t_point){j + line.start.x, i + line.start.y}, color);
			else
				ft_draw_solid_point(renderer,
					(t_point){j + line.start.x, -i + line.start.y}, color);
			i++;
		}
	}
}

typedef struct s_hor_line
{
	int	start_x;
	int	end_x;
	int	y;
}	t_hor_line;

void	ft_draw_horizontal_line(t_renderer *renderer,
	t_hor_line line, t_color color)
{
	int	j;

	j = 0;
	while (j <= abs(line.end_x - line.start_x))
	{
		ft_draw_solid_point(renderer,
			(t_point){j + fmin(line.start_x, line.end_x), line.y}, color);
		j++;
	}
}

void	ft_draw_solid_line(t_renderer *renderer,
	t_line line, t_color color)
{
	int		i;
	int		dy;
	float	slope;

	if (line.end.y < line.start.y)
	{
		ft_mem_swap(&line.start.x, &line.end.x, sizeof(int));
		ft_mem_swap(&line.start.y, &line.end.y, sizeof(int));
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
			fmax(i - 0.5f, 0) * slope + 0.5f + line.start.x,
			fmin(i + 0.5f, dy) * slope + 0.5f + line.start.x,
			i + fmin(line.start.y, line.end.y)},
			color);
		i++;
	}
}
