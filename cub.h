/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 15:24:38 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/30 16:19:55 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>     // open
# include <unistd.h>    // close, read, write
# include <stdio.h>     // printf, perror
# include <stdlib.h>    // malloc, free, exit
# include <string.h>    // strerror
# include <sys/time.h>  // gettimeofday
# include <math.h>      
# include <mlx.h>       

# define WIN_WIDTH   1280
# define WIN_HEIGHT  720
# define MOVE_SPEED  0.05
# define ROT_SPEED   0.03
# define KEY_ESC    65307
# define KEY_W      119
# define KEY_A      97
# define KEY_S      115
# define KEY_D      100
# define KEY_LEFT   65361
# define KEY_RIGHT  65363

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
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
}	t_ray;

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
	int		f_num;
	int		c_num;
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
void	is_int(char **s1, char **s2, t_cub *game);
void	flood(t_cub *game);
void	sec_flood(t_cub *game);
void	check_the_f_c(t_cub *game);
char	*open_text(char *l);

void	init_mlx(t_cub *game);
void	init_screen_buffer(t_cub *game);

void	load_images(t_cub *game);

void	init_player_dir(t_cub *game);

void	init_ray(t_cub *game, t_ray *ray, int x);

void	perform_dda(t_cub *game, t_ray *ray);
void	calc_perp_dist(t_ray *ray);

t_img	*select_texture(t_cub *game, t_ray *ray);
int		calc_tex_x(t_cub *game, t_ray *ray, t_img *tex);
int		get_tex_color(t_img *tex, int tx, int ty);

void	draw_wall_column(t_cub *game, t_ray *ray, int x);

void	draw_floor_ceil(t_cub *game);
void	render_frame(t_cub *game);
int		game_loop(void *param);

int		key_press(int keycode, t_cub *game);
int		key_release(int keycode, t_cub *game);
int		close_window(t_cub *game);

int		can_move(t_cub *game, double nx, double ny);
void	move_player(t_cub *game);
void	rotate_player(t_cub *game);

void	clean_mlx(t_cub *game);
void	exit_game(t_cub *game);

#endif