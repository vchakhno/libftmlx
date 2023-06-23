/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:52:30 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 05:55:09 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/libftmlx.h"
#include <mlx.h>

bool	ft_image_alloc(t_img *img, int width, int height)
{
	void	*mlx_context;

	if (!ft_image_context_increment(&mlx_context))
		return (false);
	img->mlx_img = mlx_new_image(mlx_context, width, height);
	if (!img->mlx_img)
	{
		ft_image_context_decrement();
		return (false);
	}
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr(img->mlx_img,
			&(int){0}, (int *)&img->line_len, &(int){0});
	return (true);
}

bool	ft_image_alloc_from_xpm(t_img *img, char *filename)
{
	void	*mlx_context;

	if (!ft_image_context_increment(&mlx_context))
		return (false);
	img->mlx_img = mlx_xpm_file_to_image(mlx_context,
			filename, (int *)&img->width, (int *)&img->height);
	if (!img->mlx_img)
	{
		ft_image_context_decrement();
		return (false);
	}
	img->addr = mlx_get_data_addr(img->mlx_img,
			&(int){0}, (int *)&img->line_len, &(int){0});
	return (true);
}

t_color	*ft_image_get_pixel(t_img *img, t_point pos)
{
	return ((t_color *)(
		img->addr
		+ pos.x * 4
		+ pos.y * img->line_len
	));
}

void	ft_image_free(t_img *img)
{
	mlx_destroy_image(ft_image_context()->mlx_context, img->mlx_img);
	ft_image_context_decrement();
}
