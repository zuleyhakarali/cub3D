/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:41:14 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/30 15:41:13 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	check_name(char **av)
{
	int	l;

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

static void	reading(char **av, int size, t_cub *game)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error("File could not be opened.", 0, game);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (i >= size)
			for_placement(i, &size, game);
		game->cub[i++] = line;
	}
	game->cub[i] = NULL;
	game->f_height = i;
	close(fd);
	if (i == 0)
		error("There is no map.", 1, game);
}

void	for_read_etc(int ac, char **av, t_cub *game)
{
	int	size;

	if (ac != 2)
		error("Invalid number of arguments.", 0, game);
	if (check_name(av))
		error("Map name is invalid.", 0, game);
	size = 2;
	game->cub = malloc(sizeof(char *) * (size + 1));
	if (!game->cub)
		error("Malloc error.", 0, game);
	reading(av, size, game);
	game->height = 0;
}
