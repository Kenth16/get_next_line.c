/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navarre <navarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:23:52 by navarre           #+#    #+#             */
/*   Updated: 2023/12/07 12:34:46 by navarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_str(char *left_str)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}

char	*get_line(char *left_str)
{
	char	*str;
	int		i;

	i = 0;
	if (!left_str)
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*read_to_str(int fd, char *left_str)
{
	char	*buf;
	int		ret;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ret = 1;
	while (!ft_strchr(left_str) && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		left_str = ft_strjoin(left_str, buf);
	}
	free(buf);
	if (left_str && left_str[0] == '\0')
	{
		free(left_str);
		return (NULL);
	}
	return (left_str);
}

char	*get_next_line(int fd)
{
	static char	*left_str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_str = read_to_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = get_line(left_str);
	left_str = clean_str(left_str);
	return (line);
}

/*#include<stdio.h>
#include <fcntl.h>
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("getlepoteau.txt", O_RDONLY);

	i = 1;
	while (i < 6)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}*/
