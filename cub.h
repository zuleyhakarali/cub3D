#ifndef CUB
#define CUB

#include <fcntl.h>     // open
#include <unistd.h>    // close, read, write
#include <stdio.h>     // printf, perror
#include <stdlib.h>    // malloc, free, exit
#include <string.h>    // strerror
#include <sys/time.h>  // gettimeofday
#include <math.h>      // Matematik kütüphanesi fonksiyonları (-lm)
#include <mlx.h>       // MiniLibX grafik kütüphanesi

typedef enum e_tex // Doku dizisinin indeks isimleri
{
    NO_t = 0,
    SO_t = 1,
    WE_t = 2,
    EA_t = 3
}   t_tex;

typedef struct s_cub
{
		char    **cub; //harita
		double	x; //px pozisyon
		double	y; //py pozisyon
		double	x_dir; //px yönü
		double	y_dir; //py yönü
		double	x_plane; // kamera düzlemi x
		double	y_plane; // kamera düzlemi y
		int		height; //yükseklik
		int		width; //genişlik
		int		floor; //taban renk
		int		ceil; ///tavan renk
		char	*no;
		char	*so;
		char	*we;
		char	*ea;
}       t_cub;

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
}		t_mlx;

int main(int ac, char **av);


#endif