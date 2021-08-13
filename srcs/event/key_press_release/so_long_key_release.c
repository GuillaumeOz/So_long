/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_release.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:22:48 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/06 18:59:18 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_release(int key, void *param)
{
	t_engine	*engine;
	t_player	*player;

	engine = (t_engine *)param;
	player = engine->player;
	if (key == W_KEY)
		player->control = ((player->control ^ W_CTRL) ^ MOVE_MARKER);
	else if (key == A_KEY)
		player->control = ((player->control ^ A_CTRL) ^ MOVE_MARKER);
	else if (key == S_KEY)
		player->control = ((player->control ^ S_CTRL) ^ MOVE_MARKER);
	else if (key == D_KEY)
		player->control = ((player->control ^ D_CTRL) ^ MOVE_MARKER);
	if (player->control != NO_CTRL)
		return (true);
	return (false);
}
