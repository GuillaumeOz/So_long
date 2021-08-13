/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_load_basic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:38:07 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:47:02 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_collectible(t_engine *engine, int x, int y)
{
	if (engine->collectible != NULL)
		return ;
	else
		engine->collectible = malloc_collectible(engine->app,
				"./textures/BigCoin.xpm", create_int_vector2(x, y));
}

void	load_player(t_engine *engine, int x, int y)
{
	if (engine->player != NULL)
		so_long_error(ERROR_PARSING14, "Many players detected on map");
	else
		engine->player = malloc_player(engine->app, "./textures/PacMan.xpm",
				create_int_vector2(x, y));
}

void	load_exit(t_engine *engine, int x, int y)
{
	if (engine->exit != NULL)
		so_long_error(ERROR_PARSING15, "Many exits detected on map");
	else
		engine->exit = malloc_exit(engine->app, "./textures/door_closed.xpm",
				"./textures/door_open.xpm", create_int_vector2(x, y));
}
