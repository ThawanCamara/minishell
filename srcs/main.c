/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:14:28 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/10 20:24:35 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_get_prompt(void)
{
	char	cwd[1024];
	char	*str;
	char	*tmp;

	str = NULL;
	getcwd(cwd, sizeof(cwd));
	if (ft_strrchr(cwd, '/') != NULL)
		str = ft_strdup(ft_strrchr(cwd, '/') + 1);
	tmp = ft_strdup(LGREEN);
	tmp = append_line(tmp, str);
	free(str);
	str = tmp;
	str = append_line(str, RESET);
	str = append_line(str, "$> ");
	return (str);
}

void	minishell(char *envp[])
{
	static char	*str = NULL;
	char		*prompt;

	(void) envp;
	while (1)
	{
		prompt = ft_get_prompt();
		str = readline(prompt);
		if (str == NULL)
		{
			printf("exit\n");
			free(prompt);
			exit(ft_clean(str, 0));
		}
		if (ft_strncmp(str, "", 1) != 0)
			add_history(str);
		free(str);
		free(prompt);
	}
}

int	ft_clean(void *ptr, int ret)
{
	free(ptr);
	ptr = NULL;
	return (ret);
}

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

void ft_free(char *s)
{
	free(s);
}

void ft_exec(void)
{
	char *argv[] = {"ls", "-l", 0};
	execve("/bin/ls", argv, NULL);
}

int	main(int argc, char *argv[], char **envp)
{
	//t_data	data;
	//t_args	args;

	//args.type = PIPE;
	//int		i = PIPE;

	//i = 0;
	//data.env = ft_copy_envp(envp);
	//ft_striter(data.env, print);
	//ft_striter(data.env, ft_free);
	//free(data.env);
	//minishell(envp);
	(void) argc;
	(void) argv;
	(void) envp;
	//ft_exec();		
	return (0);
}
