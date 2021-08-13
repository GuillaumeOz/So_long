/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_player_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:08:58 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:12:25 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_engine *engine, t_player *player, t_list *map)
{
	char	*line;
	int		x;
	int		y;

	x = player->coord.x;
	y = player->coord.y;
	line = list_at(map, y - 1);
	if (line[x] == '0' || line[x] == 'C')
	{
		line[x] = 'P';
		line = list_at(map, y);
		line[x] = '0';
		player->coord = create_int_vector2(x, y - 1);
		player->step += 1;
		if (BONUS == false)
			display_terminal_move(engine);
	}
	else if (line[x] == 'E')
		win(engine);
	else if (ft_ischar("BGORY", line[x]) == true)
		lose(engine);
}

static void	move_down(t_engine *engine, t_player *player, t_list *map)
{
	char	*line;
	int		x;
	int		y;

	x = player->coord.x;
	y = player->coord.y;
	line = list_at(map, y + 1);
	if (line[x] == '0' || line[x] == 'C')
	{
		line[x] = 'P';
		line = list_at(map, y);
		line[x] = '0';
		player->coord = create_int_vector2(x, y + 1);
		player->step += 1;
		if (BONUS == false)
			display_terminal_move(engine);
	}
	else if (line[x] == 'E')
		win(engine);
	else if (ft_ischar("BGORY", line[x]) == true)
		lose(engine);
}

static void	move_right(t_engine *engine, t_player *player, t_list *map)
{
	char	*line;
	int		x;
	int		y;

	x = player->coord.x;
	y = player->coord.y;
	line = list_at(map, y);
	if (line[x + 1] == '0' || line[x + 1] == 'C')
	{
		line[x + 1] = 'P';
		line = list_at(map, y);
		line[x] = '0';
		player->coord = create_int_vector2(x + 1, y);
		player->step += 1;
		if (BONUS == false)
			display_terminal_move(engine);
	}
	else if (line[x + 1] == 'E')
		win(engine);
	else if (ft_ischar("BGORY", line[x + 1]) == true)
		lose(engine);
}

static void	move_left(t_engine *engine, t_player *player, t_list *map)
{
	char	*line;
	int		x;
	int		y;

	x = player->coord.x;
	y = player->coord.y;
	line = list_at(map, y);
	if (line[x - 1] == '0' || line[x - 1] == 'C')
	{
		line[x - 1] = 'P';
		line = list_at(map, y);
		line[x] = '0';
		player->coord = create_int_vector2(x - 1, y);
		player->step += 1;
		if (BONUS == false)
			display_terminal_move(engine);
	}
	else if (line[x - 1] == 'E')
		win(engine);
	else if (ft_ischar("BGORY", line[x - 1]) == true)
		lose(engine);
}

void	player_move(t_engine *engine)
{
	t_player	*player;
	int			i;

	i = 0;
	player = engine->player;
	if (player->control & W_CTRL)
		move_up(engine, player, engine->map);
	else if (player->control & S_CTRL)
		move_down(engine, player, engine->map);
	else if (player->control & A_CTRL)
		move_left(engine, player, engine->map);
	else if (player->control & D_CTRL)
		move_right(engine, player, engine->map);
	if (player->control & MOVE_MARKER)
	{
		while (i < 15000000)
			i++;
	}
}
