NAME = cub3D

CC = cc

CFLAGS = -Ofast -Wall -Werror -Wextra -g
# CFLAGS =  -fsanitize=address
MLX = ../minilibx/libmlx.a
SRCS = main.c ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c parse_map.c utils.c render_scene.c key_events.c render_loop.c update.c draw.c draw_tools.c  rays.c cube_utils.c utils_2.c draw_2.c update_utils.c rays_2.c rays_3.c sprite.c t_node.c gun.c key_events_2.c render_scene_2.c render_loop_2.c utils_3.c draw_3.c parse_map_utils.c texture_loaders.c sprite_utils.c sprite_sort_utils.c sprite_shooting_biz.c sprite_visibility.c utils_4.c parse_map_utils2.c
LIBFT = ../libft/libft.a

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(MLX) $(OBJ) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o:%.c cube3d.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C ../libft/

clean:
	@make fclean -C ../libft/
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(NAME_B)

re: fclean all
