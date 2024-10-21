NAME_SERVER = server
NAME_CLIENT = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)

SRC_DIR = src

SRCS_SERVER = $(SRC_DIR)/server.c
SRCS_CLIENT = $(SRC_DIR)/client.c

all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME_SERVER): $(SRCS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME_SERVER) $(SRCS_SERVER) $(LIBFT)

$(NAME_CLIENT): $(SRCS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME_CLIENT) $(SRCS_CLIENT) $(LIBFT)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re