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

static void	sec_fill(char **tmp, int y, int x, t_cub *g)
{
	if (y < 0 || x < 0 || y >= g->height || x >= ft_strlen(tmp[y])
		|| tmp[y][x] == 'f' || tmp[y][x] == ' ' || tmp[y][x] == '\n' || tmp[y][x] == '\0')
		return ;
	tmp[y][x] = 'f';
	sec_fill(tmp, y - 1, x, g);
	sec_fill(tmp, y + 1, x, g);
	sec_fill(tmp, y, x - 1, g);
	sec_fill(tmp, y, x + 1, g);
}

static void check_the_fill(char **tmp, t_cub *g)
{
	int i;
	int j;
	char c;

	i = 0;
	while (tmp[i])
	{
		j = 0;
		while(tmp[i][j])
		{
			c = tmp[i][j];
			if (c == '1' || c == '0'
				|| c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				for_free(tmp);
				error("IT'S DOUBLE MAP", 2, g);
			}
			j++;
		}
		i++;
	}
}

void	sec_flood(t_cub *game)
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
	sec_fill(tmp, y, x, game);
	check_the_fill(tmp, game);
	game->height = i;
	for_free(tmp);
}
