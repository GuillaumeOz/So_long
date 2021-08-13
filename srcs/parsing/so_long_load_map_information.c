/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_load_map_information.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:47:01 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:43:50 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	last_check(t_engine *engine)
{
	if (engine->player == NULL)
		so_long_error(ERROR_PARSING10, "There are no player on map");
	if (engine->exit == NULL)
		so_long_error(ERROR_PARSING11, "There are no exit on map");
	if (engine->collectible == NULL)
		so_long_error(ERROR_PARSING12, "There are no collectible on map");
	if (BONUS == true)
		if (engine->ghost_blue == NULL
			|| engine->ghost_green == NULL
			|| engine->ghost_orange == NULL
			|| engine->ghost_red == NULL
			|| engine->ghost_yellow == NULL)
			 so_long_error(ERROR_PARSING13, "Some ghosts are missing on map");
}

static void	load_env(t_engine *engine)
{
	engine->env = malloc_env(engine->app,
			"./textures/floor.xpm", "./textures/wall.xpm");
}

void	load_map_informations(t_engine *engine, int size_x, int size_y)
{
	char	*line;
	int		x;
	int		y;

	y = 0;
	load_env(engine);
	while (y < size_y)
	{
		x = 0;
		line = list_at(engine->map, y);
		while (x < size_x)
		{
			if (line[x] == 'P')
				load_player(engine, x, y);
			else if (line[x] == 'E')
				load_exit(engine, x, y);
			else if (line[x] == 'C')
				load_collectible(engine, x, y);
			else if (ft_ischar("BGORY", line[x]) == true)
				load_bonus(engine, line[x], x, y);
			x++;
		}
		y++;
	}
	last_check(engine);
}
