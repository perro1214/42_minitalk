CFLAGS = -Wall -Wextra -Werror -Iincludes
CC = cc
SRC_DIR = srcs
SRCS = $(SRC_DIR)/ft_printf.c $(SRC_DIR)/ft_put_fd_int.c $(SRC_DIR)/ft_hextoa.c $(SRC_DIR)/ft_pointer_hextoa.c $(SRC_DIR)/tr_hex.c $(SRC_DIR)/tr_heX.c  $(SRC_DIR)/tr_pointer.c \
				$(SRC_DIR)/ft_prints.c $(SRC_DIR)/print_hexs.c

INC_DIR = ./includes
TARGET = libftprintf.a
LIBFT = srcs/libft
#LIBFT_BO = srcs/libft
OBJS = $(SRCS:.c=.o)

# オブジェクトファイルを生成するルール
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	make -C $(LIBFT)
#	make bonus -C $(LIBFT_BO)
	cp $(LIBFT)/libft.a ./$(TARGET)
	ar rcs $@ $(OBJS)

all: $(TARGET)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT) clean 
# libftもクリーンする

fclean: clean
	rm -f $(TARGET)
	make -C $(LIBFT) fclean 
# libftも完全クリーンする

re: fclean all

.PHONY: all clean fclean re