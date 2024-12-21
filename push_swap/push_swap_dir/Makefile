CC = cc 

CFLAGS = -Wall -Wextra -Werror -g

PWSRCS = push_swap.c push_operation.c rotate_operation.c swap_operation.c reverse_rotate.c sort.c utils.c helper.c radix.c

PWOBJ = $(PWSRCS:.c=.o)

LIBFT_DIR = ../libft


LIBFT_A = ../libft/libft.a

NAME = push_swap



all: $(LIBFT_A) $(NAME)

$(NAME) : $(PWOBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT_DIR) -lft

$(LIBFT_A) : 
	make -C $(LIBFT_DIR)
clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(PWOBJ)

fclean : clean
	$(MAKE) fclean -C  $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
