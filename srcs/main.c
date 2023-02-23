/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:14:28 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/21 15:13:24 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print(char *s)
{
	printf("%s\n", s);
}

int	main(int argc, char *argv[], char **envp)
{
	t_shell	shell;

	//char *args1[] = {"echo", "-ne", "desgraça de projeto", "insuportavel", 0};
	//char *args2[] = {"export", "KEY2=VALUE2", 0};
	//char *args3[] = {"export", "KEY3=", 0};
	// char *args4[] = {"unset", "HOME", 0};
	//char *args5[] = {"cd", "-", 0};
	char *args5[] = {"cd", "../", 0};

	(void) argc;
	(void) argv;
	ft_signal_handler();
	ft_initshell(&shell, envp);
	//ft_echo(&shell, args1);
	// ft_unset(&shell, args4);
	
	char **env1;
	char **env2;
	ft_cd(&shell, args5);
	env1 = ft_getenv("OLDPWD", shell.envp);
	env2 = ft_getenv("PWD", shell.envp);
	if (env1)
		ft_printf("OLDPWD: %s\n", env1[1]);
	if (env2)
		ft_printf("PWD: %s\n", env2[1]);
	ft_nfree_arr(2, env1, env2);
	ft_cd(&shell, args5);
	env1 = ft_getenv("OLDPWD", shell.envp);
	env2 = ft_getenv("PWD", shell.envp);
	if (env1)
		ft_printf("OLDPWD: %s\n", env1[1]);
	if (env2)
		ft_printf("PWD: %s\n", env2[1]);
	ft_nfree_arr(2, env1, env2);

	ft_pwd();
	//minishell(&shell);
	//ft_env(&shell);
	ft_clearshell(&shell);
	return (0);
}


	// ft_export(&shell, args1);
	// ft_export(&shell, args2);
	// ft_export(&shell, args3);
	// ft_unset(&shell, args4);
	// printf("return status: %d\n", ft_echo(&shell, args1));