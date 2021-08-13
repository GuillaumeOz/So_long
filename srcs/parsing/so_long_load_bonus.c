/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_load_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:56:46 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:47:14 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_bonus(t_engine *engine, char id, int x, int y)
{
	if (BONUS == false)
		so_long_error(ERROR_PARSING16, "Forbidden char on the map");
	if (id == 'B')
		load_blue_ghost(engine, BLUE, x, y);
	else if (id == 'G')
		load_green_ghost(engine, GREEN, x, y);
	else if (id == 'O')
		load_orange_ghost(engine, ORANGE, x, y);
	else if (id == 'R')
		load_red_ghost(engine, RED, x, y);
	else if (id == 'Y')
		load_yellow_ghost(engine, YELLOW, x, y);
}
