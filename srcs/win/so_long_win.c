/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:44:19 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/05 19:08:26 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win(t_engine *engine)
{
	if (check_win_condition(engine) == true)
	{
		free_engine(engine);
		printf("Congratulations you won !\n");
		exit(EXIT_SUCCESS);
	}
}
