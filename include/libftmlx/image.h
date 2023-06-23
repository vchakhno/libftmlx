/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 05:52:38 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 06:15:14 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include "libftmlx/image.h"
# undef IMAGE_H
#else
# ifndef LIBFTMLX_IMAGE_H
#  define LIBFTMLX_IMAGE_H

#  include <libft/arithmetic/fixed_types.h>
#  include "libftmlx/color.h"
#  include <stdbool.h>

typedef struct s_img
{
	t_u32	width;
	t_u32	height;
	void	*mlx_img;
	t_color	*addr;
	t_u32	line_len;
}	t_img;

// image.c
bool		ft_image_alloc(t_img *img, t_u32 width, t_u32 height);
bool		ft_image_alloc_from_xpm(t_img *img, char *filename);
t_color		*ft_image_get_pixel(t_img *img, t_u32 x, t_u32 y);
void		ft_image_free(t_img *img);

# endif
#endif