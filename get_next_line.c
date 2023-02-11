/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:24:33 by iszitoun          #+#    #+#             */
/*   Updated: 2023/02/10 15:30:50 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read_str(int fd, char *str)
{
	char	*buff;
	int		bsread;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bsread = 1;
	while (bsread != 0)
	{
		bsread = read(fd, buff, BUFFER_SIZE);
		if (bsread == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[bsread] = '\0';
		str = ft_strjoin1(str, buff);
	}
	free(buff);
	return (str);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i])
		i++;
	ptr = malloc(sizeof(char) * (i + 2));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_new_str(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new_str = malloc(sizeof(char) * (ft_strlen1(str) - i + 1));
	if (!new_str)
		return (NULL);
	i++;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_new_str(str);
	return (line);
}