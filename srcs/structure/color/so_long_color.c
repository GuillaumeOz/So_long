/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:38:46 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/02 15:33:04 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_color	*malloc_color(t_uint8 p_r, t_uint8 p_g, t_uint8 p_b, t_uint8 p_a)
{
	t_color	*color;

	color = (t_color *)malloc(sizeof(t_color));
	if (color == NULL)
		so_long_error(ERROR_COLOR1, "Can't malloc t_color in constructor");
	*color = create_color(p_r, p_g, p_b, p_a);
	return (color);
}

t_color	create_color(t_uint8 p_r, t_uint8 p_g, t_uint8 p_b, t_uint8 p_a)
{
	t_color	result;

	result.r = p_r;
	result.g = p_g;
	result.b = p_b;
	result.a = p_a;
	return (result);
}

void	destroy_color(t_color to_destroy)
{
	(void)to_destroy;
}

void	free_color(t_color *to_free)
{
	destroy_color(*to_free);
	free(to_free);
}
