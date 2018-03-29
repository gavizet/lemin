# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gavizet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/07 16:38:08 by gavizet           #+#    #+#              #
#    Updated: 2018/03/29 11:09:06 by gavizet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
MAKE	= make -C

### EXECUTABLE ###
NAME	= lem-in

### INCLUDES ###
LIBFT	= libft/
OBJPATH	= objs/
INCPATH	= includes/
SRCPATH	= srcs/

### SOURCES ###
SRCS	= srcs/main.c		\
		  srcs/parse_file1.c\
		  srcs/parse_file2.c\
		  srcs/solver.c		\
		  srcs/print.c		\
		  srcs/utils.c

### OBJECTS ###
OBJS	= $(SRCS:%.c=%.o)

### COLORS ###
NOC			= \033[0m
BOLD		= \033[1m
UNDERLINE	= \033[4m
BLACK		= \033[1;30m
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m

### RULES ###

all: lib $(NAME)

lib:
	@$(MAKE) ./libft

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]"

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling object files into executable [$(NAME)]...$(NOC)"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I $(LIBFT) -I $(INCPATH) -L $(LIBFT) -lft
	@echo "$(GREEN)[$(NAME)] was successfully created$(NOC)"

.PHONY	:	clean fclean

clean:
	@echo "$(YELLOW)Deleting object files from [Project : Lem-in]...$(NOC)"
	@$(MAKE) $(LIBFT) clean
	@/bin/rm -f $(OBJS)
	@echo "$(GREEN)Object files were successfully deleted from [Project : Lem-in].$(NOC)"

fclean:
	@$(MAKE) $(LIBFT) fclean
	@echo "$(YELLOW)Deleting object files from [Project : Lem-in]...$(NOC)"
	@/bin/rm -f $(OBJS)
	@echo "$(GREEN)Object files were successfully deleted from [Project : Lem-in].$(NOC)"
	@echo "$(YELLOW)Deleting executable [$(NAME)] from [Project : Lem-in]...$(NOC)"
	@/bin/rm -f $(NAME)
	@echo "$(GREEN)Executable [$(NAME)] was successfully deleted from [Project : Lem-in].$(NOC)"

re		: fclean all
