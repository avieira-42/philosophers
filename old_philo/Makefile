CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g -fsanitize=thread
GPROF = -pg
NAME = philo

B_NAME = philo_bonus

SRCS = srcs/main.c \
	   srcs/error.c \
	   srcs/ft_atol.c \
	   srcs/ft_putstr_fd.c \
	   srcs/get_names/get_names.c \
	   srcs/get_names/get_names_0.c \
	   srcs/get_names/get_names_1.c \
	   srcs/get_names/get_names_2.c \
	   srcs/get_names/get_names_3.c \
	   srcs/get_names/get_names_4.c \
	   srcs/get_names/get_names_5.c \
	   srcs/get_names/get_names_6.c \
	   srcs/get_names/get_names_7.c \
	   srcs/get_names/get_names_8.c \
	   srcs/get_names/get_names_9.c \
	   srcs/get_names/get_names_10.c \
	   srcs/get_names/get_names_11.c \
	   srcs/get_names/get_names_12.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@total=$(words $(SRCS)); \
	current=0; \
	bar_length=30; \
	for f in $(SRCS); do \
		current=$$((current+1)); \
		percent=$$((current*100/total)); \
		filled=$$((bar_length*current/total)); \
		empty=$$((bar_length-filled)); \
		bar="$$(printf '%0.s#' $$(seq 1 $$filled))$$(printf '%0.s-' $$(seq 1 $$empty))"; \
		printf "Compiling minishell binaries [%s] %3d%%\r" "$$bar" $$percent; \
		$(CC) $(CFLAGS) -c $$f -o $${f%.c}.o; \
	done; \
	echo ""; \
	echo "Building $(NAME) executable"; \
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME);

gprof:
	@total=$(words $(SRCS)); \
	current=0; \
	bar_length=30; \
	for f in $(SRCS); do \
		current=$$((current+1)); \
		percent=$$((current*100/total)); \
		filled=$$((bar_length*current/total)); \
		empty=$$((bar_length-filled)); \
		bar="$$(printf '%0.s#' $$(seq 1 $$filled))$$(printf '%0.s-' $$(seq 1 $$empty))"; \
		printf "Compiling minishell binaries [%s] %3d%%\r" "$$bar" $$percent; \
		$(CC) $(GPROF) -c $$f -o $${f%.c}.o; \
	done; \
	echo ""; \
	echo "Building $(NAME) executable"; \
	$(CC) $(GPROF) $(OBJS) -o $(NAME);
clean:
	@printf "Removing $(NAME) binaries... "
	@rm -rf $(OBJS)
	@echo "Done"

fclean: clean
	@printf "Removing executable... "
	@rm -rf $(NAME)
	@echo "Done"

re: fclean all

.PHONY: all clean fclean re
