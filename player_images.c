/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:43:08 by iszitoun          #+#    #+#             */
/*   Updated: 2023/02/19 04:35:05 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floor_before_player(t_s1 *m)
{
	if (m->sp[m->pos_y][m->pos_x] == 'D')
	{
		printf("hellooooo\n");
		m->xpm_img = mlx_xpm_file_to_image(m->mlx,
											"texture/floor_1.xpm",
											&m->w,
											&m->h);
		mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->pos_x * 60,
				m->pos_y * 60);
		mlx_destroy_image(m->mlx, m->xpm_img);
	}
	m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/floor.xpm", &m->w,
			&m->h);
	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->pos_x * 60, m->pos_y
			* 60);
}

void	looking_right(t_s1 *m)
{
	floor_before_player(m);
	m->sp[m->pos_y][m->pos_x] = '0';
	m->pos_x++;
	m->sp[m->pos_y][m->pos_x] = 'P';
	m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/looking_right.xpm",
			&m->w, &m->h);
	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->pos_x * 60, m->pos_y
			* 60);
}

void	looking_left(t_s1 *m)
{
	floor_before_player(m);
	m->sp[m->pos_y][m->pos_x] = '0';
	m->pos_x--;
	m->sp[m->pos_y][m->pos_x] = 'P';
	m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/looking_left.xpm",
			&m->w, &m->h);
	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->pos_x * 60, m->pos_y
			* 60);
}

void	looking_up(t_s1 *m)
{
	floor_before_player(m);
	m->sp[m->pos_y][m->pos_x] = '0';
	m->pos_y--;
	m->sp[m->pos_y][m->pos_x] = 'P';
	m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/looking_up.xpm", &m->w,
			&m->h);
	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->pos_x * 60, m->pos_y
			* 60);
}

void	looking_down(t_s1 *m)
{
	floor_before_player(m);
	m->sp[m->pos_y][m->pos_x] = '0';
	m->pos_y++;
	m->sp[m->pos_y][m->pos_x] = 'P';
	m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/Player.xpm", &m->w,
			&m->h);
	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->pos_x * 60, m->pos_y
			* 60);
}