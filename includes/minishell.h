/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:05:05 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/09 06:33:31 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "colortag.h"
# include <stdio.h>
# include <unistd.h>
# include <term.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <string.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>

/* ************************************************************************** */
/*								   DEFINITIONS								  */
/* ************************************************************************** */
# define CHECKER_FUNCTION_COUNT 3
/* ************************************************************************** */
/*								   ENUMERATIONS								  */
/* ************************************************************************** */

enum e_token_types
{
	PIPE = 10,
	CMD = 11,
	ARGS = 12,
	REDIR = 13,
	DOLLAR = 14
};

/* ************************************************************************** */

/* ************************************************************************** */
/*									 STRUCTS								  */
/* ************************************************************************** */

typedef struct s_simple
{
	char	*infile;
	char	*outfile;
	char	**cmd;
	t_list	*tokens; //*tokens
} t_simple;

typedef struct s_shell
{
	int			cmd_amount;
	int			stdin;
	int			stdout;
	char		**envp;
	t_simple	*cmd_table;
	void		**fcheck;
} t_shell;

/* ************************************************************************** */

/* ************************************************************************** */
/*									  FUNCTIONS								  */
/* ************************************************************************** */

int	g_status;

// init/ft_shellhandler.c
void	ft_build_token_list(t_shell *shell, char **input);

// init/ft_shellhandler.c
void	ft_initshell(t_shell *shell, char *envp[]);
void	ft_updateshell(t_shell *shell, char *line);
void	ft_clearshell(t_shell *shell);
void	ft_init_check_functions(t_shell *shell);

// minishell.c
void	minishell(t_shell *shell);

// utils/ft_free_arr.c
void	ft_free_arr(void **arr);

// utils/ft_charutils.c
int		ft_count_pipes(char *str);

// utils/ft_get_prompt.c
char	*ft_get_prompt(void);

// utils/ft_strdup_arr.c
char	**ft_strdup_arr(char **arr);

// utils/quotes.c
int	quotes_verification(char *str);
int	single_quotes(char *str, int i);
int double_quotes(char *str, int i);
/* ************************************************************************** */
#endif
