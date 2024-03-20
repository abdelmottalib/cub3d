/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:35:03 by samini            #+#    #+#             */
/*   Updated: 2023/06/12 11:34:48 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/fcntl.h>
# include <unistd.h>

# define W 13
# define S 1
# define A 0
# define D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_FORWARD 126
# define KEY_BACKWARD 125
# define ENTER 36
# define ESC 53
# define M 46
# define PLUS 69
# define MINUS 78
# define TILE 64
# define BACK 51
# define TICK 50
# define C 8
# define SLASH 44
# define SPACE 49
# define COLLISION_DISTANCE 10
# define DOOR_DISTANCE 100
# define TEXTURE_WIDTH 64
# define COS 0.5
# define SIN 0.8660254
# define NUM_SPRITES 1
# define FOV_ANGLE 60
# define SPR_CENTER_OFFSET 0.5
# define MARGIN 0.2
# define NUM_ANIMATIONS 10
# define GUN_ANIMATIONS 19
# define GUN_X 0
# define GUN_Y 112
# define CONSTANT 70944.801078

typedef enum e_texture_type
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	DOOR
}					t_texture_type;
typedef enum e_options
{
	IN_GAME,
	IN_OPTIONS,
	IN_SETTINGS
}					t_options;

typedef enum e_collision_type
{
	NO_COLLISION,
	WALL_COLLISION,
	DOOR_COLLISION
}					t_collision_type;

typedef struct s_calculations
{
	double			sprite_height;
	double			sprite_width;
	double			sprite_topy;
	double			sprite_boty;
	double			sprite_angle;
	double			sprite_screen_posx;
	double			sprite_leftx;
	double			sprite_rightx;
	int				texture_width;
	int				texture_height;
	double			texel_width;
	int				texture_offset_x;
	int				texture_offset_y;
	int				dist_from_top;
}					t_calculations;
typedef struct s_node
{
	char			*data;
	struct s_node	*next;
}					t_node;
typedef struct s_infos
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	unsigned int	*array;
	int				h;
	int				w;
}					t_infos;
typedef struct s_mlx_vars
{
	void			*mlx;
	void			*mlx_win;
	void			*image_paint;
}					t_mlx_vars;
typedef struct s_map
{
	char			**map;
	int				n_col;
	int				n_rows;
}					t_map;
typedef struct s_player
{
	double			x;
	double			y;
	double			td;
	double			wd;
	double			ra;
	double			ms;
	double			rs;
	bool			sideways;
	bool			mouse_toggle;
	char			direction;
}					t_player;
typedef struct s_ray
{
	double			ra;
	double			x;
	int				zx;
	double			y;
	double			dist;
	bool			door_flag;
	bool			door_flag_h;
	bool			door_flag_v;
	bool			hit_vert;
	bool			hit_hotiz;
	bool			down;
	bool			up;
	bool			right;
	bool			left;
	int				text_color;
	t_texture_type	type;
	struct s_ray	*next;
}					t_ray;
typedef struct s_game_dims
{
	int				win_width;
	int				win_height;
	double			m_scale;
}					t_game_dims;
typedef struct s_horiz
{
	double			x;
	double			y;
	double			nx;
	double			ny;
	double			dist;
	bool			found;
}					t_horiz;
typedef struct s_square
{
	double			start_y;
	double			start_x;
	double			end_x;
	double			end_y;
	double			curr_x;
	double			curr_y;
}					t_square;
typedef struct line_vars
{
	double			curr_player_x;
	double			curr_player_y;
	double			deltax;
	double			deltay;
	double			pixely;
	double			pixelx;
	int				pixels;
}					t_line_vars;
typedef struct s_vert
{
	double			x;
	double			y;
	double			nx;
	double			ny;
	double			dist;
	bool			found;
}					t_vert;
typedef struct s_hit_coord
{
	double			xs;
	double			ys;
	double			xi;
	double			yi;
	double			tan_theta;
	t_horiz			horiz;
	t_vert			vert;
}					t_hit_coord;
typedef struct s_color
{
	int				floor;
	int				ceiling;
}					t_color;
typedef struct s_3d
{
	double			ray_distance;
	double			plane_dist;
	double			wall_height;
	int				center;
	int				g;
	int				text_offs_x;
	int				text_offs_y;
}					t_3d;
typedef struct s_const
{
	double			deg2rad;
	double			fov;
}					t_const;
typedef struct s_temp
{
	double			min_x;
	double			prev_min_x;
	double			prev_min_y;
	double			min_y;
}					t_temp;
typedef struct s_circle
{
	double			center_x;
	double			center_y;
	int				radius;
}					t_circle;
typedef struct s_menu
{
	char			*label;
	int				x;
	int				y;
}					t_menu;
typedef struct s_sprite
{
	double			x;
	double			y;
	double			distance;
	double			angle;
	bool			is_visible;
	bool			is_within_range;
	bool			is_shootable;
	bool			is_dead;
	t_infos			texture[NUM_ANIMATIONS];
	t_infos			texture_dead[NUM_ANIMATIONS];
	int				ptr;
	struct s_sprite	*next;
}					t_sprite;
typedef struct s_minimap
{
	double			player_x;
	double			player_y;
	int				map_height;
	int				map_width;
	double			min_x;
	double			max_x;
	double			min_y;
	double			max_y;
}					t_minimap;
typedef struct s_data
{
	t_game_dims		game_dims;
	t_mlx_vars		mlx_v;
	t_map			map_v;
	t_infos			txtr[5];
	t_sprite		*sprite_node;
	t_infos			paint;
	t_player		player;
	t_ray			*ray;
	t_hit_coord		coord;
	t_color			color;
	t_minimap		mp;
	t_3d			infos;
	t_temp			temp;
	t_const			constants;
	t_menu			menu[3];
	t_menu			settings[4];
	int				draw_door;
	t_options		game_flag;
	int				shadow_flag;
	void			**frames;
	int				resolutions[4][2];
	int				door_closed;
	int				test;
	int				anim_ptr;
	bool			is_shooting;
	t_infos			gun_txtr[GUN_ANIMATIONS];
	int				gun_ptr;
	double			zbuffer[20000];
}					t_data;

// utils
void				free_bins(char **arr);
bool				has_wall(t_data *data, double new_x, double new_y);
bool				has_wall_ray(t_data *data, double new_x, double new_y,
						t_ray *ray);
double				compare(bool expression, double exp_true, double exp_false);
double				calc_distance(double x0, double y0, double x1, double y1);
int					make_color(int red, int green, int blue);
t_collision_type	check_collision(t_data *data, double new_x, double new_y);
bool				touch_horiz_extremity(t_data *data);
bool				touch_vert_extremity(t_data *data);
void				update_resolution(t_data *data);
void				load_door_frames(t_data *data);
char				**nodes_to_array(t_node *head, size_t max);
void				free_nodes(t_node *head);
void				append_node(t_node **head, t_node *node);
t_node				*new_node(char *data);

// parsing
void				parse_map(char *file, t_data *data);

// render_scene
void				render_scene(t_data *data);
void				init_constants(t_data *data);

// hooks
int					key_check(int keycode, t_data *data);
int					key_release(int keycode, t_data *data);
int					mouse_hook(int x, int y, t_data *data);
int					ft_close(void);
void				toggle_mouse(t_data *data);

// render_loop
int					render_loop(t_data *data);

// update
void				update_walk_and_turn(t_data *data);
void				check_door(t_data *data);
void				cast_rays(t_data *data);
void				check_walls(t_data *data, double new_x, double new_y,
						bool *wall_check);
void				check_sliding(t_data *data, double new_x, double new_y,
						bool *wall_check);
bool				slide_vert(t_data *data, double new_y);
bool				slide_horiz(t_data *data, double new_x);
void				limit_speed(t_data *data);

// draw
void				draw_map(t_data *data);
t_collision_type	door_animation(t_data *data, int map_x, int map_y);
void				draw_map(t_data *data);
void				draw_square(t_data *data, double x, double y, int color);
void				my_mlx_pixel_put(t_data *data, int x, int y,
						unsigned int color);
void				draw_line(t_data *data, double endx, double endy,
						int color);
void				draw_rays(t_data *data);
void				draw_walls(t_data *data);
void				initial_calc(t_data *data, t_ray *ray);
void				draw_ceiling(t_data *data, int i);
void				trump_walls(t_data *data, t_ray *ray, int i);
void				renderMenu(t_data *data);
void				calc_offs_x(t_data *data, t_ray *ray);
void				trump_walls_2(t_data *data, t_ray *ray, int i);
void				draw_floor(t_data *data, int i);
void				brightness(t_ray *ray);
bool				can_walk(t_data *data, double new_x, double new_y);

// init
void				init_player_position(t_data *data, int x, int y);

// rays
void				ray_cast(t_data *data, t_ray *ray, int flag);
bool				touch_horiz_extremity(t_data *data);
bool				touch_vert_extremity(t_data *data);
void				check_horizontal(t_data *data, t_ray *ray);
void				finding_horiz_wallhit_x_y(t_data *data, t_ray *ray);
void				finding_horiz_xstep_ystep(t_data *data, t_ray *ray);
void				finding_horiz_xinter_yinter(t_data *data, t_ray *ray);
t_ray				*ft_lstnew_ray(double new);
t_ray				*ft_lstlast_ray(t_ray *lst);
void				ft_lstadd_back_ray(t_ray **lst, t_ray *new);
void				ft_lstdelone_ray(t_ray *lst, void (*del)(void *));
void				ft_lstclear_ray(t_ray **lst, void (*del)(void *));
void				finding_vert_xinter_yinter(t_data *data, t_ray *ray);
void				finding_vert_wallhit_x_y(t_data *data, t_ray *ray);
void				finding_vert_xstep_ystep(t_data *data, t_ray *ray);
void				check_vertical(t_data *data, t_ray *ray);
void				compare_horiz_vert(t_data *data, t_ray *ray);
void				check_vertical(t_data *data, t_ray *ray);
void				finding_vert_xinter_yinter(t_data *data, t_ray *ray);
void				finding_vert_xstep_ystep(t_data *data, t_ray *ray);
void				finding_vert_wallhit_x_y(t_data *data, t_ray *ray);
void				horiz_distance(t_data *data);
void				vert_distance(t_data *data);
void				smallest_distance(t_data *data, t_ray *ray);
void				door_hit(t_data *data, t_ray *ray);
void				compare_horiz_vert(t_data *data, t_ray *ray);
void				draw_sprites(t_data *data);
void				draw_map_sprites(t_data *data);
t_sprite			*new_sprite_node(int x, int y, t_data *data);
void				append_sprite_node(t_sprite **head, t_sprite *node);
void				shoot_gun(t_data *data);
void				draw_gun(t_data *data);
// keys
void				movement_keys(t_data *data, int keycode);
void				navigation_keys(t_data *data, int keycode);
void				settings_keys(t_data *data, int keycode);
// init
void				init_constants(t_data *data);
void				init_settings(t_data *data);
void				init_scene(t_data *data);
// render_loop_2
void				options_menu(t_data *data);
void				render_menu(t_data *data);
void				render_settings(t_data *data);
// utils
void				load_door_frames(t_data *data);
t_collision_type	door_animation(t_data *data, int map_x, int map_y);
t_collision_type	check_collision(t_data *data, double new_x, double new_y);
// draw
void				init_minimap(t_data *data);
void				draw_map(t_data *data);
bool				has_sprite(t_data *data, double new_x, double new_y);
bool				has_wall_check(t_data *data, double new_x, double new_y);
bool				can_walk(t_data *data, double new_x, double new_y);
void				prepare_gun(t_data *data);
// parser utils
bool				is_empty_line(char *line);
bool				ft_isspace(int c);
bool				ft_isvalid(int c);
void				check_extension(char *s);
void				get_data(t_data *data, char **arr, bool texture[4],
						bool flceil[2]);
void				check_4sides(char **map, int i, int j);
void				sort_sprites(t_sprite **head);
unsigned int		*get_color_buffer(t_data *data, t_sprite *sprite);
void				increment_anim_dead(t_sprite *sprite);
void				check_shootable(t_data *data, t_sprite *sprite,
						t_calculations c);
void				check_sprite_visibility(t_data *data, double playerx,
						double playery);
void				render_visible_sprites(t_data *data, double playerx,
						double playery);
t_calculations		store_calculations(t_data *data, t_sprite *sprite,
						double playerx, double playery);
void				init_textures(bool *texture, bool *flceil);
bool				check_texture(bool *texture, bool *flceil);
int					mouse_hook_2(int button, int x, int y, t_data *data);
int					handle_mouse_release(int button, int x, int y,
						t_data *data);
void				initial_calc(t_data *data, t_ray *ray);
void				calc_offs_x(t_data *data, t_ray *ray);
void				check_player_existence(bool has_player);
void				sanitize_lines(t_node *node);
void				check_xpm(t_data *data, char *path);
bool				is_empty_line_safe(char *line);
void				check_boundaries(t_node *node, bool *in_map);
void				check_begin_end(char *line);
#endif
