/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_floor_render.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:34:13 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:29:11 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_floor_pixel(t_application *app, int x, int y,
	t_color color)
{
	t_image			*image;
	char			*tmp;

	if (x < 0 || x > app->resolution.x
		|| y < 0 || y > app->resolution.y)
		return ;
	image = app->image;
	tmp = image->pixels + (y * image->size_line + x
			* (image->bits_per_pixels / 8));
	tmp[RED_COMP] = color.r;
	tmp[GREEN_COMP] = color.g;
	tmp[BLUE_COMP] = color.b;
	tmp[ALPHA_COMP] = color.a;
}

void	draw_floor_texture(t_engine *engine, t_env	*env,
	int start_x, int start_y)
{
	t_color	color;
	int		x;
	int		y;

	y = 0;
	while (y < env->tex_resolution.y)
	{
		x = 0;
		while (x < env->tex_resolution.x)
		{
			color = int_to_color(env->pixels_floor[env->tex_resolution.y
					* y + x]);
			put_floor_pixel(engine->app, x + start_x, y + start_y, color);
			x++;
		}
		y++;
	}
}

void	floor_render(t_engine *engine)
{
	t_env	*env;
	int		x;
	int		y;

	env = engine->env;
	y = 0;
	while (y < env->app->resolution.y)
	{
		x = 0;
		while (x < env->app->resolution.x)
		{
			draw_floor_texture(engine, env, x, y);
			x += env->tex_resolution.x;
		}
		y += env->tex_resolution.y;
	}
}
