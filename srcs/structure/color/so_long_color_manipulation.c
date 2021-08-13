/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_color_manipulation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:01:04 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/05 16:50:24 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_color	int_to_color(int to_convert)
{
	t_color	color;

	color.r = ((to_convert & RED_MASK) >> 16);
	color.g = ((to_convert & GREEN_MASK) >> 8);
	color.b = to_convert & BLUE_MASK;
	color.a = ((to_convert & ALPHA_MASK) >> 24);
	return (color);
}
