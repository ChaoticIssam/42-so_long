/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:53:39 by iszitoun          #+#    #+#             */
/*   Updated: 2023/02/19 05:48:09 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	c_check(t_s1 *m)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (++i < line_count(m->sp))
	{
		j = 0;
		while (++j < line_len(*m->sp) - 1)
			if (m->sp[i][j] == 'C')
			{
				m->ball_count++;
				m->c_i = i;
				m->c_j = j;
			}
			printf("%d\n", m->ball_count);
	}
	if (m->ball_count > 0)
		return (1);
	return (0);
}

int	e_check(t_s1 *m)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	j = 1;
	count = 0;
	while (++i < line_count(m->sp))
	{
		j = 0;
		while (++j < line_len(*m->sp) - 1)
			if (m->sp[i][j] == 'E')
			{
				m->ex_i = i;
				m->ex_j = j;
				count++;
			}
	}
	if (count != 1)
		duplicated_exit_error();
	return (1);
}

int	p_check(t_s1 *m)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 1;
	count = 0;
	while (++i < line_count(m->sp))
	{
		j = 0;
		while (++j < line_len(*m->sp) - 1)
			if (m->sp[i][j] == 'P')
			{
				m->pos_y = i;
				m->pos_x = j;
				count++;
			}
	}
	if (count != 1)
		duplicated_player_error();
	return (1);
}

void	invalid_item(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (++i < 3)
	{
		j = 0;
		while (++j < line_len(*s) - 1)
		{
			if (s[i][j] != 'P' && s[i][j] != 'C' && s[i][j] != 'E'
				&& s[i][j] != '0' && s[i][j] != '1')
				invalid_item_error();
		}
	}
}

void	items_check(t_s1 *m)
{
	if (!c_check(m))
		item_needed_error();
	e_check(m);
	p_check(m);
}
