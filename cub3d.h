#ifndef CUB3D_H
# define CUB3D_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define ESC 53
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_EXIT 17

# define WALL_HEIGHT 64
# define WALL_WIDTH 64

# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480

#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define WHITE 0xFFFFFF
#define YELLOW 0xFFFF00

# define W		13
# define A		0
# define S		1
# define D		2
# define UP		126
# define DOWN	125
# define LEFT	123
# define RIGHT	124

typedef struct s_key
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	right;
	int	left;
	int	p;
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
}		t_mlx;

/* ------------------------------ main_parse.c ------------------------------ */
int	parse_map_and_walls_and_colors(int fd, t_mlx *vlx);
int	walls(char *line, t_mlx *vlx);
int	colors(char *line, t_mlx *vlx);
int	parse_input(char *file, t_mlx *vlx);

/* ------------------------------- init_values ------------------------------ */
unsigned long	rgb_to_hex(int red, int green, int blue);
int	*is_color(char **arr);
void	convert_rgb(int *rgb, int i, t_mlx *vlx);
int	init_colors(t_mlx *vlx);
void	fill_wall(int i, t_mlx *vlx);
int	init_walls(t_mlx *vlx);
void	init_values(t_mlx *vlx);

char	**ft_realloc(char **pointer, int size);
int	strlen_arr(void **arr);
void	free_arr(void ***arr);


#endif