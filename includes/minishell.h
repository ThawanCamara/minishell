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
# include <errno.h>
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

enum	e_builtins
{
	D_ECHO,
	D_CD,
	D_PWD,
	D_EXPORT,
	D_UNSET,
	D_ENV,
	D_EXIT
};

/* ************************************************************************** */

/* ************************************************************************** */
/*									 STRUCTS								  */
/* ************************************************************************** */

typedef struct s_cmd
{
	char	*cmd;
	char	*redirmode;
	char	**files;
	char	**argv;
	char	*infile;
	char	*outfile;
	int		outredir;
	int		inredir;
}	t_cmd;

typedef struct s_shell
{
	int		m_din;
	int		m_dout;
	int		m_exit;
	char	**m_envp;
	char	*m_rawline;
	t_list	*m_pidlst;
	char	*line;
	int		cmd_amount;
	t_cmd	*t_cmd;
}	t_shell;

/* ************************************************************************** */

/* ************************************************************************** */
/*									  FUNCTIONS								  */
/* ************************************************************************** */

int		g_status;

// builtins/ft_cd.c
int		ft_cd(t_shell *shell, char *argv[]);

// builtins/ft_echo.c
int		ft_echo(t_shell *shell, char *argv[]);

// builtins/ft_env.c
int		ft_env(t_shell *shell);

// builtins/ft_env_utils.c
char	**ft_setenv(char *var, char *value, char **envp);
char	**ft_getenv(char *var, char **envp);
char	**ft_delenv(char *var, char **envp);

// builtins/ft_exit.c
int		ft_exit(t_shell *shell, char *argv[]);

// builtins/ft_export.c
int		ft_export(t_shell *shell, char *argv[]);

// builtins/ft_unset.c
int		ft_unset(t_shell *shell, char *argv[]);

// builtins/ft_pwd.c
int		ft_pwd(void);

// error/ft_error.c
void	ft_error_quotes(void);
void	ft_error_token(char token);
int		ft_error_msg(char *msg, int ret);

// executor/ft_exec_builtin.c
void	ft_exec_builtin(t_shell *shell, t_cmd *cmd, int builtin);

// executor/ft_exec_pipes.c
void	ft_exec3(t_shell *shell);
void	execv_or_builtin(t_shell *shell, int i, int fdin, int fdout);
void	ft_solobuiltin(t_shell *shell, t_cmd *cmdt, int prevpipe, int i);
void	pids_wait(t_list *m_pidlist);

// executor/ft_executils.c
void	exec(t_shell *shell, int i, int fdin, int fdout);
int		ft_fdout(int pipefd, t_cmd *cmdt);
int		ft_fdin(int pipefd, t_cmd *cmdt);

// executor/ft_isbuiltin.c
int		ft_isbuiltin(char *name);

// executor/ft_open_mode.c
int		ft_open_mode(int redirmode);

// executor/ft_redirfiles.c
int		ft_redirfiles(char **files, char *redirmode);

// executor/ft_search_bin.c
void	ft_search_bin(t_shell *shell, t_cmd *cmdt);

//expansion/ft_expand_var.c
char	*ft_expand_var(char *str, char *envp[]);
int		ft_expand_get_len(char *str);
int		ft_expand_check_mode(char *str);
char	*ft_expand_search(const char *s, char *set);

// heredoc/ft_get_here_doc.c
char	*ft_get_here_doc(char *eof);

// init/ft_cmdhandler.c
void	ft_initcmd(t_shell *shell);
void	ft_clearcmd(t_shell *shell);

// init/ft_shellhandler.c
void	ft_build_token_list(t_shell *shell, char **input);

// init/ft_shellhandler.c
void	ft_initshell(t_shell *shell, char *envp[]);
void	ft_updateshell(t_shell *shell, char *line);
void	ft_resetshell(t_shell *shell);
void	ft_clearshell(t_shell *shell);
void	ft_exitshell(t_shell *shell, int ret);

// lexer/ft_lexer.c
int		ft_lexer(char *line);

// lexer/ft_lexer_checks.c
int		ft_redir_out(char *line, int qflag, int ret);
int		ft_redir_append(char *line, int qflag, int ret);
int		ft_redir_in(char *line, int qflag, int ret);
int		ft_redir_heredoc(char *line, int qflag, int ret);

// lexer/ft_lexer_utils.c
int		ft_validate_next(char *line, const char *badset);

// minishell.c
void	minishell(t_shell *shell);

// parser/ft_parser.c
char	*ft_parser(t_shell *shell, t_cmd *cmdt, char *line);

// parser/ft_parser_utils.c
void	ft_set_cmd_input(t_cmd *cmdt, char *file, int redir);

// signal/ft_signal_handler.c
int		ft_signal_handler(void);
void	reset_signal(void);

// utils/ft_free_arr.c
void	ft_free_arr(void **arr);

// utils/ft_charutils.c
int		ft_quotecheck(char c, int qflag);
int		ft_isredir(char *str);

// utils/ft_free_lst.c
void	ft_free_lst(t_list *lst);

// utils/ft_get_prompt.c
char	*ft_get_prompt(void);

// utils/ft_strutils.c
int		ft_closedquotes_check(char *str);
size_t	ft_count_cmds(const char *s);

// utils/ft_split_cmds.c
char	**ft_split_cmds(char const *s, char c);

/* ************************************************************************** */
#endif
