/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borders_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:54:45 by iszitoun          #+#    #+#             */
/*   Updated: 2023/02/13 16:55:54 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_sides(char **s)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < line_count(s) - 1)
	{
		if (s[i][0] != '1' || s[i][line_len(*s) - 1] != '1')
			sides_error();
		i++;
	}
}

int	lines_r_equal(char **s)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	while (++i < line_count(s))
		if (line_len(s[i]) != line_len(s[i + 1]))
			lines_error();
	return (1);
}

int	map_check(char **s)
{
	int	i;
	int	j;

	j = -1;
	if (!s || !*s)
		return (0);
	i = line_count(s);
	while (s[i][++j])
		if (s[i][j] != '1' || s[0][j] != '1')
			horinzontal_error();
	lines_r_equal(s);
	check_sides(s);
	return (j);
}
