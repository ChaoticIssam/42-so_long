#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

char	*get_next_line(int fd);
char	*ft_read_str(int fd, char *str);
char	*ft_strchr1(char *s, int c);
char	*ft_strjoin1(char *left_str, char *buff);
size_t	ft_strlen1(char *s);
char	*ft_get_line(char *str);
char	*ft_new_str(char *str);
int		main(void);

#endif