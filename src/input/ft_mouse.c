/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 06:09:51 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 11:52:19 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxft/mlxft.h"
#include <mlx.h>

void	ft_mouse_init(t_mouse *mouse, void *mlx_window)
{
	void *const	context = ft_mlx_context_get();
	int			i;

	mlx_mouse_get_pos(context, mlx_window, &mouse->pos.x, &mouse->pos.y);
	mouse->previous_pos = mouse->pos;
	i = 0;
	while (i < 3)
	{
		mouse->buttons[i] = false;
		mouse->previous_buttons[i] = false;
		mouse->drag_start_positions[i] = mouse->pos;
		i++;
	}
	mouse->scroll = 0;
	ft_mouse_attach_handlers(mouse, mlx_window);
}

void	ft_mouse_update(t_mouse *mouse)
{
	int	i;

	mouse->previous_pos = mouse->pos;
	i = 0;
	while (i < 3)
	{
		mouse->previous_buttons[i] = mouse->buttons[i];
		i++;
	}
	mouse->scroll = 0;
}

bool	ft_mouse_moved(t_mouse *mouse)
{
	return (
		mouse->pos.x != mouse->previous_pos.x
		|| mouse->pos.y != mouse->previous_pos.y
	);
}
