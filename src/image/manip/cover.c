/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:46:20 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 13:49:21 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/image.h"

void	ft_image_cover(t_image *image, t_color color)
{
	t_u32	i;
	t_u32	j;

	i = 0;
	while (i < image->height)
	{
		j = 0;
		while (j < image->width)
		{
			ft_image_draw_pixel__unchecked(image, j, i, color);
			j++;
		}
		i++;
	}
}
