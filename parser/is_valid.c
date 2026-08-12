#include "../cub.h"

static void	fill(char **tmp, int y, int x, t_cub *g)
{
	if (y < 0 || x < 0 || y >= g->height || x >= ft_strlen(tmp[y])
		|| tmp[y][x] == ' ')
	{
		for_free(tmp);
		error("Map is not closed.", 2, g);
	}
	if (tmp[y][x] == 'f' || tmp[y][x] == '1')
		return ;
	tmp[y][x] = 'f';
	fill(tmp, y - 1, x, g);
	fill(tmp, y + 1, x, g);
	fill(tmp, y, x - 1, g);
	fill(tmp, y, x + 1, g);
}

void	flood(t_cub *game)
{
	char	**tmp;
	int		i;
	int		j;
	int		x;
	int		y;

	y = (int)game->y;
	x = (int)game->x;
	tmp = malloc(sizeof(char *) * (game->height + 1));
	i = game->f_height - game->height;
	j = 0;
	while (game->cub[i + j])
	{
		tmp[j] = ft_strdup(game->cub[i + j]);
		j++;
	}
	tmp[j] = NULL;
	i = game->height;
	fill(tmp, y, x, game);
	game->height = i;
	for_free(tmp);
}

static void	check_valid_chars(t_cub *game, int i, int *p)
{
	int		j;
	char	c;

	j = 0;
	while (game->cub[i][j])
	{
		c = game->cub[i][j];
		if (c != '1' && c != '0' && c != 'N' && c != 'S'
			&& c != 'W' && c != 'E' && c != '\n' && c != ' ')
			error("There is a unwanted char in the map", 2, game);
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		{
			(*p)++;
			game->player = game->cub[i][j];
			game->x = j + 0.5;
			game->y = (i - (game->f_height - game->height)) + 0.5;
		}
		j++;
	}
}

void find_height(t_cub *game)
{
	int i;
	int j;

	i = 0;
	while (game->cub[i])
	{
		j = 0;
		while (game->cub[i][j] && game->cub[i][j] == ' ')
			j++;
		if (game->cub[i][j] == '1')
		{
			while (game->cub[i])
			{
				i++;
				game->height++;
			}
			break ;
		}
		i++;
	}
}

void	is_cub_valid(t_cub *game)
{
	int	i;
	int	len;
	int	p;

	p = 0;
	find_height(game);
	check_the_top(game);
	len = game->f_height - 1;
	if (game->cub[len][ft_strlen(game->cub[len]) - 1] == '\n')
		error("There is a newline in the bottom of the map.", 2, game);
	i = game->f_height - game->height;
	while (game->cub[i])
	{
		check_valid_chars(game, i, &p);
		i++;
	}
	if (p != 1)
		error("There's more or less player than wanted", 2, game);
	flood(game);
}
