# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 14:16:11 by gmontaur          #+#    #+#              #
#    Updated: 2022/10/14 14:16:34 by gmontaur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			    =	push_swap

CC				    =	gcc
CFLAGS			    =	-Wall -Werror -Wextra

LIBRARIES           =   -lft -L$(LIBFT_DIRECTORY)

LIBFT_DIRECTORY     =   ./libft/
LIBFT               =   $(LIBFT_DIRECTORY)libft.a
LIBFT_HEADERS       =   $(LIBFT_DIRECTORY)incl/

INCLUDES            =   -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I/usr/include

##################################################################
#Header PART OF MAKEFILE
##################################################################
HEADERS_DIRECTORY   =   ./incl/
HEADERS_LIST        =   push_swap.h
HEADERS             =   $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

##################################################################
#Sources PART OF MAKEFILE
##################################################################
SOURCES_DIRECTORY   =   ./src/
SOURCES_LIST        =   main.c \
               			parse.c \
               			operations.c \
               			operations2.c \
               			check_data.c \
               			sort.c \
               			small_sort.c \
               			is_sorted.c \
               			stack.c \
               			utils.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

##################################################################
#Objects PART OF MAKEFILE
##################################################################
OBJECTS_DIRECTORY = objs/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

##################################################################
#Commands PART OF MAKEFILE
##################################################################
CHECKER_PROGRAM	= ./checker_Mac

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(OBJECTS) $(LIBRARIES) $(INCLUDES) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all

test: $(TARGET)
	@test/test.sh

20: $(TARGET)
	$(shell ruby -e "puts (100..119).to_a.shuffle.join(' ')" > test/20.txt)
	@./push_swap $(shell cat "test/20.txt")
	@#./push_swap $(shell cat "test/20.txt") | wc -l

100: $(TARGET)
	$(shell ruby -e "puts (100..199).to_a.shuffle.join(' ')" > test/100.txt)
	@./push_swap $(shell cat "test/100.txt") | wc -l
	@./push_swap $(shell cat "test/100.txt") \
		| $(CHECKER_PROGRAM) $(shell cat "test/100.txt")

500: $(TARGET)
	$(shell ruby -e "puts (100..599).to_a.shuffle.join(' ')" > test/500.txt)
	@./push_swap $(shell cat "test/500.txt") | wc -l
	@./push_swap $(shell cat "test/500.txt") \
		| $(CHECKER_PROGRAM) $(shell cat "test/500.txt")

norminette:
	@make -sC $(LIBFT_DIR) norminette
	@norminette *.c *.h

.PHONY: all fclean clean re test 20 100 500 norminette
##################################################################
