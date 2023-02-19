/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:57:23 by iszitoun          #+#    #+#             */
/*   Updated: 2023/02/19 02:27:03 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_len(char *s)
{
	int	j;

	j = 0;
	if (!s)
		return (0);
	while (s[j])
		j++;
	return (j);
}

int	line_count(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	i--;
	return (i);
}

void	print_moves(t_s1 *m)
{
	FILE	*fp;

	ft_printf("For move count check: 'moves_count' FILE!\n\n\n");
	if ((fp = freopen("moves_count", "w", stdout)) == NULL)
	{
		ft_printf("Cannot open file.\n");
		exit(1);
	}
	ft_printf("move count == %d\n", m->count++);
	fclose(fp);
}

int	moving_key(int keysym, t_s1 *m)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (keysym == 2)
		right_key(m);
	if (keysym == 0)
		left_key(m);
	if (keysym == 13)
		up_key(m);
	if (keysym == 1)
		down_key(m);
	if (keysym == 53)
		exit(0);
	return (0);
}
