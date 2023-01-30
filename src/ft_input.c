/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:56:24 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/08 04:17:12 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void	ft_input_init(t_input *input, void *mlx_window)
{
	ft_mouse_init(&input->mouse, mlx_window);
}

void	ft_input_update(t_input *input)
{
	ft_mouse_update(&input->mouse);
}
