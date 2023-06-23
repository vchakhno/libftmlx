/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:54:50 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 08:52:44 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H
# include "libftmlx/math.h"
# undef MATH_H
#else
# ifndef FTMLX_MATH_H
#  define FTMLX_MATH_H

#  include <libft/arithmetic/fixed_types.h>
#  include <stdbool.h>

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

typedef struct s_triangle
{
	t_point	points[3];
}	t_triangle;

typedef struct s_circle
{
	int	x;
	int	y;
	int	r;
}	t_circle;

typedef struct s_drect
{
	t_f64	x;
	t_f64	y;
	t_f64	w;
	t_f64	h;
}	t_drect;

typedef struct s_drange
{
	t_f64	start;
	t_f64	end;
}	t_drange;

bool		ft_circle_contains(t_circle circle, t_point point);
bool		ft_rect_contains_point(t_rect rect, t_point point);

t_f64		ft_lerp(t_f64 value, t_drange from, t_drange to);

bool		ft_rect_overlap(t_drect a, t_drect b, t_drect *dest);
t_drect		ft_rect_divide(t_drect a, t_drect b);
t_drect		ft_rect_multiply(t_drect a, t_drect b);

# endif
#endif