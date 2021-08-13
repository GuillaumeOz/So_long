# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 14:46:10 by gozsertt          #+#    #+#              #
#    Updated: 2021/08/07 13:00:23 by gozsertt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        	=   so_long

CC          	=   gcc

SRC_DIR			= 	$(shell find srcs -type d)
INC_DIR			= 	$(shell find includes -type d) \
					$(shell find lib/mlx -type d) \
					$(shell find lib/libft/includes -type d)
LIB_DIR			=	lib/libft lib/mlx
OBJ_DIR			=	obj

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

LINUXFLAG	=	-lm -lX11 -lXext

# library -----------------------------------------------------------

LIB			=	ft mlx_Linux

SRC			= 	so_long.c  so_long_engine.c   so_long_color_manipulation.c 										\
				so_long_color.c   so_long_env.c   so_long_exit.c   so_long_player.c   							\
				so_long_collectible.c   so_long_ghost.c   so_long_error.c   so_long_lose.c   					\
				so_long_load_basic.c  so_long_analyse_map.c  so_long_load_ghost_bonus.c  						\
				so_long_parse_map.c  so_long_check_arguments.c  so_long_parsing.c  								\
				so_long_load_bonus.c  so_long_load_map_information.c   so_long_application_handler.c  			\
				so_long_application_pixels.c  so_long_application.c   so_long_floor_render.c   					\
				so_long_exit_render.c  so_long_opened_exit_render.c  so_long_closed_exit_render.c   			\
				so_long_player_render.c  so_long_static_player_render.c  										\
				so_long_moving_player_render_bonus.c   so_long_collectible_render.c  							\
				so_long_static_collectible_render.c  so_long_moving_collectible_render_bonus.c   				\
				so_long_wall_render.c   so_long_display_terminal_move.c  so_long_screen_move_bonus.c   			\
				so_long_ghost_render.c  so_long_moving_ghost_bonus.c   so_long_routine.c   so_long_image.c   	\
				so_long_check_win_condition.c  so_long_win.c   so_long_event_manager.c   so_long_player_move.c	\
				so_long_ghost_move_bonus.c  so_long_ghost_moving_bonus.c  so_long_set_ghost_move_bonus.c  		\
				so_long_key_press.c  so_long_key_release.c

OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

OBJ_BONUS	=	$(addprefix $(OBJ_DIR_BONUS)/, $(SRC:%.c=%.o))

# Compilation flags -------------------------------------------------

CFLAGS		=	-Wall -Wextra -Werror

D_NO_BONUS  =	-DBONUS=0

D_BONUS		=	-DBONUS=1

IFLAGS		=	$(foreach dir, $(INC_DIR), -I $(dir))

LFLAGS		=	$(foreach dir, $(LIB_DIR), -L $(dir)) \
				$(foreach lib, $(LIB), -l $(lib)) \
				$(LINUXFLAG)

# Colors ------------------------------------------------------------

_GREY	=	$'\e[30m
_RED	=	$'\e[31m
_GREEN	=	$'\e[32m
_YELLOW	=	$'\e[33m
_BLUE	=	$'\e[34m
_PURPLE	=	$'\e[35m
_CYAN	=	$'\e[36m
_WHITE	=	$'\e[37m

# main part ---------------------------------------------------------

all:
	@echo "\n$(_BLUE)___$(NAME) Setting___\n$(_WHITE)"
	@make BONUS=$(D_NO_BONUS) $(NAME)

bonus: fclean
	@echo "\n$(_BLUE)___$(NAME) Setting___\n$(_WHITE)"
	@make BONUS=$(D_BONUS) $(NAME)

show:
	@echo "$(_BLUE)SRC :\n$(_YELLOW)$(SRC)$(_WHITE)"
	@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)$(_WHITE)"
	@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"
	@echo "$(_BLUE)IFLAGS :\n$(_YELLOW)$(IFLAGS)$(_WHITE)"
	@echo "$(_BLUE)LFLAGS :\n$(_YELLOW)$(LFLAGS)$(_WHITE)"
	@echo "$(_BLUE)LIB_DIR :\n$(_YELLOW)$(LIB_DIR)$(_WHITE)"
	@echo "\n-----\n"
	@echo "$(_BLUE)Compiling : \n$(_YELLOW)$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)$(_WHITE)"

install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir);)

re-install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir) re;)

fclean-install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir) fclean;)

$(NAME): install $(OBJ)
	@echo "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
	@$(CC) $(CFLAGS) $(BONUS) $(OBJ) $(LFLAGS) -o $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

$(OBJ_DIR)/%.o : %.c
	@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(BONUS) $(IFLAGS) -o $@ -c $<
	@echo "$(_GREEN)DONE$(_WHITE)"

re:	fclean all

clean:
	@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
	@$(foreach file, $(OBJ), rm -rf $(file))
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:	clean
	@echo "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
	@rm -f $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all bonus show install re-install re clean flcean