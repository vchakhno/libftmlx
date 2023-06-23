/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_buttons.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 06:09:51 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 05:55:09 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/libftmlx.h"
#include <mlx.h>

bool	ft_mouse_button_down(t_mouse *mouse, t_button_id button)
{
	return (mouse->buttons[button]);
}

bool	ft_mouse_button_pressed(t_mouse *mouse, t_button_id button)
{
	return (mouse->buttons[button] && !mouse->previous_buttons[button]);
}

bool	ft_mouse_button_released(t_mouse *mouse, t_button_id button)
{
	return (!mouse->buttons[button] && mouse->previous_buttons[button]);
}

bool	ft_mouse_zone_clicked(t_mouse *mouse, t_rect rect, t_button_id button)
{
	return (
		ft_mouse_button_released(mouse, button)
		&& ft_rect_contains_point(rect, mouse->pos)
		&& ft_rect_contains_point(rect, mouse->drag_start_positions[button])
	);
}
