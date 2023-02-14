# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 18:48:47 by tde-souz          #+#    #+#              #
#    Updated: 2023/02/09 06:28:00 by tde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#									SETTINGS								   #
# **************************************************************************** #
NAME		:= minishell

CURRENT_OS	:= $(shell uname)
INCLUDES	:= -I libft/ -I includes/
LIBFT_DIR	:= libft/
LIBFT		:= $(LIBFT_DIR)libft.a

CC			:= cc
MAC1		= -I /Users/psydenst/.brew/opt/readline/include
MAC2		= -L /Users/psydenst/.brew/opt/readline/lib
# CFLAGS		= -Wall -Wextra -Werror -g $(MAC1) $(MAC2) $(INCLUDES) # MAC COMPILATION
ifeq ($(CURRENT_OS), Linux)
CFLAGS		= -Wall -Wextra -Werror -g $(INCLUDES) -fPIE # LINUX COMPILATION
else
CFLAGS		= -Wall -Wextra -Werror -g $(MAC1) $(MAC2) $(INCLUDES) # MAC COMPILATION
endif
# **************************************************************************** #


# **************************************************************************** #
#								   TEXT COLORS								   #
# **************************************************************************** #
GREEN		:= \e[38;5;118m
GOLD		:= \e[38;5;220m
RESET		:= \e[0m
BOLD		:= \e[1m
# **************************************************************************** #


# **************************************************************************** #
#								   SOURCE FILES								   #
# **************************************************************************** #
				
SRCS		:=	srcs/minishell.c	\
				srcs/utils/ft_get_prompt.c	\
				srcs/utils/ft_strdup_arr.c	\
				srcs/init/ft_shellhandler.c	\
				srcs/utils/ft_free_arr.c	\
				srcs/token/ft_build_token_list.c	\
				srcs/utils/ft_charutils.c	\
				srcs/main.c

OBJS		:= $(SRCS:.c=.o)
# **************************************************************************** #


# **************************************************************************** #
#									  RULES									   #
# **************************************************************************** #
all:		$(NAME)

#$(NAME):	$(LIBFT) $(OBJS) $(EXECS) includes/ libft/
#			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)
#			@printf "$(NAME) [$(BOLD)$(GREEN)READY$(RESET)]\n"

#just while developing
$(NAME):	$(LIBFT) $(SRCS) $(EXECS) includes/ libft/
			$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -lreadline -o $(NAME)
			@printf "$(NAME) [$(BOLD)$(GREEN)READY$(RESET)]\n"

$(LIBFT):
			make -C $(LIBFT_DIR) extra
			make -C $(LIBFT_DIR) clean
clean:
			$(RM) $(OBJS)
			@printf "$(NAME) [$(BOLD)$(GOLD)INFO$(RESET)] - object files removed\n"

fclean:		clean
			make -C $(LIBFT_DIR) fclean
			$(RM) $(NAME)
			@printf "$(NAME) [$(BOLD)$(GOLD)INFO$(RESET)] - program removed\n"

re:			fclean all

run:		all
			clear
			./$(NAME) ola mundo

leak:		all
			clear
			valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) ola mundo

.PHONY:		all clean fclean re run leak
# **************************************************************************** #
