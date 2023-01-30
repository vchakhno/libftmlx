/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:46:02 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/15 12:01:01 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include <mlx.h>

bool	ft_renderer_alloc(t_renderer *renderer,
	void *mlx_window, int width, int height)
{
	if (!ft_image_alloc(&renderer->back_buffer, width, height))
		return (false);
	renderer->mlx_window = mlx_window;
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
	mlx_put_image_to_window(
		ft_mlx_context_get(), renderer->mlx_window,
		renderer->back_buffer.mlx_img, 0, 0);
}
