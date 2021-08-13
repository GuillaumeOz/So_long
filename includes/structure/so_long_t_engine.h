/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_t_engine.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:48:19 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:02:07 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_T_ENGINE_H
# define SO_LONG_T_ENGINE_H

enum e_bonus_engine
{
	NO_BONUS = 0,
	ENEMY_BONUS = (1 << 0),
	ANIMATION_BONUS = (1 << 1),
	MOUV_COUNT_BONUS = (1 << 2),
};

typedef struct s_engine
{
	t_application	*app;
	int				map_size_x;
	int				map_size_y;
	t_player		*player;
	t_exit			*exit;
	t_collectible	*collectible;
	t_env			*env;
	t_ghost			*ghost_red;
	t_ghost			*ghost_blue;
	t_ghost			*ghost_green;
	t_ghost			*ghost_yellow;
	t_ghost			*ghost_orange;
	t_list			*map;
	char			*allow_charset;
	t_uint8			bonus;
}					t_engine;

t_engine		*malloc_engine(void);
t_engine		create_engine(void);
void			destroy_engine(t_engine to_destroy);
void			free_engine(t_engine *to_free);

#endif