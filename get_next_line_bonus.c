/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:14:19 by ismirand          #+#    #+#             */
/*   Updated: 2023/11/11 18:19:36 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*temp;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	i = 0;
	j = 0;
	temp = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	while (s2[j])
		temp[i++] = s2[j++];
	free(s1);
	return (temp);
}

char	*get_ret(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!*str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		line = ft_calloc(sizeof(char), i + 2);
	else
		line = ft_calloc(sizeof(char), i + 1);
	if (!line)
	{
		free (str);
		return (NULL);
	}
	i = -1;
	while (str[++i] && str[i] != '\n')
		line[i] = str[i];
	if (str[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*save_line(char *str)
{
	char		*new_line;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!*str)
	{
		free(str);
		return (NULL);
	}
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	new_line = ft_calloc(sizeof(char), ft_strlen(str) - i + 1);
	while (str[++i])
		new_line[j++] = str[i];
	free(str);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*dest[FOPEN_MAX];
	char		*buf;
	char		*line;
	int			char_read;

	char_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (!(newline(buf)) && char_read)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read < 0)
			return (ft_clean(&dest[fd], &buf));
		buf[char_read] = '\0';
		dest[fd] = ft_strjoin(dest[fd], buf);
	}
	line = get_ret(dest[fd]);
	dest[fd] = save_line(dest[fd]);
	free(buf);
	return (line);
}

/* int	main(void)
{
	int	fd;
	int	FD;
	char	*line;
	char	*LINE;
	
	fd = open("toread.txt", O_RDONLY);
	FD = open("read.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	free (line);
	
	LINE = get_next_line(FD);
	printf("%s\n", LINE);
	free (LINE);
	
	line = get_next_line(fd);
	printf("%s\n", line);
	free (line);
	
	LINE = get_next_line(FD);
	printf("%s\n", LINE);
	free (LINE);
	
	line = get_next_line(fd);
	printf("%s\n", line);
	free (line);
	
	LINE = get_next_line(FD);
	printf("%s\n", LINE);
	free (LINE);
	
	close(fd);
	close (FD);
	return (0);
} */