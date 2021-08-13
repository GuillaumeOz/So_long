/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_set_ghost_move_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 20:58:32 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:07:00 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	random_in_range(t_ghost *ghost, int min, int max)
{
	int	rand;

	ghost->rand = ((ghost->rand * ghost->rand) / 100) % 10000;
	rand = ghost->rand % (max + 1 - min) + min;
	return (rand);
}

static void	set_rand_ghost_move(t_engine *engine, t_ghost *ghost,
	t_list *map, char id)
{
	int	rand;

	rand = random_in_range(ghost, 0, 20);
	if (0 <= rand && rand < 5)
		ghost_move_up_bonus(engine, ghost, map, id);
	else if (5 <= rand && rand < 10)
		ghost_move_down_bonus(engine, ghost, map, id);
	else if (10 <= rand && rand < 15)
		ghost_move_right_bonus(engine, ghost, map, id);
	else if (15 <= rand && rand < 20)
		ghost_move_left_bonus(engine, ghost, map, id);
	ghost->rand = 3251 + rand
		- engine->player->coord.x - engine->player->coord.y;
}

void	set_ghost_move_bonus(t_engine *engine)
{
	set_rand_ghost_move(engine, engine->ghost_blue, engine->map, 'B');
	set_rand_ghost_move(engine, engine->ghost_green, engine->map, 'G');
	set_rand_ghost_move(engine, engine->ghost_orange, engine->map, 'O');
	set_rand_ghost_move(engine, engine->ghost_red, engine->map, 'R');
	set_rand_ghost_move(engine, engine->ghost_yellow, engine->map, 'Y');
}
