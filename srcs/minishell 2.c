/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:16:50 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/13 17:16:50 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_line(t_shell *shell);

void	minishell(t_shell *shell)
{
	static char	*line = NULL;

	while (shell->exit == 0)
	{
		line = get_line(shell);
		if (ft_lexer(line) == 0)
		{
			ft_updateshell(shell, line);
			ft_get_argv(shell, ft_split_cmds(line, '|'));
			//ft_build_token_list(shell, ft_split_cmds(line, '|'));
		}
		free(line);
	}
	rl_clear_history();
}

char	*get_line(t_shell *shell)
{
	char	*prompt;
	char	*line;

	prompt = ft_get_prompt();
	line = readline(prompt);
	if (line == NULL)
	{
		ft_putstr_fd("exit\n", 2);
		free(prompt);
		rl_clear_history();
		ft_clearshell(shell);
		exit(0);
	}
	if (ft_strncmp(line, "", 1) != 0)
		add_history(line);
	free(prompt);
	return (line);
}
