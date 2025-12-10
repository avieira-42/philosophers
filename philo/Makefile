CC = cc

FLAGS = -Wall -Wextra -Werror -g -pthread

NAME = philo

OUTFILE = -o $(NAME)

SRCS = srcs/main.c \
	   srcs/lib.c \
	   srcs/state_write.c \
	   srcs/parse.c \
	   srcs/feast_init.c \
	   srcs/time_get.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) $(OUTFILE)

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean $(NAME)
