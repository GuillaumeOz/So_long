/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ghost_moving_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 21:22:12 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/06 15:25:49 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ghost_move_up_bonus(t_engine *engine, t_ghost *ghost,
	t_list *map, char id)
{
	char		*line;
	int			x;
	int			y;

	x = ghost->coord.x;
	y = ghost->coord.y;
	line = list_at(map, y - 1);
	if (line[x] == '0')
	{
		line[x] = id;
		line = list_at(map, y);
		line[x] = '0';
		ghost->coord = create_int_vector2(x, y - 1);
	}
	else if (line[x] == 'P')
		lose(engine);
}

void	ghost_move_down_bonus(t_engine *engine, t_ghost *ghost,
	t_list *map, char id)
{
	char		*line;
	int			x;
	int			y;

	x = ghost->coord.x;
	y = ghost->coord.y;
	line = list_at(map, y + 1);
	if (line[x] == '0')
	{
		line[x] = id;
		line = list_at(map, y);
		line[x] = '0';
		ghost->coord = create_int_vector2(x, y + 1);
	}
	else if (line[x] == 'P')
		lose(engine);
}

void	ghost_move_right_bonus(t_engine *engine, t_ghost *ghost,
	t_list *map, char id)
{
	char		*line;
	int			x;
	int			y;

	x = ghost->coord.x;
	y = ghost->coord.y;
	line = list_at(map, y);
	if (line[x + 1] == '0')
	{
		line[x + 1] = id;
		line = list_at(map, y);
		line[x] = '0';
		ghost->coord = create_int_vector2(x + 1, y);
	}
	else if (line[x + 1] == 'P')
		lose(engine);
}

void	ghost_move_left_bonus(t_engine *engine, t_ghost *ghost,
	t_list *map, char id)
{
	char		*line;
	int			x;
	int			y;

	x = ghost->coord.x;
	y = ghost->coord.y;
	line = list_at(map, y);
	if (line[x - 1] == '0')
	{
		line[x - 1] = id;
		line = list_at(map, y);
		line[x] = '0';
		ghost->coord = create_int_vector2(x - 1, y);
	}
	else if (line[x - 1] == 'P')
		lose(engine);
}
