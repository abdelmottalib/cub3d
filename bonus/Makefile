NAME = cub3D

CC = cc

CFLAGS = -Ofast -Wall -Werror -Wextra -g
# CFLAGS =  -fsanitize=address
MLX = ../minilibx/libmlx.a
SRCS = main_bonus.c ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c parse_map_bonus.c utils_bonus.c render_scene_bonus.c key_events_bonus.c render_loop_bonus.c update_bonus.c draw_bonus.c draw_tools_bonus.c  rays_bonus.c cube_utils_bonus.c utils_2_bonus.c draw_2_bonus.c update_utils_bonus.c rays_2_bonus.c rays_3_bonus.c sprite_bonus.c t_node_bonus.c gun_bonus.c key_events_2_bonus.c render_scene_2_bonus.c render_loop_2_bonus.c utils_3_bonus.c draw_3_bonus.c parse_map_utils_bonus.c texture_loaders_bonus.c sprite_utils_bonus.c sprite_sort_utils_bonus.c sprite_shooting_biz_bonus.c sprite_visibility_bonus.c utils_4_bonus.c parse_map_utils2_bonus.c
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
