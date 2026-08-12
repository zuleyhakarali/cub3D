#include "cub.h"

void    error(char *m, int i, t_cub *game)
{
    write(2, "Error\n", 6);
    ft_putendl_fd(m, 2);
	if (i == 2)
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
    exit(1);
}

void reg_exit(t_cub *game)
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

int check_name(char **av)
{
    int l;

    l = ft_strlen(av[1]);
    if (l < 5)
        return (1);
    l--;
    if (av[1][l] != 'b' || av[1][l - 1] != 'u' || av[1][l - 2] != 'c'
        || av[1][l - 3] != '.' || av[1][l - 4] == '\0' || av[1][l - 4] == '/')
        return (1);
    return (0);
}

static void	for_placement(int i, int *size, t_cub *game)
{
	int		j;
	char	**tmp;

	*size *= 2;
	tmp = malloc(sizeof(char *) * (*size + 1));
	if (!tmp)
		return ;
	j = 0;
	while (j < i)
	{
		tmp[j] = game->cub[j];
		j++;
	}
	free(game->cub);
	game->cub = tmp;
	tmp[i] = NULL;
}

void    reading(char **av, int size, t_cub *game)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error("File could not be opened.", 0, game);
	i = 0;
	size = 2;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (i >= size)
			for_placement(i, &size, game);
		game->cub[i++] = line;
	}
	if (i == 0)
		error("There is no map.", 0, game);
	game->cub[i] = NULL;
	game->f_height = i;
	close(fd);
}

int main(int ac, char **av)
{
    int     size;
    t_cub   *game;

	game = malloc(sizeof(t_cub));
	if (!game)
		return (1);
    if (ac != 2)
        error("Invalid number of arguments.", 0, game);
    if (check_name(av))
        error("Map name is invalid.", 0, game);
    size = 2;
	game->cub = malloc(sizeof(char *) * (size + 1));
	if (!game->cub)
		error("Malloc error.", 0, game);
    reading(av, size, game);
	game->width = ft_strlen(game->cub[0]);
	if (game->cub[0][game->width - 1] == '\n')
		game->width--;
	game->height = 0;
	is_cub_valid(game);
	reg_exit(game);
}
