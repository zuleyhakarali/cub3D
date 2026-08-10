/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:59:27 by zkarali           #+#    #+#             */
/*   Updated: 2025/08/13 15:33:09 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extra_line(char **rest, int nl_i)
{
	char	*line;
	char	*oldrest;
	int		len;

	line = sub_str(*rest, 0, nl_i + 1);
	len = str_len(*rest) - (nl_i + 1);
	oldrest = *rest;
	*rest = sub_str(*rest, nl_i + 1, len);
	free(oldrest);
	return (line);
}

static char	*append_rest(char *rest, char *buf)
{
	char	*tmp;

	tmp = rest;
	rest = str_join(rest, buf);
	free(tmp);
	return (rest);
}

static char	*read_to_rest(int fd, char *rest)
{
	char	*buf;
	ssize_t	bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	while (newline_i(rest) < 0 && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		rest = append_rest(rest, buf);
	}
	free(buf);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	int			nl_i;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	rest = read_to_rest(fd, rest);
	if (!rest)
		return (NULL);
	nl_i = newline_i(rest);
	if (nl_i >= 0)
		return (extra_line(&rest, nl_i));
	if (rest && *rest)
	{
		line = sub_str(rest, 0, str_len(rest));
		free(rest);
		rest = NULL;
		return (line);
	}
	free(rest);
	rest = NULL;
	return (NULL);
}	
