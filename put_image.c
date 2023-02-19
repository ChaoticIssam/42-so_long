/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:02:11 by iszitoun          #+#    #+#             */
/*   Updated: 2023/02/19 05:51:14 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_image(t_s1 *m)
{
	static int	c;

	while (m->sp[m->i])
	{
		m->j = 0;
		while (m->sp[m->i][m->j])
		{
			put_floor(m);
			if (m->sp[m->i][m->j] == '1')
				put_walls(m);
			if (m->sp[m->i][m->j] == 'D')
			{
				m->xpm_img = mlx_xpm_file_to_image(m->mlx,
													"texture/floor_1.xpm",
													&m->w,
													&m->h);
				mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->j * 60,
						m->i * 60);
				mlx_destroy_image(m->mlx, m->xpm_img);
			}
			if (m->sp[m->i][m->j] == 'U')
			{
				m->xpm_img = mlx_xpm_file_to_image(m->mlx,
													"texture/upper.xpm",
													&m->w,
													&m->h);
				mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->j * 60,
						m->i * 60);
				mlx_destroy_image(m->mlx, m->xpm_img);
			}
			if (m->sp[m->i][m->j] == 'B')
			{
				m->xpm_img = mlx_xpm_file_to_image(m->mlx,
													"texture/buttom.xpm",
													&m->w,
													&m->h);
				mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->j * 60,
						m->i * 60);
				mlx_destroy_image(m->mlx, m->xpm_img);
			}
			// if (m->sp[m->i][m->j] == 'C')
			// 	put_collectibles(m);
			if (m->sp[m->i][m->j] == 'P')
				put_player(m);
			m->j++;
		}
		m->i++;
	}
	while (c == 1500)
	{
		for_exit(m);
		for_collectible(m);
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

void	for_collectible(t_s1 *m)
{
	while (m->sp[m->c_i])
	{
		m->c_j = 0;
		while (m->sp[m->c_i][m->c_j])
		{
			if (m->sp[m->c_i][m->c_j] == 'C')
			{
				put_collectibles(m);
				mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->c_j
						* 60 + 15, m->c_i * 60 + 15);
			}
			m->c_j++;
		}
		m->c_i++;
	}
	m->c_i = 0;
	m->c_j = 0;
}

void	put_floor(t_s1 *m)
{
	m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/floor.xpm", &m->w,
			&m->h);
	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->j * 60, m->i * 60);
	mlx_destroy_image(m->mlx, m->xpm_img);
}

void	put_walls(t_s1 *m)
{
	m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/void.xpm", &m->w,
			&m->h);
	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->j * 60, m->i * 60);
}
void	put_exit(t_s1 *m)
{
	static int	index;

	if (index >= 4)
		index = 0;
	char *array[] = {
		"texture/exit.xpm",
		"texture/2.xpm",
		"texture/3.xpm",
		"texture/4.xpm",
		"texture/5.xpm",
	};
	index++;
	m->xpm_img = mlx_xpm_file_to_image(m->mlx,
										array[index],
										&m->w,
										&m->h);
}

void	put_collectibles(t_s1 *m)
{
	static int	index;

	if (index >= 4)
		index = 0;
	char *array[] = {
		"texture/cool.xpm",
		"texture/cool2.xpm",
		"texture/cool3.xpm",
		"texture/cool4.xpm",
		"texture/cool5.xpm",
	};
	index++;
	m->xpm_img = mlx_xpm_file_to_image(m->mlx,
										array[index],
										&m->w,
										&m->h);
}

// void	put_collectibles(t_s1 *m)
// {
// 	m->xpm_img = mlx_xpm_file_to_image(m->mlx,
// 										"texture/cool.xpm",
// 										&m->w,
// 										&m->h);
// 	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->j * 60 + 15, m->i
// 			* 60 + 15);
// }

void	put_player(t_s1 *m)
{
	m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/Player.xpm", &m->w,
			&m->h);
	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->j * 60, m->i * 60);
}
