/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 06:09:51 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 11:52:19 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxft/mlxft.h"
#include <mlx.h>
#include <X11/X.h>

void	ft_mouse_attach_handlers(t_mouse *mouse, void *mlx_window)
{
	mlx_hook(mlx_window,
		ButtonPress, ButtonPressMask,
		&ft_mouse_press_handler, mouse);
	mlx_hook(mlx_window,
		ButtonRelease, ButtonReleaseMask,
		&ft_mouse_release_handler, mouse);
	mlx_hook(mlx_window,
		MotionNotify, PointerMotionMask,
		&ft_mouse_move_handler, mouse);
}

int	ft_mouse_press_handler(int button, int x, int y, t_mouse *mouse)
{
	if (button <= 3)
	{
		mouse->buttons[button - 1] = true;
		mouse->drag_start_positions[button - 1] = (t_point){x, y};
	}
	else if (button == 4)
		mouse->scroll++;
	else if (button == 5)
		mouse->scroll--;
	return (0);
}

int	ft_mouse_release_handler(int button, int x, int y, t_mouse *mouse)
{
	(void) x;
	(void) y;
	mouse->buttons[button - 1] = false;
	return (0);
}

int	ft_mouse_move_handler(int x, int y, t_mouse *mouse)
{
	mouse->pos.x = x;
	mouse->pos.y = y;
	return (0);
}
