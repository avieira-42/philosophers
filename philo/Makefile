# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/12 03:51:00 by avieira-          #+#    #+#              #
#    Updated: 2025/12/12 14:22:56 by avieira-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

.PHONY: all clean fclean re print_art

all: $(NAME) print_art

# Progress bar compilation
%.o: %.c
	   @total=$(words $(SRCS)); \
	   current=0; \
	   bar_length=30; \
	   for f in $(SRCS); do \
	       current=$$((current+1)); \
	       percent=$$((current*100/total)); \
	       filled=$$((bar_length*current/total)); \
	       empty=$$((bar_length-filled)); \
	       bar="$$(printf '%0.s#' $$(seq 1 $$filled))$$(printf '%0.s-' $$(seq 1 $$empty))"; \
	       printf "Compiling philo binaries [%s] %3d%%\r" "$$bar" $$percent; \
	       $(CC) $(FLAGS) -c $$f -o $${f%.c}.o; \
	   done; \
	   echo "";

$(NAME): $(OBJS)
	@echo "Building $(NAME) executable"
	   @$(CC) $(FLAGS) $(OBJS) $(OUTFILE)

clean:
	   @printf "Removing $(NAME) binaries... "
	   @rm -rf $(OBJS)
	   @echo "Done"

fclean: clean
	   @printf "Removing executable... "
	   @rm -rf $(NAME)
	   @echo "Done"

re: fclean all

print_art:
	@printf "\033[35m"
	@printf "                                   __________.__    .__.__                            .__\n"
	@printf "                                   \\______   \\  |__ |__|  |   ____  __________ ______ |  |__   ___________  ______\n"
	@printf "                                    |     ___/  |  \\|  |  |  /  _ \\/  ___/  _ \\\\____ \\|  |  \\_/ __ \\_  __ \\/  ___/\n"
	@printf "                                    |    |   |   Y  \\  |  |_(  <_> )___ (  <_> )  |_> >   Y  \\  ___/|  | \\/\\___ \\ \n"
	@printf "                                    |____|   |___|  /__|____/\\____/____  >____/|   __/|___|  /\\___  >__|  /____  >\n"
	@printf "                                                  \\/                   \\/      |__|        \\/     \\/           \\/ \n"
	@printf "                                   \n\n"
	@printf "\033[1;37m"
	@printf "                                                                 /:/:/:/:-\n"
	@printf "                                                                 +/:/:/:=\n"
	@printf "                                                                .-/:--+\n"
	@printf "                                                             #####=-+ ###*                    ****\n"
	@printf "                                                             #### ## * #######+                 -#****\n"
	@printf "                                                             #### ##.*.###### ##             .##+---**\n"
	@printf "                                                             #### ##***###@@###           #### ##---=#\n"
	@printf "                                       /:######=                ##@##@**###@ *##.       #######= ########\n"
	@printf "                                      .#######+ ###/:           ###@##/:-/:##+++##       ##### ##+##/:########\n"
	@printf "                                        ###-==######@          ###============-=====@#####   @##@#######*\n"
	@printf "                                        .*++==###@@@@.      ==+== +==/:=/:.==-==@==####== /:@##########\n"
	@printf "                                       #####  #/:##@/:@######+*==-== -+/:==/:=/:-====---=+=--====##=########\n"
	@printf "                                      ####@######*@@  .======-=-====   ======-===./:++/:/:--- ===######\n"
	@printf "                                        #### ##@####=##== -+-=/:--.=====+======+*======= ./:/:.=--===== @\n"
	@printf "                                          #### ## ##+##== -==++*==-==================================\n"
	@printf "                                           /:###### ###/:/:----==============================----=======    *--/:*#.\n"
	@printf "                                            ## +####-=---======+-#++=========================-#########+=-/:*#+*##\n"
	@printf "                                                *####=@+==============================/: ---- -===*####*+=######\n"
	@printf "                                           #@@@##*##=======/:   .=======+========#+==== -*=/:-/:=- ===  =/:.-==*##-\n"
	@printf "                                          @@@@@@@+##===== ==*=/:-- ====*+=========@/:= == /:+-+=++- ==/: @###########\n"
	@printf "                                          .@@@@*+/:-#+== -++-*+*---=========.    ====@/:--/:   ====###@#######@*\n"
	@printf "                                        *#  #########@@##==######@=====+==-/:/:++/:*+=#. ====###=#######@######@@/:\n"
	@printf "                                         ##### #################+======#===/:+/:-+=+*/:== ====####=+@##########@@##=\n"
	@printf "                                          #####@############@##============/:- -./:/:= .=**#**#####@##*#@###  #\n"
	@printf "                                           ##+*@######@@@#####@##+========####========####**##@      ###@###\n"
	@printf "                                           @- ########@##*  #####      .=####*====@@@###*##@@@@-        #\n"
	@printf "                                           ##   ###=######                 #####@#####.#***######/:       #\n"
	@printf "                                                 ##                        @###@############ #\n"
	@printf "                                                 @                           #@########*#@##-\n"
	@printf "                                                                               =@@####@    @\n"
	@printf "                                                                                @##        @\n"
	@printf "                                                                                @         @\n"
	@printf "                                                                                ##\n"
	@printf "                                                                                +\n"
