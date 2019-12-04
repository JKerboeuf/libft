/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:18:05 by jukerboe          #+#    #+#             */
/*   Updated: 2019/12/04 13:59:53 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	gnl_strsub(char *rest)
{
	long	i;
	long	j;
	char	cpy[BUFFER_SIZE + 1];

	i = 0;
	while (i < BUFFER_SIZE + 1)
		cpy[i++] = '\0';
	i = 0;
	while (rest[i] != '\n' && i < BUFFER_SIZE && rest[i] != '\0')
		i++;
	if (rest[i] == '\n')
		i++;
	j = 0;
	while (i < BUFFER_SIZE)
		cpy[j++] = rest[i++];
	i = -1;
	while (++i < BUFFER_SIZE)
		rest[i] = cpy[i];
	rest[i] = '\0';
}

static int	gnl_cut(int l_len, int r_len, char **line, char *rest)
{
	long	i;
	char	cpy[l_len];

	i = -1;
	while (++i < l_len - r_len)
		cpy[i] = (*line)[i];
	i = -1;
	while (++i + (l_len - r_len) < l_len)
		cpy[i + (l_len - r_len)] = rest[i];
	free((*line));
	if (!((*line) = malloc(sizeof(char) *
		(l_len + ((rest[r_len] == '\n' || !r_len) ? 1 : 0)))))
		return (-1);
	i = -1;
	while (++i < l_len)
		(*line)[i] = cpy[i];
	if (!(i *= 0) && (rest[r_len] == '\n' || !r_len))
	{
		(*line)[l_len] = '\0';
		gnl_strsub(rest);
		return (1);
	}
	while ((rest[r_len] != '\n' || r_len) && i < BUFFER_SIZE)
		rest[i++] = '\0';
	return (0);
}

static int	gnl_read(int fd, char rest[OPEN_MAX][BUFFER_SIZE + 1])
{
	long	r_len;
	long	oct;

	if (fd < 0)
		return (-1);
	r_len = 0;
	while (rest[fd][r_len] && rest[fd][r_len] != '\n' && r_len < BUFFER_SIZE)
		r_len++;
	if (r_len > 0 || rest[fd][r_len] == '\n')
		return (r_len);
	if ((oct = read(fd, rest[fd], BUFFER_SIZE)) < 0)
		return (-1);
	r_len = 0;
	while (rest[fd][r_len] != '\n' && r_len < oct)
		r_len++;
	return (r_len);
}

int			get_next_line(int fd, char **line)
{
	int				r_len;
	int				l_len;
	static char		rest[OPEN_MAX][BUFFER_SIZE + 1];

	if (!line || BUFFER_SIZE <= 0 || !((*line) = malloc(sizeof(char)))
		|| (r_len = gnl_read(fd, rest)) < 0)
		return (-1);
	if (!r_len && rest[fd][r_len] != '\n')
		(*line)[0] = '\0';
	l_len = 0;
	while ((l_len += r_len) > -1 && (r_len || rest[fd][r_len] == '\n'))
	{
		if ((r_len = gnl_cut(l_len, r_len, line, rest[fd])) != 0)
			return (1);
		if ((r_len = gnl_read(fd, rest)) < 0)
			return (-1);
	}
	if (l_len > 0)
		if (gnl_cut(l_len, r_len, line, rest[fd]) < 0)
			return (-1);
	return (0);
}
