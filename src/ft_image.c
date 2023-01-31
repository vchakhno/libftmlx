/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:52:30 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 11:52:19 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxft/mlxft.h"
#include <mlx.h>

bool	ft_image_alloc(t_img *img, int width, int height)
{
	img->mlx_img = mlx_new_image(ft_mlx_context_get(), width, height);
	if (!img->mlx_img)
		return (false);
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr(img->mlx_img,
			&img->bpp, &img->line_len, &img->endian);
	return (true);
}

t_color	*ft_image_get_pixel(t_img *img, t_point pos)
{
	return ((t_color *)(
		img->addr
		+ pos.x * (img->bpp / 8)
		+ pos.y * img->line_len
	));
}

void	ft_image_free(t_img *img)
{
	mlx_destroy_image(ft_mlx_context_get(), img->mlx_img);
}
