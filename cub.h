/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 15:24:38 by zkarali           #+#    #+#             */
/*   Updated: 2026/09/01 15:11:58 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <math.h>
# include <mlx.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef enum e_tex
{
	NO_t = 0,
	SO_t = 1,
	WE_t = 2,
	EA_t = 3
}	t_tex;

typedef struct s_img
{
	void	*img;
	char	*pix_ptr;
	int		bits_per_pix;
	int		line_l;
	int		endian;
	int		wid;
	int		heig;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	t_img	screen_b;
	t_img	textures[4];
}	t_mlx;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	int		cell_x;
	int		cell_y;
	int		step_x;
	int		step_y;
	double	cost_x;
	double	cost_y;
	double	to_border_x;
	double	to_border_y;
	int		hit_wall;
	int		hit_vertical;
	double	distance;
}	t_ray;

typedef struct s_wall
{
	int		screen_x;
	int		height;
	int		top;
	int		bottom;
	int		tex_x;
	t_img	*tex;
}	t_wall;

typedef struct s_cub
{
	char	**cub;
	double	x;
	double	y;
	double	x_dir;
	double	y_dir;
	double	x_plane;
	double	y_plane;
	int		height;
	int		f_height;
	int		floor;
	int		ceil;
	char	*f;
	char	*c;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		fd;
	char	player;
	t_mlx	*mlx;
	int		map_offset;
	int		key_w;
	int		key_s;
	int		key_a;
	int		key_d;
	int		key_left;
	int		key_right;
}	t_cub;

int		main(int ac, char **av);
void	is_cub_valid(t_cub *game);
void	error(char *m, int i, t_cub *game);
void	check_the_top(t_cub *game);
void	for_free(char **s);
void	for_read_etc(int ac, char **av, t_cub *game);
void	check_rgb(t_cub *game, char **s1, char **s2);
void	check_the_texture(t_cub *game);
void	flood(t_cub *game);
void	sec_flood(t_cub *game);
void	check_the_f_c(t_cub *game);
char	*open_text(char *l);
void	init_mlx(t_cub *game);
void	load_images(t_cub *game);
void	init_player_dir(t_cub *game);
void	init_ray(t_cub *game, t_ray *ray, int screen_x);
void	cast_ray(t_cub *game, t_ray *ray);
t_img	*pick_texture(t_cub *game, t_ray *ray);
int		texture_column(t_cub *game, t_ray *ray, t_img *tex);
int		texture_pixel(t_img *tex, int tx, int ty);
void	draw_wall(t_cub *game, t_ray *ray, t_wall *wall);
void	draw_floor_ceil(t_cub *game);
void	render_frame(t_cub *game);
int		game_loop(void *param);
int		key_press(int keycode, t_cub *game);
int		key_release(int keycode, t_cub *game);
int		close_window(t_cub *game);
void	move_player(t_cub *game);
void	rotate_player(t_cub *game);
void	clean_mlx(t_cub *game);
void	exit_game(t_cub *game);

#endif