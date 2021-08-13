/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_collectible.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:39:10 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:51:31 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_collectible	*malloc_collectible(t_application *app,
	char *path, t_int_vector2 coord)
{
	t_collectible	*collectible;

	collectible = (t_collectible *)malloc(sizeof(t_collectible));
	if (collectible == NULL)
		so_long_error(ERROR_COLLECTIBLE1, "t_collectible can't be malloc");
	*collectible = create_collectible(app, path, coord);
	return (collectible);
}

t_collectible	create_collectible(t_application *app,
	char *path, t_int_vector2 coord)
{
	t_collectible	collectible;
	t_int_vector2	tex;

	collectible.app = app;
	collectible.path = ft_strdup(path);
	collectible.coord = coord;
	collectible.animation = 0;
	tex = create_int_vector2(0, 0);
	collectible.img_ptr = mlx_xpm_file_to_image(app->mlx_ptr,
			path, &tex.x, &tex.y);
	if (collectible.img_ptr == NULL)
		so_long_error(ERROR_COLLECTIBLE2,
			"mlx_xpm_file_to_image failed in create_collectible");
	collectible.tex_resolution = create_int_vector2(tex.x, tex.y);
	collectible.pixels = (int *)mlx_get_data_addr(collectible.img_ptr,
			&(collectible.bits_per_pixels), &(collectible.size_line),
			&(collectible.endian));
	return (collectible);
}

void	destroy_collectible(t_collectible to_destroy)
{
	free(to_destroy.path);
	mlx_destroy_image(to_destroy.app->mlx_ptr, to_destroy.img_ptr);
}

void	free_collectible(t_collectible *to_free)
{
	destroy_collectible(*to_free);
	free(to_free);
}
