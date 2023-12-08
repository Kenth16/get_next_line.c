/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navarre <navarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:50:55 by navarre           #+#    #+#             */
/*   Updated: 2023/12/07 12:08:03 by navarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		ft_strchr(char *str);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *left_str, char *buf);
char	*clean_str(char *left_str);
char	*get_line(char *left_str);
char	*read_to_str(int fd, char *left_str);
char	*get_next_line(int fd);

#endif
