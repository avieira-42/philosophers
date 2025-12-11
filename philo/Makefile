CC = cc

FLAGS = -Wall -Wextra -Werror -g -pthread

NAME = philo

OUTFILE = -o $(NAME)

SRCS = srcs/main.c \
	   srcs/lib.c \
	   srcs/state_write.c \
	   srcs/parse.c \
	   srcs/feast_init.c \
	   srcs/feast.c \
	   srcs/time_get.c \
	   srcs/philo_live.c \
	   srcs/death_collector.c \
	   srcs/wait_all.c \
	   srcs/mutex.c \
	   srcs/getter_setter.c \
	   srcs/precise_usleep.c \
	   srcs/error.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) $(OUTFILE)

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean $(NAME)
