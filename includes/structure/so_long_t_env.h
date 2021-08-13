/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_t_env.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:44:50 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/04 17:33:42 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_T_ENV_H
# define SO_LONG_T_ENV_H

typedef struct s_env
{
	t_application	*app;
	char			*floor;
	char			*wall;
	t_int_vector2	coord;
	t_int_vector2	tex_resolution;
	void			*img_ptr_floor;
	void			*img_ptr_wall;
	int				*pixels_floor;
	int				*pixels_wall;
	int				bits_per_pixels;
	int				size_line;
	int				endian;
}				t_env;

t_env		*malloc_env(t_application *app, char *floor, char *wall);
t_env		create_env(t_application *app, char *floor, char *wall);
void		destroy_env(t_env to_destroy);
void		free_env(t_env *to_free);

#endif