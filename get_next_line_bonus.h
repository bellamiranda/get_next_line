/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:18:19 by ismirand          #+#    #+#             */
/*   Updated: 2023/11/11 18:28:27 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(char *str);
int		newline(char *str);
char	*ft_clean(char **s1, char **s2);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*get_ret(char *str);
char	*save_line(char *str);

#endif