/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_t_collectible.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:47 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/05 16:41:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_T_COLLECTIBLE_H
# define SO_LONG_T_COLLECTIBLE_H

typedef struct s_collectible
{
	t_application	*app;
	char			*path;
	t_int_vector2	coord;
	int				animation;
	t_int_vector2	tex_resolution;
	void			*img_ptr;
	int				*pixels;
	int				bits_per_pixels;
	int				size_line;
	int				endian;
}				t_collectible;

t_collectible	*malloc_collectible(t_application *app,
					char *path, t_int_vector2 coord);
t_collectible	create_collectible(t_application *app,
					char *path, t_int_vector2 coord);
void			destroy_collectible(t_collectible to_destroy);
void			free_collectible(t_collectible *to_free);

#endif