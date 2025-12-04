CC = cc
CFLAGS = -pthread -g
NAME = philo

B_NAME = philo_bonus

SRCS = srcs/main.c \
	   srcs/error.c \
	   srcs/parse.c \
	   srcs/ft_atol.c \
	   srcs/ft_putstr_fd.c

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
