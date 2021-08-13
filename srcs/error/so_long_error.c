/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:41:37 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/05 20:38:17 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long_error(t_so_long_error error, char *error_msg)
{
	printf("Error\n(%d) ", error);
	printf("%s\n", error_msg);
	exit(error);
}
