/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:46:37 by iszitoun          #+#    #+#             */
/*   Updated: 2023/02/16 18:20:42 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moving_key(int keysym, t_s1 *m)
{
	int i;
	int j;
	
	i = 0;
	j = 1;
	printf("x == %d\n y == %d\n", m->pos_x, m->pos_y);

	if (keysym == 2)
		right_key(m);
	if (keysym == 0)
	{
		left_key(m);
	}
	if (keysym == 13)
	{
		up_key(m);
	}
	if (keysym == 1)
	{
		down_key(m);	
	}
		if (keysym == 53)
			exit(1);
	return (0);
}