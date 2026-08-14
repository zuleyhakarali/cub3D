#include "cub.h"

static void	reg_exit(t_cub *game)
{
	for_free(game->cub);
	if (game->so)
		free(game->so);
	if (game->no)
		free(game->no);
	if (game->ea)
		free(game->ea);
	if (game->we)
		free(game->we);
	free(game);
	exit(0);
}

int	main(int ac, char **av)
{
	t_cub	*game;

	game = ft_calloc(1, sizeof(t_cub));
	if (!game)
		return (1);
	for_fir_check(ac, av, game);
	is_cub_valid(game);
	//raycasting
	reg_exit(game);
}
