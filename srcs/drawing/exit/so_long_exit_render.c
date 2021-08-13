/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_exit_render.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:21:40 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:27:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_render(t_engine *engine)
{
	if (check_win_condition(engine) == true)
		opened_exit_render(engine);
	else
		closed_exit_render(engine);
}
