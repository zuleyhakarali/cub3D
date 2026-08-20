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
# include <math.h>      // Matematik kütüphanesi fonksiyonları (-lm)
# include <mlx.h>       // MiniLibX grafik kütüphanesi

# define WIN_WIDTH   1280  //pencere yüksekliği
# define WIN_HEIGHT  720   //pencere genişliği
# define MOVE_SPEED  0.05  // oyuncu hızı
# define ROT_SPEED   0.03  // oyuncu rotasyon speed

typedef enum e_tex // Doku dizisinin indeks isimleri
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

typedef struct s_cub
{
	char	**cub; //harita
	double	x; //px pozisyon
	double	y; //py pozisyon
	double	x_dir; //px yönü
	double	y_dir; //py yönü
	double	x_plane; // kamera düzlemi x
	double	y_plane; // kamera düzlemi y
	int		height; //yükseklik
	int		f_height; //harita toplam uzunluğu
	int		width; //genişlik
	int		floor; //taban renk
	int		ceil; ///tavan renk
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
}	t_cub;


int		main(int ac, char **av);
void	is_cub_valid(t_cub *game);
void	error(char *m, int i, t_cub *game);
void	check_the_top(t_cub *game);
void	for_free(char **s);
void	for_read_etc(int ac, char **av, t_cub *game);
char	*open_text(char *l);
void	check_text_nums(t_cub *game);
void	check_rgb(t_cub *game, char **s1, char **s2);
void	check_the_texture(t_cub *game);
int		ft_iswanted(char *s);
void	check_int(char **s1, char **s2, t_cub *game);
void	flood(t_cub *game);
void	sec_flood(t_cub *game);



//executor

void	init_mlx(t_cub *game);
void	init_screen_buffer(t_cub *game);

void load_images(t_cub *game);
void draw_floor_ceil(t_cub *game);
void	clean_mlx(t_cub *game);

#endif
