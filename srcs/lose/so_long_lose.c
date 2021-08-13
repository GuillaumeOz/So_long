/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_lose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:08:45 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/05 19:09:50 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lose(t_engine *engine)
{
	free_engine(engine);
	printf("You are dead...\n");
	exit(EXIT_SUCCESS);
}
