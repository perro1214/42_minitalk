all:
	@cd ft_printf && make all
	@cc -Wall -Wextra -Werror src/server.c ft_printf/libftprintf.a -o server
	@cc -Wall -Wextra -Werror src/client.c ft_printf/libftprintf.a -o client

clean:
	@cd ft_printf && make clean
	@rm -f server
	@rm -f client

fclean: clean
	@cd ft_printf && make fclean

re: fclean all