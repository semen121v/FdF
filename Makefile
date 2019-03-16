NAME = fdf

SRCC = *.c

LIB = libft/libft.a

all:$(NAME)

$(NAME): $(LIB)
	gcc  -o $(NAME) -I /usr/local/include $(SRCC) $(LIB) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit 

$(LIB):
	$(MAKE) -C libft/ fclean && make -C libft/ 

clean: 
	@rm -f $(NAME)
	$(MAKE) -C libft/ clean 

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C libft/ fclean 
re: fclean all