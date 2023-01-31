/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smoothstep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:08:47 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 11:49:20 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxft/math.h"
#include <math.h>

int	ft_imin(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_imax(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_iclamp(int start, int value, int end)
{
	return (ft_imin(ft_imax(start, value), end));
}

double	ft_dclamp(double start, double value, double end)
{
	return (fmin(fmax(start, value), end));
}

double	ft_smoothstep(double value, t_drange from, t_drange to)
{
	value = (value - from.start) / (from.end - from.start);
	value = ft_dclamp(0., value, 1.);
	value = value * (to.end - to.start) + to.start;
	return (value);
}
