/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_load_ghost_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:27:41 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:47:59 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_blue_ghost(t_engine *engine, t_ghost_color id, int x, int y)
{
	if (engine->ghost_blue != NULL)
		so_long_error(ERROR_PARSING18, "Many blue ghost on the map");
	else
		engine->ghost_blue = malloc_ghost(engine->app,
				"./textures/blueGhost.xpm", id, create_int_vector2(x, y));
}

void	load_green_ghost(t_engine *engine, t_ghost_color id, int x, int y)
{
	if (engine->ghost_green != NULL)
		so_long_error(ERROR_PARSING19, "Many green ghost on the map");
	else
		engine->ghost_green = malloc_ghost(engine->app,
				"./textures/greenGhost.xpm", id, create_int_vector2(x, y));
}

void	load_orange_ghost(t_engine *engine, t_ghost_color id, int x, int y)
{
	if (engine->ghost_orange != NULL)
		so_long_error(ERROR_PARSING20, "Many orange ghost on the map");
	else
		engine->ghost_orange = malloc_ghost(engine->app,
				"./textures/orangeGhost.xpm", id, create_int_vector2(x, y));
}

void	load_red_ghost(t_engine *engine, t_ghost_color id, int x, int y)
{
	if (engine->ghost_red != NULL)
		so_long_error(ERROR_PARSING21, "Many red ghost on the map");
	else
		engine->ghost_red = malloc_ghost(engine->app,
				"./textures/redGhost.xpm", id, create_int_vector2(x, y));
}

void	load_yellow_ghost(t_engine *engine, t_ghost_color id, int x, int y)
{
	if (engine->ghost_yellow != NULL)
		so_long_error(ERROR_PARSING22, "Many yellow ghost on the map");
	else
		engine->ghost_yellow = malloc_ghost(engine->app,
				"./textures/yellowGhost.xpm", id, create_int_vector2(x, y));
}
