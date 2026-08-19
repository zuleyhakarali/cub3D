#include "../cub.h"

//mlx kaynaklarını temiz free etme

void	clean_mlx(t_cub *game)
{
	int	i;

	i = 0;
	if (!game->mlx)
		return ;

	while (i < 4)
	{
		if (game->mlx->textures[i].img)
			mlx_destroy_image(game->mlx->mlx, game->mlx->textures[i].img);
		i++;
	}
	if (game->mlx->screen_b.img)
		mlx_destroy_image(game->mlx->mlx, game->mlx->screen_b.img);
	if (game->mlx->window)
		mlx_destroy_window(game->mlx->mlx, game->mlx->window);
	free(game->mlx);
	game->mlx = NULL;
}

