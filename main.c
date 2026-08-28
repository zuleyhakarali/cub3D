#include "cub.h"

int	main(int ac, char **av)
{
	t_cub	*game;

	game = ft_calloc(1, sizeof(t_cub));
	if (!game)
		return (1);
	for_read_etc(ac, av, game);
	is_cub_valid(game);
	game->map_offset = game->f_height - game->height;
	init_mlx(game);
	load_images(game);
	init_player_dir(game);
	render_frame(game);
	mlx_hook(game->mlx->window, 2, 1L << 0, (int (*)())key_press, game);
	mlx_hook(game->mlx->window, 3, 1L << 1, (int (*)())key_release, game);
	mlx_hook(game->mlx->window, 17, 0, (int (*)())close_window, game);
	mlx_loop_hook(game->mlx->mlx, (int (*)())game_loop, game);
	mlx_loop(game->mlx->mlx);
	return (0);
}
