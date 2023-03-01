/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:39:02 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/28 22:33:31 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int array_len(char **argv);

void    get_argv(t_shell *shell, char **argv)
{
    int array_lenth;
	
	array_lenth = array_len(argv);
    shell->argv = malloc(sizeof(char *) * array_lenth);
	
}
int quotes_double(char ** argv, int off, int i, int ret);
int quotes_simple(char ** argv, int off, int i, int ret);

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
				sign = 1;
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
			if (i < 0)
				return (-1);
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

// int main() // Preciso tratar o caso de nao ter nada depois de pipe. ex: echo hello |         
// {
// 	char **argv = ft_split("olha o teste | dos testes | testantes |       ", '|');
// 	printf("%i\n", array_len(argv));		
// }