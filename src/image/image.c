/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:52:30 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/26 04:22:20 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/libftmlx.h"
#include <mlx.h>

bool	ft_image_alloc(t_image *image, t_u32 width, t_u32 height)
{
	void	*mlx_context;

	if (!ft_image_context_increment(&mlx_context))
		return (false);
	image->mlx_image = mlx_new_image(mlx_context, width, height);
	if (!image->mlx_image)
	{
		ft_image_context_decrement();
		return (false);
	}
	image->width = width;
	image->height = height;
	image->pixels = (t_color *) mlx_get_data_addr(image->mlx_image,
			&(int){0}, (int *)&image->line_length, &(int){0});
	ft_image_cover(image, (t_color){.a = 255});
	return (true);
}

bool	ft_image_alloc_from_xpm(t_image *image, char *filename)
{
	void	*mlx_context;

	if (!ft_image_context_increment(&mlx_context))
		return (false);
	image->mlx_image = mlx_xpm_file_to_image(mlx_context,
			filename, (int *)&image->width, (int *)&image->height);
	if (!image->mlx_image)
	{
		ft_image_context_decrement();
		return (false);
	}
	image->pixels = (t_color *) mlx_get_data_addr(image->mlx_image,
			&(int){0}, (int *)&image->line_length, &(int){0});
	return (true);
}

t_color	*ft_image_get_pixel(t_image *image, t_u32 x, t_u32 y)
{
	return (image->pixels + x + y * image->line_length / sizeof(t_color));
}

void	ft_image_free(t_image *image)
{
	mlx_destroy_image(ft_image_context()->mlx_context, image->mlx_image);
	ft_image_context_decrement();
}
