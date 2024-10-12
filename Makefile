NAME = client server

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

client: client.c
	$(CC) $(CFLAGS) -o client client.c

server: server.c
	$(CC) $(CFLAGS) -o server server.c

clean:
	rm -f client server

fclean: clean

re: fclean all
