#include "../cub.h"

void for_free(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char *open_text(char *l)
{
	l++;
	l++;
	return (ft_strtrim(l, " \n"));
}

void file_open(t_cub *game)
{
	game->fd = open(game->no, O_RDONLY);
	if (game->fd < 0)
		error("NO file cannot open.", 2, game);
	close(game->fd);
	game->fd = open(game->so, O_RDONLY);
	if (game->fd < 0)
		error("SO file cannot open.", 2, game);
	close(game->fd);
	game->fd = open(game->ea, O_RDONLY);
	if (game->fd < 0)
		error("EA file cannot open.", 2, game);
	close(game->fd);
	game->fd = open(game->we, O_RDONLY);
	if (game->fd < 0)
		error("WE file cannot open.", 2, game);
	close(game->fd);
}

void    check_the_texture(t_cub *game)
{
	int i = 0;

	while (game->cub[i])
	{
		if (ft_strncmp(game->cub[i], "NO ", 3) == 0)
			game->no = open_text(game->cub[i]);
		else if (ft_strncmp(game->cub[i], "SO ", 3) == 0)
			game->so = open_text(game->cub[i]);
		else if (ft_strncmp(game->cub[i], "EA ", 3) == 0)
			game->ea = open_text(game->cub[i]);
		else if (ft_strncmp(game->cub[i], "WE ", 3) == 0)
			game->we = open_text(game->cub[i]);
		i++;
	}
	if (!game->no || !game->so || !game->ea || !game->we)
		error("Direction file not found.", 2, game);
	file_open(game);
}

int	ft_iswanted(char *s)
{
	int i;
	int com;

	i = 1;
	com = 0;
	while (s[i] == ' ')
		i++;
	while (s[i] && s[i] != '\n')
	{
		if (!(s[i] >= '0' && s[i] <= '9') && s[i] != ',' && s[i] != ' ')
			return (0);
		if (s[i] == ',')
			com++;
		i++;
	}
	if (com != 2)
		return (0);
	return (1);
}

void check_int(char **s1, char **s2, t_cub *game)
{
	int i = 0;
	int j;

	while (s1[i])
	{
		j = 0;
		while (s1[i][j] && s1[i][j] != '\n')
		{
			if (!ft_isdigit(s1[i][j]))
				error("Floor's values are not true type.", 2, game);
			j++;
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		j = 0;
		while (s2[i][j] && s2[i][j] != '\n')
		{
			if (!ft_isdigit(s2[i][j]))
				error("Ceiling's values are not true type.", 2, game);
			j++;
		}
		i++;
	}
}

void   check_rgb(t_cub *game, char **s1, char **s2)
{
	int fir;
	int sec;
	int thi;

	check_int(s1, s2, game);
	fir = ft_atoi(s1[0]);
	sec = ft_atoi(s1[1]);
	thi = ft_atoi(s1[2]);
	if ((fir > 255 || fir < 0) || (sec > 255 || sec < 0) || (thi > 255 || thi < 0))
	{
		for_free(s1);
		for_free(s2);
		error("Floor's RGB values are incorrect.", 2, game);
	}
	game->floor = (fir << 16) | (sec << 8) | thi;
	fir = ft_atoi(s2[0]);
	sec = ft_atoi(s2[1]);
	thi = ft_atoi(s2[2]);
	if ((fir > 255 || fir < 0) || (sec > 255 || sec < 0) || (thi > 255 || thi < 0))
	{
		for_free(s1);
		for_free(s2);
		error("Ceiling's RGB values are incorrect.", 2, game);
	}
	game->ceil = (fir << 16) | (sec << 8) | thi;
	for_free(s1);
	for_free(s2);
}

void check_the_c_f(t_cub *game)
{
	int i = 0;
	int j = 0;

	while (game->cub[i])
	{
		if (ft_strncmp(game->cub[i], "F ", 2) == 0)
		{
			if (!ft_iswanted(game->cub[i]))
				error("You have a problem with the floor RGB", 2, game);
			game->f = open_text(game->cub[i]);
			j++;
		}
		else if (ft_strncmp(game->cub[i], "C ", 2) == 0)
		{
			if (!ft_iswanted(game->cub[i]))
				error("You have a problem with the ceil RGB", 2, game);
			game->c = open_text(game->cub[i]);
			j++;
		}
		i++;
	}
	if (j != 2)
		error("There's more or less ceil/floor than requirement.", 2, game);
}

void check_the_top(t_cub *game)
{
	char **s1;
	char **s2;

	check_the_texture(game);
	check_the_c_f(game);
	s1 = ft_split(game->f, ',');
	s2 = ft_split(game->c, ',');
	free(game->f);
	free(game->c);
	if (!s1 || !s1[0] || !s1[1] || !s1[2] || s1[3] != NULL
    || !s2 || !s2[0] || !s2[1] || !s2[2] || s2[3] != NULL)
	{
		for_free(s1);
		for_free(s2);
		error("You have a problem with the ceil/floor RGB.", 2, game);
	}
	check_rgb(game, s1, s2);
}
