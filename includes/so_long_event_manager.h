/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_event_manager.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:24:47 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:03:29 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_EVENT_MANAGER_H
# define SO_LONG_EVENT_MANAGER_H

# define ONELEFTMASK 2147483648

enum	e_so_long_event
{
	NO_CTRL = 0,
	W_CTRL = (1 << 0),
	A_CTRL = (1 << 1),
	S_CTRL = (1 << 2),
	D_CTRL = (1 << 3),
	MOVE_MARKER = (ONELEFTMASK >> 0),
};

bool	check_win_condition(t_engine *engine);

void	win(t_engine *engine);
void	lose(t_engine *engine);

void	ghost_move_up_bonus(t_engine *engine, t_ghost *ghost,
			t_list *map, char id);
void	ghost_move_down_bonus(t_engine *engine, t_ghost *ghost,
			t_list *map, char id);
void	ghost_move_right_bonus(t_engine *engine, t_ghost *ghost,
			t_list *map, char id);
void	ghost_move_left_bonus(t_engine *engine, t_ghost *ghost,
			t_list *map, char id);

void	set_ghost_move_bonus(t_engine *engine);
void	ghost_move_bonus(t_engine *engine);

void	player_move(t_engine *engine);

int		key_release(int key, void *param);
int		key_press(int key, void *param);

void	event_manager(t_engine *engine);

#endif