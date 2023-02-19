/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:45:09 by iszitoun          #+#    #+#             */
/*   Updated: 2023/02/19 05:48:45 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_s1	*m;

	(void)ac;
	m = malloc(sizeof(t_s1));
	m->fd = open(av[1], O_RDONLY);
	m->i = 0;
	m->j = 0;
	m->ball_count = 0;
	m->ex_i = 0;
	m->ex_j = 0;
	m->c_i = 0;
	m->c_j = 0;
	m->str = NULL;
	m->str = ft_read_str(m->fd, m->str);
	if (!m->str)
		return (0);
	m->sp = ft_split(m->str, '\n');
	m->line = words_count(m->str, '\n');
	map_check(m->sp);
	//invalid_item(m->sp);
	items_check(m);
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, ft_strlen(*m->sp) * 60, (line_count(m->sp)
				+ 1) * 60, "so_long");
	mlx_loop_hook(m->mlx, put_image,m);
	mlx_hook(m->win, 2, 0, &moving_key, m);
	mlx_loop(m->mlx);
}
