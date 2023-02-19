/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:02:11 by iszitoun          #+#    #+#             */
/*   Updated: 2023/02/19 01:52:29 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_image(t_s1 *m)
{
	static int c;
	while (m->sp[m->i])
	{
		m->j = 0;
		while (m->sp[m->i][m->j])
		{
			put_floor(m);
			if (m->sp[m->i][m->j] == '1')
				put_walls(m);
			if (m->sp[m->i][m->j] == 'C')
				put_collectibles(m);
			if (m->sp[m->i][m->j] == 'P')
				put_player(m);
			m->j++;
		}
		m->i++;
	}
	while (c == 2000)
	{
		for_exit(m);
		c = 0;
	}
	c++;
	return (0);
}

void	for_exit(t_s1 *m)
{
	while (m->sp[m->ex_i])
	{
		m->ex_j = 0;
		while (m->sp[m->ex_i][m->ex_j])
		{
			if (m->sp[m->ex_i][m->ex_j] == 'E')
			{
				put_exit(m);
				mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->ex_j
						* 60, m->ex_i * 60);
			}
			m->ex_j++;
		}
		m->ex_i++;
	}
	m->ex_i = 0;
	m->ex_j = 0;
}

void	put_floor(t_s1 *m)
{
	m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/floor.xpm", &m->w,
			&m->h);
	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->j * 60, m->i * 60);
}

void	put_walls(t_s1 *m)
{
	m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/void.xpm", &m->w,
			&m->h);
	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->j * 60, m->i * 60);
}
// void	put_exit(t_s1 *m)
// {
// 	static int	index;

// 	if (index >= 4)
// 		index = 0;
// 	char *array[] = {
// 		"texture/exit.xpm",
// 		"texture/2.xpm",
// 		"texture/3.xpm",
// 		"texture/4.xpm",
// 		"texture/5.xpm",
// 	};
// 	index++;
// 	m->xpm_img = mlx_xpm_file_to_image(m->mlx,
// 										array[index],
// 										&m->w,
// 										&m->h);
// }

void	put_collectibles(t_s1 *m)
{
	m->xpm_img = mlx_xpm_file_to_image(m->mlx,
										"texture/Collectible.xpm",
										&m->w,
										&m->h);
	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->j * 60 + 15, m->i
			* 60 + 15);
}

void	put_player(t_s1 *m)
{
	m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/Player.xpm", &m->w,
			&m->h);
	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->j * 60, m->i * 60);
}
