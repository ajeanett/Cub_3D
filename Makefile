NAME = cub3D

SRC_DIR = src/
OBJ_DIR = obj/
LIBFT_DIR = libft/
MLX_DIR = minilibx_mms/

INCLUDES = -I includes/ -I libft/ -I minilibx_mms/

CC = gcc
FLAGS = -Wall -Wextra -Werror

FRWRKS	= -framework OpenGL -framework AppKit
MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit 
LIBS = libft.a libmlx.dylib

SRCS = bmp.c \
		error.c \
		find_save.c \
		floor_sky.c \
		floor_sky2.c \
		get_next_line_utils.c \
		get_next_line.c \
		init_player.c \
		init_tex.c \
		init_tex2.c \
		main.c \
		make_map.c \
		map_verification.c \
		move.c \
		move2.c \
		parser_map.c \
		parser_map2.c \
		raycasting.c \
		sprite.c \
		sprite2.c \
		textures.c \
		utils.c \
		utils2.c

SRC = $(addprefix $(SRC_DIR), $(SRCS))

OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME):  $(OBJ)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR) bonus
	@make -C $(LIBFT_DIR)
	@cp $(MLX_DIR)libmlx.dylib ./
	@cp $(LIBFT_DIR)libft.a ./
	$(CC) ${FLAGS} $(INCLUDES) ${FRWRKS} $(OBJ) -o $(NAME) $(LIBS)

$(OBJ): $(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@rm -f *.bmp

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@rm -f libft.a
	@rm -f libmlx.dylib

re: fclean all

.PHONY: all clean fclean run re
