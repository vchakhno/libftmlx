/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:43:43 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/15 12:02:44 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include <math.h>
#include <stdio.h>

void	ft_renderer_draw_solid_point(t_renderer *renderer,
	t_point point, t_color color)
{
	*ft_image_get_pixel(&renderer->back_buffer, point) = color;
}

void	ft_renderer_draw_opaque_point(t_renderer *renderer,
	t_point point, t_color color, float opacity)
{
	t_color	*old_pixel;

	old_pixel = ft_image_get_pixel(&renderer->back_buffer, point);
	old_pixel->r += (char)((float)(color.r - old_pixel->r) * opacity);
	old_pixel->g += (char)((float)(color.g - old_pixel->g) * opacity);
	old_pixel->b += (char)((float)(color.b - old_pixel->b) * opacity);
}

void	ft_renderer_fill_rect(t_renderer *renderer,
	t_rect rect, t_color color, float opacity)
{
	int	i;
	int	j;

	rect.x = ft_iclamp(0, rect.x, renderer->width);
	rect.w = ft_iclamp(0, rect.w, renderer->width - rect.x);
	rect.y = ft_iclamp(0, rect.y, renderer->height);
	rect.h = ft_iclamp(0, rect.h, renderer->height - rect.y);
	i = rect.y;
	while (i < rect.y + rect.h)
	{
		j = rect.x;
		while (j < rect.x + rect.w)
		{
			ft_renderer_draw_opaque_point(renderer,
				(t_point){j, i}, color, opacity);
			j++;
		}
		i++;
	}
}

void	ft_renderer_fill_circle(t_renderer *renderer,
	t_circle circle, t_color color, float opacity)
{
	int		i;
	int		j;
	float	edge_opacity;

	(void) opacity;
	if (circle.x - circle.r - 1 < 0 || circle.y - circle.r - 1 < 0
		|| circle.x + circle.r + 1 >= renderer->back_buffer.width
		|| circle.y + circle.r + 1 >= renderer->back_buffer.height)
		return ;
	i = -circle.r;
	while (i <= +circle.r)
	{
		j = -circle.r;
		while (j <= +circle.r)
		{
			edge_opacity = (float) ft_smoothstep(
					sqrt(i * i + j * j),
					(t_drange){circle.r - 1, circle.r + 1},
					(t_drange){1., 0.});
			ft_renderer_draw_opaque_point(renderer,
				(t_point){circle.x + j, circle.y + i}, color,
				edge_opacity);
			j++;
		}
		i++;
	}
}

void	ft_renderer_clear(t_renderer *renderer, t_color color)
{
	int	i;
	int	j;

	i = 0;
	while (i < renderer->back_buffer.height)
	{
		j = 0;
		while (j < renderer->back_buffer.width)
		{
			ft_renderer_draw_solid_point(renderer, (t_point){j, i}, color);
			j++;
		}
		i++;
	}
}
