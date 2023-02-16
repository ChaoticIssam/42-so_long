NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SOURCES = errors.c\
			borders_check.c\
			items_check.c\
			so_long_utils.c\
			get_next_line_utils.c\
			get_next_line.c\
			moves.c\
			wasd.c\
			so_long.c\

LIBFT_OB = libft/libft.a
FT_PRINTF_OB = ft_printf/libftprintf.a

OBJECTS = ${SOURCES:.c=.o}

all : $(NAME) $(LIBFT_OB)

$(NAME):	$(OBJECTS) $(LIBFT_OB)
	
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJECTS) $(LIBFT_OB) $(FT_PRINTF_OB) -o $(NAME)
$(LIBFT_OB):
	make all -C libft
	make -C ./ft_printf

clean:
	$(RM)	$(OBJECTS)
	make clean -C libft
	make clean -C ft_printf
fclean:	clean
	$(RM) $(NAME)
	make fclean -C libft
	make fclean -C ft_printf
re:clean fclean all
	make re -C libft
	make re -C ft_printf
.PHONY: all clean fclean re