/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:39:02 by psydenst          #+#    #+#             */
/*   Updated: 2023/03/03 19:40:02 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int 	array_len(char **argv);
int 	quotes_double(char ** argv, int off, int i, int ret);
int 	quotes_simple(char ** argv, int off, int i, int ret);
void	copy_argv(t_shell *shell, char **argv);
int		double_quotes_cpy(t_shell *shell, char **argv, int i, int begin, int off);
int		simple_quotes_cpy(t_shell *shell, char **argv, int i, int begin, int off);
int		simple_cpy(t_shell *shell, char **argv, int i, int begin, int off);


int		get_argv(t_shell *shell, char **argv)
{
    int array_lenth;
	
	if ((array_lenth = array_len(argv)) < 0)
		return (-1); 
//	shell->argv = malloc(sizeof(char **));
    shell->argv = malloc(sizeof(char *) * array_lenth);
	copy_argv(shell, argv);
	return (0);
}

void	copy_argv(t_shell *shell, char **argv)
{
	int i;
	int off;
	int begin;

	i = 0;
	off = 0;
	shell->ret = 0;
	while (argv[off])
	{
		i = 0;
		begin = 0;
		while (argv[off][i])
		{
			begin = i;
			if (argv[off][i] == '\'')
			{
				i++;
				i = simple_quotes_cpy(shell, argv, i, begin + 1, off);
				shell->ret++;
			}
			if (argv[off][i] == '"')
			{
				i++;
				i = double_quotes_cpy(shell, argv, i, begin + 1, off);
				shell->ret++;
			}
			else
			{
				i = simple_cpy(shell, argv, i, begin, off);
				shell->ret++;
			}
			i++;
		}
		off++;
	}
}

int	simple_cpy(t_shell *shell, char **argv, int i, int begin, int off)
{
	while (argv[off][i] != '"' && argv[off][i] != '\''
		&& argv[off][i] != ' ')
		i++;
	shell->argv[shell->ret] = ft_substr(argv[off], begin, i - begin);
	return (i);
}

int	double_quotes_cpy(t_shell *shell, char **argv, int i, int begin, int off)
{
	while (argv[off][i] != '"' && argv[off][i])
		i++;
	shell->argv[shell->ret] = ft_substr(argv[off], begin, i - begin);
	return (i);
}

int	simple_quotes_cpy(t_shell *shell, char **argv, int i, int begin, int off)
{
	while (argv[off][i] != '\'' && argv[off][i])
		i++;
	shell->argv[shell->ret] = ft_substr(argv[off], begin, i - begin);
	return (i);
}

int array_len(char **argv)
{
	int i;
	int off;
	int ret;
	int sign;

	sign = 0;
	ret = 0;
	off = 0;
	i = 0;
	while(argv[off])
	{
		sign = 0;
		i = 0;
		while(argv[off][i])
		{
			if (argv[off][0] == ' ' && sign == 0)
			{
				if (argv[off][i] == ' ' && argv[off][i - 1] == '\0'
					&& argv[off][i + 1] == '\0')
					break;
				sign = 1;
				i++;
				while(argv[off][i] == ' ')
					i++;
			}
			if ((argv[off][i] == ' ' | argv[off][i + 1] == '\0')
				&& argv[off][i + 1] != '"' && argv[off][i + 1] != ' '
				&& argv[off][i + 1] != '\'')
				ret++;
			if (argv[off][i] == '"')
			{
				if ((i = quotes_double(argv, off, i, ret)) < 0)
					return (-1);
				else
					ret++;
			}
			if (argv[off][i] == '\'')
			{
				if ((i = quotes_simple(argv, off, i, ret)) < 0)
					return (-1);
				else
					ret++;
			}
			i++;
		}
		off++;
	}
	return (ret);
}

int quotes_double(char ** argv, int off, int i, int ret)
{
	i++;
	while (argv[off][i] != '"')
	{
		if (argv[off][i] == '\0')
			return (-1);
		i++;
	}
	i++;
	if (argv[off][i + 1] != ' ' && argv[off][i] != '\0')
	{
		while (argv[off][i] != ' ' && argv[off][i])
			i++;
	}
	return (i);
}

int quotes_simple(char ** argv, int off, int i, int ret)
{
	i++;
	while (argv[off][i] != '\'')
	{
		if (argv[off][i] == '\0')
			return (-1);
		i++;
	}
	i++;
	if (argv[off][i + 1] != ' ' && argv[off][i] != '\0')
	{
		while (argv[off][i] != ' ' && argv[off][i])
			i++;
	}
	return (i);
}

int main() // Preciso tratar o caso de nao ter nada depois de pipe. ex: echo hello
{
	t_shell shell;
	int i = 0;
	char **argv = ft_split(" teste1 | teste2 ", '|');
	get_argv(&shell, argv);

	while (shell.argv[i])
	{
		printf("%s\n", shell.argv[i]);
		i++;
	}
}