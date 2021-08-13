/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:25:59 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:12:43 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	routine(void *param)
{
	t_engine	*engine;

	engine = (t_engine *)param;
	floor_render(engine);
	wall_render(engine);
	collectible_render(engine);
	exit_render(engine);
	ghost_render_bonus(engine);
	player_render(engine);
	ghost_move_bonus(engine);
	player_move(engine);
	application_render(engine->app);
	display_screen_move_bonus(engine);
	return (0);
}
