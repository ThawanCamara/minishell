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


#MAC1		= -I /Users/psydenst/.brew/opt/readline/include #mac42 pedro compilation
#MAC2		= -L /Users/psydenst/.brew/opt/readline/lib

#MAC1		= -I /opt/homebrew/opt/readline/include #local pedro compilation
#MAC2		= -L /opt/homebrew/opt/readline/lib # local pedro compilation

MAC1		= -I/Users/tde-souz/.brew/opt/readline/include	#tde-souz
MAC2		= -L/Users/tde-souz/.brew/opt/readline/lib		#tde-souz
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
				srcs/init/ft_shellhandler.c	\
				srcs/utils/ft_charutils.c	\
				srcs/lexer/ft_lexer.c	\
				srcs/lexer/ft_lexer_utils.c	\
				srcs/lexer/ft_lexer_checks.c	\
				srcs/utils/ft_split_cmds.c	\
				srcs/utils/ft_strutils.c	\
				srcs/signal/ft_signalhandler.c	\
				srcs/error/ft_error.c	\
				srcs/builtins/ft_echo.c	\
				srcs/builtins/ft_exit.c	\
				srcs/builtins/ft_cd.c	\
				srcs/builtins/ft_env.c	\
				srcs/builtins/ft_pwd.c	\
				srcs/builtins/ft_unset.c	\
				srcs/builtins/ft_export.c	\
				srcs/builtins/ft_env_utils.c	\
				srcs/expansion/ft_expand_var.c	\
				srcs/expansion/ft_expand_var_utils.c	\
				srcs/executor/ft_exec_pipes.c	\
				srcs/parser/ft_parser.c	\
				srcs/init/ft_cmdhandler.c	\
				srcs/executor/ft_isbuiltin.c	\
				srcs/executor/ft_exec_builtin.c	\
				srcs/executor/ft_search_bin.c	\
				srcs/executor/ft_open_mode.c	\
				srcs/heredoc/heredoc.c		\
				srcs/utils/ft_free_lst.c	\
				srcs/parser/ft_parser_utils.c	\
				srcs/executor/ft_redirfiles.c	\
				srcs/executor/ft_executils.c	\
				srcs/main.c \

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
			./$(NAME) fodase -n five "|" /bin/cat
#			./$(NAME) fodase -n five "|" /bin/wc -c "|" /bin/cat -e

leak:		all
			clear
			valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME) ola
#			 valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=./minimal.supp ./$(NAME)
#			valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=./minimal.supp --gen-suppressions=all --show-reachable=yes --error-limit=no --log-file=minimalraw.log ./$(NAME) ola mundo
#			valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME) /bin/echo five "|" /bin/wc -c "|" /bin/cat -e

.PHONY:		all clean fclean re run leak
# **************************************************************************** #
