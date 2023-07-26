/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:40:15 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/26 04:06:10 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

typedef enum e_button_id {
	FT_MOUSE_LEFT = 0,
	FT_MOUSE_MIDDLE = 2,
	FT_MOUSE_RIGHT = 1,
	FT_SCROLL_UP = 4,
	FT_SCROLL_DOWN = 5
}	t_button_id;

typedef struct s_mouse
{
	t_point				pos;
	t_point				previous_pos;
	bool				buttons[3];
	bool				previous_buttons[3];
	t_point				drag_start_positions[3];
	int					scroll;
}	t_mouse;

// mouse.c
void	ft_mouse_init(t_mouse *mouse);
void	ft_mouse_update(t_mouse *mouse);
bool	ft_mouse_moved(t_mouse *mouse);

// mouse_buttons.c
bool	ft_mouse_button_down(t_mouse *mouse, t_button_id button);
bool	ft_mouse_button_pressed(t_mouse *mouse, t_button_id button);
bool	ft_mouse_button_released(t_mouse *mouse, t_button_id button);
bool	ft_mouse_zone_clicked(t_mouse *mouse,
			t_drect rect, t_button_id button);

typedef struct s_input
{
	t_mouse	mouse;
}	t_input;

// input.c
void	ft_input_init(t_input *input);
void	ft_input_update(t_input *input);

#endif