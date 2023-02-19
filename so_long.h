/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:30:07 by iszitoun          #+#    #+#             */
/*   Updated: 2023/02/19 05:45:55 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

typedef struct t_s1
{
	int		w;
	int		h;
	void	*mlx;
	void	*win;
	void	*xpm_img;
	int		fd;
	char	*str;
	char	**sp;
	int		line;
	int		i;
	int		j;
	int		pos_x;
	int		pos_y;
	int		ex_i;
	int		ex_j;
	int		c_i;
	int		c_j;
	int		count;
	int		ball_count;
}			t_s1;

char		*get_next_line(int fd);
char		*ft_read_str(int fd, char *str);
char		*ft_strchr1(char *s, int c);
char		*ft_strjoin1(char *left_str, char *buff);
size_t		ft_strlen1(char *s);
char		*ft_get_line(char *str);
char		*ft_new_str(char *str);

void		lines_error(void);
void		sides_error(void);
void		horinzontal_error(void);
void		item_needed_error(void);
void		invalid_item_error(void);
void		duplicated_player_error(void);
void		duplicated_exit_error(void);

int			line_len(char *s);
int			line_count(char **str);

void		check_sides(char **s);
int			lines_r_equal(char **s);
int			map_check(char **s);

int			c_check(t_s1 *m);
int			e_check(t_s1 *m);
int			p_check(t_s1 *m);
void		items_check(t_s1 *m);
void		invalid_item(char **s);

int			moving_key(int keysym, t_s1 *m);

void		right_key(t_s1 *m);
void		left_key(t_s1 *m);
void		up_key(t_s1 *m);
void		down_key(t_s1 *m);

void		floor_before_player(t_s1 *m);
void		looking_right(t_s1 *m);
void		looking_left(t_s1 *m);
void		looking_up(t_s1 *m);
void		looking_down(t_s1 *m);

void		print_moves(t_s1 *m);

int			put_image(t_s1 *m);
void		put_floor(t_s1 *m);
void		put_walls(t_s1 *m);
void		for_exit(t_s1 *m);
void		put_exit(t_s1 *m);
// void		put_collectibles(t_s1 *m);
void		put_player(t_s1 *m);

void	for_collectible(t_s1 *m);
void	put_collectibles(t_s1 *m);

int			main(int ac, char **av);

#endif