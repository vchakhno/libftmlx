/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:43:43 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/27 17:23:23 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/libftmlx.h"

void	ft_image_fill_rect__unchecked(
	t_image *image, t_drect rect, t_color color
) {
	t_u32	i;
	t_u32	j;

	i = rect.y;
	while (i < rect.y + rect.h)
	{
		j = rect.x;
		while (j < rect.x + rect.w)
		{
			(*ft_image_get_pixel(image, j, i)) = color;
			j++;
		}
		i++;
	}
}

void	ft_image_fill_rect(t_image *image, t_drect rect, t_color color)
{
	if (ft_rect_overlap(
			rect, (t_drect){0, 0, image->width, image->height}, &rect
	))
		ft_image_fill_rect__unchecked(image, rect, color);
}

void	ft_image_stroke_rect__unchecked(
	t_image *image, t_drect rect, t_color color, t_f32 thickness
) {
	ft_image_fill_rect__unchecked(image, (t_drect){
		rect.x - thickness / 2, rect.y - thickness / 2,
		rect.w + thickness, thickness}, color);
	ft_image_fill_rect__unchecked(image, (t_drect){
		rect.x - thickness / 2, rect.y - thickness / 2,
		thickness, rect.h + thickness}, color);
	ft_image_fill_rect__unchecked(image, (t_drect){
		rect.x + rect.w - thickness / 2, rect.y - thickness / 2,
		rect.w + thickness, thickness}, color);
	ft_image_fill_rect__unchecked(image, (t_drect){
		rect.x - thickness / 2, rect.y + rect.h - thickness / 2,
		thickness, rect.h + thickness}, color);
}

void	ft_image_stroke_rect(
	t_image *image, t_drect rect, t_color color, t_f32 thickness
) {
	ft_image_fill_rect(image, (t_drect){
		rect.x - thickness / 2, rect.y - thickness / 2,
		rect.w + thickness, thickness}, color);
	ft_image_fill_rect(image, (t_drect){
		rect.x - thickness / 2, rect.y - thickness / 2,
		thickness, rect.h + thickness}, color);
	ft_image_fill_rect(image, (t_drect){
		rect.x - thickness / 2, rect.y + rect.h - thickness / 2,
		rect.w + thickness, thickness}, color);
	ft_image_fill_rect(image, (t_drect){
		rect.x + rect.w - thickness / 2, rect.y - thickness / 2,
		thickness, rect.h + thickness}, color);
}
