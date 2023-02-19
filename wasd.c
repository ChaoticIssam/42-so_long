/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:42:32 by iszitoun          #+#    #+#             */
/*   Updated: 2023/02/19 04:43:56 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right_key(t_s1 *m)
{
	if (m->sp[m->pos_y][m->pos_x + 1] == '0')
		looking_right(m);
	else if (m->sp[m->pos_y][m->pos_x + 1] == 'E')
	{
		floor_before_player(m);
		m->sp[m->pos_y][m->pos_x] = '0';
		put_exit(m);
		m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/looking_right.xpm",
				&m->w, &m->h);
		mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, (m->pos_x) * 60,
				m->pos_y * 60);
	}
	else if (m->sp[m->pos_y][m->pos_x + 1] == 'C')
	{
		looking_right(m);
		m->ball_count--;
	}
	return ;
}

void	left_key(t_s1 *m)
{
	if (m->sp[m->pos_y][m->pos_x - 1] == '0')
		looking_left(m);
	else if (m->sp[m->pos_y][m->pos_x - 1] == 'E')
	{
		floor_before_player(m);
		m->sp[m->pos_y][m->pos_x] = '0';
		put_exit(m);
		m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/looking_left.xpm",
				&m->w, &m->h);
		mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, (m->pos_x) * 60,
				m->pos_y * 60);
	}
	else if (m->sp[m->pos_y][m->pos_x - 1] == 'C')
	{
		looking_left(m);
		m->ball_count--;
	}
	
	return ;
}

void	up_key(t_s1 *m)
{
	if (m->sp[m->pos_y - 1][m->pos_x] == '0')
		looking_up(m);
	else if (m->sp[m->pos_y - 1][m->pos_x] == 'E')
	{
		floor_before_player(m);
		m->sp[m->pos_y][m->pos_x] = '0';
		put_exit(m);
		m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/looking_up.xpm",
				&m->w, &m->h);
		mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, (m->pos_x) * 60,
				m->pos_y * 60);
	}
	else if (m->sp[m->pos_y - 1][m->pos_x] == 'C')
	{
		looking_up(m);
		m->ball_count--;
	}
	return ;
}

void	down_key(t_s1 *m)
{
	if (m->sp[m->pos_y + 1][m->pos_x] == '0')
		looking_down(m);
	else if (m->sp[m->pos_y + 1][m->pos_x] == 'E')
	{
		floor_before_player(m);
		m->sp[m->pos_y][m->pos_x] = '0';
		put_exit(m);
		m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/Player.xpm", &m->w,
				&m->h);
		mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, (m->pos_x) * 60,
				m->pos_y * 60);
	}
	else if (m->sp[m->pos_y + 1][m->pos_x] == 'C')
	{
		looking_down(m);
		m->ball_count--;
	}
	printf("%d\n", m->ball_count);
	return ;
}
