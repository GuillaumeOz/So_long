/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:45:48 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:52:30 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_exit	*malloc_exit(t_application *app,
	char *path_close, char *path_open, t_int_vector2 coord)
{
	t_exit	*exit;

	exit = (t_exit *)malloc(sizeof(t_exit));
	if (exit == NULL)
		so_long_error(ERROR_EXIT1, "t_exit can't be malloc");
	*exit = create_exit(app, path_close, path_open, coord);
	return (exit);
}

t_exit	create_exit(t_application *app,
	char *path_close, char *path_open, t_int_vector2 coord)
{
	t_exit			exit;
	t_int_vector2	tex;

	exit.app = app;
	exit.path_closed = ft_strdup(path_close);
	exit.path_open = ft_strdup(path_open);
	exit.coord = coord;
	tex = create_int_vector2(0, 0);
	exit.img_ptr_closed = mlx_xpm_file_to_image(app->mlx_ptr,
			path_close, &tex.x, &tex.y);
	if (exit.img_ptr_closed == NULL)
		so_long_error(ERROR_EXIT2,
			"mlx_xpm_file_to_image failed in create_exit");
	exit.img_ptr_open = mlx_xpm_file_to_image(app->mlx_ptr,
			path_open, &tex.x, &tex.y);
	if (exit.img_ptr_open == NULL)
		so_long_error(ERROR_EXIT3,
			"mlx_xpm_file_to_image failed in create_exit");
	exit.tex_resolution = create_int_vector2(tex.x, tex.y);
	exit.pixels_closed = (int *)mlx_get_data_addr(exit.img_ptr_closed,
			&(exit.bits_per_pixels), &(exit.size_line), &(exit.endian));
	exit.pixels_open = (int *)mlx_get_data_addr(exit.img_ptr_open,
			&(exit.bits_per_pixels), &(exit.size_line), &(exit.endian));
	return (exit);
}

void	destroy_exit(t_exit to_destroy)
{
	free(to_destroy.path_closed);
	free(to_destroy.path_open);
	mlx_destroy_image(to_destroy.app->mlx_ptr, to_destroy.img_ptr_closed);
	mlx_destroy_image(to_destroy.app->mlx_ptr, to_destroy.img_ptr_open);
}

void	free_exit(t_exit *to_free)
{
	destroy_exit(*to_free);
	free(to_free);
}
