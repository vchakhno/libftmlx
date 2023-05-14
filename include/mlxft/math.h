/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:54:50 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/14 17:07:52 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

# include <stdbool.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_line
{
	t_point	start;
	t_point	end;
}	t_line;

typedef struct s_rect
{
	int	x;
	int	y;
	int	w;
	int	h;
}	t_rect;

typedef struct s_circle
{
	int	x;
	int	y;
	int	r;
}	t_circle;

typedef struct s_drect
{
	double	x;
	double	y;
	double	w;
	double	h;
}	t_drect;

typedef struct s_drange
{
	double	start;
	double	end;
}	t_drange;

bool		ft_circle_contains(t_circle circle, t_point point);
bool		ft_rect_contains_point(t_rect rect, t_point point);

double		ft_lerp(double value, t_drange from, t_drange to);

#endif