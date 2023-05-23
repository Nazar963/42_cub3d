/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:32:45 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/23 17:49:04 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define ESC 65307
# define X_EVENT_EXIT 17

# define WALL_HEIGHT 64
# define WALL_WIDTH 64

# define MAP_WIDTH 24
# define MAP_HEIGHT 24

# define SCREEN_WIDTH 1500
# define SCREEN_HEIGHT 1000

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00

# define W		119
# define A		97
# define S		115
# define D		100
# define LEFT	65361
# define RIGHT	65363

typedef struct s_key
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	right;
	int	left;
}		t_key;

typedef struct s_ray
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	double			wall_x;
	double			step;
	double			text_pos;
	double			frame_time;
	double			move_speed;
	double			rotate_speed;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				text_num;
	int				text_y;
	int				text_x;
	unsigned int	color;
}		t_ray;

typedef struct s_wall
{
	void	*image;
	int		*add;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}		t_wall;

typedef struct s_img
{
	void	*image;
	char	*add;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}		t_img;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*address;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			**xpm;
	char			**rgb;
	char			**map;

	int				wall_dim[4][WALL_HEIGHT * WALL_WIDTH];

	unsigned long	pavimento;
	unsigned long	soffitto;

	t_key			key;
	t_ray			ray;
	t_wall			wall[4];
	t_img			image;
}		t_mlx;

/* --------------------------- parse/main_parse.c --------------------------- */
int				colors(char *line, t_mlx *vlx);
void			walls_fill(char **str_split, t_mlx *vlx, int n);
int				walls(char *line, t_mlx *vlx);
int				parse_map_and_walls_and_colors(int fd, t_mlx *vlx);
int				parse_input(char *file, t_mlx *vlx);

/* ---------------------------- parse/map_parse.c --------------------------- */
void			map_checker_helper_1(char *line, t_mlx *vlx);
int				map_checker(char *line, t_mlx *vlx);
int				map(int fd, t_mlx *vlx);

/* --------------------------- init/init_values.c --------------------------- */
void			fill_wall(int i, t_mlx *vlx);
int				init_walls(t_mlx *vlx);
void			set_val_1(double dir_x, double dir_y, double pla_y, t_mlx *vlx);
void			init_vectors(int x, int y, t_mlx *vlx);
void			init_values(t_mlx *vlx);

/* ------------------------------ init/colors.c ----------------------------- */
unsigned long	rgb_to_hex(int red, int green, int blue);
int				*is_color(char **arr);
void			convert_rgb(int *rgb, int i, t_mlx *vlx);
int				init_colors(t_mlx *vlx);

/* --------------------------- init/validate_map.c -------------------------- */
void			set_val(double dir_x, double dir_y, double pla_x, t_mlx *vlx);
int				check_char(t_mlx *vlx);
int				validate_map(t_mlx *vlx);

/* ------------------------------ utils/utils.c ----------------------------- */
char			**ft_realloc(char **pointer, int size);
int				strlen_arr(void **arr);
void			free_arr(void ***arr);
void			my_pixel_put(int x, int y, int color, t_mlx *vlx);

/* -------------------------- raycasting/distance.c ------------------------- */
void			delta_distance(t_mlx *vlx);
void			step_side_dist_x(t_mlx *vlx);
void			step_side_dist_y(t_mlx *vlx);
void			set_texture(t_mlx *vlx);
void			algorithm_dda(t_mlx *vlx);

/* ----------------------- raycasting/calculate_line.c ---------------------- */
void			calculate_distance_perspective(t_mlx *vlx);
void			calculate_draw_start_and_draw_end(t_mlx *vlx);
void			calculate_texture_x(t_mlx *vlx);
void			draw_vertical_texture_stripe(int i, t_mlx *vlx);

/* --------------------------------- move.c --------------------------------- */
void			player_move_forward(t_mlx *vlx);
void			player_move_backwards(t_mlx *vlx);
void			player_move_left(t_mlx *vlx);
void			player_move_right(t_mlx *vlx);
void			player_rotate_right(t_mlx *vlx);

/* ----------------------------- rotate_print.c ----------------------------- */
void			print_pavimento(t_mlx *vlx);
void			print_soffitto(t_mlx *vlx);
void			player_rotate_left(t_mlx *vlx);

#endif