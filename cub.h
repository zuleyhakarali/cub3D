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

typedef struct s_cub
{
		char    **cub;
		int     x;// ya da double
		int     y;
		int		m_height;
		int		m_width;
		
}       t_cub;

typedef struct s_mlx
{
		void	*mlx;
        void	*window;
        void	*iwall;
        void	*ifloor;
		void	*iground;
}		t_mlx;

int main(int ac, char **av);


#endif