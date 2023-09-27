# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 13:47:48 by chonorat          #+#    #+#              #
#    Updated: 2023/09/27 18:18:15 by chonorat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLOR
_GREEN = \033[92m
_YELLOW = \033[33m
_RED = \033[31m

#POLICE
_END = \033[0m
_BOLD = \033[1m

NAME = so_long
CC = @cc
RM = @rm -rf
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L ./minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz
MLX = minilibx-linux/libmlx.a
HEADER = Includes/so_long.h
LIBFT = libft/libft.a
MAKE_LIBFT = @make -C libft
CLEAN_LIBFT = @make clean -C libft
FCLEAN_LIBFT = @make fclean -C libft
MAKE_MLX = @make -C minilibx-linux
CLEAN_MLX = @make clean -C minilibx-linux
DIR = @mkdir -p
PRINT = @echo
FILES = so_long\
		Mlx/mlx_window\
		Mlx/list_utils\
		Mlx/get_hook\
		Mlx/image_utils\
		Parsing/init_data\
		Parsing/get_map\
		Parsing/check_map\
		Parsing/is_accessible\
		Parsing/accessible_path\
		Parsing/get_mask\
		Print/print_assets\
		Print/print_walls\
		Print/print_player\
		Print/print_hearts\
		Print/print_exit\
		Print/print_ennemy\
		Print/print_tree\
		Print/is_water\
		Print/is_tree\
		Print/print_move\
		Movement/move_player\
		Movement/ennemy_position\
		Movement/ennemy_movement\
		Exit/free_data\
		Exit/exit_message\
		Exit/show_error
SRCS = $(addsuffix .c, $(addprefix Sources/, $(FILES)))
OBJS = $(addsuffix .o, $(addprefix Objects/, $(FILES)))

$(NAME): $(OBJS)
	$(PRINT) "\n${_YELLOW}Checking Libft...${_END}"
	$(MAKE_LIBFT)
	$(PRINT) "\n${_YELLOW}Making MLX Library...${_END}"
	$(MAKE_MLX)
	$(PRINT) "${_BOLD}${_GREEN}MLX ready.${_END}"
	$(PRINT) "\n${_YELLOW}Making so_long...${_END}"
	$(CC) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	$(PRINT) "${_BOLD}${_GREEN}so_long done.${_END}"

Objects/%.o: Sources/%.c Makefile $(HEADER)
	$(DIR) Objects
	$(DIR) Objects/Exit Objects/Mlx Objects/Movement Objects/Parsing Objects/Print
	$(PRINT) "Compiling ${_BOLD}$<$(_END)..."
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

clean:
	$(CLEAN_LIBFT)
	$(PRINT) "\n${_BOLD}Cleaning Objects...${_END}"
	$(RM) $(OBJS)
	$(PRINT) "${_BOLD}${_GREEN}Objects cleaned.${_END}"

fclean:
	$(PRINT) "\n${_BOLD}Cleaning MLX...${_END}"
	$(CLEAN_MLX)
	$(PRINT) "${_GREEN}MLX cleaned.\n${_END}"
	$(FCLEAN_LIBFT)
	$(PRINT) "\n${_BOLD}Cleaning Objects...${_END}"
	$(RM) $(OBJS)
	$(PRINT) "${_RED}Deleting so_long...${_END}"
	$(RM) $(NAME)
	$(PRINT) "${_RED}Deleting Objects directory...${_END}"
	$(RM) Objects
	$(PRINT) "${_GREEN}Objects cleaned.${_END}"
	$(PRINT) "${_GREEN}So_long deleted.${_END}"
	$(PRINT) "${_GREEN}Objects directory deleted.\n${_END}"

re: fclean all

.PHONY: all clean fclean re