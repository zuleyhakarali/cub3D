#include "../cub.h"

//mlx kaynaklarını temiz free etme

void	clean_mlx(t_cub *game)
{
	if (!game->mlx)
		return ;
	if (game->mlx->screen_b.img)
		mlx_destroy_image(game->mlx->mlx, game->mlx->screen_b.img);
	if (game->mlx->window)
		mlx_destroy_window(game->mlx->mlx, game->mlx->window);
	free(game->mlx);
	game->mlx = NULL;
}