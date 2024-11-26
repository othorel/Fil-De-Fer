/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:18:23 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:01:01 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_free(char *buffer, char *b)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, b);
	free(buffer);
	return (tmp);
}

char	*ft_next_line(char *str)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new = ft_calloc(sizeof(char), ft_strlen(str) - i + 1);
	if (!new)
	{
		free(str);
		return (NULL);
	}
	i++;
	j = 0;
	while (str[i])
		new[j++] = str[i++];
	free(str);
	return (new);
}

char	*ft_read_and_stock(int fd, char *str)
{
	char	*buffer;
	int		b_read;

	if (!str)
		str = ft_calloc(1, 1);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	b_read = 1;
	while (!ft_strchr(str, '\n') && b_read != 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[b_read] = 0;
		str = ft_free(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*ft_extract_line(char *str)
{
	char	*new;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new = ft_calloc(sizeof(char), i + 2);
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new[i] = '\n';
		i++;
	}
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read_and_stock(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_extract_line(buffer[fd]);
	buffer[fd] = ft_next_line(buffer[fd]);
	if (!buffer[fd])
		free(buffer[fd]);
	return (line);
}

/* int	main(void)
{
	int fd1 = open("test1.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	char *line1;
	char *line2;
	
	while ((line1 = get_next_line(fd1)) || (line2 = get_next_line(fd2)))
	{
		if (line1)
		{
			printf("%s\n", line1);
			free(line1);
		}
		if (line2)
		{
			printf("%s\n", line2);
			free(line1);
		}
	}
	close(fd1);
	close(fd2);
	return (0);
} */