/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 07:16:19 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/25 09:04:03 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/font.h"
#include <libft/data/mem.h>
#include <libft/arithmetic/bounds.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

bool	ft_font_alloc(t_font *font, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (false);
	if (4 != read(fd, &font->size, sizeof(t_u32))
		|| 4 != read(fd, &font->letter_w, sizeof(t_u32))
		|| 4 != read(fd, &font->letter_h, sizeof(t_u32))
		|| !ft_mem_malloc(&font->alpha, font->letter_w * font->letter_h * 94))
	{
		close(fd);
		return (false);
	}
	if (read(fd, font->alpha, font->letter_w * font->letter_h * 94)
		!= font->letter_w * font->letter_h * 94)
	{
		free(font->alpha);
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}

t_u8	ft_font_get_alpha__unchecked(t_font *font, char c, t_u32 x, t_u32 y)
{
	if (c < ' ' || '~' < c)
		c = '?';
	return (font->alpha[
			font->letter_w * 94 * y
			+ font->letter_w * (c - ' ')
			+ x
		]);
}

t_u8	ft_font_get_alpha(t_font *font, char c, t_u32 x, t_u32 y)
{
	return (ft_font_get_alpha__unchecked(
			font, c,
			ft_u32_min(x, font->letter_w),
			ft_u32_min(y, font->letter_h)
		));
}

void	ft_font_free(t_font *font)
{
	free(font->alpha);
}
