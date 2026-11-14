CC = cc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printchar.c ft_printnumber.c ft_print_ptr.c ft_print_u_number.c ft_printf.c ft_print_hex.c ft_printprecent.c ft_printstr.c ft_strlen.c
OBJ = $(SRC:.c=.o) 

all : $(NAME)
$(NAME) : $(OBJ)
	ar -rcs $@ $^
%.o : %.c ft_printf.h
	$(CC) -c $(CFLAGS) -o $@ $<
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re : fclean all
.PHONY : clean

