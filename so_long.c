/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:45:09 by iszitoun          #+#    #+#             */
/*   Updated: 2023/02/11 15:16:17 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_len(char *s)
{
	int	j;

	j = 0;
	while (s[j])
		j++;
		printf("line len == %d\n", j);
	return (j);
}

int	line_count(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	lines_r_equal(char **s)
{
	int	i;

	i = 0;
	while (i < line_count(s))
	{
		if (line_len(s[i]) != line_len(s[i + 1]))
			exit (1);
		i++;
	}
	return (1);
}

int	map_check(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[0])
		while (s[i])
			i++;
	i = i - 1;
	while (s[i][j])
	{
		if (s[i][j] != '1' || s[0][j] != '1')
			exit(1);
		j++;
	}
	lines_r_equal(s);
	return (j);
}

int	main(void)
{
	int fd = open("map.ber", O_RDONLY);
	char *str;
	char **sp;
	int line;

	str = NULL;
	str = ft_read_str(fd, str);
	sp = ft_split(str, '\n');
	line = words_count(str, '\n');
	map_check(sp);
}