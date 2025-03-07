all:
	@cd libft && make
	@cc -Wall -Wextra -Werror src/server.c libft/libft.a -o server
	@cc -Wall -Wextra -Werror src/client.c libft/libft.a -o client

clean:
	@cd libft && make clean
	@rm -f server
	@rm -f client

fclean: clean
	@cd libft && make fclean

re: fclean all