/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:43:43 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/31 21:32:59 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxft/mlxft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_draw_solid_line(t_renderer *renderer,
	t_line line, t_color color)
{
	int	i;
	int	dx;
	int	dy;
	int	j_start;
	int	j_end;

	if (line.end.y < line.start.y)
	{
		ft_swap(&line.start.x, &line.end.x);
		ft_swap(&line.start.y, &line.end.y);
	}
	dx = line.end.x - line.start.x;
	dy = line.end.y - line.start.y;
	i = 0;
	while (i <= dy)
	{
		j_start = ((float) i) / dy * dx + line.start.x;
		j_end = ((float) i + 1.0f) / dy * dx + line.start.x;
		ft_draw_horizontal_line(renderer,
			(t_hor_line){j_start, j_end,
			i + fmin(line.start.y, line.end.y)},
			color);
		i++;
	}
}