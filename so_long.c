/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:45:09 by iszitoun          #+#    #+#             */
/*   Updated: 2023/02/16 17:53:06 by iszitoun         ###   ########.fr       */
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
	m->str = NULL;
	m->str = ft_read_str(m->fd, m->str);
	if (!m->str)
		return (0);
	m->sp = ft_split(m->str, '\n');
	m->line = words_count(m->str, '\n');
	map_check(m->sp);
	invalid_item(m->sp);
	items_check(m);
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, ft_strlen(*m->sp) * 60, (line_count(m->sp) + 1)
			* 60, "so_long");
	while (m->sp[m->i])
	{
		m->j = 0;
		while (m->sp[m->i][m->j])
		{
			m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/Background.xpm",
					&m->w, &m->h);
			mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->j * 60, m->i * 60);
			if (m->sp[m->i][m->j] == '1')
			{
				m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/void.xpm",
						&m->w, &m->h);
				mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->j * 60, m->i
						* 60);
			}
			if (m->sp[m->i][m->j] == 'E')
			{
				m->xpm_img = mlx_xpm_file_to_image(m->mlx,
						"texture/exit.xpm", &m->w, &m->h);
				mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->j * 60, m->i
						* 60);
			}
			if (m->sp[m->i][m->j] == 'C')
			{
				m->xpm_img = mlx_xpm_file_to_image(m->mlx,
						"texture/Collectible.xpm", &m->w, &m->h);
				mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->j * 60, m->i
						* 60);
			}
			if (m->sp[m->i][m->j] == 'P')
			{
				m->xpm_img = mlx_xpm_file_to_image(m->mlx, "texture/Player.xpm",
						&m->w, &m->h);
				mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->j * 60, m->i
						* 60);
			}
			m->j++;
		}
		m->i++;
	}
	mlx_hook(m->win, 2, 0, &moving_key, m);
	mlx_loop(m->mlx);
}
