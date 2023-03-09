CC=gcc
CFLAGS= -Werror -Wall -Wextra
SRCS= parser.c gnl.c ft_strjoin_freed.c
INC= cub.h
LIB= libft/libft.a
OBJ =$(subst .c,.o,$(SRCS))

%.o: %.c $(INC)
	$(CC) -c -o $@ $< $(CFLAGS)
all: cub

$(LIB): force
	@make -C libft

force:

cub: $(OBJ) $(LIB)
		$(CC) -fsanitize=address  -o $@ $^ $(CFLAGS)
clean:
	rm -rf $(OBJ)
fclean : clean
	@make fclean -C libft
	rm -rf cub
re:fclean
	$(MAKE)
