/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjuszko <kjuszko@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:39:50 by kjuszko           #+#    #+#             */
/*   Updated: 2025/05/21 16:09:53 by kjuszko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*write_line(char *text)
{
	char	*line;
	int		i;

	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (text[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*line_left(char *text)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i] || (text[i] == '\n' && !text[i + 1]))
		return (free(text), NULL);
	i++;
	line = malloc(ft_strlen(text) - i + 1);
	if (!line)
		return (free(text), NULL);
	while (text[i])
		line[j++] = text[i++];
	line[j] = '\0';
	free(text);
	return (line);
}

char	*parseline(char *text, int fd)
{
	int		bytes;
	char	*buffer;

	bytes = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(text), NULL);
	while (!text || !ft_strchr(text, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), free(text), text = NULL, NULL);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		text = ft_strjoin(text, buffer);
		if (!text)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	line = NULL;
	if (fd == -1)
	{
		if (text)
			free(text);
		return (text = NULL, NULL);
	}
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!text)
		text = NULL;
	text = parseline(text, fd);
	if (!text || (*text == '\0'))
		return (free(text), text = NULL, NULL);
	line = write_line(text);
	text = line_left(text);
	return (line);
}

/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("only_nl.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	else
	{
		printf("Opened successfully.\n");
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	// Ensure that the static variable `text` is freed before exiting
	get_next_line(-1);
	if (close(fd) == -1)
	{
		printf("Error closing file!\n");
		exit(1);
	}
	return (0);
} */

/* char	*get_next_line(int fd)
{
	static char	*text;
	char		*buffer;
	int			bytes;
	char		*line;
	char		*joined;
	int			fd;
	char		*line;

	bytes = 0;
	line = NULL;
	if (fd == -1)
	{
		if (text)
			free(text);
		text = NULL;
		return (NULL);
	}
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!text)
	{
		text = ft_strdup("");
		if (!text)
		{
			free(text);
			return (NULL);
		}
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(text, '\n') && (bytes = read(fd, buffer,
				BUFFER_SIZE)) > 0)
	{
		buffer[bytes] = '\0';
		joined = ft_strjoin(text, buffer);
		if (!joined)
		{
			free(text);
			free(buffer);
			return (NULL);
		}
		text = joined;
	}
	free(buffer);
	if ((bytes < 0) || (bytes == 0 && (*text == '\0')))
	{
		free(text);
		text = NULL;
		return (NULL);
	}
	line = write_line(text);
	text = line_left(text);
	return (line);
} */

/* int	main(void)
{
	int		fd;
	char	buffer[10];
	int		bytesRead;

	fd = open("t.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening!\n\n");
		exit(1);
	}
	else
		printf("Opened successfully.\n\n");
	bytesRead = read(fd, buffer, sizeof(buffer));
	printf("%d bytes read\n\n", bytesRead);
	printf("content:\n\n%s\n", buffer);
} */
/* 	if (line == NULL || line[0] == '\0')
	{
		free(line);
		return (NULL);
	} */
