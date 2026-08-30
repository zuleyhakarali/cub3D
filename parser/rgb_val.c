/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:41:21 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/30 16:24:52 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	is_int_sec(char **s2, t_cub *game)
{
	int	i;
	int	j;

	i = 0;
	while (s2[i])
	{
		j = 0;
		while (s2[i][j] && s2[i][j] != '\n')
		{
			if (!ft_isdigit(s2[i][j]))
				error("Ceiling's values are not true.", 2, game);
			j++;
		}
		i++;
	}
}

void	is_int(char **s1, char **s2, t_cub *game)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i][j] && s1[i][j] != '\n')
		{
			if (!ft_isdigit(s1[i][j]))
				error("Floor's values are not true.", 2, game);
			j++;
		}
		i++;
	}
	is_int_sec(s2, game);
}
