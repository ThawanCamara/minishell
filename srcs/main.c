/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:14:28 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/14 15:55:20 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* int main(void)
{
	printf("%d\n", ft_count_pipes("ls  grep mundo"));
	return (0);
} */

int	main(int argc, char *argv[], char **envp)
{
	t_shell	shell;

	(void) argc;
	(void) argv;
	ft_initshell(&shell, envp);
	minishell(&shell);
	ft_clearshell(&shell);
	return (0);
}
