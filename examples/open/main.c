/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:58:42 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/14 20:30:16 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxft/mlxft.h>
#include <stdio.h>

int	main(void)
{
	t_window	window;

	setbuf(stdout, NULL);
	if (!ft_window_alloc(&window, 800, 600, "Test window"))
		return (1);
	if (!ft_window_open(&window))
	{
		ft_window_free(&window);
		return (1);
	}
	ft_window_free(&window);
	return (0);
}
