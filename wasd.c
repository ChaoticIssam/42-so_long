/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:42:32 by iszitoun          #+#    #+#             */
/*   Updated: 2023/02/16 18:41:39 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right_key(t_s1 *m)
{
	if (m->sp[m->pos_y][m->pos_x + 1] != '1')
	{
		m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/Background.xpm",
				&m->w, &m->h);
			mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->pos_x * 60, m->pos_y * 60);
			m->sp[m->pos_y][m->pos_x] = '0';
			
				printf("D -> Old coordinates == %d, %d\n", m->pos_y, m->pos_x);
			
			m->pos_x++;

				printf("D -> New coordinates == %d, %d\n", m->pos_y, m->pos_x);
				
			m->sp[m->pos_y][m->pos_x] = 'P';
			m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/looking_right.xpm",
					&m->w, &m->h);
			mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->pos_x * 60, m->pos_y
					* 60);
	}
	return ;
}

void	left_key(t_s1 *m)
{
	if (m->sp[m->pos_y][m->pos_x - 1] != '1')
	{
		m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/Background.xpm",
				&m->w, &m->h);
			mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->pos_x * 60, m->pos_y * 60);
			m->sp[m->pos_y][m->pos_x] = '0';
			m->pos_x--;

				printf("D -> New coordinates == %d, %d\n", m->pos_y, m->pos_x);
				
			m->sp[m->pos_y][m->pos_x] = 'P';
			m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/looking_left.xpm",
					&m->w, &m->h);
			mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->pos_x * 60, m->pos_y
					* 60);
	}
	return ;
}

void	up_key(t_s1 *m)
{
	if (m->sp[m->pos_y - 1][m->pos_x] != '1')
	{
		m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/Background.xpm",
		&m->w, &m->h);
		mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->pos_x * 60, m->pos_y * 60);
		m->sp[m->pos_y][m->pos_x] = '0';
		m->pos_y--;
		m->sp[m->pos_y][m->pos_x] = 'P';
		m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/looking_up.xpm",
				&m->w, &m->h);
		mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->pos_x * 60, m->pos_y
				* 60);
	}
	return ;
}

void	down_key(t_s1 *m)
{
	if (m->sp[m->pos_y + 1][m->pos_x] != '1')
	{
		m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/Background.xpm",
		&m->w, &m->h);
		mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->pos_x * 60, m->pos_y * 60);
		m->sp[m->pos_y][m->pos_x] = '0';
		m->pos_y++;
		m->sp[m->pos_y][m->pos_x] = 'P';
		m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/Player.xpm",
				&m->w, &m->h);
		mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->pos_x * 60, m->pos_y
				* 60);
	}
	return ;
}
