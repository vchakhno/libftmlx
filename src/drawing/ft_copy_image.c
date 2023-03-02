/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:43:43 by vchakhno          #+#    #+#             */
/*   Updated: 2023/03/02 11:16:57 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxft/mlxft.h"
#include "mlxft/math.h"
#include <math.h>
#include <stdio.h>

void	ft_copy_image(t_renderer *renderer,
	t_point dst_pos, t_img *src, t_rect	src_rect)
{
	int		i;
	int		j;
	t_color	pixel_color;

	i = 0;
	while (i < src_rect.h)
	{
		j = 0;
		while (j < src_rect.w)
		{
			pixel_color = *ft_image_get_pixel(src,
					(t_point){j + src_rect.x, i + src_rect.y});
			*ft_image_get_pixel(&renderer->back_buffer,
				(t_point){j + dst_pos.x, i + dst_pos.y}) = pixel_color;
			j++;
		}
		i++;
	}
}
