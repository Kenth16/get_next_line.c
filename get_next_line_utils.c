/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navarre <navarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:46:58 by navarre           #+#    #+#             */
/*   Updated: 2023/12/06 22:22:27 by navarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *left_str, char *buf)
{
	int		i;
	int		j;
	char	*tab;

	if (!left_str)
	{
		left_str = (char *)malloc(sizeof(char) * 1);
		left_str[0] = '\0';
	}
	tab = malloc(sizeof(char) * (ft_strlen(left_str) + ft_strlen(buf) + 1));
	if (!tab || !left_str || !buf)
		return (NULL);
	i = 0;
	j = 0;
	while (left_str[i])
		tab[j++] = left_str[i++];
	i = 0;
	while (buf[i])
		tab[j++] = buf[i++];
	tab[j] = '\0';
	free(left_str);
	return (tab);
}

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
