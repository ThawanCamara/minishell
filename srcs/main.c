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

void	increase_shlvl(t_shell *shell);

int	main(int argc, char *argv[], char **envp)
{
	t_shell	shell;

	(void) argc;
	(void) argv;
	ft_signal_handler();
	ft_initshell(&shell, envp);
	increase_shlvl(&shell);
	minishell(&shell);
	ft_clearshell(&shell);
	return (g_status);
}

void	increase_shlvl(t_shell *shell)
{
	char	**s;
	char	*value;

	s = ft_getenv("SHLVL", shell->m_envp);
	value = ft_itoa(ft_atoi(s[1]) + 1);
	shell->m_envp = ft_setenv(s[0], value, shell->m_envp);
	free(value);
	ft_free_arr((void **)s);
}
