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
#include <stdlib.h>

t_image_context	*ft_image_context(void)
{
	static t_image_context	context;

	return (&context);
}

bool	ft_image_context_increment(void **mlx_context)
{
	t_image_context *const	context = ft_image_context();

	if (context->image_count == 0)
	{
		context->mlx_context = mlx_init();
		if (!context->mlx_context)
			return (false);
	}
	context->image_count++;
	*mlx_context = context->mlx_context;
	return (true);
}

void	ft_image_context_decrement(void)
{
	t_image_context *const	context = ft_image_context();

	context->image_count--;
	if (context->image_count == 0)
	{
		mlx_destroy_display(context->mlx_context);
		free(context->mlx_context);
	}
}
