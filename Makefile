NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SOURCES = get_next_line_utils.c\
			get_next_line.c\
			so_long.c\

LIBFT_OB = libft/libft.a
OBJECTS = ${SOURCES:.c=.o}

all : $(NAME) $(LIBFT_OB)

$(NAME):	$(OBJECTS) $(LIBFT_OB)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_OB) -o $(NAME)
$(LIBFT_OB):
	make all -C libft
clean:
	$(RM)	$(OBJECTS)
	make clean -C libft

fclean:	clean
	$(RM) $(NAME)
	make fclean -C libft

re:clean fclean all
	make re -C libft

.PHONY: all clean fclean re