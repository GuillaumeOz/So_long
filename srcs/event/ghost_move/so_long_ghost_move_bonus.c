/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ghost_move_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 20:56:00 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:06:34 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ghost_move_bonus(t_engine *engine)
{
	if (BONUS == true)
		set_ghost_move_bonus(engine);
}
