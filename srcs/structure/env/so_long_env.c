/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:53:21 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:53:30 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_env	*malloc_env(t_application *app, char *floor, char *wall)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (env == NULL)
		so_long_error(ERROR_ENV1, "t_env can't be malloc");
	*env = create_env(app, floor, wall);
	return (env);
}

t_env	create_env(t_application *app, char *floor, char *wall)
{
	t_env			env;
	t_int_vector2	tex;

	env.app = app;
	env.floor = ft_strdup(floor);
	env.wall = ft_strdup(wall);
	tex = create_int_vector2(0, 0);
	env.img_ptr_floor = mlx_xpm_file_to_image(app->mlx_ptr,
			floor, &tex.x, &tex.y);
	if (env.img_ptr_floor == NULL)
		so_long_error(ERROR_ENV2,
			"mlx_xpm_file_to_image failed in create_env");
	env.img_ptr_wall = mlx_xpm_file_to_image(app->mlx_ptr,
			wall, &tex.x, &tex.y);
	if (env.img_ptr_wall == NULL)
		so_long_error(ERROR_ENV3,
			"mlx_xpm_file_to_image failed in create_env");
	env.tex_resolution = create_int_vector2(tex.x, tex.y);
	env.pixels_floor = (int *)mlx_get_data_addr(env.img_ptr_floor,
			&(env.bits_per_pixels), &(env.size_line), &(env.endian));
	env.pixels_wall = (int *)mlx_get_data_addr(env.img_ptr_wall,
			&(env.bits_per_pixels), &(env.size_line), &(env.endian));
	return (env);
}

void	destroy_env(t_env to_destroy)
{
	free(to_destroy.floor);
	free(to_destroy.wall);
	mlx_destroy_image(to_destroy.app->mlx_ptr, to_destroy.img_ptr_floor);
	mlx_destroy_image(to_destroy.app->mlx_ptr, to_destroy.img_ptr_wall);
}

void	free_env(t_env *to_free)
{
	destroy_env(*to_free);
	free(to_free);
}
