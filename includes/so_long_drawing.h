/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_drawing.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:34:54 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/06 19:16:11 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DRAWING_H
# define SO_LONG_DRAWING_H

void	display_screen_move_bonus(t_engine *engine);
void	display_terminal_move(t_engine *engine);

void	moving_ghost_render_bonus(t_engine *engine);
void	ghost_render_bonus(t_engine *engine);

void	closed_exit_render(t_engine *engine);
void	opened_exit_render(t_engine *engine);
void	exit_render(t_engine *engine);

void	moving_player_render_bonus(t_engine *engine);
void	static_player_render(t_engine *engine);
void	player_render(t_engine *engine);

void	moving_collectible_render_bonus(t_engine *engine);
void	static_collectible_render(t_engine *engine);
void	collectible_render(t_engine *engine);

void	wall_render(t_engine *engine);

void	floor_render(t_engine *engine);

#endif