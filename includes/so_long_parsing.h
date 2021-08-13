/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:17:40 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:04:26 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_PARSING_H
# define SO_LONG_PARSING_H

void	load_blue_ghost(t_engine *engine, t_ghost_color id, int x, int y);
void	load_green_ghost(t_engine *engine, t_ghost_color id, int x, int y);
void	load_orange_ghost(t_engine *engine, t_ghost_color id, int x, int y);
void	load_red_ghost(t_engine *engine, t_ghost_color id, int x, int y);
void	load_yellow_ghost(t_engine *engine, t_ghost_color id, int x, int y);

void	load_bonus(t_engine *engine, char id, int x, int y);

void	load_collectible(t_engine *engine, int x, int y);
void	load_player(t_engine *engine, int x, int y);
void	load_exit(t_engine *engine, int x, int y);

void	load_map_informations(t_engine *engine, int size_x, int size_y);

void	analyse_map(t_engine *engine);

void	parse_map(t_engine *engine, int fd);

void	check_arguments(int argc, char **argv);

void	parsing(t_engine *engine, int argc, char **argv);

#endif