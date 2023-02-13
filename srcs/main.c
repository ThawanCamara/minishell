/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:14:28 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/13 18:16:34 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_copy_envp(char *envp[])
{
	char	**ret;
	int		i;
	int		j;

	ret = 0;
	j = 0;
	i = 0;
	while (envp[j] != NULL)
		j++;
	ret = malloc(sizeof(char *) * j);
	while (i < j)
	{
		ret[i] = strdup(envp[i]);
		i++;
	}
	ret[i] = ft_strdup(NULL);
	return (ret);
}



void print(char *s)
{
	printf("%s\n", s);
}

int	main(int argc, char *argv[], char **envp)
{
	//t_data	data;
	//t_args	args;

	// char **s = ft_strdup_arr(envp);
	// printf("%s==== Original ====%s\n", B_TEAL, RESET);
	// ft_striter(envp, print);
	// printf("%s==== Dup ====%s\n", B_TEAL, RESET);
	// ft_striter(s, print);
	// ft_striter(s, free);
	// free(s);
	
	//free(data.env);
	minishell(envp);
	(void) argc;
	(void) argv;
	(void) envp;
	//ft_exec();		
	return (0);
}
