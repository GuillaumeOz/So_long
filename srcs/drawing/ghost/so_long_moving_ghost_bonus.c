/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_moving_ghost_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:47:48 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:16:03 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_moving_ghost_pixel(t_application *app, int x, int y,
	t_color color)
{
	t_image	*image;
	char	*tmp;

	if (x < 0 || x > app->resolution.x
		|| y < 0 || y > app->resolution.y)
		return ;
	if (color.r == 0 && color.g == 0
		&& color.b == 0 && color.a == 0)
		return ;
	image = app->image;
	tmp = image->pixels + (y * image->size_line + x
			* (image->bits_per_pixels / 8));
	tmp[RED_COMP] = color.r;
	tmp[GREEN_COMP] = color.g;
	tmp[BLUE_COMP] = color.b;
	tmp[ALPHA_COMP] = color.a;
}

static void	offset_calc(t_ghost *ghost, int *index, int x, int y)
{
	float	offset;

	offset = ghost->animation / 16;
	*index = (128 * y + offset * 16 + x);
	if (ghost->animation == 128)
		ghost->animation = 0;
}

static void	draw_moving_ghost_texture(t_engine *engine, t_ghost *ghost,
	float start_x, float start_y)
{
	t_color			color;
	int				index;
	int				x;
	int				y;

	y = 0;
	start_x *= (engine->app->resolution.x / engine->map_size_x);
	start_y *= (engine->app->resolution.y / engine->map_size_y);
	while (y < (engine->app->resolution.y / engine->map_size_y))
	{
		x = 0;
		while (x < (engine->app->resolution.x / engine->map_size_x))
		{
			offset_calc(ghost, &index, x, y);
			color = int_to_color(ghost->pixels[index]);
			put_moving_ghost_pixel(engine->app,
				(int)start_x + x, (int)start_y + y, color);
			x++;
		}
		y++;
	}
	ghost->animation += 2;
}

static t_ghost	*ghost_selector(t_engine *engine, char c)
{
	if (c == 'B')
		return (engine->ghost_blue);
	else if (c == 'G')
		return (engine->ghost_green);
	else if (c == 'O')
		return (engine->ghost_orange);
	else if (c == 'R')
		return (engine->ghost_red);
	else if (c == 'Y')
		return (engine->ghost_yellow);
	return (engine->ghost_blue);
}

void	moving_ghost_render_bonus(t_engine *engine)
{
	t_ghost	*ghost;
	t_list	*map;
	char	*line;
	int		x;
	int		y;

	y = 0;
	map = engine->map;
	while (y < engine->map_size_y)
	{
		x = 0;
		while (x < engine->map_size_x)
		{
			line = list_at(map, y);
			if (ft_ischar("BGORY", line[x]) == true)
			{
				ghost = ghost_selector(engine, line[x]);
				draw_moving_ghost_texture(engine, ghost, x, y);
			}
			x++;
		}
		y++;
	}
}
