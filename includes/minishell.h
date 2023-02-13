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
//stuff :D
/* ************************************************************************** */
/*								   ENUMERATIONS								  */
/* ************************************************************************** */
//stuff :D
/* ************************************************************************** */

/* ************************************************************************** */
/*									 STRUCTS								  */
/* ************************************************************************** */
//stuff :D
/* ************************************************************************** */

/* ************************************************************************** */

/* ************************************************************************** */
/*									  FUNCTIONS								  */
/* ************************************************************************** */

enum e_types
{
	PIPE = 10,
	CMD = 11,
	ARGS = 12,
	FLAG = 13,
	REDIR = 14
};

int	g_status;

typedef struct s_args
{
	void	*content;
	int		type;
	void	*next;
} t_args;

typedef struct s_simple
{
	int		argc;
	t_args	*var;
	int		append;
	char	*infile;
	char	*outfile;
	char	**argv;
} t_simple;

typedef struct s_shell
{
	int		stdin;
	int		stdout;
	char	**envp;
} t_shell;

/*
 * minishell.c
 */
void	minishell(char *envp[]);

/*
 * utils/ft_get_prompt.c
 */
char	*ft_get_prompt(void);

/*
 * utils/ft_strdup_arr.c
 */
char	**ft_strdup_arr(char **arr);

/* ************************************************************************** */
#endif
