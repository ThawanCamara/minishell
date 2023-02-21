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

# include "libft.h"
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
# define CHECKER_FUNCTION_COUNT 6
/* ************************************************************************** */
/*								   ENUMERATIONS								  */
/* ************************************************************************** */

enum e_token_types
{
	CMD = 11,
	ARGS = 12,
	RED_OUT = 13, // >
	RED_APPEND = 14, // >>
	RED_IN = 15, // <	
	RED_HRDOC = 16, // <<
	DOLLAR = 17,
	ENV = 18 // {} depois do $ || tudo o que vier depois $ até achar um ' '.
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
	t_list	*tokens;
} t_simple;

typedef struct s_shell
{
	int			cmd_amount;
	int			stdin;
	int			stdout;
	char		**envp;
	t_simple	*cmd_table;
	void		**fcheck;
	int			qflag;
	int			is_command;
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

// lexer/ft_lexer.c
int	ft_lexer(char *line);

// lexer/ft_lexer_checks.c
int 	ft_redir_out(char *line, int qflag);
int 	ft_redir_append(char *line, int qflag);
int 	ft_redir_in(char *line, int qflag);
int 	ft_redir_heredoc(char *line, int qflag);

// lexer/ft_lexer_utils.c
int		ft_validate_next(char *line, const char *badset);

// minishell.c
void	minishell(t_shell *shell);

// utils/ft_free_arr.c
void	ft_free_arr(void **arr);

// utils/ft_charutils.c
int		ft_count_pipes(char *str);
int		ft_quotecheck(char c, int qflag);

// utils/ft_get_prompt.c
char	*ft_get_prompt(void);

// utils/ft_strdup_arr.c
char	**ft_strdup_arr(char **arr);

// utils/ft_strutils.c
int	ft_closedquotes_check(char *str);

// utils/ft_split_cmds.c
char	**ft_split_cmds(char const *s, char c);
size_t	ft_count_cmds(const char *s);
/* ************************************************************************** */
#endif
