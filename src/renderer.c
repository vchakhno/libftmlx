/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:46:02 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 06:29:54 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/libftmlx.h"
#include <mlx.h>
#include <stdio.h>
#include <stddef.h>

bool	ft_renderer_alloc(t_renderer *renderer, int width, int height)
{
	if (!ft_image_alloc(&renderer->back_buffer, width, height))
		return (false);
	renderer->width = width;
	renderer->height = height;
	return (true);
}

void	ft_renderer_free(t_renderer *renderer)
{
	ft_image_free(&renderer->back_buffer);
}

void	ft_renderer_display(t_renderer *renderer)
{
	t_window	*window;

	window = (void *)renderer \
			- (ptrdiff_t) &((t_window *)0)->renderer;
	mlx_put_image_to_window(
		window->mlx_context, window->mlx_window,
		renderer->back_buffer.mlx_img, 0, 0);
}

void	ft_renderer_clear(t_renderer *renderer, t_color color)
{
	t_u32	i;
	t_u32	j;

	i = 0;
	while (i < renderer->back_buffer.height)
	{
		j = 0;
		while (j < renderer->back_buffer.width)
		{
			ft_draw_solid_point(renderer, j, i, color);
			j++;
		}
		i++;
	}
}
