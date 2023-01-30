/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:54:50 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/29 06:31:42 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <stdbool.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

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

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

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
double		ft_squared_dist(t_complex a, t_complex b);
bool		ft_rect_contains_point(t_rect rect, t_point point);

int			ft_imin(int a, int b);
int			ft_imax(int a, int b);
int			ft_iclamp(int start, int value, int end);

double		ft_smoothstep(double value, t_drange from, t_drange to);

#endif