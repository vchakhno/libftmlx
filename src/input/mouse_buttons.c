/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_buttons.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 06:09:51 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/27 14:50:05 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmlx/libftmlx.h"
#include <mlx.h>

bool	ft_mouse_button_down(t_mouse *mouse, t_button_id button)
{
	return (mouse->buttons[button - 1]);
}

bool	ft_mouse_button_pressed(t_mouse *mouse, t_button_id button)
{
	return (mouse->buttons[button - 1] && !mouse->previous_buttons[button - 1]);
}

bool	ft_mouse_button_released(t_mouse *mouse, t_button_id button)
{
	return (!mouse->buttons[button - 1] && mouse->previous_buttons[button - 1]);
}

bool	ft_mouse_zone_clicked(t_mouse *mouse, t_drect rect, t_button_id button)
{
	return (
		ft_mouse_button_released(mouse, button)
		&& ft_rect_contains_point(rect, mouse->pos)
		&& ft_rect_contains_point(rect, mouse->drag_start_positions[button - 1])
	);
}
