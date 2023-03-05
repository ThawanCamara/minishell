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
	char		**argv;
	char		**envp;
	t_simple	*cmd_table;
	void		**fcheck;
	int			is_command;
	int			exit;
	int			ret;
} t_shell;

/* ************************************************************************** */

/* ************************************************************************** */
/*									  FUNCTIONS								  */
/* ************************************************************************** */

int	g_status;

// builtins/ft_cd.c
int	ft_cd(t_shell *shell, char *argv[]);

// builtins/ft_echo.c
int	ft_echo(t_shell *shell, char *argv[]);

// builtins/ft_env.c
int	ft_env(t_shell *shell);

// builtins/ft_env_utils.c
char	**ft_setenv(char *var, char *value, char **envp);
char	**ft_getenv(char *var, char **envp);
char	**ft_delenv(char *var, char **envp);

// builtins/ft_exit.c
int	ft_exit(t_shell *shell, char *argv[]);

// builtins/ft_export.c
int	ft_export(t_shell *shell, char *argv[]);

// builtins/ft_unset.c
int	ft_unset(t_shell *shell, char *argv[]);

// builtins/ft_pwd.c
int		ft_pwd(void);

// error/ft_error.c
void	ft_error_quotes(void);
void	ft_error_token(char token);
int		ft_error_msg(char *msg, int ret);

// executor/ft_exec.c
int	ft_exec(char *pathname, char *argv[], char *envp[]);

//expansion/ft_expand_var.c
char	*ft_expand_var(char *str, char *envp[]);

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
int 	ft_redir_out(char *line, int qflag, int ret);
int 	ft_redir_append(char *line, int qflag, int ret);
int 	ft_redir_in(char *line, int qflag, int ret);
int 	ft_redir_heredoc(char *line, int qflag, int ret);

// lexer/ft_lexer_utils.c
int		ft_validate_next(char *line, const char *badset);

// minishell.c
void	minishell(t_shell *shell);

// signal/ft_signal_handler.c
int	ft_signal_handler(void);

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
