/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:52:30 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/14 20:04:07 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxft/mlxft.h"
#include <mlx.h>

bool	ft_image_alloc(t_img *img, void *mlx_context, int width, int height)
{
	img->mlx_img = mlx_new_image(mlx_context, width, height);
	if (!img->mlx_img)
		return (false);
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr(img->mlx_img,
			&(int){0}, (int *)&img->line_len, &(int){0});
	return (true);
}

bool	ft_image_alloc_from_xpm(t_img *img, void *mlx_context, char *filename)
{
	img->mlx_img = mlx_xpm_file_to_image(mlx_context,
			filename, (int *)&img->width, (int *)&img->height);
	if (!img->mlx_img)
		return (false);
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

void	ft_image_free(t_img *img, void *mlx_context)
{
	mlx_destroy_image(mlx_context, img->mlx_img);
}
