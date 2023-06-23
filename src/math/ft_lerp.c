/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lerp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:08:47 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 02:17:29 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxft/math.h"
#include <libft/arithmetic/bounds.h>
#include <math.h>

double	ft_lerp(double value, t_drange from, t_drange to)
{
	value = (value - from.start) / (from.end - from.start);
	value = ft_f64_clamp(0., value, 1.);
	value = value * (to.end - to.start) + to.start;
	return (value);
}
