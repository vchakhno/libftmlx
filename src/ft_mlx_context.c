/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_context.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:55:56 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/04 04:33:38 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include <mlx.h>
#include <stdlib.h>

typedef struct s_mlx_context
{
	void	*mlx;
	int		window_count;
}	t_mlx_context;

static t_mlx_context	*ft_mlx_context(void)
{
	static t_mlx_context	context;

	return (&context);
}

bool	ft_mlx_context_add_window(void)
{
	t_mlx_context *const	context = ft_mlx_context();

	if (!context->window_count)
	{
		context->mlx = mlx_init();
		if (!context->mlx)
			return (false);
	}
	context->window_count++;
	return (true);
}

void	*ft_mlx_context_get(void)
{
	return (ft_mlx_context()->mlx);
}

void	ft_mlx_context_remove_window(void)
{
	t_mlx_context *const	context = ft_mlx_context();

	context->window_count--;
	if (!context->window_count)
	{
		mlx_destroy_display(context->mlx);
		free(context->mlx);
	}
}
