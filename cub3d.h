/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:32:45 by naal-jen          #+#    #+#             */
/*   Updated: 2023/06/17 19:29:30 by naal-jen         ###   ########.fr       */
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

# define W		119
# define A		97
# define S		115
# define D		100
# define LEFT	65361
# define RIGHT	65363

# define MOVE_SPEED 0.08
# define ROTATE_SPEED 0.048

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

	unsigned long	pavimento;
	unsigned long	soffitto;

	t_key			key;
	t_ray			ray;
	t_wall			wall[4];
	t_img			image;
}		t_mlx;

/* --------------------------------- main.c --------------------------------- */
int				quit(t_mlx *vlx);

/* --------------------------- parse/main_parse.c --------------------------- */
int				colors(char *line, t_mlx *vlx);
void			walls_fill(char **str_split, t_mlx *vlx, int n);
int				walls(char **line, t_mlx *vlx);
int				parse_map_and_walls_and_colors(int fd, t_mlx *vlx);
int				parse_input(char *file, t_mlx *vlx);

/* ---------------------------- parse/map_parse.c --------------------------- */
int				map_checker(char *line, t_mlx *vlx);
int				map(int fd, t_mlx *vlx);
void			quite_1(t_mlx *vlx, int fd);
void			evil_line(int fd);

/* --------------------------- init/init_values.c --------------------------- */
int				init_walls(t_mlx *vlx);
void			set_val_1(double dir_x, double dir_y, double pla_y, t_mlx *vlx);
void			init_vectors(int x, int y, int *count, t_mlx *vlx);
int				init_values(t_mlx *vlx);

/* ------------------------------ init/colors.c ----------------------------- */
int				is_color(char **arr);
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
int				new_quit(t_mlx *vlx);

/* -------------------------- raycasting/distance.c ------------------------- */
void			calculate_the_distance_to_the_next_x_or_y_side(t_mlx *vlx);
void			calculate_the_step_and_initial_side_distance_x(t_mlx *vlx);
void			calculate_the_step_and_initial_side_distance_y(t_mlx *vlx);
void			set_texture(t_mlx *vlx);
void			perform_digital_differential_analysis(t_mlx *vlx);

/* ----------------------- raycasting/calculate_line.c ---------------------- */
void			calculate_distance_projected_on_camera_direction(t_mlx *vlx);
void			calculate_draw_start_and_draw_end(t_mlx *vlx);
void			calculate_texture_x(t_mlx *vlx);
void			draw_stripe_color_pixel(int i, t_mlx *vlx);

/* --------------------------------- move.c --------------------------------- */
void			move_forward(t_mlx *vlx);
void			move_backwards(t_mlx *vlx);
void			move_left(t_mlx *vlx);
void			move_right(t_mlx *vlx);
void			rotate_right(t_mlx *vlx);

/* ----------------------------- rotate_print.c ----------------------------- */
void			print_pavimento_soffitto(t_mlx *vlx);
void			rotate_left(t_mlx *vlx);
int				check_boarders_helper(int i, int j, t_mlx *vlx);
int				check_boarders(t_mlx *vlx);
int				new_quit_2(t_mlx *vlx);

#endif