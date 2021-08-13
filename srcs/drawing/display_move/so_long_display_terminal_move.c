/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_display_terminal_move.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 18:41:07 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:16:35 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_terminal_move(t_engine *engine)
{
	t_player	*player;

	player = engine->player;
	printf("%d\n", player->step);
}
